import java.awt.*;
import java.awt.event.*;

public class GUI_Button_TextField extends MeinFenster {
  Button button1, button2;
  Label label1;
  TextField textfield1;
  
  //Im Konstruktor erzugen wir die GUI-Elemente
  public GUI_Button_TextField(String titel, int w, int h){
    super(titel, w, h);
    setSize(w, h);
    
    //wir registrieren den WindowListener, um auf 
    //WIndowEvents reagieren zu können
    addWindowListener(new meinWindowListener());
    
    //wir bauen einen ActionListener, der nur auf Knopfdruck reagiert
    ActionListener aktion = new Knopfdruck();
    
    setLayout(new FlowLayout());
    
    textfield1 = new TextField("hier steht schon was", 25);
    add(textfield1);
    
    button1 = new Button("Knopf");
    add(button1);
    button1.addActionListener(aktion);
    button1.setActionCommand("b1");
    
    label1 = new Label ("noch steht hier nicht viel");
    add(label1);
    setVisible(true);  
  }
  
  private void button1Clicked(){
    String txt = textfield1.getText();
    label1.setText(txt);
    }
    
    //********************************************************
    //Innere Klassen für das Eventmanagement
    class meinWindowListener extends WindowAdapter{
      public void windowClosing(WindowEvent event){
        System.exit(0);
        }
      }
      
      class Knopfdruck  implements ActionListener{
        public void actionPerformed (ActionEvent e){
          //wir behandeln die Ereignisse
          String cmd = e.getActionCommand();
          if(cmd.equals("b1"))
          button1Clicked();
          }
        }
        //******************************************************
        
        public static void main(String [] args) {
  GUI_Button_TextField f = new GUI_Button_TextField ("Klick mich...", 500, 500);
    }
    }