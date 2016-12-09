import java.net.*;
import java.io.*;
import java.util.*;
import java.lang.*;

public class TestServ
{
  public static void main(String argv[])
  throws IOException
  {
    ServerSocket ss =
    new ServerSocket(Integer.parseInt(argv[0]));
    
    while (true) new TinyServConn(ss.accept());
    
  }
}
class TinyServConn extends Thread
{
  Socket sock;
  TinyServConn(Socket s)
  {
    sock=s;
    start();
  }
  public void run()
  {
    try
    {
      String Command=null;
      String req="",S;
      byte buf[]=new byte[128];
      BufferedReader BR=
      new BufferedReader(new InputStreamReader(sock.getInputStream()));
      // Finde die Zeile, die mit GET beginnt !
      while(!(S=BR.readLine()).startsWith("GET"));req=S;
      System.out.println("Req:"+req);
      
      StringTokenizer st=new StringTokenizer(req);
      if ((st.countTokens()>=2)
      &&  (Command=st.nextToken()).equals("GET"))
      {
        OutputStream out=sock.getOutputStream();
        if ((req =st.nextToken()).startsWith("/")) req=req.substring(1);
        
        System.out.println("File to send: "+req);
        File F=new File(req);
        FileInputStream fis=new FileInputStream(req);
        
        int len;
        while ((len=fis.read(buf))!=-1) out.write(buf,0,len);
          
          sock.shutdownOutput();
      }
      System.out.println("ready");
      sock.close();
    }catch(IOException e) {System.out.println("I/O Error "+e);}
  }

}

    