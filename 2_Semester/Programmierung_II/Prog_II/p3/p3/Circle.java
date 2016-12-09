
   //double umfang(circumference) = Math.PI * 2*radius;
  //double flaeche(area) =  Math.PI * (radius * radius);
  
import java.awt.*;

public class Circle extends Figur{
  
  double circumference;
  double area;
  int height;
  int width;
  
  public double radius = 2;
  int r = (int)radius;
  
  Circle ( double radius){
    this.radius=radius;
  }
  public double getCircumference(){
    return Math.PI*2*radius;
  }
  public double getArea(){
    return Math.PI*(radius * radius);
  }
  public int getHeight(){
    return r;
  }
  public int getWidth(){
    return r;
  }
  void setCircumference(double umfang){
    circumference=umfang;
  }
  void setArea(double flaeche){
    area=flaeche;  
  }
  void setHeight(int r){
    height=r;  
  }
  void setWidth(int r){
    width=r;   
  } 
  
  public void paint(Graphics g) {
    Graphics2D ga = (Graphics2D)g;
    ga.setPaint(Color.red);
    ga.drawOval(150,150,r,r);
  }
  
  //void drawOval(int x, int y, int breite, int hoehe)
     
  
  
     
}