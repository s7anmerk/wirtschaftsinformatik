 import java.io.*;
 public class Materialartikel {
 
 
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
 

         private static int n=0;

         private String artikelname;
         private String artikelnummer;
         private String mengeneinheit;
         private int packungsgroesse;
         private int mindeststueckzahl;
         private int bestellmenge;
         private int lagerbestand;
         private String hersteller;
         private int entmenge;
         private int nachbestellung;

   public static int getN(){
      return n;
     }

     Materialartikel( String artikelname,
                      String artikelnummer,
                      String mengeneinheit,
                      int packungsgroesse,
                      int mindeststueckzahl,
                      int bestellmenge,
                      int lagerbestand,
                      int entmenge,
                      String hersteller){

     this.artikelnummer=artikelnummer;
     this.artikelname=artikelname;
     this.mengeneinheit=mengeneinheit;
     this.packungsgroesse=packungsgroesse;
     this.mindeststueckzahl=mindeststueckzahl;
     this.bestellmenge=bestellmenge;
     this.lagerbestand=lagerbestand;
     this.entmenge=entmenge;
     this.hersteller=hersteller;
     n=n+1;
     }
     public String getArtikelname(){
     return artikelname;
     }
     public String getArtikelnummer(){
     return artikelnummer;
     }
     public String getMengeneinheit(){
     return mengeneinheit;
     }
     public int getPackungsgroesse(){
     return packungsgroesse;
     }
     public int getMindeststueckzahl(){
     return mindeststueckzahl;
     }
     public int getBestellmenge(){
     return bestellmenge;
     }
     public int getLagerbestand(){
     return lagerbestand;
     }
     public int getEntmenge(){
     return entmenge;
     }
     public String getHersteller(){
     return hersteller;
     }

     public void entnahme(){
     
     
         if(lagerbestand < entmenge){
    // lagerbestand = lagerbestand - entmenge;      //Es wird mehr entonemmn als überhaupt im Lager zur Verfügung steht!!                                                  
     
     //bestellmenge = mindeststueckzahl - lagerbestand; 
     
     bestellmenge=entmenge - lagerbestand + mindeststueckzahl;
     
    // lagerbestand = lagerbestand + bestellmenge;   
     System.out.println("\nLagerbestand überschritten. Möchten Sie nachbestellen?(ja/nein)"); String antwort=einlesen();
     
     if(antwort.equals("ja") || antwort.equals("j") || antwort.equals("JA") || antwort.equals("Ja")){
     System.out.println("\nLagerbestand ueberschritten. Es wurden automatisch "+bestellmenge+" "+mengeneinheit+" nachbestellt");
     System.out.println("\n"+entmenge+" "+mengeneinheit+" wurden entnommen");
     }
     else System.out.println("\nMaterialentnahme abgebrochen.");
     }
     else if((lagerbestand - entmenge) >= mindeststueckzahl) {   //Mindeststückzahl unterschritten!!   //entmenge=bestellmenge   //bestellmenge = nachbestellmenge
     lagerbestand = lagerbestand-entmenge;
     System.out.println("\n"+entmenge+" "+mengeneinheit+" wurden entnommen");
     }
     else {
     System.out.println("\nMindeststückzahl unterschritten. Möchten Sie nachbestellen?(ja/nein)"); String antwort=einlesen();
     
     if(antwort.equals("ja") || antwort.equals("j") || antwort.equals("JA") || antwort.equals("Ja")){
     System.out.println("\nAutomatische Nachbestellung erfolgt, da der Mindeststückzahl unterschritten worden ist.");
     
     lagerbestand = lagerbestand - entmenge;
     bestellmenge = mindeststueckzahl - lagerbestand;
     lagerbestand = lagerbestand + bestellmenge;
    
     System.out.println("\n"+bestellmenge+" "+mengeneinheit+" wurden automatisch nachbestellt.");
     System.out.println("\n"+entmenge+" "+mengeneinheit+" wurden entnommen");      
     }
     else System.out.println("\nMaterialentnahme abgebrochen.");
     }
     }
     
    
    public void nachbestellung(){
     lagerbestand=lagerbestand+bestellmenge;
     lagerbestand=lagerbestand;     
     }


     public void setLagerbestand(int bestand){
     lagerbestand=bestand;
     }
     public void setBestellmenge(int menge){
     bestellmenge=menge;
     }
     public void setEntmenge(int e_menge){
     entmenge=e_menge;
     }

     public String toString(){
     
     return                            ("Artikelname: "+artikelname
                                      +"\nArtikelnummer: "+artikelnummer
                                      +"\nMengeneinheit: "+mengeneinheit
                                      +"\nPackungsgroesse: "+packungsgroesse
                                      +"\nMindeststueckzahl: "+mindeststueckzahl
                                      +"\nNachbestellmenge: "+bestellmenge
                                      +"\nLagerbestand: "+lagerbestand);
}

}
