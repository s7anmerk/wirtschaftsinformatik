//C:/Users/Anxhela/Desktop/vorlesungen/2_Semester/Programmierung_II/Prog_II/p9/windfarm.jpg

import java.awt.*;
import java.awt.event.*;

public class ImgPanel extends Panel
{
  private Image Img;
  float [] prozentzahl = {0,0,0,0};
  float [] winkel      = {0,0,0,0};
  int n = 4;
  
  public ImgPanel(Image Img, String args [])
  {
    arc_angle(args);
    this.Img=Img;
    MediaTracker M = new MediaTracker(this);
    M.addImage(Img, 1);
    
    try{
      M.waitForID(1);
    }catch(Exception e){}
  }
  public void arc_angle(String [] args)  //Die Funktion rechnet die Prozentwerten in Winkelwerten um
  {
    for(int i = 0; i < n; i++){
      
      prozentzahl[i] = Float.parseFloat(args[i]);
      winkel[i]= prozentzahl[i] * 360 / 100;
      System.out.println(""+winkel[i]);
    }
  }

  @Override
  public void paint(Graphics g){
    g.drawImage(Img, 0, 0, this);
    
    String [] name = {"Atom","Kohle","Gas","Sonne/Wind"};
    Color  [] col  = {new Color (200,0 ,0  ,127),
    new Color (76,175,80 ,127),
    new Color (200,10,140,127),
    new Color (0  ,0 ,200,127)
    };
    
    int angle = 0;
    
    for(int i = 0; i < n; i++){
      g.setColor(col[i]);
      g.fillArc(Img.getWidth(this)/2-300/2, Img.getHeight(this)/2-300/2, 400, 400, angle, (int)winkel[i]);
      g.drawString(name[i] + ':'+' ' + prozentzahl[i] + '%', 420, 80+i*20);
      angle += (int)winkel[i];
    }
  }
    
  @Override
  public Dimension getPreferredSize(){
    return new Dimension(Img.getWidth(this), Img.getHeight(this));
  }
    
  public static void main(String args[])
  {
    Frame F=new Frame("Diagramm");
    
    //Image Img = F.getToolkit().getImage("C:/Users/Anxhela/Desktop/vorlesungen/2_Semester/Programmierung_II/Prog_II/p9/windfarm.jpg");
    
    Image Img = F.getToolkit().getImage(args[4]);
    
      F.addWindowListener(new WindowAdapter(){public void windowClosing(WindowEvent we){System.exit(0);}});
    ImgPanel P=new ImgPanel(Img, args);
    F.add(P);
    F.pack();
    F.setVisible(true);
  }
}
