import java.lang.*;
import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class HexDumpPanel extends Panel{
  
  private TextField tf = new TextField(70);
  HexDumpArea area     = new HexDumpArea(20,50);
  
  ActionListener url1 = new ActionListener(){
    public void actionPerformed(ActionEvent e){
      String eingabe = tf.getText();
      URL url = null;
      try{
      url = new URL(eingabe);
        }catch(MalformedURLException me){}
        String buf, ausgabe="";
        InputStreamReader i = null;
        BufferedReader BR = null;
        try{
          i= new InputStreamReader(url.openStream());
          BR = new BufferedReader(i);
          while((buf=BR.readLine()) != null){
            System.out.println(buf);
            ausgabe = ausgabe + buf;
            }
            area.replace(ausgabe);
            BR.close();
          }catch(IOException ioe){}
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
          try{
            c.connect();
            }catch(IOException ioe){}
        }catch(MalformedURLException me){}
        
      String buf, ausgabe="";
      InputStreamReader i = null;
      BufferedReader BR = null;
      try{
        i = new InputStreamReader(url.openStream());
        BR = new BufferedReader(i);
        
        while((buf = BR.readLine()) != null){
          System.out.println(buf);
          ausgabe = ausgabe + buf;
          }
          area.replace(ausgabe);
          BR.close();
        }catch(IOException ioe){System.out.println(ioe);
        System.exit(1);
        }
      }
    };
    
    ActionListener asock = new ActionListener(){
      public void actionPerformed(ActionEvent e){
         String eingabe = tf.getText();
         URL url = null;
         try{
           url = new URL(eingabe);
           }catch(MalformedURLException me){}
           try{
             Socket s = new Socket(url.getHost(), 80);
             PrintStream O = new PrintStream(s.getOutputStream());
             O.println("GET"+url.getPath());
             O.println("\r");
             BufferedReader I = new BufferedReader(new InputStreamReader(s.getInputStream()));
             String X = "", buf;
             
             while((buf = I.readLine()) != null)
              X = X + buf;
              area.replace(X);
              s.close();
             }catch(Exception ee){System.out.println(ee);
             ee.printStackTrace();}
        }
      };
    
    Button [] button = new Button[3];
    private String [] buttonString = {"Get URL-Object","Get URL-Connection","Get Socket"};
    ActionListener als [] = {url1, c, asock};
    
    public HexDumpPanel(){
      Panel P = new Panel();
      Label l = new Label("Enter File");
      P.add(l);
      P.add(tf);
      Panel keys = new Panel();
      for(int i = 0; i < buttonString.length; i++){
        Button b = new Button(buttonString[i]);
        keys.add(b);
        b.addActionListener(als[i]);
        }
        setLayout(new BorderLayout());
        add(P, BorderLayout.NORTH);
        add(area, BorderLayout.CENTER);
        add(keys, BorderLayout.SOUTH);
      }
  public static void main (String [] args){
    Frame F = new Frame();
    F.addWindowListener(new WindowAdapter(){public void windowClosing(WindowEvent we){System.exit(0);}});
    
    HexDumpPanel P = new HexDumpPanel();
    F.add(P);
    F.pack();
    F.setVisible(true);
    }
}