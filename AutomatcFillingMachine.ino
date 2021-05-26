int in1 = 8;
int in2 = 9;
int LED = 5;
int in3 = 7;
int in4 = 6;
//%-------------------------------------------------------------
int analogInPin = A0;
int sensorValue = 0;
//%-------------------------------------------------------------
#define trigPin 13
#define echoPin 12
//%-------------------------------------------------------------
int moistureAnalogValue = 0;
int moistureDigitalValue = 0;
int analogPin = A1;
int digitalPin = 2;
//%-------------------------------------------------------------
int p1 = 0;



void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
  pinMode(LED, OUTPUT);
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT);
//%-------------------------------------------------------------
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
//%-------------------------------------------------------------
  pinMode(analogPin,INPUT);
  pinMode(digitalPin,INPUT);
}


void TurnMotorA_ROn (){ 
  digitalWrite(in2, HIGH); 
  digitalWrite(in1, LOW); 
} 
//%-------------------------------------------------------------
void TurnMotorA_On (){ 
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW); 
  
} 
//%-------------------------------------------------------------
void TurnMotorA_OFF(){ 
  digitalWrite(in1, LOW); 
  digitalWrite(in2, LOW); 
} 
//%-------------------------------------------------------------
void TurnMotorB_On (){ 
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW);
} 
//%-------------------------------------------------------------
void TurnMotorB_OFF(){ 
  digitalWrite(in3, LOW); 
  digitalWrite(in4, LOW);
}




void loop() {
  sensorValue = analogRead(analogInPin);
//%-------------------------------------------------------------
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; 
//%-------------------------------------------------------------
  moistureAnalogValue = analogRead(analogPin);
  moistureDigitalValue = digitalRead(digitalPin);
//%-------------------------------------------------------------
  Serial.print("  Leser sensor = ");
  Serial.print(sensorValue);
  Serial.println("");
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print("  Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
  }  
  Serial.print("Analog Waster value : ");  
  Serial.print(moistureAnalogValue);
  Serial.print("\t");
  Serial.print("Digital Water value : ");
  Serial.print(moistureDigitalValue);
  Serial.println("");
  if (moistureDigitalValue==0){
        Serial.println("  Error, check the tank  ");
       }
//%-------------------------------------------------------------  
    if (distance <=4) {
      delay(500);
      Serial.print("  Leser sensor = ");
      Serial.print(sensorValue);
      Serial.println("");
      if (distance >= 200 || distance <= 0){
      Serial.println("Out of range");
      }
      else {
      Serial.print("  Distance = ");
      Serial.print(distance);
      Serial.println(" cm");
      }  
      Serial.print("Analog Waster value : ");  
      Serial.print(moistureAnalogValue);
      Serial.print("\t");
      Serial.print("Digital Water value : ");
      Serial.print(moistureDigitalValue);
      Serial.println("");
      if (moistureDigitalValue==0){
        Serial.println("  Error, check the tank  ");
      }
      if (p1==0){
      delay(6000);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
      if (distance <=4) { 
      TurnMotorA_On();
      p1 = 1;
      }
      }
    }
        if (p1==1){
      digitalWrite(LED, HIGH);
    }
    else{
      digitalWrite(LED, LOW);
    }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
    
    if (distance >= 13 && distance <= 23) {
      delay(500);
      Serial.print("  Leser sensor = ");
      Serial.print(sensorValue);
      Serial.println("");
      if (distance >= 200 || distance <= 0){
      Serial.println("Out of range");
      }
      else {
      Serial.print("  Distance = ");
      Serial.print(distance);
      Serial.println(" cm");
      }  
      Serial.print("Analog Waster value : ");  
      Serial.print(moistureAnalogValue);
      Serial.print("\t");
      Serial.print("Digital Water value : ");
      Serial.print(moistureDigitalValue);
      Serial.println("");
    
      TurnMotorA_OFF();

      if (p1==1){
      delay(3000);
       if (moistureDigitalValue==1) {
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
        delay(500);
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
        delay(500);
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
        delay(500);
        TurnMotorB_On();
        delay(3000); 
        TurnMotorB_OFF();
        delay(2000);        
       }
       else if (moistureDigitalValue==0){
        Serial.println("  Error, check the tank  ");
       }
       p1=0;
        TurnMotorA_ROn();
        delay(1250);
        TurnMotorA_OFF();
      }
    } 
  }
