import java.io.*;

public class Lagerhaltung {

 public static String einlesen(){
   String str="";
   try {
   InputStreamReader isr = new InputStreamReader(System.in);
   BufferedReader bur    = new BufferedReader(isr);

  //Hier lesen wir einen String ein:
   str = bur.readLine();

  //und geben ihn gleich wieder aus
  //System.out.println(str);  
   }
   catch( Exception e ) { }
  return str;
 }

    public static void main(String [] args){

    System.out.println("Artikel einfügen:");
    System.out.println("\nArtikelname: "); String artikelname=einlesen();
    System.out.println("\nArtikelnummer: "); String artikelnummer=einlesen();
    System.out.println("\nMengeneinheit: "); String mengeneinheit=einlesen();
    System.out.println("\nPackungsgroesse: "); String packungsgroesse=einlesen();
    System.out.println("\nMindeststueckzahl: "); String mindeststueckzahl=einlesen();
    System.out.println("\nLagerbestand: "); String lagerbestand=einlesen();
    System.out.println("\nHersteller: "); String hersteller=einlesen();
    Materialartikel artikel1 = new Materialartikel(
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
    System.out.println("\n  - Auswählen \n0 - Anzeigen \n1 - Lagerbestand  \n2 - Materialentnahme \n3 - Nachbestellung \n4 - Verlassen");
    String str = einlesen();
    if(str.equals("4")) break;
    switch(str){
    
    case "0":
    
    System.out.println(artikel1.toString());
   /* System.out.println("Artikelname: "+artikel1.getArtikelname().toString()
                                      +"\nArtikelnummer: "+artikel1.getArtikelnummer().toString()
                                      +"\nMengeneinheit: "+artikel1.getMengeneinheit()
                                      +"\nPackungsgroesse: "+artikel1.getPackungsgroesse()
                                      +"\nMindeststueckzahl: "+artikel1.getMindeststueckzahl()
                                      +"\nNachbestellmenge: "+artikel1.getBestellmenge()
                                      +"\nLagerbestand: "+artikel1.getLagerbestand());
     */                                 
                                      
    break;

    case "1":
    System.out.println("Lagerbestand ist: "+artikel1.getLagerbestand());
    break;

    case "2":
    System.out.println("Wie viel möchten Sie aus dem Lager entnehmen? "); String e_menge=einlesen();
    artikel1.setEntmenge(Integer.parseInt(e_menge));
    artikel1.entnahme();
    System.out.println("Lagerbestand: "+artikel1.getLagerbestand());
    break;

    case "3":
    System.out.println("Wie viel möchten Sie nachbestellen?"); String menge=einlesen();
    artikel1.setBestellmenge(Integer.parseInt(menge));
    System.out.println("Nachbestellung wird ausgelöst.");
    artikel1.nachbestellung();
    System.out.println("Lagerbestand: "+artikel1.getLagerbestand());
    break;

    
    default: System.out.println("...");

    }
    }
    }
    }
