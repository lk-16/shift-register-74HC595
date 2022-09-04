/* Libary: shiftregister

    Die Funktionen eines Schieberegisters sollen einfacher genutzt werden können.
    - einfaches erstellen von Schieberegistern
    - einfaches Abrufen aller Daten
    - wenig sichtbarer Programmieraufwand --> weniger Fehler

    lk-16 14.10.2020
*/
#include <shiftregister.h>                         //include into libary


shiftregister register1(1, 8, 9, 10);      //definieren an object of class shiftregister:
                                                    // register(number of Registers, SH_CP, ST_CP, DS-Pin)

void  setup()
{
  Serial.begin(9600);

}
void loop()
{
  register1.setPin(1, HIGH);                   //Methode um einen Pin an- bzw. auszuschalten
  delay(250);
  register1.printPinStatus();                  //Methode um alle Werte eines Schieberegisterverbunds anzuzeigen
  register1.setPin(1, LOW);                    //....setPin(PinNr. , neuerWert)
  delay(250);
  register1.printPinStatus();                  //Methode um alle Werte eines Schieberegisterverbunds anzuzeigen
  
  Serial.println(register1.getPinStatus(2));   //Methode um Pins auszulesen
}
