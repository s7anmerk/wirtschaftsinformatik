import java.awt.*;
import java.awt.event.*;

public class PieChart extends Frame {
   private Font         font; 

   public PieChart ()
   {
      setSize( 600, 400 );
      setLocation( 70, 70 ) ;
      show();
   }

   public void paint( Graphics g )
   {

      font = new Font("Sanserif", Font.BOLD, 14);
      // start at 0 and sweep 360 degrees

      g.setColor( Color.black );
      g.fillArc( 110, 80, 300, 300, 0, 36 );
      g.drawString("Atom: 10%", 420, 80);

      g.setColor( Color.red );
      g.fillArc( 110, 80, 300, 300, 36, 120 );
      g.drawString("Kohle: 33%", 420, 100);

      g.setColor( Color.blue );
      g.fillArc( 110, 80, 300, 300, 156, 80 );
      g.drawString("Gas: 22%", 420, 120);

      g.setColor( Color.green );
      g.fillArc( 110, 80, 300, 300, 236, 124 );
      g.drawString("Sonne/Wind: 35%", 420, 140);

   }


}
