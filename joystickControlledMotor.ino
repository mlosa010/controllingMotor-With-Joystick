int const rightMotor = 5;
int const rightDirection = 4;
int leftDirection =2;
int leftMotor =3;
int sleepPinL=8;
int const sleepPinR = 7;
int const potPinOne = A0;
int potPinTwo=A1;
int potValTwo;
int potValOne;
int motorSpeedL;
int motorSpeedR;
//int forwardSpeed;
//int backwardSpeed;
void controlMotor(int motorSpeed, int directionPin, int pwmPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(rightDirection, OUTPUT);
  pinMode(sleepPinL, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  pinMode(leftDirection, OUTPUT);
  pinMode(sleepPinR, OUTPUT);
  pinMode(rightMotor, OUTPUT);


  digitalWrite(sleepPinR, HIGH);
  digitalWrite(sleepPinL, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValOne = analogRead(potPinOne);
  potValTwo = analogRead(potPinTwo);

  motorSpeedR = map(potValOne, 0, 1023, 0, 255);
  motorSpeedL = map(potValTwo, 0, 1023, 0, 255);

  Serial.print("PWM Value: ");
  Serial.println(motorSpeedL);
  controlMotor(motorSpeedL,rightDirection,rightMotor);
  controlMotor(motorSpeedR,leftDirection,leftMotor);
  

  
  
}

void controlMotor(int motorSpeed, int directionPin, int pwmPin){
 if (motorSpeed >= 0 && motorSpeed < 128){
    digitalWrite(directionPin, LOW);
    int backwardSpeed = map(motorSpeed, 0, 127, 255, 0);
    analogWrite(pwmPin, backwardSpeed); 
    Serial.println(backwardSpeed);
  }else if (motorSpeed >= 128 && motorSpeed < 256){
    digitalWrite(directionPin, HIGH);
    int forwardSpeed = map(motorSpeed, 128, 255, 0, 255);
    analogWrite(pwmPin, forwardSpeed);
    Serial.println(forwardSpeed);
    
  } 
  
  
}
