int a;
boolean fire = false;


#define Right A4    // right sensor
#define Left A5   //front sensor

#define LM1 10      // left motor
#define LM2 11       // left motor
#define RM1 12       // right motor
#define RM2 13       // right motor
#define pump 8
#define leftPWM 5
#define rightPWM 6

void setup()
{
  Serial.begin(9600);
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(leftPWM, OUTPUT);
  pinMode(rightPWM, OUTPUT);
  analogWrite(leftPWM, 180);
  analogWrite(rightPWM, 180);

}


void loop()
{

  if (Serial.available() > 0) {
    a = Serial.read();
    Serial.println(a);


    if (a == 50) { //forward
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
    }
    else if (a == 51) { //left
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, LOW);
    }
    else if (a == 49) { //right
      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, HIGH);
    }
    else if (a == 52) { //back
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, HIGH);
    }
    else if (a == 53) { //stop
      digitalWrite(LM1, LOW);
      digitalWrite(LM2, LOW);
      digitalWrite(RM1, LOW);
      digitalWrite(RM2, LOW);
    }
    else if (a == 54) { //PUMP start
      digitalWrite(pump, HIGH);
    }
    else if (a == 55) { //PUMP STOP
      digitalWrite(pump, LOW);
    }






    else if (digitalRead(Left) == 1 || digitalRead(Right) == 1)
    {

      digitalWrite(LM1, HIGH);
      digitalWrite(LM2, HIGH);
      digitalWrite(RM1, HIGH);
      digitalWrite(RM2, HIGH);
      fire = true;
    }

    while (fire == true)
    {
      put_off_fire();
    }
  }
}



void put_off_fire()
{
  delay (50);

  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);

  digitalWrite(pump, HIGH);
  delay(500);

  digitalWrite(pump, LOW);

  fire = false;
}
