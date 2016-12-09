//Lagerbestand
import java.io.*;

public class Lagerhaltung{

  public static String einlesen(){
    String str = "";   //String auf 0 setzen
    
    try{
      InputStreamReader isr  =  new InputStreamReader(System.in);
      BufferedReader     bur  =  new BufferedReader(isr);
      
      //Hier lesen wir einen String ein
      str  =  bur.readLine();
      //und geben ihn gleich wieder aus
      //System.out.println(str);
    }catch(Exception e){}
    return str;
  }
    
  public static void main (String [] args) {
    /*
    Materialartikel artikel1 = new Materialartikel(args[0],
    args[1],
    args[2],
    Integer.parseInt(args[3]),
    Integer.parseInt(args[4]),
    Integer.parseInt(args[5]),
    Integer.parseInt(args[6]),
    args[7]);
    */
    
    System.out.println( "Artikel einfügen: ");
    System.out.println("\nArtikelname: "); String artikelname = einlesen();
    while(artikelname.equals("")){
      System.out.println("\nBitte geben Sie den Artikelnamen ein.");
      artikelname = einlesen();
    }
    System.out.println("\nArtikelnummer: "); String artikelnummer = einlesen();
    while(artikelnummer.equals("")){
      System.out.println("\nBitte geben Sie die Artikelnummer ein.");
      artikelnummer = einlesen();
    }
    System.out.println("\nMengeneinheit: "); String mengeneinheit = einlesen();
    while(mengeneinheit.equals("")){
      System.out.println("\nBitte geben Sie die Mengeneinheit ein.");
      mengeneinheit = einlesen();
    }
    System.out.println("\nPackungsgroesse: "); String packungsgroesse = einlesen();
    while(packungsgroesse.equals("")){
      System.out.println("\nBitte geben Sie die Packungsgroesse ein.");
      packungsgroesse = einlesen();
    }
    System.out.println("\nMindeststueckzahl: "); String mindeststueckzahl = einlesen();
    while(mindeststueckzahl.equals("")  ||   Integer.parseInt(mindeststueckzahl)<0){
      System.out.println("\nFalsche Eingabe. Versuchen Sie es noch mal.");
      mindeststueckzahl  = einlesen();
    }
    System.out.println("\nLagerbestand: "); String lagerbestand = lagerbestand = einlesen();
    while(lagerbestand.equals("")  ||   Integer.parseInt(lagerbestand)<0){
      System.out.println("\nFalsche Eingabe. Versuchen Sie es noch mal.");
      lagerbestand  = einlesen();
    }
    System.out.println("\nHersteller: "); String hersteller = einlesen();
    while(hersteller.equals("")){
      System.out.println("\nBitte geben Sie den Hersteller ein.");
      hersteller  = einlesen();
    }
    
    Materialartikel  artikel  = new Materialartikel(
    artikelname,
    artikelnummer,
    mengeneinheit,
    Integer.parseInt(packungsgroesse),
    Integer.parseInt(mindeststueckzahl),
    0,
    Integer.parseInt(lagerbestand),
    0,
    hersteller);
    
    
    while(true){
      System.out.println("\nAuswählen \n0 - Anzeigen \n1 - Lagerbestand \n2 - Materialentnahme \n3 - Nachbestellung \n4 - Verlassen");
      String str = einlesen();
      if(str.equals("4")) break;
      
      switch(str){
        
        case "0":
          System.out.println(artikel.toString());
          break;
        case "1":
          System.out.println("Lagerbestand ist: " + artikel.getLagerbestand());
          break;
        case "2":
          System.out.println("Wie viel möchten Sie aus dem Lager entnehmen?");
          String e_menge = einlesen();
          while(e_menge.equals("")   ||   Integer.parseInt(e_menge)<0){
            System.out.println("Falsche Eingabe. Versuchen Sie es nochmal.");
            e_menge = einlesen();
          }
          artikel.setEntmenge(Integer.parseInt(e_menge));
          
          if(artikel.getLagerbestand() < artikel.getEntmenge()){
            System.out.println("\n Lagerbestand überschritten. Möchten Sie nachbestellen?(ja/nein)");
            String antwort = einlesen();
            
            if(antwort.equals("ja")  ||  antwort.equals("j")  ||  antwort.equals("JA")  ||  antwort.equals("Ja")){
              
              int nachbestellmenge = artikel.getEntmenge() - artikel.getLagerbestand() + artikel.getMindeststueckzahl();
              artikel.setBestellmenge(nachbestellmenge);
              
              System.out.println("\nLagerbestand überschritten. Es wurden automatisch"+nachbestellmenge+" "
              +artikel.getMengeneinheit()+" nachbestellt");
              System.out.println("\n"+artikel.getEntmenge()+""+artikel.getMengeneinheit()+"wurden entnommen");
            }
            else System.out.println("\nMaterialentnahme abgebrochen");
          }
          else if ((artikel.getLagerbestand() - artikel.getEntmenge())>= artikel.getMindeststueckzahl()) {
            artikel.entnahme();
            System.out.println("\n"+artikel.getEntmenge()+""+artikel.getMengeneinheit()+"wurden entnommen");
          }
          else {
            System.out.println("\nMindesstueckzahl unterschritten. Möchten Sie nachbestellen?(ja/nein)");
            String antwort = einlesen();
            if(antwort.equals("ja")  ||  antwort.equals("j")  ||  antwort.equals("JA")  ||  antwort.equals("Ja")){
              System.out.println("Automatische Nachbestellung erfolgt, da der Mindesstueckzahl unterschritten worden ist.");
              artikel.entnahme();
              int nachbestellmenge = artikel.getMindeststueckzahl() - artikel.getLagerbestand();
              
              artikel.setBestellmenge(nachbestellmenge);
              System.out.println("\n"+nachbestellmenge+""+artikel.getMengeneinheit()+"wurden entnommen");
              }
            else System.out.println("\nMaterialentnahme abgebrochen."); 
          }
          System.out.println("Lagerbestand: "+artikel.getLagerbestand());
          break;
          
      case "3":
      System.out.println("Wieviel möchten Sie nachbestellen?");  String menge = einlesen();
      artikel.setBestellmenge(Integer.parseInt(menge));
      System.out.println("Nachbestellung wird ausgelöst");
      artikel.nachbestellung();
      System.out.println("Lagerbestand: "+artikel.getLagerbestand());
      break;
      
      default: System.out.println("...");
          
      }
    } 
  }
}