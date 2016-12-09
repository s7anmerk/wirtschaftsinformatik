import java.awt.*;
public class Circle extends Figur{
  int radius;
  Circle(int r){
    this.radius =r;
    }
  public double getCircumference(){
    return Math.PI*2*radius;
    }
  public double getArea(){
    return Math.PI*(radius*radius);
    }
  public int getHeight(){
    return 2*radius;
    }
  public int getWidth(){
    return 2*radius;
    }
  public void paint(Graphics g){
    g.setColor(new Color(75,100,1,200));
    g.drawOval(0,0,getWidth(),getHeight());
    }
  }