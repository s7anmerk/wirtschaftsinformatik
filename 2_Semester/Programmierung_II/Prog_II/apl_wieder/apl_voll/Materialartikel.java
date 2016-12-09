 import java.io.*;
 public class Materialartikel {
 
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
     lagerbestand=lagerbestand-entmenge;
     }
     
    
     public void nachbestellung(){
     lagerbestand=lagerbestand+bestellmenge;
     lagerbestand=lagerbestand;     
     }


     public void setLagerbestand(int bestand){
     lagerbestand=bestand;
     }
     public void setBestellmenge(int nachbestellmenge){
     bestellmenge=nachbestellmenge;
     }
     public void setEntmenge(int e_menge){
     entmenge=e_menge;
     }
     public void setArtikelnummer(String anr){
     this.artikelnummer=anr;
     }
     public void setArtikelname(String aname){
     this.artikelname=aname;
     }
     public void setMengeneinheit(String einheit){
     this.mengeneinheit=einheit;
     }
     public void setPackungsgroesse(int pckgroesse){
     packungsgroesse=pckgroesse;
     }
     public void setMindeststueckzahl(int zahl){
     mindeststueckzahl=zahl;
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
