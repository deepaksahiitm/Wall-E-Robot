// This is ongoing project so for latest code & Modifications visit: https://github.com/deepaksahiitm/Wall-E-Robot.git
// Your Suggestions & support for this project will be highly appreciated. 
// This code is for neck & eye movement only.In this project 2 servo motor is for eye & 3 for neck.

#include <Servo.h>  // its include servo library for servo motor
Servo myservo;  
Servo myservo1;
Servo myservo2; 
Servo myservo6; 
Servo myservo5; 
int pos = 73;  //define the initial Position of servo 
int pos1 = 90;
int pos2 = 90;
int pos6 = 120;
int pos5 = 70;

String voice;

void setup() 
{
  Serial.begin(9600);
  myservo.attach(9);       // attached the servo signal wire to 9 no. pin of Arduino Mega
  myservo1.attach(8);
  myservo2.attach(7);      // 7,8 & 9 no. servo for neck motion
  myservo6.attach(6);       // 5 & 6 no. servo for eye motion
  myservo5.attach(5);
 
 
 
   myservo.write(pos);   //sets the Servo in defined initial position
   myservo1.write(pos1); 
   myservo2.write(pos2); 
   myservo6.write(pos6);  
   myservo5.write(pos5);
}

void loop() {
  while(Serial.available()) {
    delay(10);
    char c=Serial.read();  //Reads the data(say voice) comming from serial communication (here bluetooh)
    if(c=='#')
    {break; }
    voice += c;            // stores the value in voice
    
}

if (voice.length() > 0) {
  Serial.println(voice);
  if (voice == "look left")        
  
 for (pos = 163; pos <= 163; pos += 3)  //from any position robot will move neck to left most position,here we have measured left at 163 degree
    // in steps of 3 degree
    {
    myservo.write(pos);              
    delay(1000); 
    // waits 1s for the servo to reach the position
  }
  
     
     
  if (voice == "look right")              
   for (pos = 0; pos >= 0; pos -= 3) { 
   
    
    myservo.write(pos); 
    
    delay(1000); 
    }
     if (voice == "look front")
   for (pos = 73; pos <= 73; pos += 3) { 
    
   
    myservo.write(pos);
    }
    
  if (voice == "wali utho")   // This will create a special effect combining the motion of eye & neck at once
  {
  for (pos5 = 110; pos5 <= 110; pos5 += 3) { 
    myservo5.write(pos5);
  }
    for (pos6 = 50; pos6 <= 50; pos6 += 3) { 
    myservo6.write(pos6);
    }
   for (pos1 = 90; pos1 >= 60; pos1 -= 10) { 
    // in steps of 1 degree
    myservo1.write(pos1); 
  
    }
    for (pos2 = 90; pos2 <= 120; pos2 += 10) { 
    // in steps of 1 degree
      myservo2.write(pos2); 
    } 
   delay(1000);
  
  }  
  if (voice == "wali cooldown"){
  
   for (pos5 = 70; pos5 <= 70; pos5 += 3) { 
    // in steps of 1 degree
   
    myservo5.write(pos5);
  }
    for (pos6 = 120; pos6 <= 120; pos6 += 3) { 
    // in steps of 1 degree
   
    myservo6.write(pos6);  
    }
 for (pos1 = 60; pos1 <= 90; pos1 += 3) { 
    // in steps of 1 degree
    myservo1.write(pos1); 
  
    }
    for (pos2 = 120; pos2 >= 90; pos2 -= 3) { 
    
      myservo2.write(pos2); 
    } 
   delay(1000);
  
  }  
  
   if (voice == "look up")  // Neck upp
   {
    for (pos5 = 90; pos5 >= 10; pos5 -= 3) {
    
    myservo5.write(pos5); 
     }
   for (pos6 = 90; pos6 >= 10; pos6 -= 3) { 
    
    myservo6.write(pos6); 
  
    }
   }
    if (voice == "look down")  // neck down
    {
    for (pos5 = 90; pos5 <= 150; pos5 += 3) 
    { 
    myservo5.write(pos5); 
    } 
  for (pos6 = 90; pos6 <= 160; pos6 += 3)
  { 
   myservo6.write(pos6); 
    }
   }
   if (voice == "look straight")
   for (pos5 = 90; pos5 <= 90; pos5 += 3) 
   { 
    myservo5.write(pos5);
    for (pos6 = 90; pos6 <= 90; pos6 += 3)
    { 
    myservo6.write(pos6);
    }
   }
voice="";
}
}
