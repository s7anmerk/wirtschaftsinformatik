import java.awt.*;
import java.awt.event.*;

public class CardLayout extends Panel{

  Button b1 = new Button("M");
 

  public CardPanel(){
  setFont(new Font("System", Font.PLAIN, 22));
    setLayout(cards);
    add(b1);
    b1.addActionListener(this);  
}

  public void actionPerformed(ActionEvent e){
    cards.next();
  }
  
  public static void main(String [] args){

      Frame F = new Frame();
       CardLayout cards = new CardLayout();

      F.add(cards);
      
      F.addWindowListener(new WindowAdapter(){public void windowClosing(WindowEvent we){System.exit(0);}});
      
      F.pack();
      F.setVisible(true);
    }
  }