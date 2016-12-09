import java.io.*;
import java.net.*;

public class Server {
  
  public static void main(String [] args){
    
    DatagramSocket skt = null;
    
    try{
      skt = new DatagramSocket(6755); //PortNummer = 6755
      byte [] buffer = new byte[1024];
      
      while(true){
        
        DatagramPacket request = new DatagramPacket(buffer, buffer.length);
        skt.receive(request);
        
        String msg = new String (request.getData(), 0, request.getLength());
        File file = new File(msg);
        if(file.exists()){
          msg = msg + " existiert und hat die Länge"+file.length();
          //ask for new file name
        } else msg = msg + " existiert nicht";
        byte [] sendMsg = msg.getBytes();
        DatagramPacket reply = new DatagramPacket(sendMsg, sendMsg.length, request.getAddress(), request.getPort());
        skt.send(reply);
        skt.close();
        }
      }catch(Exception ex){}
    }
  }