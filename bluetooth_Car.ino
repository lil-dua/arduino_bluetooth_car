const int motorA1  = 6;    // Pin  6 of L298.
const int motorA2  = 7;    // Pin  7 of L298.
const int motorB1  = 9;   // Pin 9 of L298.
const int motorB2  = 10;   // Pin 10 of L298.
const int buzzer = 12 ;   // Define o Pino 13  Buzzer.
const int BTState = 2;    // Gán chân 2 là chân nhận  Bluetooth.
int i = 0;
int j = 0;
int state_rec;
int vSpeed = 200;   // Gán tốc độ 0 < vSpeed < 255.
char state;
void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(BTState, INPUT);
  Serial.begin(9600);
}
void loop() {

  if (digitalRead(BTState) == LOW) {
    state_rec = 'S';
  }

  if (Serial.available() > 0) {
    state_rec = Serial.read();
    state = state_rec;
  }
  // Điều chỉnh tốc độ của động cơ
  if (state == '0') {
    vSpeed = 0;   // gán tốc độ của xe = 0 khi state nhận được là 0
  }
  else if (state == '4') {
    vSpeed = 100; // gán tốc độ của xe = 0 khi state nhận được là 4
  }
  else if (state == '6') {
    vSpeed = 155; // gán tốc độ của xe = 0 khi state nhận được là 6
  }
  else if (state == '7') {
    vSpeed = 180; // gán tốc độ của xe = 0 khi state nhận được là 7
  }
  else if (state == '8') {
    vSpeed = 200; // gán tốc độ của xe = 0 khi state nhận được là 8
  }
  else if (state == '9') {
    vSpeed = 230; // gán tốc độ của xe = 0 khi state nhận được là 9
  }
  else if (state == 'q') {
    vSpeed = 255; // gán tốc độ của xe = 0 khi state nhận được là q
  }
  if (state != 'S') {
    Serial.print(state);
  }
  if (state == 'F') {         //Forward : Tiến lên phía trước
    analogWrite(motorB1, vSpeed);
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);
    analogWrite(motorB2, 0);
  }
    else if (state == 'I') {   //Fordward Right:  Tiến lên bên phải
    analogWrite(motorA1, vSpeed); 
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 100);    
    analogWrite(motorB2, 0);
  }
    else if (state == 'G') {  //Forward Left:  Tiến lên bên trái
    analogWrite(motorA1, 100); 
    analogWrite(motorA2, 0);
    analogWrite(motorB1, vSpeed);      
    analogWrite(motorB2, 0);
  }
  else if (state == 'B') {    //Back: Lùi về
    analogWrite(motorA1, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed);
    analogWrite(motorA2, vSpeed);
  }
   else if (state == 'H') {  //Back Left: Lùi trái
    analogWrite(motorA1, 0);   
    analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, 0); 
    analogWrite(motorB2, 100);
  }
  
  else if (state == 'J') {  //Back Right: Lùi phải
    analogWrite(motorA1, 0);   
    analogWrite(motorA2, 100);
    analogWrite(motorB1, 0);   
    analogWrite(motorB2, vSpeed);
  }
  else if (state == 'L') {   //Left: Rẽ trái
    analogWrite(motorA1, 0);
    analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, vSpeed);
    analogWrite(motorB2, 0);
  }
  else if (state == 'R') {  //Right: Rẽ phải
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed);
  }
  else if (state == 'S') {  //Stop: Dừng
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 0);
  }

  else if (state == 'V') { 
    if (j == 0) {
      tone(buzzer, 1000);
      j = 1;
    }
    else if (j == 1) {
      noTone(buzzer);
      j = 0;
    }
    state = 'n';
  }
}
