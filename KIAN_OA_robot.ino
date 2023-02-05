const int Enable_A = 10;
const int Enable_B = 11;
const int inputA1 = 3;
const int inputA2 = 5;
const int inputB1 = 6;
const int inputB2 = 9;

int trig = 12, echo=13;


void setup() {
  Serial.begin(9600);
  pinMode(Enable_A, OUTPUT);
  pinMode(Enable_B, OUTPUT);
  pinMode(inputA1, OUTPUT);
  pinMode(inputA1, OUTPUT);
  pinMode(inputB1, OUTPUT);
  pinMode(inputB2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
}

void loop() {
   forward_OA();
}

// Sol Motor daha Zayıf ona göre daha fazla güç verıyoruz onu 
void forward_OA(){  
  int dis = distance();
  if(dis <= 10){
    analogWrite(Enable_A, 0);
    analogWrite(Enable_B, 0);
    delay(1000);
    analogWrite(Enable_A, 150);
    analogWrite(Enable_B, 100);
    
    digitalWrite(inputA1,LOW);
    digitalWrite(inputA2,HIGH);
    digitalWrite(inputA1,HIGH);
    digitalWrite(inputA2,LOW);
    delay(1000);
    }
    
  else{
  analogWrite(Enable_A, 150);
  analogWrite(Enable_B, 100);

  digitalWrite(inputA1, HIGH);
  digitalWrite(inputA2, LOW);
  digitalWrite(inputB1 , HIGH);
  digitalWrite(inputB2, LOW);
  }
}
