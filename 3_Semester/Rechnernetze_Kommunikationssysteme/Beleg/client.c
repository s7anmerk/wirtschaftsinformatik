#define _CRT_SECURE_NO_DEPRECATE 
#pragma comment(lib, "Ws2_32.lib")
#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include <ws2ipdef.h>
#include <in6addr.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 100
struct packet{
	unsigned int seq;
	char buffer[BUFFER_SIZE];
	unsigned int endOfFile;
};

int main(int argc, char **argv)
{
	WSADATA wsaData;
	SOCKET clientSocket;
	struct sockaddr_in6 remoteAddr;
	struct timeval asyncTimeval;
	int res = 0;
	// Initialize Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) == SOCKET_ERROR){
		wprintf(L"WSAStartup failed with error-code: %d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	else
		printf("WSAStartup Initialized successful\n");
	// Create a UPD socket for sending data
	clientSocket = socket(AF_INET6, SOCK_DGRAM, 0);
	if (clientSocket == INVALID_SOCKET){
		wprintf(L"create Socket failed with error-code: %d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	else
		printf("Socket created successful\n");
	//
	u_long nNoBlock = 1;
	ioctlsocket(clientSocket, FIONBIO, &nNoBlock);
	//commit Address-Information into structs
	struct addrinfo hints, *remoteAddrInfo = NULL;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET6;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	hints.ai_flags = AI_PASSIVE;
	res = getaddrinfo("::1", "50000", &hints, &remoteAddrInfo);
	if (res != 0) {
		printf("GetAddrInfo failed with error: %d\n", res);
		WSACleanup();
		exit(-1);
	}
	printf("GetAddrInfo returned success\n");
	//
	remoteAddr = *((struct sockaddr_in6 *) (remoteAddrInfo->ai_addr));
	freeaddrinfo(remoteAddrInfo);
	//
	FILE *file = fopen("test.txt", "rt");
	if (file == NULL){
		printf("Open file failed!\n");
		getchar();
		return 1;
	}
	//
	asyncTimeval.tv_sec = 5;
	asyncTimeval.tv_usec = 0;
	//
	unsigned int seq = 1;
	unsigned int ack = 0;
	int tryRepeatPacket = 0;
	struct packet writeData;
	int remoteAddrLen = sizeof(remoteAddr);
	unsigned int simulatePacketNumber = 0;
	unsigned int isSimulatePacketNumber = 0;
	//begin simulation
	if (argv[1] != NULL){
		simulatePacketNumber = atoi(argv[1]);
		isSimulatePacketNumber = 0;
		printf("Client turn on packet for simulation %d \n", simulatePacketNumber);
	}
	//if no argument - no simulation
	else {
		simulatePacketNumber = 0;
		isSimulatePacketNumber = 1;
	}

	//read file
	while (!feof(file)) {
		if (!tryRepeatPacket){
			memset(&writeData.buffer, '\0', BUFFER_SIZE);
			size_t bytesRead = fread(&writeData.buffer, 1, BUFFER_SIZE, file);
			//
			writeData.endOfFile = feof(file);
			writeData.seq = seq;
		}
		//
		if (!isSimulatePacketNumber && seq%simulatePacketNumber == 0){
			isSimulatePacketNumber = 1;
			printf("Simulation lost packet. Try again(y/n)?\n");
			char answer = getchar();
			if (answer == 'y' || answer == 'Y'){
				tryRepeatPacket = 1;
				continue;
			}
		}
		// Send Package
		res = sendto(clientSocket, (char*)&writeData, sizeof(struct packet), 0, (struct sockaddr*)&remoteAddr, sizeof(remoteAddr));
		if (res == SOCKET_ERROR) {
			wprintf(L"Sendto() failed! Error: %d\n", WSAGetLastError());
			closesocket(clientSocket);
			fclose(file);
			WSACleanup();
			return 1;
		}
		//
		printf("Send Packet. Seq: %u\n", writeData.seq);
		//
		fd_set readSet;
		fd_set exceptSet;
		//
		FD_ZERO(&readSet);
		FD_ZERO(&exceptSet);
		FD_SET(clientSocket, &readSet);
		FD_SET(clientSocket, &exceptSet);
		//select () is waiting for the status of the socket
		if (select(0, &readSet, 0, &exceptSet, &asyncTimeval) <= 0){
			printf("Waiting timeout. Try again(y/n)?\n");
			char answer = getchar();
			if (answer == 'y' || answer == 'Y'){
				tryRepeatPacket = 1;
				continue;
			}
			else{

				printf("Socket recieve failed\n");
				fclose(file);
				closesocket(clientSocket);
				return 1;
			}
		}
		//
		if (FD_ISSET(clientSocket, &readSet)){
			res = recvfrom(clientSocket, (char*)&ack, sizeof(ack), 0, (struct sockaddr*)&remoteAddr, &remoteAddrLen);
			if (res == SOCKET_ERROR) {
				wprintf(L"Recvfrom() failed! Error: %d\n", WSAGetLastError());
				printf("Try again?\n");
				char answer = getchar();
				if (answer == 'y' || answer == 'Y'){
					tryRepeatPacket = 1;
					continue;
				}
				else
					return 1;
			}
			//
			if (ack != writeData.seq){
				printf("Packet mismatch. Try again(y/n)?\n");
				char answer = getchar();
				if (answer == 'y' || answer == 'Y'){
					tryRepeatPacket = 1;
					continue;
				}
			}
			seq++;
			tryRepeatPacket = 0;
		}
		//
		if (FD_ISSET(clientSocket, &exceptSet)){
			printf("Socket exception\n");
			fclose(file);
			closesocket(clientSocket);
			return 1;
		}
	}
	//
	printf("Finished\n");
	closesocket(clientSocket);
	fclose(file);
	return 0;
}
//------------------------------------------------------------------------------------------------



