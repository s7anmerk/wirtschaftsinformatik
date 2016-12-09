import java.io.*;
import java.net.*;

public class Client{
  
  public static void main(String [] args){
    
    DatagramSocket skt = null;
    
    try{
      skt = new DatagramSocket();
      
      String msg = args[0];
      
      //die Nachricht konvertieren
      byte[] b = msg.getBytes();
      InetAddress host = InetAddress.getByName("localhost");
      int serverSocket = 6755;  //PortNummer
      //Leeres DatagramPacket zum Senden bereitstellen
      DatagramPacket request = new DatagramPacket(b, b.length, host, serverSocket);
      //Senden
      skt.send(request);
      
      //um Antwort zu bekommen
      byte [] buffer = new byte[1024];
      //Leeres DatagramPacket bereitstellen 
      DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
      //Empfangen der Antwort
      skt.receive(reply);
      
      //Packet auspacken
      msg = new String(reply.getData(), 0, reply.getLength());
      
      //Antwort auf die Konsole ausgeben
      System.out.println(msg);
      skt.close();
      }catch(Exception ex){}
    }
  }