/*  
 *  @name shiftregister
 *  @author lk-16 
 *  @date 14.10.2020
 *  This libary allows to control a shift register easily.
 * 
*/



#ifndef shiftregister_h
#define shiftregister_h
#include "Arduino.h"

class shiftregister
{
  public:

    shiftregister(int numberOfRegisters, int sh, int st, int ds);
    void setPin(int pinNo, boolean pinStatus);              /*<Pins can be controlled individually*/
    void printPinStatus();                                  /*<Status of the entire pins is printed via the serial monitor*/
    boolean getPinStatus(int pinNo);                        /*<Returns the status of one pin*/

  private:
    int _sh;
    int _st;
    int _ds;
    int _numberOfPins;                                        //number of Pins in the register
    boolean *_data;                                        //flexible array for passing the data to the register


};

#endif
