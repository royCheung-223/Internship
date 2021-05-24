
//Code Authors:
//* Ahmed A. Radwan (author)
//* Maisa Jazba 
#include <ArduinoHardware.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int64.h>
#include <std_msgs/Float32.h>
#define EN_L 12
#define IN1_L 7
#define IN2_L 9
#define EN_R 13
#define IN1_R 8
#define IN2_R 10
#define encoder_L 3
#define encoder_R 2

volatile unsigned int pulses_L = 0;
volatile unsigned int pulses_R = 0;
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
std_msgs::Int64 str_msg;          //define the message
std_msgs::Int64 str_msgR;
std_msgs::Float32 str_msgPW1;
std_msgs::Float32 str_msgPW2;
ros::Publisher chatter("chatter", &str_msg);     //set rostopic name 
ros::Publisher chatterR("chatterR", &str_msgR);
ros::Publisher pulse_Width1("pulse_Width1", &str_msgPW1);
ros::Publisher pulse_Width2("pulse_Width2", &str_msgPW2);
ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", &messageCb );  //subscribe the rostopic cmd_vel
void Motors_init();
void MotorL(int Pulse_Width1);
void MotorR(int Pulse_Width2);
void countL() {
  // This function is called by the interrupt
  pulses_L++;
}

void countR() {
  // This function is called by the interrupt
  pulses_R++;
}

void setup(){
    Motors_init();
    nh.initNode();
    nh.advertise(chatter);
    nh.advertise(chatterR);
    nh.advertise(pulse_Width1);
    nh.advertise(pulse_Width2); 
    nh.subscribe(sub);
    pinMode(encoder_L, INPUT);
    pinMode(encoder_R, INPUT);
    attachInterrupt(digitalPinToInterrupt(3), countL, RISING); //count the rising pulse
    attachInterrupt(digitalPinToInterrupt(2), countR, RISING); //count the rising pulse
    
}
void loop(){
 /*   Serial.write("speed_lin");
    Serial.println(speed_lin);
    Serial.write("speed_ang");
    Serial.println(speed_ang);*/
    MotorL(w_l*40);
    MotorR(w_r*40);
    nh.spinOnce();
    Serial.print("Motor L:");
    Serial.println(pulses_L);
    Serial.print("Motor R:");
    Serial.println(pulses_R);
    str_msg.data = pulses_L;     //set str_msg value = pulses_L
    str_msgR.data = pulses_R;
    str_msgPW1.data = w_l*40;
    str_msgPW2.data = w_r*40;
    chatter.publish( &str_msg );   //publish the pulses_L value 
    chatterR.publish(&str_msgR);
    pulse_Width1.publish(&str_msgPW1);
    pulse_Width2.publish(&str_msgPW2);
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
