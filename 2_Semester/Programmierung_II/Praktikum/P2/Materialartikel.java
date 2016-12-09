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

   public static int getN(){
      return n;
     }

     Materialartikel (String artikelname,
                      String artikelnummer,
                      String mengeneinheit,
                      int packungsgroesse,
                      int mindeststueckzahl,
                      int bestellmenge,
                      int lagerbestand,
                      String hersteller){

     this.artikelname=artikelname;
     this.artikelnummer=artikelnummer;
     this.mengeneinheit=mengeneinheit;
     this.packungsgroesse=packungsgroesse;
     this.mindeststueckzahll=mindeststueckzahl;
     this.bestellmenge=bestellmenge;
     this.lagerbestand=lagerbestand;
     this.hersteller=hersteller;
     n=n+1;
     }

     String getArtikelname(){
     return artikelname;
     }

     String getArtikelnummer(){
     return artikelnummer;
     }

     String getMengeneinheit(){
     return mengeneinheit;
     }

     int getPackungsgroesse(){
     return packungsgroesse;
     }

     int getMindeststueckzahl(){
     return mindeststueckzahl;
     }

     int getBestellmenge(){
     return bestellmenge;
     }

     int getLagerbestand(){
     return lagerbestand;
     }

     String getHersteller(){
     return hersteller;
     }
}
