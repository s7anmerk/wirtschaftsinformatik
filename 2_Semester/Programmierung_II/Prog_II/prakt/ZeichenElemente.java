import java.awt.*;
public class ZeichenElemente extends Frame{
  public ZeichenElemente(String titel){
    setTitle(titel);
    setSize(500,300);
    setBackground(Color.lightGray);
    setForeground(Color.red);
    setVisible(true);
    }
  public static void wartemal(long millis){
try {
  Thread.sleep(millis);
} catch(InterruptedException e) {} 
}
public void paint (Graphics g){
  g.drawRect(30,50,440,200);
  g.setColor(Color.black);
  g.drawLine(30,150,470,150);
  g.setFont(new Font("SansSerif", Font.BOLD, 20));
  g.drawString("Schick!",60,80);
  wartemal(3000);
  g.drawString("Geht so...", 350, 220);
  }
  
  public static void main(String[] args){
    ZeichenElemente t = new ZeichenElemente("Linien im Fenster");
    }
  }