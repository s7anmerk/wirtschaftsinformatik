import java.lang.*;
import java.io.*;

public class HexDump
{
  
  byte data[];

  HexDump(String s)
  {
    data=s.getBytes();
  }

  HexDump(InputStream fis)
  {
    try
    {
      ByteArrayOutputStream bos=new ByteArrayOutputStream(1024);
      byte buf[]=new byte[1024];
      int lenr;
      
      while ((lenr=fis.read(buf))>-1) bos.write(buf,0,lenr);
        
        data=bos.toByteArray();
    }catch(Exception e){System.out.println(e);}
  }

  /* produces a char Array of length len displaying
     the hexadecimal Value of the value z */
  private char[] hexByte(int z, int len)
  {
    char[] x=new char[len];
    int i,hx;
    for(i=len-1;i>=0;i--)
    {
      hx=z;
      z>>>=4;
      hx&=0xf;
      x[i]=(char)(hx<=9?hx+'0':hx+'A'-10);
    } 
    return x;
  }

  /* produces a String in the Form of a hexdump
     of an array of bytes */
     //////////////////////////////////////////////////////////////////////////////////////////
  public String getHexString()
  {
    String s="";
    
    //Ausgabe von i in Hexadezimal
    for (int i=0; i < data.length; i+=16){
      s+= '\n'+new String(hexByte(i,4))+": ";
      
    //Ausgabe des HexBytes mit '|' nach jeder 4 Zeilen
    for (int j=0; j<16 && (i+j)< data.length; j++) {
      s+= new String(hexByte(data[i+j],2))+' ';
      if(((i+j+1)%4)==0)
      s+=" | ";
      } 
      
    //Ausgabe des Textes args[0]
    for(int j =0; j<16 && (i+j)<data.length; j++){
      s+=(char)data[i+j]; 
      }
    }
    return s;
    }
    // geben Sie zuerst den Text in data als String zurueck, erzeugen Sie dazu ein 
    // neues Objekt der Klasse String und initialisieren es mit data.
    // Als zweites erzeugen Sie ein Stringobjekt aus dem Returnwert der 
    // Fuhnktion getHexByte, der Sie das erste Byte von Data und die 
    // Laenge 2 uebergeben.
    // Als drittes bauen Sie eine Schleife, in der die Bytes aus Data 
    // mit getHexByte umgewndelt werden und nacheinander, durch Leerzeichen 
    // getrennt zu dem String zusammen gebaut werden.
/////////////////////////////////////////////////////////////////////////////////////////////////
  public static void main(String args[])
  {
    //     System.out.println(new HexDump(args[0]).getHexString());
    try
    {
      System.out.println(new HexDump(new FileInputStream(args[0])).getHexString());
    }catch(Exception e){System.out.println(e);}
  }
}
