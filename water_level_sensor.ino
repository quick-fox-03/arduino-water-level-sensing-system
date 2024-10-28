#define sensorPower 7
#define sensorPin A0
int read_value = 0;
int greenPin=2;
int yellowPin=4;

int lowerThreshold=400;
int upperThreshold=510;
void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPower, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  digitalWrite(sensorPower, LOW);
  Serial.begin(9600);
  digitalWrite(greenPin,LOW);
  digitalWrite(yellowPin,LOW);
}

void loop() {
  //put your main code here, to run repeatedly:
  int level = readSensor();
  if(level==0){
    Serial.println("Water Level: Empty");
		digitalWrite(yellowPin, LOW);
		digitalWrite(greenPin, LOW);
  }else if (level > 0 && level <= lowerThreshold) {
		Serial.println("Water Level: Low");
		
		digitalWrite(yellowPin, LOW);
		digitalWrite(greenPin, HIGH);
	}
	else if (level > lowerThreshold && level <= upperThreshold) {
		Serial.println("Water Level: Medium");
		
		
    digitalWrite(yellowPin, HIGH);
		digitalWrite(greenPin, LOW);
	}
	else if (level > upperThreshold) {
		Serial.println("Water Level: High");
		
	
    digitalWrite(yellowPin, HIGH);
		digitalWrite(greenPin, HIGH);
	}
  // digitalWrite(greenPin,HIGH);
  // digitalWrite(yellowPin,HIGH);
	// delay(1000);
  // digitalWrite(greenPin,LOW);
  // digitalWrite(yellowPin,LOW);
  delay(1000);
}
int readSensor(){
  digitalWrite(sensorPower, HIGH);
  delay(10);
  read_value=analogRead(sensorPin);
  digitalWrite(sensorPower, LOW);
  return read_value;
}
