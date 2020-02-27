int ledPin = 8;
int triggerPin = 7;
int echoPin = 2;

int blinkDelay = 500;
long duration;
int distance;

void setup() 
{  
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
  
  if (blinkDelay > 500)
  {
    blinkDelay = 500;
  }
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
  ping();  
  if(distance < 50)
  {
    blink();   
  }
  else 
  {
    digitalWrite(ledPin, HIGH);
  }
}
