import java.awt.*;
public class Quadrat extends Figur{
  
  double circumference;
  double area;
  int height;
  int width;
  
  public double a;  //Seitenlänge
  
  Quadrat (double a){
    this.a=a;
  }

  public double getCircumference(){
    return a*4;
  }
  public double getArea(){
    return a*a;
  }
  public int getHeight(){
    int b = (int)a;
    return b;
  }
  public int getWidth(){
  int b =(int)a;
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

}