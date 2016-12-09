import java.awt.*;
import java.awt.event.*;

public class GUI_Button extends MeinFenster {
  Button button1, button2;
  Label label1;
  
  //Im Konstruktor erzugen wir die GUI-Elemente
  public GUI_Button(String titel, int w, int h){
    
    super(titel, w, h);
    setSize(w, h);
    
    //wir registrieren den WindowListener, um auf 
    //WIndowEvents reagieren zu können
    addWindowListener(new MeinWindowListener());
    
    //wir bauen einen ActionListener, der nur auf Knopfdruck reagiert
    ActionListener aktion = new Knopfdruck();
    
    setLayout(new FlowLayout());
    
    button1 = new Button("Linker Knopf");
    add(button1);
    button1.addActionListener(aktion);
    button1.setActionCommand("b1");
    
    button2 = new Button("Recter knopf");
    add(button2);
    button2.addActionListener(aktion);
    button2.setActionCommand("b2");
    
    label1 = new Label ("Ein Label");
    add(label1);
    setVisible(true);  
  }
  
  //******************************************************************
  //Innere Klassen für das Eventmanagement
  
  class MeinWindowListener extends WindowAdapter{
    public void windowClosing(WindowEvent event){
     System.exit(0);
      }
    }
    class Knopfdruck implements ActionListener{
      public void actionPerformed(ActionEvent e){
        label1.setText(e.getActionCommand());
        }
      }
      //************************************************************
      public static void main(String [] args){
        GUI_Button f = new GUI_Button("Schliesse mich!", 500, 500);
        }
}
