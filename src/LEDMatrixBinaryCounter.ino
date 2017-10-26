//We always have to include the library
#include "LedControlMS.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn
 pin 11 is connected to the CLK
 pin 10 is connected to LOAD
 We have only a single MAX72XX.
 */
#define NBR_MTX 2
LedControl lc=LedControl(12,11,10, NBR_MTX);

#define SPEED 50

String digits= "1234567890";
int digitCounter=0;
/* we always wait a bit between updates of the display */
unsigned long delaytime=300;


void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  Serial.begin (9600);
  Serial.println("Setup");
  digitCounter=0;
  for (int i=0; i< NBR_MTX; i++){
    lc.shutdown(i,false);
  /* Set the brightness to a medium values */
    lc.setIntensity(i,8);
  /* and clear the display */
    lc.clearDisplay(i);
  }

//  Serial.println("LED0: 0 0");
//  lc.setLed(0,0,0,true);
//  delay(1000);
//  Serial.println("LED0: 0 7");
//  lc.setLed(0,0,7,true);
//  delay(1000);
//  Serial.println("LED0: 7 0");
//  lc.setLed(0,7,0,true);
//  delay(1000);
//  Serial.println("LED0: 7 7");
//  lc.setLed(0,7,7,true);
//  delay(1000);
//  Serial.println("LED0: 0 0 off");
//  lc.setLed(0,0,0,false);
//  delay(1000);
//  Serial.println("LED0: 0 7 off");
//  lc.setLed(0,0,7,false);
//  delay(1000);
//  Serial.println("LED0: 7 0 off");
//  lc.setLed(0,7,0,false);
//  delay(1000);
//  Serial.println("LED0: 7 7 off");
//  lc.setLed(0,7,7,false);
//  delay(1000);
//  //clearAll();
//
//  lc.setRow(0,1,0x0C);
//  delay(1000);
//  lc.clearDisplay(0);
//  lc.setRow(0,1,0xC0);
//  delay(1000);
//  lc.clearDisplay(0);
//
//  lc.setColumn(0,1,0x0C);
//  delay(1000);
//  lc.clearDisplay(0);
//  lc.setColumn(0,1,0xC0);
//  delay(1000);
//  lc.clearDisplay(0);
//
//  lc.writeString(0,"Hola Mundo");
//  delay(1000);
//  lc.clearAll();
//  scrollLeft('O');
//  delay(1000);
//  lc.clearAll();
//  scrollRight('O');
//  delay(1000);
//  lc.clearAll();

}


void loop() {
  int j = 0;
  int k = 0;
  int l = 0;
  int m = 0;
  int n = 0;
  int o = 0;
  int p = 0;
  for (int i=0; i<8;) {
    delay(SPEED);
    lc.setLed(0,i,0,true);
    i++;

    if (i == 8) {
      i = 0;
      clearColumn(0);
      lc.setLed(0,j,1,true);
      j++;

      if (j == 8) {
        j = 0;
        clearColumn(1);
        lc.setLed(0,k,2,true);
        k++;

        if (k == 8) {
          k = 0;
          clearColumn(2);
          lc.setLed(0,l,3,true);
          l++;

          if (l == 8) {
            l = 0;
            clearColumn(3);
            lc.setLed(0,m,4,true);
            m++;

            if (m == 8) {
              m = 0;
              clearColumn(4);
              lc.setLed(0,n,5,true);
              n++;

              if (n == 8) {
                n = 0;
                clearColumn(5);
                lc.setLed(0,o,6,true);
                o++;

                if (o == 8) {
                  o = 0;
                  clearColumn(6);
                  lc.setLed(0,p,7,true);
                  p++;

                  if (o == 8) {
                    p = 0;
                    lc.clearAll();
                  }
                }
              }
            }
          }
        }
      }

      }
  }
}

void clearColumn(int c) {
  delay(SPEED);
  lc.setLed(0,0,c,false);
  lc.setLed(0,1,c,false);
  lc.setLed(0,2,c,false);
  lc.setLed(0,3,c,false);
  lc.setLed(0,4,c,false);
  lc.setLed(0,5,c,false);
  lc.setLed(0,6,c,false);
  lc.setLed(0,7,c,false);

}
