#include <QTRSensors.h>

QTRSensors qtr;
const uint8_t SensorCount = 6;
uint16_t sensorValues[SensorCount];


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

void loop() {
 ileri();
 geri();

}
void ileri(){
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

void geri(){
  digitalWrite(back_led,1);
  tone(buzzer, 250);
  analogWrite(Enable_A, 150);
  analogWrite(Enable_B, 150);
  
  digitalWrite(inputA1, LOW);
  digitalWrite(inputA2, HIGH);
  
  digitalWrite(inputB1 , LOW);
  digitalWrite(inputB2, HIGH);
  delay(2000);
  
  analogWrite(Enable_A, 0);
  analogWrite(Enable_B, 0);
  delay(1000);
  digitalWrite(back_led,0);
  noTone(buzzer);
  }