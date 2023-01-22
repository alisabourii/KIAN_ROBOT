const int Enable_A = 10;
const int Enable_B = 11;
const int inputA1 = 3;
const int inputA2 = 5;
const int inputB1 = 6;
const int inputB2 = 9;

void setup() {
  pinMode(Enable_A, OUTPUT);
  pinMode(Enable_B, OUTPUT);
  pinMode(inputA1, OUTPUT);
  pinMode(inputA2, OUTPUT);
  pinMode(inputB1, OUTPUT);
  pinMode(inputB2, OUTPUT);

}

void loop() {
  move_digital();

}


void move_digital()
{
  digitalWrite(Enable_A, HIGH);
  digitalWrite(Enable_B, HIGH);
  digitalWrite(inputA1, HIGH);
  digitalWrite(inputA2, LOW);
  
  digitalWrite(inputB1 , HIGH);
  digitalWrite(inputB2, LOW);
  delay(2000);
  digitalWrite(Enable_A, LOW);
  digitalWrite(Enable_B, LOW);
  delay(1000);
  digitalWrite(Enable_A, HIGH);
  digitalWrite(Enable_B, HIGH);
  
  digitalWrite(inputA1, LOW);
  digitalWrite(inputA2, HIGH);
  
  digitalWrite(inputB1 , LOW);
  digitalWrite(inputB2, HIGH);
  delay(2000);
  digitalWrite(Enable_A, LOW);
  digitalWrite(Enable_B, LOW);
  delay(1000);
  }




  
