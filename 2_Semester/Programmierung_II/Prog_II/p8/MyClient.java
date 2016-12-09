import java.net.*;
import java.io.*;

public class MyClient
{
  public static void main(String args[])
  {
    if (args.length!=3)
    System.err.println("usage java MyClient <host> <port> >file>");
    else
    try
    {
       Socket s=new Socket(args[0],Integer.parseInt(args[1]));
       PrintStream O=new PrintStream(s.getOutputStream());
       O.println("GET "+args[2]);
       O.println("\r");
       BufferedReader I=new BufferedReader(new InputStreamReader(s.getInputStream()));
       String X;
       while((X=I.readLine())!=null) System.out.println(X);
       s.close();
    }catch(Exception e){System.out.println(e);e.printStackTrace();}
  }
}
