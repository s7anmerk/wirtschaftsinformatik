
   //double umfang(circumference) = Math.PI * 2*radius;
  //double flaeche(area) =  Math.PI * (radius * radius);
  
import java.awt.*;

public class Circle extends Figur{
  int radius;
  Circle ( int r){
    this.radius=r;
  }
  
  public double getCircumference(){
    return Math.PI*2*radius;
  }
  public double getArea(){
    return Math.PI*(radius * radius);
  }
  public int getHeight(){
    return radius;
  }
  public int getWidth(){
    return radius;
  }
  
  /*
  void setCircumference(double umfang){
    circumference=umfang;
  }
  void setArea(double flaeche){
    area=flaeche;  
  }
  void setHeight(int radius){
    height=r;  
  }
  void setWidth(int radius){
    width=r;   
  }      
*/
  public void paint(Graphics g){
   g.setColor(Color.BLUE);
   g.drawOval(0,0,getWidth(),getHeight());
   }
  }
