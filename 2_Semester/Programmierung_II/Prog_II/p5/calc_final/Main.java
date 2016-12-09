import java.awt.GridLayout;
/*ww w  .  ja  va 2 s  .  c o  m*/
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Main {
  private static final float BTN_FONT_SIZE = 20f; 
  private static final String[][] BTN_LABELS = {
      {"7", "8", "9", "-"},
      {"4", "5", "6", "+"},      
      {"1", "2", "3", "/"},
      {"0", ".", " ", "="}
   };
  private JPanel mainPanel = new JPanel();

  public Main() {
    int rows = BTN_LABELS.length;
    int cols = BTN_LABELS[0].length;
    int gap = 4;
    mainPanel.setBorder(BorderFactory.createEmptyBorder(gap, gap, gap, gap));
    mainPanel.setLayout(new GridLayout(rows, cols, gap, gap));
    for (String[] btnLabelRow : BTN_LABELS) {
      for (String btnLabel : btnLabelRow) {
        JButton btn = createButton(btnLabel);
        mainPanel.add(btn);
      }
    }
  }

  private JButton createButton(String btnLabel) {
    JButton button = new JButton(btnLabel);
    button.setFont(button.getFont().deriveFont(BTN_FONT_SIZE));
    return button;
  }

  public JComponent getMainComponent() {
    return mainPanel;
  }

  public static void main(String[] args) {
    Main mainPanel = new Main();
    
    JFrame frame = new JFrame("CalcEg");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.getContentPane().add(mainPanel.getMainComponent());
    frame.pack();
    frame.setLocationByPlatform(true);
    frame.setVisible(true);
  }
}