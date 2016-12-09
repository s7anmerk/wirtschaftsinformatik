import java.net.*;
import java.io.*;
import java.util.*;
import java.io.IOException;

  public class Client{
  public static void main(String args[]) throws IOException,
                    InterruptedException
  
  {
  InetAddress ia = InetAddress.getByName("localhost");
  
  while(true)
  {

  String s = new Date().toString();
  
  
  byte[] raw = s.getBytes();

  //InetAddress addr = InetAddress.getByName(myHost);
  
  DatagramPacket packet = new DatagramPacket(raw, raw.length, ia, 4711);
  
  DatagramSocket dSocket = new DatagramSocket();
  
  dSocket.send(packet);
  
  System.out.println("Geschickt");

      }
      
   }

}
