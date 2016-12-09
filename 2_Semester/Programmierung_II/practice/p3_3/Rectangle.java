import java.awt.*;
public class Rectangle extends Figur{

  public int w;
  public int h;  
  Rectangle(int b, int a){
    this.w=b;
    this.h=a;
  }
  
  public double getCircumference(){
    return w*2+h*2;
  }
  public double getArea(){
    return w*h;
  }
  public int getHeight(){
    return h;
  }
  public int getWidth(){
    return w;
  }
  public void paint(Graphics g){
    g.setColor(Color.RED);
    g.drawRect(0,0,getWidth(), getHeight());
  }
  
}