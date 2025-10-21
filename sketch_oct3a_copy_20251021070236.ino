#include <Servo.h>
#define x_pin A0
#define y_pin A1
#define hardcoded_vcc A2
#define hardcoded_gnd A3

Servo myServo;
void setup(){
serial.begin(9600);
pinMode(hardcoded_vcc,OUTPUT);
pinMode(hardcoded_gnd,OUTPUT);
digitalWrite(hardcoded_vcc,HIGH);
digitalWrite(hardcoded_gnd,LOW);
myServo.attach(6);

}
void loop(){
  int x_val=analogRead(x_pin);
  int y_val=analogRead(y_pin);
  int angle =map(x_val,0,1023,0,180);
  myServo.write(angle);
  delay(15);
  serial.print("(");
  serial.print(x_val);
  serial.print(",");
  serial.print(y_val);
  serial.println(")");
  
}