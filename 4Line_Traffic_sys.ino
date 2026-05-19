// -------- SHIFT REGISTER PINS --------
int dataPin = A0;
int clockPin = A1;
int latchPin = A2;

// -------- DISPLAY DIGITS --------
int digit1 = A3;
int digit2 = A4;

// -------- TRAFFIC LED PINS --------
int R[] = {2,5,8,11};
int Y[] = {3,6,9,12};
int G[] = {4,7,10,13};

// -------- NUMBERS (COMMON ANODE) --------
byte num[10] = {
  B11000000, //0
  B11111001, //1
  B10100100, //2
  B10110000, //3
  B10011001, //4
  B10010010, //5
  B10000010, //6
  B11111000, //7
  B10000000, //8
  B10010000  //9
};

// -------- SETUP --------
void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);

  for(int i=0;i<4;i++){
    pinMode(R[i], OUTPUT);
    pinMode(Y[i], OUTPUT);
    pinMode(G[i], OUTPUT);
  }
}

// -------- SEND DATA --------
void sendData(byte data){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}

// -------- DISPLAY FUNCTION --------
void displayNumber(int numVal){
  int tens = numVal / 10;
  int ones = numVal % 10;

  for(int i=0;i<80;i++){

    // Digit 1 (tens)
    digitalWrite(digit1, HIGH);  // ON (common anode)
    digitalWrite(digit2, LOW);   // OFF
    sendData(num[tens]);
    delay(2);

    // Digit 2 (ones)
    digitalWrite(digit1, LOW);   // OFF
    digitalWrite(digit2, HIGH);  // ON
    sendData(num[ones]);
    delay(2);
  }
}

// -------- COUNTDOWN --------
void countdown(int t){
  for(int i=t;i>=0;i--){
    long start = millis();
    while(millis() - start < 1000){
      displayNumber(i);
    }
  }
}

// -------- ALL RED --------
void allRed(){
  for(int i=0;i<4;i++){
    digitalWrite(R[i], HIGH);
    digitalWrite(Y[i], LOW);
    digitalWrite(G[i], LOW);
  }
}

// -------- MAIN LOOP --------
void loop() {

  // ===== PHASE 1: ROAD A & C GREEN =====
  allRed();
  digitalWrite(R[0], LOW); digitalWrite(G[0], HIGH); // A
  digitalWrite(R[2], LOW); digitalWrite(G[2], HIGH); // C
  countdown(10);

  // YELLOW
  digitalWrite(G[0], LOW); digitalWrite(Y[0], HIGH);
  digitalWrite(G[2], LOW); digitalWrite(Y[2], HIGH);
  countdown(3);

  // ===== PHASE 2: ROAD B & D GREEN =====
  allRed();
  digitalWrite(R[1], LOW); digitalWrite(G[1], HIGH); // B
  digitalWrite(R[3], LOW); digitalWrite(G[3], HIGH); // D
  countdown(10);

  // YELLOW
  digitalWrite(G[1], LOW); digitalWrite(Y[1], HIGH);
  digitalWrite(G[3], LOW); digitalWrite(Y[3], HIGH);
  countdown(3);
}