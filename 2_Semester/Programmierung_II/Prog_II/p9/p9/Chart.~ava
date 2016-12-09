import java.awt.*;
import java.awt.event.*;


//drawArc(int x, int y, int width, int height, int startAngle, int arcAngle)
//Color(int r, int g, int b, int a)
public class Chart extends Panel
  {
  private Image Img;
  float [] prozentzahl = {0, 0, 0, 0}; 
  float [] h           = {0, 0, 0, 0};   //höhe
  int n=4;
     
  public Chart(Image Img, String args[] ) {
    
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
      h[i]=prozentzahl[i]*10;
      System.out.println(""+h[i]);
      
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
      //g.fillRect(Img.getWidth(this)/2-300/2, Img.getHeight(this)/2-300/2, angle, (int)h[i]);
      
      //g.fillRect(Img.getWidth(this)/n+i*200, Img.getHeight(this)/n,100,(int)h[i]);
      
      //g.fillRect(((int)prozentzahl[i] - (Img.getWidth(this) - (int)prozentzahl[i])), Img.getHeight(this)/n,100,(int)h[i]);
      
      //g.fillRect(((int)h[i] - (Img.getHeight(this) - (int)h[i])), Img.getHeight(this)/n, 50,(int)h[i]);
      
      g.fillRect(Img.getHeight(this)/n,((int)h[i] - (1200 - (int)h[i])), 100,(int)h[i]);
      
      g.drawString(name[i] + ':' + ' ' + prozentzahl[i] + '%', 420, 80+i*20);
      angle += (int)h[i];
    }
  }
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
    
    Chart P = new Chart(Img,args);
    F.add(P);
    F.pack();
    F.setVisible(true);
  }

} 

 
 
