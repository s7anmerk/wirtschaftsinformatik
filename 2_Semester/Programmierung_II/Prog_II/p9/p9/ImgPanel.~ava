import java.awt.*;
import java.awt.event.*;


//drawArc(int x, int y, int width, int height, int startAngle, int arcAngle)
//Color(int r, int g, int b, int a)
public class ImgPanel extends Panel
  {
  private Image Img;
  float [] prozentzahl = {0, 0, 0, 0};   
  float [] winkel      = {0, 0, 0, 0}; 
  int n=4;
     
  public ImgPanel(Image Img, String args[] ) {
    
    arc_angle(args);
    this.Img = Img;
    MediaTracker M = new MediaTracker(this);
    M.addImage(Img,1);
    
    try {
      M.waitForID(1);
    }catch (Exception e) {}
  }
      
  public void arc_angle(String args[]){
    
    for(int i=0;i<n;i++){
      prozentzahl [i] = Float.parseFloat(args[i]);
      winkel [i] = prozentzahl[i]*360/100;
      System.out.println(""+winkel[i]);
    } 
  }
      
    @Override
  public void paint(Graphics g)
  {
    g.drawImage(Img, 0, 0, this);
    
    String [] name = {"Atom", "Kohle", "Gas", "Sonne/Wind"};
    Color []  col = { new Color (200,0,0,127),
    new Color (76, 175, 80, 127),
    new Color (200,10,140,127),
    new Color (0,0,200,127) 
    };
    
    int angle = 0;
    
    for(int i=0; i<n;i++){
      
      g.setColor(col[i]);
      g.fillArc(Img.getWidth(this)/2-300/2, Img.getHeight(this)/2-300/2, 400, 400, angle, (int)winkel[i]);
      g.drawString(name[i] + ':' + ' ' + prozentzahl[i] + '%', 420, 80+i*20);
      angle += (int)winkel[i];
    }
  }
    /*
        font = new Font("Sanserif", Font.BOLD, 20);
      g.setColor( new Color(200,0,0,127) );
      g.fillArc( Img.getWidth(this)/2-300/2, Img.getHeight(this)/2-300/2, 400, 400, 0, 36 );  //110,80
      g.drawString("Atom: 10%", 420, 80);

      g.setColor( new Color(76, 175, 80, 127) );
      g.fillArc(Img.getWidth(this)/2-300/2, Img.getHeight(this)/2-300/2, 400, 400, 36, 120 );
      g.drawString("Kohle: 33%", 420, 100);

      g.setColor( new Color(200,10,140,127));
      g.fillArc( Img.getWidth(this)/2-300/2, Img.getHeight(this)/2-300/2, 400, 400, 156, 80 );
      g.drawString("Gas: 22%", 420, 120);

      g.setColor( new Color(0,0,200,127) );
      g.fillArc( Img.getWidth(this)/2-300/2, Img.getHeight(this)/2-300/2, 400, 400, 236, 124 );
      g.drawString("Sonne/Wind: 35%", 420, 140);
      */
 @Override
  public Dimension getPreferredSize(){
    return new Dimension(Img.getWidth(this), Img.getHeight(this));
  }
 
    
  public static void main (String [] args){
    Frame F = new Frame("Diagramm");
    Image Img = F.getToolkit().getImage("C:/Users/Anxhela/Desktop/vorlesungen/2_Semester/Programmierung_II/Prog_II/p9/windfarm.jpg");
    F.addWindowListener(new WindowAdapter()
      {public void windowClosing(WindowEvent e)
      {System.exit(0);}});
    
    ImgPanel P = new ImgPanel(Img,args);
    F.add(P);
    F.pack();
    F.setVisible(true);
  }

} 

 
 
