
/*
  Virtual Mouse
  Wiggles the mouse in a square to stop screen saver
 
 Hardware:
 * 1x Freetronics Leostick + bluetack
 
 */

#define WHITE 240, 240, 240
#define ORANGE 220, 40, 0
#define TURQUOISE 5, 80, 140

// set pin numbers for the five buttons:
const int r = 13;     
const int g = 9;        
const int b = 10;
const int snd = 11;

//time between mouse movements
const unsigned long delayPeriod = 50000;
unsigned long nextMoveT;

void setup() {
  nextMoveT = delayPeriod + millis();
  blip(WHITE, 100);
  
  // initialize mouse control:
  Mouse.begin();
  blip(TURQUOISE, 200);
}

void loop() {
  unsigned long temp = millis();
  if (nextMoveT < temp) {
    if (!(nextMoveT <= delayPeriod)) {
      nextMoveT = temp + delayPeriod;
      alert();
      moveMouse();
    }
  }
}

void moveMouse(){
  // move mouse left
  Mouse.move(-10, 0);
  delay(3);
  Mouse.move(-10, 0);
  delay(3);
  // move mouse down
  Mouse.move(0, 10);
  delay(3);
  Mouse.move(0, 10);
  delay(3);
  // move mouse right
  Mouse.move(10, 0);
  delay(3);
  Mouse.move(10, 0);
  delay(3);
  // move mouse up
  Mouse.move(0, -10);
  delay(3);
  Mouse.move(0, -10);
}

void alert(){
  blip(TURQUOISE, 50);
  delay(50);
  blip(TURQUOISE, 50);
  delay(50);
  blip(ORANGE, 100);
}

void blip(int red, int grn, int blu, int time){
  analogWrite(r, red);
  analogWrite(g, grn);
  analogWrite(b, blu);
  delay(time);
  analogWrite(r, 0);
  analogWrite(g, 0);
  analogWrite(b, 0);
}
