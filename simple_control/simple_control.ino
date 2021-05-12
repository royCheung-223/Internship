//Code Authors:
//* Ahmed A. Radwan (author)
//* Maisa Jazba 
#include <ArduinoHardware.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
#define EN_L 12
#define IN1_L 7
#define IN2_L 9
#define EN_R 13
#define IN1_R 8
#define IN2_R 10
double w_r=0, w_l=0;
//wheel_rad is the wheel radius ,wheel_sep is
double wheel_rad = 0.0325, wheel_sep = 0.295;
ros::NodeHandle nh;
int lowSpeed = 200;
int highSpeed = 50;
double speed_ang=0, speed_lin=0;
void messageCb( const geometry_msgs::Twist& msg){
      speed_ang = -msg.angular.z;
      speed_lin = -msg.linear.x;
      w_r = (speed_lin/wheel_rad) - ((speed_ang*wheel_sep)/(2.0*wheel_rad)*2);
      w_l = (speed_lin/wheel_rad) + ((speed_ang*wheel_sep)/(2.0*wheel_rad)*2);

      
}
ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &messageCb );
void Motors_init();
void MotorL(int Pulse_Width1);
void MotorR(int Pulse_Width2);
void setup(){
    Motors_init();
    nh.initNode();
    nh.subscribe(sub);
}
void loop(){
    Serial.write("speed_lin");
    Serial.println(speed_lin);
    Serial.write("speed_ang");
    Serial.println(speed_ang);
    MotorL(w_l*40);
    MotorR(w_r*40);
    nh.spinOnce();
    delay(100);
 
}
void Motors_init(){
    pinMode(EN_L, OUTPUT);
    pinMode(EN_R, OUTPUT);
    pinMode(IN1_L, OUTPUT);
    pinMode(IN2_L, OUTPUT);
    pinMode(IN1_R, OUTPUT);
    pinMode(IN2_R, OUTPUT);
    digitalWrite(EN_L, LOW);
    digitalWrite(EN_R, LOW);
    digitalWrite(IN1_L, LOW);
    digitalWrite(IN2_L, LOW);
    digitalWrite(IN1_R, LOW);
    digitalWrite(IN2_R, LOW);
}
void MotorL(int Pulse_Width1){
 if (Pulse_Width1 > 0){
    analogWrite(EN_L, Pulse_Width1);
    digitalWrite(IN1_L, LOW);
    digitalWrite(IN2_L, HIGH);
 }
 if (Pulse_Width1 < 0){
     Pulse_Width1=abs(Pulse_Width1);
    analogWrite(EN_L, Pulse_Width1);
    digitalWrite(IN1_L, HIGH);
    digitalWrite(IN2_L, LOW);
 }
 if (Pulse_Width1 == 0){
    analogWrite(EN_L, Pulse_Width1);
    digitalWrite(IN1_L, LOW);
    digitalWrite(IN2_L, LOW);
 }
}
void MotorR(int Pulse_Width2){
 if (Pulse_Width2 > 0){
    analogWrite(EN_R, Pulse_Width2);
    digitalWrite(IN1_R, LOW);
    digitalWrite(IN2_R, HIGH);
 }
 if (Pulse_Width2 < 0){
    Pulse_Width2=abs(Pulse_Width2);
    analogWrite(EN_R, Pulse_Width2);
    digitalWrite(IN1_R, HIGH);
    digitalWrite(IN2_R, LOW);
 }
 if (Pulse_Width2 == 0){
    analogWrite(EN_R, Pulse_Width2);
    digitalWrite(IN1_R, LOW);
    digitalWrite(IN2_R, LOW);
 }
}
