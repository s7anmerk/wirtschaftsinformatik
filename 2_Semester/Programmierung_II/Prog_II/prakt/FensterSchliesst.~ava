import java.awt.*;
import java.awt.event.*;
public class FensterSchliesst extends MeinFenster
                              implements WindowListener {
public FensterSchliesst(String titel, int w, int h){
 super(titel, w, h);
 addWindowListener(this);   //wir registrieren hier dem Ergebnistyp für WindowEvents
 setVisible(true); 
  }
  //*****************************************************************
  //Hier werden die WindowListener-Methoden implementiert
  //Methode:Fenster wird geschlossen
  
 public void windowClosing(WindowEvent event){
   System.exit(0);
   }
   public void windowClosed(WindowEvent event)      {}
   public void windowDeiconified(WindowEvent event) {} 
   public void windowIconified(WindowEvent event)   {}
   public void windowActivated(WindowEvent event)   {}
   public void windowDeactivated(WindowEvent event) {}
   public void windowOpened(WindowEvent event)      {}
   //***************************************************************
   
   public static void main (String [] args){
     FensterSchliesst f = new FensterSchliesst("Schliesse mich!", 200, 100);
     }
  }