import java.net.*;
import java.io.*;
import java.io.IOException;

    public class Server{
    public static void main(String args[]) throws IOException
    {
    
    
    DatagramSocket socket = new DatagramSocket(4711);
    
    while(true)
    {

    DatagramPacket packet = new DatagramPacket (new byte[1024], 1024);
    socket.receive(packet);
    
    InetAddress address = packet.getAddress();
    int         port    = packet.getPort();
    int         len     = packet.getLength();
    byte[]      data    = packet.getData();
    
    System.out.println("Anfrage von "+address+" vom Port "+port+"mit der Länge "+len+" "+new String(data, 0, len));
    
        
    socket.close();
          }
    
        }
    }
