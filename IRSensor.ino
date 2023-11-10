const int OUT = 2; 
const int ledPin = 13;

int Number_of_Object = 0;
int SensorState = 0;
void setup()
{
 Serial.begin(9600); 
 pinMode(ledPin, OUTPUT); 
 pinMode(OUT, INPUT); 
}
void loop()
{
 SensorState = digitalRead(OUT);
 if (SensorState == HIGH)
 {
 digitalWrite(ledPin, HIGH);
 Number_of_Object++;
 Serial.println(Number_of_Object);
 }
 else
 {
 digitalWrite(ledPin, LOW);
 }
}

