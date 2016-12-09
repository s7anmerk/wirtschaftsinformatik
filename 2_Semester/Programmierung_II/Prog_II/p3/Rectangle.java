import java.awt.*;
public class Rectangle extends Figur{
  
  /*
  double circumference;
  double area;
  int height;
  int width;
  */
  public int  w;  //Breite  width
  public int h;  //Höhe    height
  
  Rectangle (int  breite, int  hoehe){
    this.w=breite;
    this.h=hoehe;
  }
  public double getCircumference(){
    return 2*w + 2*h;
  }
  public double getArea(){
    return w*h;
  }
  public int getHeight(){
    //int a = (int)h;
    return h;
  }
  public int getWidth(){
   // int b = (int)w;
    return w;
  }
  
  public void paint (Graphics g){
  
  g.setColor(Color.RED);
  g.drawRect(0,0, getWidth(), getHeight());
  
  }
  
  /*
  
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
  
  */
  
}
