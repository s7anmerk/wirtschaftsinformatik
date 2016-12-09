import java.io.*;
import java.io.IOException;
import java.net.*;
import java.util.*;

class UDPClient {

  public static void main(String [] args)throws IOException, InterruptedException
  {
    //Liefert Internet Adresse
    InetAddress addr = InetAddress.getByName("localhost");
    
    while(true){
      
      String s = new Date().toString();
      byte [] raw = s.getBytes();
      //Packet bereitstellen  Das Datenpacket
      DatagramPacket packet = new DatagramPacket(raw, raw.length, addr, 4711);
      
      //Der SendeSocket 
      DatagramSocket dSocket = new DatagramSocket();
      
      dSocket.send(packet);
      
      System.out.println("Weg is' es");
      
      Thread.sleep(1000);
      
    }
  }
}