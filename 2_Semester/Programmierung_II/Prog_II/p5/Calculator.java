import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Calculator extends JPanel implements ActionListener {
  private JTextField display = new JTextField("0");

  String[] buttonText = {   "M+", "7", "8", "9", "/",
                            "M-", "4", "5", "6", "*",
                            "MR", "1", "2", "3", "-",
                            "CE", "0", ".", "=", "+"}; 
  
  boolean[] function = new boolean[4];
  double[] temporary = {0, 0};
  private double result = 0;

  private String operator = "=";

  private boolean calculating = true;

  public Calculator() {
    setLayout(new BorderLayout());
    
    display.setEditable(false);
    add(display, "North");
    
    JPanel p = new JPanel();
    p.setLayout(new GridLayout(4, 5));
    
    for (int i = 0; i < buttonText.length; i++) {
      JButton b = new JButton(buttonText[i]);
      p.add(b);
      b.addActionListener(this);
      
    }
    //add(p, "Center");  
    add(p, BorderLayout.CENTER); //////
  }

  public void actionPerformed(ActionEvent evt) {
    String cmd = evt.getActionCommand();
    if ('0' <= cmd.charAt(0) && cmd.charAt(0) <= '9' || cmd.equals(".")) {
      if (calculating)
        display.setText(cmd);
      else
        display.setText(display.getText() + cmd);
      calculating = false;
    } else {
      if (calculating) {
        if (cmd.equals("-")) {
          display.setText(cmd);
          calculating = false;
        } else
          operator = cmd;
      } else {
        double x = Double.parseDouble(display.getText());
        calculate(x);
        operator = cmd;
        calculating = true;
      }
    }
  }
  private void calculate(double n) {
    if (operator.equals("+"))
      result += n;
    else if (operator.equals("M+"))
      result = (1)*n;
    else if (operator.equals("M-"))
      result = (-1)*n;
    else if (operator.equals("CE")) 
      result= 0;
    else if (operator.equals("-"))
      result -= n;
    else if (operator.equals("*"))
      result *= n;
    else if (operator.equals("/"))
      result /= n;
    else if (operator.equals("="))
      result = n;
    display.setText("" + result);
  }

  public static void main(String[] args) {
    
    Frame F=new Frame();
      F.addWindowListener(new WindowAdapter(){public void windowClosing(WindowEvent we){System.exit(0);}});
    Calculator P=new Calculator();
    F.add(P);
    F.pack();
    F.setVisible(true);   
  }
}