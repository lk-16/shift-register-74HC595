# shift register
A library that allows to control Pins of a shift register easily like normal outputs on an arduino microcontroller. You can find some detailed instructions [here](https://makeandcreate.4lima.de/en/shift-register-74hc595-for-arduino/)

## hardware

The library is compatible with the Arduino framework and testet with 74HC595 shift registers.

## funktions
You can set the digital outputs of the shift register easily with the method _register1.setPin(1, HIGH);_. Moreover you are able to return the status of the shift register pins and print them via the serial connection or other display possibilities.
