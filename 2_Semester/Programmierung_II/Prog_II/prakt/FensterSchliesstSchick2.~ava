import java.awt.*;
import java.awt.event.*;
public class FensterSchliesstSchick2 extends MeinFenster{
  public FensterSchliesstSchick2(String titel, int w, int h){
    super(titel, w, h);
    addWindowListener(new WindowClosingAdapter());
    setVisible(true);
  }
  //***************************************************
  //innere Klasse
  private class WindowClosingAdapter extends WindowAdapter{
    public void windowClosing(WindowEvent e ){
      System.exit(0);
      }
    }
    //**************************************************
    public static void main (String [] args){
      FensterSchliesstSchick2 f = new FensterSchliesstSchick2("Schliesse mich",300,200);
      }
      }