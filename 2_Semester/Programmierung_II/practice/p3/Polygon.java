import java.awt.*;

public class Polygon extends Figur{
  
  public int a;
  public int b;
  Polygon(){
    this.a=a;
    this.b=b;
  }
  double getCircumference()
     {return 1;}
  double getArea ()
     {return 1;}
  int    getHeight()
     {return 1;}
  int    getWidth () 
     {return 1;}
  public void paint (Graphics g){
    g.setColor(Color.darkGray);
    
    //drawPolygon(int [] xPoints, int [] yPoints, int nPoints);
    
    int xPoints[] = {10,90,10,90,10};
    int yPoints[] = {10,10,90,90,10};
    int nPoints   = 5;
    
    g.drawPolygon(xPoints, yPoints, nPoints);
  }
}