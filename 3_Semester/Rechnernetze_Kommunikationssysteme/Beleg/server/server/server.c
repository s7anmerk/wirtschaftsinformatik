#define _CRT_SECURE_NO_DEPRECATE 
#pragma comment(lib, "Ws2_32.lib")
#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include <ws2ipdef.h>
#include <in6addr.h>
#include <stdlib.h>
#include <stdio.h>
#include "time.h"

#define BUFFER_SIZE 200

struct packet {
	unsigned int seq;
	char buffer[BUFFER_SIZE];
	unsigned int endOfFile;
};

int receivingData(SOCKET listenSocket, unsigned int simulatePacketNumber);

int main(int argc, char **argv)
{
	WSADATA wsaData;
	SOCKET serverSocket;
	int res = 0;
	//Fehlersimulation, Packetnummer als Argument übergeben
	unsigned int simulatePacketNumber = 0;
	if (argv[1] != NULL) {
		simulatePacketNumber = atoi(argv[1]);
		printf("SERVER turn on packet for simulation %d \n", simulatePacketNumber);
	}
	else {
		simulatePacketNumber = 0;
	}
	//
	// Initialize Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) == SOCKET_ERROR) {
		wprintf(L"WSAStartup failed with error-code: %d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	else
		printf("WSAStartup Initialized successful\n");
	//
	// Create a receiver socket to receive packages
	serverSocket = socket(AF_INET6, SOCK_DGRAM, 0);
	if (serverSocket == INVALID_SOCKET) {
		wprintf(L"create Socket failed with error-code: %d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	else
		printf("Socket created successful\n");
	//
	// Set nonBlock
	u_long nNoBlock = 1;
	ioctlsocket(serverSocket, FIONBIO, &nNoBlock);
	//Initialize struct to bind socket
	struct addrinfo hints, *listenAddr = NULL;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET6;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_protocol = IPPROTO_UDP;
	hints.ai_flags = AI_PASSIVE;//localhost, all requests will be accepted

	res = getaddrinfo(NULL, "50000", &hints, &listenAddr);

	if (res != 0) {
		printf("Getaddrinfo failed with error: %d\n", res);
		WSACleanup();
		exit(-1);
	}
	printf("Getaddrinfo returned success\n");
	//
	res = bind(serverSocket, (struct sockaddr*)(listenAddr->ai_addr), (int)listenAddr->ai_addrlen);
	if (res == SOCKET_ERROR) {
		wprintf(L"Bind Socket failed with error-code: %d\n", WSAGetLastError());
		closesocket(serverSocket);
		WSACleanup();
		return 1;
	}
	else
		printf("Bind Socket successful\n");
	//
	//Call the function to receive packages
	while (1) {

		if (receivingData(serverSocket, simulatePacketNumber))
			printf("Read file failed!\n");
		else
			printf("Read file finished!\n");
		//
		printf("Process more files (y/n)?\n");
		char answer = getchar();
		if (answer == 'n' || answer == 'N')
			return 0;
	}
	return 0;
}

int receivingData(SOCKET listenSocket, unsigned int simulatePacketNumber)
{
	struct sockaddr_in6 remoteAddr;
	int remoteAddrLen = sizeof(remoteAddr);
	unsigned int lastSeq = 0;
	struct packet readData;
	unsigned int res;
	struct timeval asyncTimeval;
	asyncTimeval.tv_sec = 5;
	asyncTimeval.tv_usec = 0;
	//
	int isSimulatePacketNumber = 0;
	if (!simulatePacketNumber) isSimulatePacketNumber = 1; // ignore simulation
														   //
	while (1)
	{
		fd_set readSet;
		fd_set exceptSet;
		//
		FD_ZERO(&readSet);
		FD_ZERO(&exceptSet);
		FD_SET(listenSocket, &readSet);
		FD_SET(listenSocket, &exceptSet);
		//
		if (select(0, &readSet, 0, &exceptSet, 0) <= 0)
		{
			printf("Socket recieve failed\n");
			return 1;
		}
		//Listen to socket
		if (FD_ISSET(listenSocket, &readSet))
		{
			res = recvfrom(listenSocket, (char*)&readData, sizeof(struct packet), 0, (struct sockaddr*)&remoteAddr, &remoteAddrLen);
			if (res == SOCKET_ERROR) {
				wprintf(L"Recvfrom() failed.Error: %d\n", WSAGetLastError());
				break;
			}
			if (res == 0) {
				wprintf(L"Closed Connection. Error  %d\n", WSAGetLastError());
				break;
			}
			//Simulation
			if (!isSimulatePacketNumber && simulatePacketNumber && (readData.seq%simulatePacketNumber == 0)) {
				printf("Simulation lost packet. Seq: %u\n", simulatePacketNumber);
				isSimulatePacketNumber = 1;
			}
			else {
				if (readData.seq>lastSeq) {
					printf(readData.buffer);
					lastSeq = readData.seq;
				}
				//Sending without simulation
				res = sendto(listenSocket, (char*)&lastSeq, sizeof(lastSeq), 0, (struct sockaddr*)&remoteAddr, sizeof(remoteAddr));
				if (res == SOCKET_ERROR) {
					wprintf(L"Sendto() failed! Error: %d\n", WSAGetLastError());
					return 1;
				}
			}
			//
			if (readData.endOfFile)
				return 0;
		}
		//
		if (FD_ISSET(listenSocket, &exceptSet))
		{
			printf("Exception\n");
			return 1;
		}
	}
	return 1;
}
