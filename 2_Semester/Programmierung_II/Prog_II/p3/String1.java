import java.awt.*;
public class String1 extends Figur{
  
  public int x;
  public int y;
  
  String1 (int m,int n){
    this.x=m;   //Koordinaten x und y
    this.y=n;
  }
  public double getCircumference(){
    return 1;
  }
  public double getArea(){
    return 1;
  }
  public int getHeight(){
    return  x;
  }
  public int getWidth(){
    return y;
  }
  public void paint (Graphics g){
    
    Font font = new Font("Serif", Font.ITALIC, 50);
    g.setFont(font);
    g.drawString("Hello!", x, y);
  }
}