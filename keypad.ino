/* Based on:
|| @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com

Keypad Pinout:

   Rows and columns are connected as such on the keypad:
   -------------
   | 1 | 2 | 3 | - 0
   | 4 | 5 | 6 | - 1
   | 7 | 8 | 9 | - 2
   -------------
     |   |   |
     8   7   6
 
   This is how they're connected to the ProMicro:
   Keypad Pin ------ Pro Micro Pin
      0 ------------------ 2
      1 ------------------ 3
      2 ------------------ 4
      6 ------------------ 7
      7 ------------------ 8
      8 ------------------ 9
*/
#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 3; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};
byte rowPins[ROWS] = {2, 3, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Keyboard.begin();
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Keyboard.press(customKey);
    delay(100);
    Keyboard.release(customKey);
  }
}
