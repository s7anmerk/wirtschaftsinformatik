import java.awt.*;
import java.awt.event.*;

public class MausKlick extends MeinFenster{
  public MausKlick(String titel, int w, int h){
    super(titel, w, h);
    setSize(w, h);
    //wir verwenden eine innere anonyme Klasse. Kurz und knapp.
    addWindowListener(new WindowAdapter(){
      public void windowClosing(WindowEvent e){
        System.exit(0);
        }
      });
      addMouseListener(new MouseAdapter(){
        public void mousePressed(MouseEvent e){
          Graphics g = getGraphics();
          g.setColor(Color.green);
          g.fillOval(e.getX(), e.getY(), 10, 10);
          }
          });
      setVisible(true);
    }
    public static void main(String [] args){
      MausKlick f = new MausKlick("Schliesse mich!", 500, 200);
      }
  }