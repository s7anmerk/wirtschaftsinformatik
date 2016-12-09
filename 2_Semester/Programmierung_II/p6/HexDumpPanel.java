import java.lang.*;
import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;

public class HexDumpPanel extends Panel{

  private TextField tf = new TextField(70);
  TextArea area = new TextArea(20,50);

  
  ActionListener url1 = new ActionListener(){
    public void actionPerformed(ActionEvent e){
      String eingabe = tf.getText();
      URL        url = null;
      try{
        url = new URL(eingabe);
      }catch(MalformedURLException me)
      {
        System.out.println(me); System.exit(1);
      }
      
      //InputStream  i = url.openStream();
      String req,buf;
      InputStreamReader i=null;
      BufferedReader BR=null;
      try{
        i = new InputStreamReader(url.openStream());
        BR = new BufferedReader(i);
        while((buf=BR.readLine())!=null)
          System.out.println(buf);
    
          //area.insert(s.getHexString(),1);     
          // area.setText(buf);
          // area.setText(buf.toString());
          //area.setText(area.getText()+"\n"+buf);
          
        BR.close();
      }catch(IOException ioe){
        System.out.println(ioe); System.exit(1);  
      }
    }
  };

  ActionListener urlConnection = new ActionListener(){
    public void actionPerformed(ActionEvent e){
      
    }
  };

  ActionListener socket = new ActionListener(){
    public void actionPerformed(ActionEvent e){
      
    }
  };
  


  Button[] button = new Button[3];
  private String[] buttonString = { "Get URL-Objekt", "Get URL-Connection", "Get Socket"};
  ActionListener als [] = {url1,  urlConnection, socket};
 

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
