#include "StringInstrument.h"


/*
 * TODO - add explenation + HANDSON TIPS
 */
int main() {
  //create a StringInstrument object and pass a name as parameter.
  StringInstrument myStringInstrument("My Precious");

  std::cout << std::endl;
  myStringInstrument.makeSound();

  Instrument *instrument = (Instrument*) &myStringInstrument;
  instrument->makeSound();
  //exit the programm -> deconstructor Instrument objects will be called
  return 0;
}
