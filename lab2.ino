// Definition of the pins to be used.
const int rightButton = 2;
const int leftButton = 3;
const int pinA = 4;
const int pinB = 5;
const int pinC = 6;
const int pinD = 7;
const int pinE = 8;
const int pinF = 9;
const int pinG = 10;
const int pinDigit1 = 11;

void setup() {
  // Setting the pins of the display in output mode.
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDigit1, OUTPUT);
  Serial.begin(9600);
}

void showNumber(int num) {
  // Table to show the numbers in the 7 segments display.
  // Each element of the array corresponds to pins A, B, C, D, E, F, and G, respectively.
  int tabla[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
  };

  if (num >= 0 && num <= 9) {
    digitalWrite(pinA, tabla[num][0]);
    digitalWrite(pinB, tabla[num][1]);
    digitalWrite(pinC, tabla[num][2]);
    digitalWrite(pinD, tabla[num][3]);
    digitalWrite(pinE, tabla[num][4]);
    digitalWrite(pinF, tabla[num][5]);
    digitalWrite(pinG, tabla[num][6]);
  }
}

void loop() {
  // Check the left button status.
  if (digitalRead(leftButton) == HIGH) {
    for (int i = 0; i < 10; i++) {
      showNumber(i);
      delay(500); //delay to avoid wrong readings.
    }
  }
  
  // Check the right button status.
  if (digitalRead(rightButton) == HIGH) {
    for (int i = 9; i >= 0; i--) {
      showNumber(i);
      delay(500); //delay to avoid wrong readings.
    }
  }
  
  // Check if a number has been received from the serial monitor.
  if (Serial.available() > 0) {
    int number = Serial.parseInt();
    // Verify that the number is a single digit.
    if (number >= 0 && number <= 9) {
      showNumber(number);
    }
  }
}
