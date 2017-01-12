#define CLK   A1
#define DATA  A2
#define LATCH A0 

#define NUM_OF_COLUMNS 8

#define PIXEL_TIME 20 //350
//------------------------------------------------------------------//

void setup() {
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  digitalWrite(CLK, LOW);
  digitalWrite(DATA, LOW);
  digitalWrite(LATCH, LOW);
}

void loop() {
  pictureIt();
  delay(1000);
  pictureIt2();
  delay(1000);
  
}


void loadLine(long line) {
  for (int i = 0; i < NUM_OF_COLUMNS; i++) {
    digitalWrite(DATA, !((line >> i) & 1));
    oneClk();
  }
  latchIt();
  delay(PIXEL_TIME);
}

void oneClk() {
  digitalWrite(CLK, HIGH);
  digitalWrite(CLK, LOW);
}

void latchIt() {
  digitalWrite(LATCH, HIGH);
  digitalWrite(LATCH, LOW);
}

void pictureIt() {
  /*
  loadLine(0x1);
  loadLine(0x2);
  loadLine(0x4);
  loadLine(0x8);
  loadLine(0x10);
  loadLine(0x20);
  loadLine(0x40);
  loadLine(0x80);
  loadLine(0x40);
  loadLine(0x20);
  loadLine(0x10);
  loadLine(0x8);
  loadLine(0x4);
  loadLine(0x2);
  */
  /*
  loadLine(0x81);
  loadLine(0x0);
  //loadLine(0x0);
  loadLine(0x42);
  loadLine(0x0);
  //loadLine(0x0);
  loadLine(0x24);
  loadLine(0x0);
  //loadLine(0x0);
  loadLine(0x18);
  loadLine(0x0);
  //loadLine(0x0);
  loadLine(0x24);
  loadLine(0x0);
  //loadLine(0x0);
  loadLine(0x42);
  loadLine(0x0);
  //loadLine(0x0);
  loadLine(0x81);
  */

  /*
  loadLine(0xFF);
  loadLine(0xFF);
  //loadLine(0xFF);
  loadLine(0x0);
  loadLine(0x0);
  loadLine(0x0);
  loadLine(0x0);
  loadLine(0x0);
  loadLine(0x0);
  */
  loadLine(0x1);
  loadLine(0x3);
  loadLine(0x7);
  loadLine(0xf);
  loadLine(0x1f);
  loadLine(0x3f);
  loadLine(0x7f);
  loadLine(0xff);
  loadLine(0x0);
  
}
void pictureIt2() {
  /*
  loadLine(0x1);
  loadLine(0x2);
  loadLine(0x4);
  loadLine(0x8);
  loadLine(0x10);
  loadLine(0x20);
  loadLine(0x40);
  loadLine(0x80);
  loadLine(0x40);
  loadLine(0x20);
  loadLine(0x10);
  loadLine(0x8);
  loadLine(0x4);
  loadLine(0x2);
  */
  /*
  loadLine(0x81);
  loadLine(0x0);
  //loadLine(0x0);
  loadLine(0x42);
  loadLine(0x0);
  //loadLine(0x0);
  loadLine(0x24);
  loadLine(0x0);
  //loadLine(0x0);
  loadLine(0x18);
  loadLine(0x0);
  //loadLine(0x0);
  loadLine(0x24);
  loadLine(0x0);
  //loadLine(0x0);
  loadLine(0x42);
  loadLine(0x0);
  //loadLine(0x0);
  loadLine(0x81);
  */

  /*
  loadLine(0xFF);
  loadLine(0xFF);
  //loadLine(0xFF);
  loadLine(0x0);
  loadLine(0x0);
  loadLine(0x0);
  loadLine(0x0);
  loadLine(0x0);
  loadLine(0x0);
  */
  loadLine(0x80);
  loadLine(0xc0);
  loadLine(0xe0);
  loadLine(0xf0);
  loadLine(0xf8);
  loadLine(0xfc);
  loadLine(0xfe);
  loadLine(0xff);
  loadLine(0x0);
  
}

