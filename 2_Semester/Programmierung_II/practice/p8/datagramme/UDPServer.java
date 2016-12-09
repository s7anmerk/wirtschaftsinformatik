import java.io.*;
import java.io.IOException;
import java.net.*;

public class UDPServer{
  
  public static void main (String [] args)throws IOException
  {
    
    DatagramSocket socket = new DatagramSocket();
    
    while(true){
       //Auf Anfrage warten
      //Leeres Datagram bereitstellen
      DatagramPacket packet= new DatagramPacket(new byte[1024], 1024);
      
      socket.receive(packet);
      
      //Empf�nger auslesen
      
      InetAddress address = packet.getAddress();
      int         port    = packet.getPort();
      int         len     = packet.getLength();
      byte []     data    = packet.getData();
      
      System.out.printf("Anfrage von %s vom Port %d mit der L�nge %d:%n%s%n",
                         address, port, len, new String(data, 0, len));
    }
  }
}