import java.net.*;
import java.io.*;

public class Client {
  public static void main (String[] args){
    DatagramSocket skt=null;
    
    try{
       skt = new DatagramSocket();
       String msg = args[0];
       //konvertieren unsere Nachricht
       byte [] b = msg.getBytes();
       InetAddress host = InetAddress.getByName("localhost");
       int serverSocket = 6755;
       //datagrammpacket zum Senden
       DatagramPacket request = new DatagramPacket(b,b.length,host,serverSocket);
       //wir benutzen skt um Daten zu senden
       skt.send(request);
       //************************************************************************
       
       //um antwort zu bekommen
       byte [] buffer = new byte[1000];
       DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
       //jetzt bekommen wir die antwort
       skt.receive(reply);
       // Paket auspacken
        msg=new String(reply.getData(),0,reply.getLength());

       //antwort auf die konsole ausgeben
       System.out.println(msg);
       skt.close();
    }catch (Exception ex){}  
  }
}
