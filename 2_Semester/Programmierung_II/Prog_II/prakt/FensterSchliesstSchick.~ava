import java.awt.*;
import java.awt.event.*;
public class FensterSchliesstSchick extends MeinFenster{
  public FensterSchliesstSchick(String titel, int w, int h){
    super(titel, w, h);
    //wir verwenden eine Klasse, die nur die gewünschten Methoden
    //der Klasse WindowAdapter überschreibt
    
    addWindowListener(new WindowClosingAdapter());
    setVisible(true);
    }
    public static void main(String[] args){
      FensterSchliesstSchick f = new FensterSchliesstSchick("Schliesse mich!", 200, 100);
      }
  }
  //lokale Klasse, die sich um das Schließen des fensters kümmert
  class WindowClosingAdapter extends WindowAdapter{
    public void windowClosing(WindowEvent e){
      System.exit(0);
      }
    }