/ Rotary Encoder Inputs
#define CLK 2
#define DT 3

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";

void setup() {

  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);

  Serial.begin(9600);

  
  lastStateCLK = digitalRead(CLK);
  
  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);
}

void loop() {
}

void updateEncoder(){
  
  currentStateCLK = digitalRead(CLK);

  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

    if (digitalRead(DT) != currentStateCLK) {
      counter --;
      currentDir ="CCW";
    } else {
      counter ++;
      currentDir ="CW";
    }

    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print(" | Counter: ");
    Serial.println(counter);
  }

  
  lastStateCLK = currentStateCLK;
}

