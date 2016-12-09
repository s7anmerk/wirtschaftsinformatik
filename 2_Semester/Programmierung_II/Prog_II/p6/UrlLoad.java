
import java.net.*;
import java.io.*;
public class UrlLoad
{
public static void main(String args[])
{
if (args.length!=2)
{System.err.println("Usage:..."); System.exit(1);}
try
{
URL        url = new URL(args[0]);
OutputStream o = new FileOutputStream(args[1]);
InputStream  i = url.openStream();
int len;
byte buf[]=new byte[128];
while ((len=i.read(buf))!=-­1) o.write(buf,0,len);
o.close();
i.close();
}
catch (MalformedURLException e)
{ System.out.println(e); System.exit(1);}
catch (IOException e)
{ System.out.println(e); System.exit(1);}
}
}
