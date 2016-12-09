import java.awt.*;
import java.awt.event.*;
import java.util.*;

//drawArc(int x, int y, int width, int height, int startAngle, int arcAngle)

public class ImgPanel extends Panel
  {
  private Image Img;
     
  ImgPanel(Image Img /*,hier kommen 2 Arraysw rein, die dann an dem PieChart übergeben werden*/ ) {
    
    this.Img = Img;
    MediaTracker M = new MediaTracker(this);
    M.addImage(Img,1);
    
    try {
    M.waitForID(1);}catch (Exception e) {}
  }
   
    @Override
  public void paint(Graphics g)
  {
    g.drawImage(Img, 0, 0, this);
    PieChart app = new PieChart ();
    
    
  }
 
  public Dimension getPreferredSize(){
    return new Dimension(Img.getWidth(this), Img.getHeight(this));
  }
    
  public static void main (String [] args)
  
  {
    Frame F = new Frame();
    Image I = F.getToolkit().getImage("C:/Users/Anxhela/Desktop/vorlesungen/2_Semester/Programmierung_II/Prog_II/p9/windfarm.jpg");
    ImgPanel P = new ImgPanel(I);
    //F.setSize(500,300);
    //Kreisdragramm k = new ..... //////////////////////////
    //F.add(k);
    F.add(P);
    F.addWindowListener(new WindowAdapter()
      {public void windowClosing(WindowEvent e)
      {System.exit(0);}});
    F.pack();
    F.setVisible(true);
  }

} 

 
 
