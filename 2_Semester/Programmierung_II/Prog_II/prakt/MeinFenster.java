import java.awt.*;

public class MeinFenster extends Frame{
  public MeinFenster (String titel, int w, int h){
    this.setTitle(titel);
    this.setSize(w,h);
    
    //zentrier das Fenster
    Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
    this.setLocation((d.width - w)/2, (d.height - h)/2);
    }
  }
  