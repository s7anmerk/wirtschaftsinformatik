import java.awt.*;
import java.awt.event.*;
import java.lang.Object;
import java.awt.Graphics;

class AWTFigur extends Panel
{
  Figur f;

  AWTFigur (Figur f)
  {
    this.f=f;
  }

  public void paint(Graphics g)
  {
    f.paint(g);
    
    //super.paint(g);
    //g.setColor(Color.BLUE);
    g.drawRect(1, 1, 15,10);
  }

  public Dimension getPreferredSize()
  {
    return new Dimension (f.getWidth()+40, f.getHeight()+40);
  }

  public static void main(String args[])
  {
    
    double radius=2;
    Circle kreis = new Circle (radius);
    kreis.getCircumference();
    System.out.println("\nUmfang = "+kreis.getCircumference()+"\n");
    kreis.getWidth();
    System.out.println("\nBreite des Kreises = "+kreis.getWidth()+"\n ");
    
    double a = 2;
    Quadrat quadrat1 = new Quadrat (a);
    quadrat1.getHeight();
    System.out.println("\n\nHöhe des Quadrats = "+quadrat1.getHeight()+" ");
    quadrat1.getWidth();
    System.out.println("\n\nBreite des Quadrats = "+quadrat1.getWidth()+" ");
    
    
    double w = 2;
    double h = 3;
    Rectangle rechteck = new Rectangle (w, h);
    rechteck.getArea();
    System.out.println("\nFlaeche des Rechtecks = "+rechteck.getArea()+" \n");
    rechteck.getHeight();
    System.out.println("\n\nHöhe des Rechtecks = "+rechteck.getHeight()+" ");
    
    /*Figur rechteck1 = new Figur ();
    rechteck1.getCircumference();
    System.out.println("\nUmfang des Rechtecks = "+rechteck1.getArea()+" \n");*/
    
    
    Frame F= new Frame();
    F.setLayout(new FlowLayout());
    F.addWindowListener(new WindowAdapter()
      {public void windowClosing(WindowEvent we){System.exit(0);}});
    AWTFigur P1=new AWTFigur(new Quadrat(30));
    F.add(P1);
    AWTFigur P2=new AWTFigur (new Circle(50));
    F.add(P2);
    F.pack();
    F.setVisible(true);
    
  }
}
