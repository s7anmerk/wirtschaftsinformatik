import java.awt.*;
import java.util.Random;

public class BildFenster extends Frame{
  public BildFenster(String titel){
    setTitle(titel);
    setSize(423,317);
    setBackground(Color.lightGray);
    setForeground(Color.red);
    setVisible(true);     
    
    
  }

  public void paint(Graphics g){
    Image pic = Toolkit.getDefaultToolkit().getImage("C:\\Users\\Anxhela\\Pictures\\art\\martin stejskal");    
    g.drawImage(pic, 0, 0, this);
    
  }
    
  public static void main(String [] args){     
    BildFenster t = new BildFenster("Bild im Fenster");
    img = getToolkit().getImage("C:\\Users\\Anxhela\\Pictures\\art\\martin stejskal"); 
    Mediatracker mt = new Mediatracker (this);
    mt.addImage(img, 0);
    try{
      mt.waitForAll();
      }catch (InterruptedException e){}
      
      g.drawImage(img, 0, 0, this);
  }
    
}