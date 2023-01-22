#include <QTRSensors.h>

QTRSensors qtr;
const uint8_t SensorCount = 6;
uint16_t sensorValues[SensorCount];

#define M1_defult_speed 50
#define M2_defult_speed 50
#define M1_max_speed 70
#define M2_max_speed 70


const int Enable_A = 10;
const int Enable_B = 11;
const int inputA1 = 3;
const int inputA2 = 5;
const int inputB1 = 6;
const int inputB2 = 9;

int back_led = 13;
int buzzer = 7;

void setup() {
  pinMode(Enable_A, OUTPUT);
  pinMode(Enable_B, OUTPUT);
  pinMode(inputA1, OUTPUT);
  pinMode(inputA2, OUTPUT);
  pinMode(inputB1, OUTPUT);
  pinMode(inputB2, OUTPUT);
  
  pinMode(back_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  
  //--------------QTR SETUP-------------------
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5}, SensorCount);
  qtr.setEmitterPin(2);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode

  //------kalibrate ayarlamalar------
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW); // turn off Arduino's LED to indicate we are through with calibration

  // print the calibration minimum values measured when emitters were on
  Serial.begin(9600);
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();

  // print the calibration maximum values measured when emitters were on
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  delay(1000);
  

}

int lastError = 0;
int  last_proportional = 0;
int integral = 0;

#define KP 0.1
#define KD 0.7



void loop() {
 forward();
 backward();
 right_ward();
 left_ward();
 

}
void forward(){
  /*unsigned int sensors[5];
  int position = qtr.read(sensors);
  int error = position - 2000;

  int motorSpeed = KP * error + KD * (error - lastError);
  lastError = error;*/
  
  analogWrite(Enable_A, 150);
  analogWrite(Enable_B, 150);
  
  digitalWrite(inputA1, HIGH);
  digitalWrite(inputA2, LOW);
  
  digitalWrite(inputB1 , HIGH);
  digitalWrite(inputB2, LOW);
  delay(2000);
  
  analogWrite(Enable_A, 0);
  analogWrite(Enable_B, 0);
  delay(1000);
  }

void backward(){
  
 analogWrite(Enable_A, 100);
  analogWrite(Enable_B, 100);
  
  digitalWrite(inputA1, LOW);
  digitalWrite(inputA2, HIGH);
  
  digitalWrite(inputB1 , LOW);
  digitalWrite(inputB2, HIGH);
  delay(2000);
  analogWrite(Enable_A, 0);
  analogWrite(Enable_B, 0);
  delay(1000);
  }
void right_ward(){
  analogWrite(Enable_A, 150);
  analogWrite(Enable_B, 150);

  digitalWrite(inputA1, LOW);
  digitalWrite(inputA2, HIGH);
  
  digitalWrite(inputB1 , HIGH);
  digitalWrite(inputB2, LOW);
  delay(2000);
  analogWrite(Enable_A, 0);
  analogWrite(Enable_B, 0);
  delay(1000);
  }
void left_ward(){
  analogWrite(Enable_A, 150);
  analogWrite(Enable_B, 150);

  digitalWrite(inputA1, HIGH);
  digitalWrite(inputA2, LOW);
  
  digitalWrite(inputB1 , LOW);
  digitalWrite(inputB2, HIGH);
  delay(2000);
  analogWrite(Enable_A, 0);
  analogWrite(Enable_B, 0);
  delay(1000);
  }
