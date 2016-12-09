import java.lang.*;
import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;
import java.lang.*;
import java.util.*;

public class HexDumpPanel extends Panel{

  private TextField tf = new TextField(70);
  HexDumpArea area = new HexDumpArea(20,50);

  
  ActionListener url1 = new ActionListener(){
    public void actionPerformed(ActionEvent e){
      String eingabe = tf.getText();
      URL        url = null;
      try{
        url = new URL(eingabe);
      }catch(MalformedURLException me)
      {}
      
      //InputStream  i = url.openStream();
      String buf, ausgabe="";
      InputStreamReader i=null;
      BufferedReader BR=null;
      try{
        i = new InputStreamReader(url.openStream());
        BR = new BufferedReader(i);
        while((buf=BR.readLine())!=null){
          System.out.println(buf);
          ausgabe= ausgabe + buf;
        }      
        area.replace(ausgabe);      
        BR.close();
      }catch(IOException ioe){
      }
    }       
  };

  ActionListener c = new ActionListener(){
    public void actionPerformed(ActionEvent e){
      
      String eingabe = tf.getText();
      URL url = null;
      URLConnection c = null;
      try{
        
        url = new URL(eingabe);
        
        try{
          c = url.openConnection();
        }catch(IOException ioe){}
        
        System.out.println("Length :"+c.getContentLength());
        System.out.println("Type :"+c.getContentType());
        System.out.println("Encoding :"+c.getContentEncoding());
        System.out.println("header :"+c.getHeaderFields());
        
        try{
          c.connect();
        }catch(IOException ioe){}
        
      }catch(MalformedURLException me)
      {
        
      }
      String buf, ausgabe="";
      InputStreamReader i=null;
      BufferedReader BR=null;
      try{
        i = new InputStreamReader(url.openStream());
        BR = new BufferedReader(i);
        while((buf=BR.readLine())!=null){
          System.out.println(buf);
          ausgabe= ausgabe + buf;
        }
        
        area.replace(ausgabe);
        
        BR.close();
      }catch(IOException ioe){ System.out.println(ioe);
        System.exit(1);
      }
      
    }
  };

  ActionListener socket = new ActionListener(){
    public void actionPerformed(ActionEvent e){
      String eingabe = tf.getText();
      try{
        ServerSocket socket = new ServerSocket(Integer.parseInt(eingabe));//}catch(IOException ioe){}
        
        while (true)
          //try{
          new TinyServConn(socket.accept());} catch(IOException ioe){} 
      
    }
  };

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
        String ausgabe = "";
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
          while ((len=fis.read(buf))!=-1)    ausgabe= ausgabe + buf;
            out.write(buf,0,len);
          //ausgabe= ausgabe + buf; //------------------------------------------
          
          sock.shutdownOutput();
        }
        System.out.println("ready");
        
        //--------------------------------------------------------------------
        area.replace(ausgabe);
        
        sock.close();
      }catch(IOException e) {System.out.println("I/O Error "+e);}
    }
  }
    
  Button[] button = new Button[3];
  private String[] buttonString = { "Get URL-Objekt", "Get URL-Connection", "Get Socket"};
  ActionListener als [] = {url1,  c, socket};
        
        
  public HexDumpPanel()
  {
    //setFont(new Font("Hevetica",Font.BOLD,32));
    Panel P=new Panel();
    
    Label l = new Label("Enter File");
    P.add(l);
    
    P.add(tf);
    // label
    Panel keys = new Panel();
    for(int i=0;i<buttonString.length;i++){
      Button b = new Button(buttonString[i]);
      keys.add(b);
      b.addActionListener(als[i]);  
      
    }
    
    setLayout(new BorderLayout());
    add(P,  BorderLayout.NORTH);
    add(area,BorderLayout.CENTER);
    add(keys,BorderLayout.SOUTH);
    
  }
        
  public static void main(String args[])
  {
    Frame F=new Frame();
      F.addWindowListener(new WindowAdapter(){public void windowClosing(WindowEvent we){System.exit(0);}});
    
    HexDumpPanel P=new HexDumpPanel();
    F.add(P);
    F.pack();
    F.setVisible(true);
    
    
  }
        
}
      
      