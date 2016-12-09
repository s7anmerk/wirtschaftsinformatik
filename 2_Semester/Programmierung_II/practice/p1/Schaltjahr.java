public class Schaltjahr{
  public static void main(String [] args){
    int tag = 22;
    int monat = 3;
    int jahr= 2016;
    int i;
    int anzahl_tagen = 0;
    int februar = 0;
    int rest = 0;
    for(i=1900; i<jahr; i++){
      boolean istSchaltJahr = (i%4 == 0) && (i%100 != 0 || i%400 == 0);
      if(istSchaltJahr) anzahl_tagen += 365;
      else anzahl_tagen += 365;} 
    boolean istSchaltJahr = (jahr%4 == 0) && (jahr%100 == 0);
    if(istSchaltJahr) februar = 29;
    else februar = 28;   
    switch (monat) {
      case  1: break; 
      case  2: anzahl_tagen += 31; break;
      case  3: anzahl_tagen += 31 + februar; break;
      case  4: anzahl_tagen += 31 + februar + 31; break;
      case  5: anzahl_tagen += 31 + februar + 31 + 30; break;
      case  6: anzahl_tagen += 31 + februar + 31 + 30 + 31; break;
      case  7: anzahl_tagen += 31 + februar + 31 + 30 + 31 + 30; break;
      case  8: anzahl_tagen += 31 + februar + 31 + 30 + 31 + 30 + 31; break;
      case  9: anzahl_tagen += 31 + februar + 31 + 30 + 31 + 30 + 31 + 31; break;
      case 10: anzahl_tagen += 31 + februar + 31 + 30 + 31 + 30 + 31 + 31 + 30; break;
      case 11: anzahl_tagen += 31 + februar + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31; break;
      case 12: anzahl_tagen += 31 + februar + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30; break; } 
    anzahl_tagen += tag;
    rest = anzahl_tagen%7;
    switch (rest) {
      case  0: System.out.println("\nDer gesuchte Tag ist Sonntag   "); break;
      case  1: System.out.println("\nDer gesuchte Tag ist Montag    "); break;
      case  2: System.out.println("\nDer gesuchte Tag ist Dienstag  "); break;
      case  3: System.out.println("\nDer gesuchte Tag ist Mittwoch  "); break;  
      case  4: System.out.println("\nDer gesuchte Tag ist Donnerstag"); break;
      case  5: System.out.println("\nDer gesuchte Tag ist Freitag   "); break;
      case  6: System.out.println("\nDer gesuchte Tag ist Samstag   "); break;}}}