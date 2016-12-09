import java.awt.*;

public class String1 extends Figur{
  public int x;
  public int y;
  
  String1(int m, int n){
    this.x = m;
    this.y = n;
  }
  double getCircumference()
  {return 1;}
  double getArea ()
  {return 1;}
  int    getHeight()
  {return x;}
  int    getWidth ()
   {return y;}
  public void paint (Graphics g){
     Font font = new Font("Serif", Font.ITALIC, 50);
     g.setFont(font);
     g.drawString("Hello",x,y);
  }
  
}