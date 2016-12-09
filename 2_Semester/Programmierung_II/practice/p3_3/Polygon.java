import java.awt.*;
public class Polygon extends Figur{
  
  public int a;
  public int b;
  Polygon(){
    this.a=a;
    this.b=b;
    }
    public double getCircumference(){
    return 1;
    }
    public double getArea(){
    return 1;
    }
    public int getHeight(){
    return 1;
    }
    public int getWidth(){
    return 1;
    }
    public void paint(Graphics g){
    g.setColor(Color.darkGray);
    //drawPolygon(xPoints, yPoints,nPoints);
    int [] xPoints = {10,90,10,90,10};
    int [] yPoints = {10,10,90,90,10};
    int nPoints = 5;
    
    g.drawPolygon(xPoints, yPoints, nPoints);
    }
    }
    
    
    
  