#include <pt.h>

struct pt hilo1;
struct pt hilo2;

static long t = 0;
//heartbeat
int LED_HB   = 12;
uint8_t hbval = 128;
int8_t hbdelta = 8;
long wait_1 = 60;
long wait_off = 1280;

//charlieplex
int LED_1 = 10;     //LED row 1
int LED_2 = 9;     //LED row 2
int LED_3 = 8;     //LED row 3

void setup() {
  PT_INIT(&hilo1);
  PT_INIT(&hilo2);
}

void loop() {
  heartbeat(&hilo1);
  charlieplex(&hilo2);
}

void heartbeat(struct pt *pt) {
  PT_BEGIN(pt);
  // void setup() {
  pinMode(LED_HB, OUTPUT);
  // }
  
  do {
  // void loop() {
  static unsigned long last_time = 0;
  unsigned long now = millis();
  if ((now - last_time) < 40)
    return;
  last_time = now;
  if (hbval > 192) hbdelta = -hbdelta;
  if (hbval < 32) hbdelta = -hbdelta;
  hbval += hbdelta;
  analogWrite(LED_HB, hbval);
    
  // }
  } while(true);
  PT_END(pt);
}

void charlieplex(struct pt *pt) {
  PT_BEGIN(pt);
  // void setup() {
  
  // }
  
  do {
  // void loop() {
    led1();
    t = millis();
    PT_WAIT_WHILE(pt, (millis()-t)<wait_1);    
    led2();
    t = millis();
    PT_WAIT_WHILE(pt, (millis()-t)<wait_1);
    led3();
    t = millis();
    PT_WAIT_WHILE(pt, (millis()-t)<wait_1);
    led4();
    t = millis();
    PT_WAIT_WHILE(pt, (millis()-t)<wait_1);
    led5();
    t = millis();
    PT_WAIT_WHILE(pt, (millis()-t)<wait_1);
    led6();
    t = millis();
    PT_WAIT_WHILE(pt, (millis()-t)<wait_1);
    ledoff();
    t = millis();
    PT_WAIT_WHILE(pt, (millis()-t)<wait_off);
  // }
  } while(true);
  PT_END(pt);
}

void led1(){ 
  //turn on LED L1
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, HIGH);  
  pinMode(LED_3, INPUT);      //row 3
  digitalWrite(LED_3, LOW);
}

void led2(){  
  //turn on LED L2
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, LOW);   
  pinMode(LED_3, INPUT);      //row 3
  digitalWrite(LED_3, LOW);
}
 
void led3() {  
  //turn on LED L3
  pinMode(LED_1, INPUT);      //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, LOW);  
  pinMode(LED_3, OUTPUT);     //row 3
  digitalWrite(LED_3, HIGH);
}
 
void led4(){  
  //turn on LED L4
  pinMode(LED_1, INPUT);     //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);    //row 2
  digitalWrite(LED_2, HIGH);  
  pinMode(LED_3, OUTPUT);    //row 3
  digitalWrite(LED_3, LOW);
}
  
void led5(){
  //turn on LED L5
  pinMode(LED_1, OUTPUT);    //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);     //row 2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);    //row3
  digitalWrite(LED_3, HIGH);
}
 
void led6(){  
  //turn on LED L6
  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_3, LOW);
}

void ledoff(){  
  //turn off all leds
  pinMode(LED_1, INPUT);
  pinMode(LED_2, INPUT);
  pinMode(LED_3, INPUT);
  
}
