import java.awt.*;
import java.awt.event.*;
class AWTFigur extends Panel{
  Figur f;
  
  AWTFigur(Figur f){
    this.f=f;
  }
  public void paint(Graphics g){
    f.paint(g);
  }
  public Dimension getPreferredSize(){
    return new Dimension(f.getWidth()+200, f.getHeight()+200);
  }
  public static void main(String [] args){
    
    Circle kreis = new Circle(20);
    System.out.println("Umfang = "+kreis.getCircumference()+"\n");
    System.out.println("Breite des Kreises = "+kreis.getWidth()+"\n");
    Rectangle rechteck = new Rectangle(2,3);
    System.out.println("Fläche des Rechtecks = "+rechteck.getArea());
    
    Figur P11 = new Rectangle(10,20);
    System.out.println("Höhe des Rechtecks = "+P11.getHeight());
    
    
    Frame F = new Frame();
    F.setLayout(new FlowLayout());
    
    F.addWindowListener(new WindowAdapter(){public void windowClosing(WindowEvent we){System.exit(0);}});
    
    AWTFigur P1 = new AWTFigur(new Quadrat(30));
    F.add(P1);
    AWTFigur P2 = new AWTFigur (new Circle(50));
    F.add(P2);
    AWTFigur P3 = new AWTFigur (new Rectangle(70,90));
    F.add(P3);
    AWTFigur P4 = new AWTFigur (new Polygon());
    F.add(P4);
    AWTFigur P5 = new AWTFigur (new String1("Hello", 10,35));
    F.add(P5);
    
    F.pack();
    F.setVisible(true);
  }
  
  
}