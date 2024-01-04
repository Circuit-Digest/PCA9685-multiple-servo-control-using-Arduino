#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver board1 = Adafruit_PWMServoDriver(0x40);       // called this way, it uses the default address 0x40   

#define SERVOMIN  125                                                 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  625                                                 // this is the 'maximum' pulse length count (out of 4096)

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  board1.begin();
  board1.setPWMFreq(60);                  // Analog servos run at ~60 Hz updates
}

void loop() 
  { for(int i=0; i<8; i++)
      { board1.setPWM(i, 0, angleToPulse(0) );}
    delay(1000);
    
    for( int angle =0; angle<181; angle +=10)
      { for(int i=0; i<8; i++)
          { board1.setPWM(i, 0, angleToPulse(angle) );}
      }
    delay(100);
  }

int angleToPulse(int ang)                             //gets angle in degree and returns the pulse width
  {  int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);  // map angle of 0 to 180 to Servo min and Servo max 
     Serial.print("Angle: ");Serial.print(ang);
     Serial.print(" pulse: ");Serial.println(pulse);
     return pulse;
  }
