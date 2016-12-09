import java.io.*;

public class Materialartikel{
  
  private String name;
  private String nummer;
  private String einheit;
  private int pgroesse;
  private int msz;  //Mindeststueckzahl
  private int bestellmenge;
  private int lagerbestand;
  private String hersteller;
  private int entmenge;
  
  Materialartikel(String name,
                  String nummer,
                  String einheit,
                  int pgroesse,
                  int msz,
                  int bestellmenge,
                  int lagerbestand,
                  int entmenge,
                  String hersteller){
                    this.name = name;
                    this.nummer = nummer;
                    this.einheit=einheit;
                    this.pgroesse=pgroesse;
                    this.msz=msz;
                    this.bestellmenge=bestellmenge;
                    this.lagerbestand = lagerbestand;
                    this.entmenge=entmenge;
                    this.hersteller=hersteller;
                    }
  public String getName(){
    return name;
    }
  public String getNummer(){
    return nummer;
    }
  public String getEinheit(){
    return einheit;
    }
  public int getPgroesse(){
    return pgroesse;
    }
  public int getMsz(){
    return msz;
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
    lagerbestand=lagerbestand - entmenge;
    }
  public void nachbestellung(){
    lagerbestand = lagerbestand + bestellmenge;
    lagerbestand = lagerbestand;
    }
  
  public void setLagerbestand(int lagerbestand){
    lagerbestand = lagerbestand;
    }
  public void setBestellmenge(int bestellmenge){
    bestellmenge = bestellmenge;
    }
  public void setEntmenge(int entmenge){
    entmenge = entmenge;
    }
  public void setName(String name){
    this.name = name;
    }
  public void setNummer(String nummer){
    this.nummer = nummer;
    }
  public void setEinheit(String einheit){
    this.einheit = einheit;
    }
  public void setPgroesse(int pgroesse){
    pgroesse=pgroesse;
    }
  public void setMsz(int msz){
    msz=msz;
    }
    
  public String toString(){
    
    return    ("Artikelname: "+name
              +"\nArtikelnummer: "+nummer
              +"\nMengeneinheit: "+einheit
              +"\nPackungsgroesse: "+pgroesse
              +"\nMindeststueckzahl: "+msz
              +"\nNachbestellmenge: "+bestellmenge
              +"\nLagerbestand: "+lagerbestand);
    }
  }
  