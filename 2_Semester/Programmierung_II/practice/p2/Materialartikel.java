//Materialartikel

import java.io.*;
public class Materialartikel{
  
  private String artikelname;
  private String artikelnummer;
  private String mengeneinheit;
  private int    packungsgroesse;
  private int    mindeststueckzahl;
  private int    bestellmenge;
  private int    lagerbestand;
  private String hersteller;
  private int    entmenge;
  
  Materialartikel (String artikelname,        //Konstruktor
  String artikelnummer,
  String mengeneinheit,
  int    packungsgroesse,
  int    mindeststueckzahl,
  int    bestellmenge,
  int    lagerbestand,
  int    entmenge,
  String hersteller){
    
    this.artikelname        =        artikelname;
    this.artikelnummer      =      artikelnummer;
    this.mengeneinheit      =      mengeneinheit;
    this.packungsgroesse    =    packungsgroesse;
    this.mindeststueckzahl  =  mindeststueckzahl;
    this.bestellmenge       =       bestellmenge;
    this.lagerbestand       =       lagerbestand;
    this.entmenge           =           entmenge;
    this.hersteller         =         hersteller;
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
    lagerbestand = lagerbestand - entmenge;
  }
  public void nachbestellung(){
    lagerbestand = lagerbestand + bestellmenge;
    lagerbestand = lagerbestand;
  }
     
  public void setLagerbestand(int bestand){
    lagerbestand = bestand;
  }
  public void setBestellmenge(int nachbestellmenge){
    bestellmenge = nachbestellmenge;
  }
  public void setEntmenge(int e_menge){
    entmenge = e_menge;
  }    
  public void setArtikelname(String aname){
    artikelname = aname;
  }     
  public void setArtikelnummer(String anr){
    artikelnummer = anr;
  }
  public void setMengeneinheit(String einheit){
    mengeneinheit = einheit;
    }
  public void setPackungsgroesse(int pckgroesse){
    packungsgroesse = pckgroesse;
    } 
  public void SetMindeststueckzahl(int zahl){
    mindeststueckzahl = zahl;
    }
    
  public String toString(){
                  
    return                ("  Artikelname: "       +artikelname
                          +"\nArtikelnummer: "     +artikelnummer
                          +"\nMengeneinheit: "     +mengeneinheit
                          +"\nPackungsgroesse: "   +packungsgroesse
                          +"\nMindeststueckzahl: " +mindeststueckzahl 
                          +"\nNachbestellmenge: "  +bestellmenge
                          +"\nLagerbestand: "      +lagerbestand);
    
    }
    
  }