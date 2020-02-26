
int ledPin = 8;
int triggerPin = 7;
int echoPin = 2;

int blinkDelay = 500;
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void blink()
{
  digitalWrite(ledPin, HIGH);
  delay(blinkDelay);
  digitalWrite(ledPin, LOW);
  delay(blinkDelay);
  blinkDelay = distance * 10; 
}

void ping()
{
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);    
  distance = duration*0.034/2;
}

void loop() 
{
  Serial.print("Distance in cm: ");
  Serial.println(distance);
  ping();  
  blink();
   
}


