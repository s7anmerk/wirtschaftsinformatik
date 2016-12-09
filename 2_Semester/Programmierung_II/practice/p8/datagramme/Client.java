import java.net.*;
import java.io.*;

public class Client{
  
  public static void main(String [] args){
    
    DatagramSocket skt = null;
    
    try{
      skt = new DatagramSocket();
      String msg = args[0]; //Die Nachricht die wir schicken möchten
      
      //die Nachricht konvertieren
      byte [] b = msg.getBytes();
      
      InetAddress host = InetAddress.getByName("localhost");
      int serverSocket = 6755;  //PortNummer
      
      //leeres DatagramPacket zum Sendes bereitstellen
      DatagramPacket request = new DatagramPacket(b, b.length, host, serverSocket);
      
      //senden
      skt.send(request);
      
      //um die Antwort zu bekommen
      
      byte [] buffer = new byte[1024];
      DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
     
      //Antwort bekommen
      skt.receive(reply);
      
      //Packet auspacken
      
      msg = new String(reply.getData(), 0, reply.getLength());
      
      //Antwort auf die Konsole ausgeben
      System.out.println(msg);
      skt.close();
      }catch(Exception ex){}
    }
  }