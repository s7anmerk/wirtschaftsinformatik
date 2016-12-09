public class Lagerhaltung{

    public static void main(String [] args){

    Materialartikel aartikel1 = new Materialartikel(  args[0],
                                               args[1],
                                               args[2],
                                               Integer.parseInt(args[3]),
                                               Integer.parseInt(args[4]),
                                               Integer.parseInt(args[5]),
                                               Integer.parseInt(args[6]),
                                               args[7]);


    System.out.println("Artikelname: "+artikel1.getArtikelname());                            $
    System.out.println("\nArtielnummer: "+artikel1.getArtikelnummer());
    System.out.println("\nMengeneinheit: "+artiekel1.getMengeneinheit());
    System.out.println("\nPackungsgroesse: "+artikel1.getPackungsgroesse());
    System.out.println("\nMindeststueckzahl: "+aartikel1.getMindeststueckzahl());
    System.out.println("\nBestellmenge: "+artikel1.getBestellmenge());
    System.out.println("\nLagerbestand: "+artikel1.getLagerbestand());

    System.out.println(Materialartikel.getN());

    }
 }
