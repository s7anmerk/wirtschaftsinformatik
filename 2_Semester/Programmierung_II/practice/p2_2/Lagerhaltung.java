import java.io.*;

public class Lagerhaltung{
  
  public static String einlesen(){
    String str = "";
    try{
      InputStreamReader isr = new InputStreamReader(System.in);
      BufferedReader    buf = new BufferedReader(isr);
      //Hier lesen wir einen String ein
      str = buf.readLine();
      //und geben ihn gleich aus
      //System.out.println(str);
    }catch(Exception e){}
    return str;
  }
    
  public static void main (String [] args){
    /* Materialartikel artikel = new Materialartikel(args[0],
    args[1], 
    args[2],
    Integer.parseInt(args[3]),
    Integer.parseInt(args[4]),
    Integer.parseInt(args[5]),
    Integer.parseInt(args[6]),
    args[7]);  */
    System.out.println("Artikel einfügen: ");
    System.out.println("\nArtikelname: "); String name = einlesen();
    while(name.equals("")){
      System.out.println("\nBitte geben Sie den Artikelnamen ein.");
      name = einlesen();
    }
    System.out.println("\nArtikelnummer: "); String nummer = einlesen();
    while(nummer.equals("")){
      System.out.println("\nBitte geben Sie die Artikelnummer ein.");
      nummer = einlesen();
    }
    System.out.println("\nMengeneinheit: "); String einheit = einlesen();
    while(einheit.equals("")){
      System.out.println("\nBitte geben Sie die Mengeneinheit ein.");
      einheit = einlesen();
    }
    System.out.println("\nPackungsgroesse: "); String pgroesse = einlesen();
    while(pgroesse.equals("")){
      System.out.println("\nBitte geben Sie die Packungsgroesse ein.");
      pgroesse = einlesen();
    }
    System.out.println("\nMindeststueckzahl: "); String msz = einlesen();
    while(msz.equals("") || Integer.parseInt(msz)<0){
      System.out.println("\nFalsche Eingabe. Vesuchen Sie noch mal.");
      msz = einlesen();
    }
    System.out.println("\nLagerbestand: "); String lagerbestand = einlesen();
    while(lagerbestand.equals("") || Integer.parseInt(lagerbestand)<0){
      System.out.println("\nFalsche Eingabe. Vesuchen Sie noch mal.");
      lagerbestand = einlesen();
    }
    System.out.println("\nHersteller: "); String hersteller = einlesen();
    while(hersteller.equals("")){
      System.out.println("\nBitte geben Sie den Hersteller ein.");
      hersteller = einlesen();
    }
    
    Materialartikel artikel = new Materialartikel(
    name,
    nummer, 
    einheit,
    Integer.parseInt(pgroesse),
    Integer.parseInt(msz),
    0,
    Integer.parseInt(lagerbestand),
    0,
    hersteller);
    
    while(true){
      System.out.println("\n - Auswählen \n0 - Anzeigen \n1 - Lagerbestand \n2 - Materialentnahme \n3 - Nachbestellung \n4 - Verlassen");
      String str = einlesen();
      if(str.equals("4"))break;
      switch(str){
      case "0":
      System.out.println(artikel.toString());
      break;
      case "1":
      System.out.println("Lagerbestand ist: "+artikel.getLagerbestand());
      break;
      case "2":
      System.out.println("Wieviel möchten Sie aus dem Lager entnehmen?");
      String entmenge = einlesen();
      while(entmenge.equals("") || Integer.parseInt(entmenge)<0){
      System.out.println("Falsche Eingabe. Versuchen Sie noch mal.");
      entmenge = einlesen();
      }
      artikel.setEntmenge(Integer.parseInt(entmenge));
      
      if(artikel.getLagerbestand() < artikel.getEntmenge()){
      System.out.println("\nLagerbestand überschritten. Möchten Sie nachbestellen? (ja/nein)");
      String antwort = einlesen();
      if(antwort.equals("ja") || antwort.equals("j") || antwort.equals("JA") || antwort.equals("Ja")){
      int nachbestellmenge = artikel.getEntmenge() - artikel.getLagerbestand() + artikel.getMsz();
      artikel.setBestellmenge(nachbestellmenge);
      
      System.out.println("\nLagerbestand überschritten. Es wurden automatisch "+nachbestellmenge+""+artikel.getEinheit()+"nachbestellt");
      System.out.println("\n"+artikel.getEntmenge()+""+artikel.getEinheit()+" wurden entnommen.");
      }
      else System.out.println("\nMaterialentnahme abgebrochen.");
      }
      else if((artikel.getLagerbestand() - artikel.getEntmenge()) >= artikel.getMsz()){
      artikel.entnahme();
      System.out.println("\n"+artikel.getEntmenge()+""+artikel.getEinheit()+" wurden entommen");
      }
      else {
      System.out.println("\nMindeststueckzahl unterschritten. Möchten Sie nachbestellen? (ja/nein)");
      String antwort = einlesen();
      if(antwort.equals("ja") || antwort.equals("j") || antwort.equals("JA") || antwort.equals("Ja")){
      System.out.println("Automatische Nachbestellung erfolgt, da die Mindeststueckzahl unterschritten worden ist.");
      artikel.entnahme();
      int nachbestellmenge = artikel.getMsz() - artikel.getLagerbestand();
      artikel.setBestellmenge(nachbestellmenge);
      
      System.out.println("\n"+nachbestellmenge+""+artikel.getEinheit()+" wurden automatisch nachbestellt");
      System.out.println("\n"+artikel.getEntmenge()+""+artikel.getEinheit()+" wurden entommen");
      }
      else System.out.println("\nMaterialentnahme abgebrochen.");
      }
      System.out.println("Lagerbestand: "+artikel.getLagerbestand());
      break;
      
      case "3" : 
      System.out.println("Wie viel möchten Sie nachbestellen?"); String nachbestellmenge = einlesen();
      artikel.setBestellmenge(Integer.parseInt(nachbestellmenge));
      System.out.println("Nachbestellung wird ausgelöst.");
      artikel.nachbestellung();;
      System.out.println("Lagerbestand: "+artikel.getLagerbestand());
      break;
      
      default: System.out.println("...");
      }
      } 
      }
      }