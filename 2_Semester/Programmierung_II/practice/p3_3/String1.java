import java.awt.*;
public class String1 extends Figur{

  public String s;
  public int x; 
  public int y;
   
  String1(String str, int m, int n){
    this.s=str;
    this.x=m;
    this.y=n;
  }
  
  public double getCircumference(){
    return 1;
  }
  public double getArea(){
    return 1;
  }
  public int getHeight(){
    return y;
  }
  public int getWidth(){
    return x;
  }
  public void paint(Graphics g){
    Font font = new Font("Serif", Font.ITALIC, 50);
    g.setFont(font);
    g.setColor(Color.BLUE);
    g.drawString(s,x,y);
  
}
}