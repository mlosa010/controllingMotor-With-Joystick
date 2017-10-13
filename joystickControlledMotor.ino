int directionalPin=2;
int transistorPin=3;
int analogPin =A0;
int transitionalVal;
int pwm;
void directional(int pwm,int directionalPin,int transistorPin);

void setup(){
 pinMode(directionalPin,OUTPUT);
 pinMode(transistorPin,OUTPUT); 
}
void loop(){
  transitionalVal=analogRead(analogPin);
  directional(transitionalVal,directionalPin,transistorPin);
  
  
  
}
void directional(int analogVal,int directionalPin,int transistorPin){
 if(analogVal>511){
  
   pwm=map(analogVal,511,1023,0,255);
   analogWrite(transistorPin,pwm);
   digitalWrite(directionalPin,HIGH);
 } 
 else if(analogVal<=511){
   pwm=map(analogVal,0,511,0,255); 
   analogWrite(transistorPin,pwm);
   digitalWrite(directionalPin,LOW);
 }
  
}
