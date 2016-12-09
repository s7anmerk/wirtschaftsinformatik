import java.io.*;
import java.util.*;
import java.sql.Timestamp;

public class example2 {

  static FileInputStream myFIS = null;
  static FileOutputStream myFOS = null;
  static PrintStream myPOS = null;

  static public void main(String[] args) {
    
    PrintStream e = System.err;
    
    try {
      myPOS = new PrintStream ( args[0]+".hex" );
      long now = new Date().getTime();
      myPOS.printf( "Hex dump of file %s %s %n", args[0], new Timestamp(now) );
      myFIS = new FileInputStream( args[0] );
      
      while ( myFIS.available() > 0 )
        dump( (byte)myFIS.read() );
        
        } catch (IOException x) {
      e.println( "Exception: " + x.getMessage() );
    }
  }

  static private long byteCount = 0;
  static private String byteString = "";
  static private Character actChar = null;


  static private void dump(byte b) {
    
    if ( byteCount % 16 == 0 ) {
      myPOS.print( "  " + byteString );
      byteString = "";
      
      myPOS.printf( "%n%08x:", byteCount );
    }
    
    // output a space every 4 bytes
    if ( byteCount++ % 4 == 0 )
      myPOS.print("  ");
    
    // dump the byte as 2 hex chars
    myPOS.printf( "%02x", b );
    
    actChar = new Character( (char) b);
    
    // try to eleminate non-printable ASCII-output
    if ( Character.isISOControl(actChar) )
      actChar = new Character('.');
    
    // save the char in the String
    byteString +=  actChar.toString();
    
    
  }

}