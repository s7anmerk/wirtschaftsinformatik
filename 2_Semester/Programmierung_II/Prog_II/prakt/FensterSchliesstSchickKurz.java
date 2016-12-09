import java.awt.*;
import java.awt.event.*;
public class FensterSchliesstSchickKurz extends MeinFenster{
  public FensterSchliesstSchickKurz(String titel, int w, int h){
    super(titel, w, h);
    
    //wir verwenden eine innere anonyme Klasse. Kurz und Knapp!
    
    addWindowListener(new WindowAdapter(){
      public void windowClosing(WindowEvent e ) {
       System.exit(0);
        }
      });
    setVisible(true);
  }
  public static void main(String [] args){
    FensterSchliesstSchickKurz f = new FensterSchliesstSchickKurz("Schliesse mich!", 300, 200);
    
    }
    }