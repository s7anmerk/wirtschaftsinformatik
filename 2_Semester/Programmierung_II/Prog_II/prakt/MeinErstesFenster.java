import java.awt.Frame;
public class MeinErstesFenster {

  public static void main(String[] args){
    
    //öffnet ein AWT-Fenster
    Frame f= new Frame("So einfach geht das?");
    f.setSize(300,200);
    f.setVisible(true); //sollte immer am Ende stehen
  }
}
