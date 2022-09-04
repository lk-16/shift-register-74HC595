/*  
 *  @name shiftregister
 *  @author lk-16 
 *  @date 14.10.2020
 *  Die Funktionen sollen einfacher abgebildet und genutzt werden können.
 * 
*/


#include "Arduino.h"
#include "shiftregister.h"


shiftregister::shiftregister(int numberOfRegisters, int sh, int st, int ds)
{
  Serial.begin(9600);
  _numberOfPins = numberOfRegisters * 8;
  _sh = sh;                                       //Übergabepins für das Register werden festgelegt
  _st = st;
  _ds = ds;
  pinMode(_sh, OUTPUT);                           // Pins für shiftregister als Ausgang definieren
  pinMode(_st, OUTPUT);
  pinMode(_ds, OUTPUT);

  digitalWrite(_sh, LOW);
  digitalWrite(_st, LOW);
  digitalWrite(_ds, LOW);


  //definieren der Größe des dynamischen Arrays
  _data = (boolean*)calloc(_numberOfPins, (sizeof(boolean)));
  if (_data == NULL)                                         //wenn kein speicer mehr frei ist, soll eine Fehlermeldung ausgegeben werden
  {
    Serial.println("Error: Data of the shift register cannot be saved Source: shiftregister.h shiftregister::shiftregister()");
    return;
  }
}


void shiftregister::setPin(int pinNo, boolean pinStatus)
{
  digitalWrite(_st, LOW);
  _data[pinNo - 1] = pinStatus;

  for (int index = _numberOfPins - 1; index >= 0; index --)    // Die Reihenfolge der leuchtenden LEDs
  { // durch die for- Schleife einfügen

    digitalWrite(_ds, 0);                        // DS Pin SH_CP Pin auf "0" (LOW) stellen
    digitalWrite(_sh, 0);                        //
    digitalWrite(_ds, _data[index]);             // In DS Pin schreiben, ob LED an oder aus (0 für LOW, also aus, und 1 für HIGH, also an)
    digitalWrite(_sh, 1);                        // SH_CP Pin auf 1 setzen (HIGH) damit die Information am DS Pin gespeichert wird
  }
      digitalWrite(_st, HIGH);                           // Wenn for- Schleife beendet wurde, ST_CP Pin auf 1 (HIGH) setzen damit die Datenübertragen werden
}

void shiftregister::printPinStatus()
{
  int read = 0;
  for (int a = 1; a <= _numberOfPins / 8; a++)
  {
    for (int j = 1; j <= 8; j ++)
    {
      Serial.print(_data[read]);
      read++;
    }
    Serial.println();

  }
}

boolean shiftregister::getPinStatus(int pinNo)
{
  return _data[pinNo];
}
