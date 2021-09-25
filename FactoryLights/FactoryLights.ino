// Project LED Factory Lights Simulator Effect for my storage cupboard
//
// Connections:
// LED Strips (all PWM pins, UNO has 3, 5, 6, 9, 10, 11 available):
// 
//   D3 <--> GND (eventually more; one per cupboard shelf)
// 
// 
// Power (5v):
// 
//   +5v --> microswitch  -->  VIN --> GND
// 

int ledPin1 = 3;
int maxBrightnessLevel = 10;
int currentBrightness = 0;

int stutterSeed = 5;
int stutterLength = 5;

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(ledPin1, OUTPUT);
  
}

void loop()
{
//  Serial.println(maxBrightnessLevel);
//  delay(random(100));

  analogWrite(ledPin1, 0);
  delay(random(1000));

  while (stutterLength < 1000) {
    stutterLength = (stutterLength + (random(stutterSeed)));
    stutterSeed = (stutterSeed*1.2);
    Serial.print(" [ Length = ");
    Serial.print(stutterLength);
    Serial.print(" Seed = ");
    Serial.print(stutterSeed);
    Serial.print(" ]   ");
    
    analogWrite(ledPin1, random(20)*maxBrightnessLevel);
    delay(random(10)+stutterLength);  
  }
  
  Serial.println(" Flash ");
  stutterLength = 5;
  stutterSeed = 5;
  analogWrite(ledPin1, 255);
  delay(3000);
  while (1==1) {           // basically keep the lights on until reset or off
                           // perhaps an occasional flicker would be nice here
  }
  
}
