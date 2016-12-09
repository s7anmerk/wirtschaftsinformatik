import java.awt.*;
import java.awt.event.*;

public class Calculator extends Panel{
  //hier Referenzen für Komponenten
  //Buttons, Textfields, Panels vereinbaren
  
  private double result = 0;
  private double m = 0;
  private String memorystring;
  private double memory;
  
  private String lastCommand= "=";
  private boolean start = true;
  
  ActionListener nl = new ActionListener(){
    public void actionPerformed(ActionEvent e){
      if (start)
        tf.setText("");
      tf.setText(tf.getText()+e.getActionCommand());
      start = false;
    }
  };
  ActionListener clr = new ActionListener(){
    public void actionPerformed(ActionEvent e) {
      tf.setText("");
      start=true;
    }
  };
  ActionListener mpl = new ActionListener(){
    public void actionPerformed(ActionEvent e){
      Double d = Double.parseDouble(tf.getText());
      memory = memory + d;
    }
  };
  ActionListener minus = new ActionListener(){
    public void actionPerformed(ActionEvent e){
      Double d = Double.parseDouble(tf.getText());
      memory = memory - d;
    }
  };
  ActionListener mr = new ActionListener(){
    public void actionPerformed(ActionEvent e){
      memorystring = String.valueOf(memory);
      tf.setText(""+memorystring);
    }
  };
  
  
  ActionListener command = new CommandAction();
    
  private class CommandAction implements ActionListener{
    public void actionPerformed(ActionEvent event){
      String command = event.getActionCommand();{
        calculate(Double.parseDouble(tf.getText()));
        lastCommand = command;
        start = true;
      }
    }
  }
  
  private TextField tf = new TextField (40);
  Button [] button = new Button[19];
  String [] buttonString = { "M+","7","8","9","/",
                             "M-","4","5","6","*",
                             "MR","1","2","3","-",
                             "CE","0",".","=","+"
                           };
  ActionListener als [] =  { mpl,   nl, nl, nl,      command,
                             minus, nl, nl, nl,      command,
                             mr,    nl, nl, nl,      command,
                             clr,   nl, nl, command, command
                           };
  
  
  
  Calculator(){
    //Komponenten erzeugen und zu Oberfläche zusammenbauen,
    //Listener verbinden
    
    setLayout(new BorderLayout());
    add(tf,BorderLayout.NORTH);
    Panel keys = new Panel(new GridLayout(4,5));
    
    //For-Schleife
    for(int i=0; i<buttonString.length; i++ ) {
      Button b = new Button(buttonString[i]);
      keys.add(b);
      b.addActionListener(als[i]);
    } 
    add(keys, BorderLayout.CENTER);
    
  }
  public void calculate(double x){
    System.out.println("Result: "+result+" x: "+x);
    if(lastCommand.equals("+")) result +=x;
    else if (lastCommand.equals("-")) result -= x;
    else if (lastCommand.equals("*")) result *= x;
    else if (lastCommand.equals("/")) result /= x;
    else if (lastCommand.equals("=")) result =  x;
    tf.setText(""+result);
  }
    
  public static void main (String args[]){
    Frame F = new Frame();
      F.addWindowListener(new WindowAdapter(){public void windowClosing(WindowEvent we){System.exit(0);}});
    
    //F.setLayout(new GidBagLayout());
    
    Calculator P = new Calculator();
    F.add(P);
    F.pack();
    F.setVisible(true);
  }
}