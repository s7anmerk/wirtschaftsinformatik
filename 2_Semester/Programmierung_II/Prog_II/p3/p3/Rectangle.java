import java.awt.*;

import java.lang.Object;
import java.awt.Graphics;


public class Rectangle extends Figur{
  
  double circumference;
  double area;
  int height;
  int width;
  
  public double w;  //Breite  width
  public double h;  //Höhe    height
 
  Rectangle (double w, double h){
    this.w=w;
    this.h=h;
  }
  public double getCircumference(){
    return 2*w + 2*h;
  }
  public double getArea(){
    return w*h;
  }
  public int getHeight(){
    int a = (int)h;
    return a;
  }
  public int getWidth(){
    int b = (int)w;
    
    return b;
  }
 
  void setCircumference(double umfang){
    circumference=umfang;
  }
  void setArea(double flaeche){
    area=flaeche; 
  }
  void setHeight(int b){
    height=b; 
  }
  void setWidth(int b){
    width=b;  
  } 
  
//  void drawRect(int x, int y, int breite, int hoehe) 
  
  //@Override
  public void paint(Graphics g){
   // g.setColor(Color.BLUE);
   // g.drawRect(100, 100, 150, 50);
  }
  
 
  }