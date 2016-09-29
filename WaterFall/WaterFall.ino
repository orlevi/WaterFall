#define CLK   A1
#define DATA  A2
#define LATCH A0 

#define NUM_OF_COLUMNS 8

#define PIXEL_TIME 350
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
}


void loadLine(long line) {
  for (int i = 0; i < NUM_OF_COLUMNS; i++) {
    digitalWrite(DATA, (line >> i) & 1);
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
  loadLine(0xFF);
  loadLine(0x0);
}

