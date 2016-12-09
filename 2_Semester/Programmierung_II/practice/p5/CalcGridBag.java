import java.awt.*;
import java.awt.event.*;

public class CalcGridBag extends Panel{
  //hier Referenzen f�r Komponenten
  //Buttons, Textfields, Panels vereinbaren
  
  private double result = 0;
  private double m = 0;
  private String memorystring;
  private double memory;
  
  private String lastCommand= "=";
  private boolean start = true;
   
  
  GridBagConstraints C = new GridBagConstraints();
  Label l = new Label("Calculator");
  Button b;
  
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
  
  private TextField tf = new TextField (50);
  //Button [] button = new Button[19];
  private static final String [][] buttonString = { {"M+","7","8","9","/" },
                             {  "M-","4","5","6","*" },
                             {  "MR","1","2","3","-" },
                             {  "CE","0",".","=","+" }};
  ActionListener als [][] =  { {mpl,   nl, nl, nl,       command},
                             {minus,   nl, nl, nl,       command},
                             {mr,      nl, nl, nl,       command},
                             {clr,     nl, nl, command,  command}};
  
  CalcGridBag(){
    //Komponenten erzeugen und zu Oberfl�che zusammenbauen,
    //Listener verbinden
    
    int rows = buttonString.length;
    int cols = buttonString[0].length;
    
    setLayout(new GridBagLayout());
    C.weightx = 1.0; C.weighty = 1.0;
    C.fill = GridBagConstraints.BOTH;
    C.anchor = GridBagConstraints.WEST;
    C.gridx = 0; C.gridy = 0;
    add(l, C);
    C.gridx = 1;
    C.gridwidth = GridBagConstraints.REMAINDER;
    add(tf, C);
    
    C.gridwidth = 1;
    //C.gridheight = 1;
    C.gridy = 4;
    C.gridx = GridBagConstraints.RELATIVE;
    for(int i=0; i < rows; i++){
      for(int j=0; j < cols; j++){
        //C.gridx = GridBagContraints.RELATIVE;
        Button b = new Button(buttonString[i][j]);
        add(b, C);
        b.addActionListener(als[i][j]);
      } C.gridy = C.gridy + 1;  //spaltenweise �berspringen
    }
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
    
    CalcGridBag P = new CalcGridBag();
    
    F.setLayout(new BorderLayout());
    F.add(P, BorderLayout.CENTER);
    
    F.add(P);
    F.pack();
    F.setVisible(true);
  }
}