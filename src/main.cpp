#include <Arduino.h>

int second = 0;
int minute = 0;
int hour = 0;
//Khoi tao cac gia tri gio, phut, giay.
void setup()
{
  for(int i = 0; i < 12; i++){
  	pinMode(i, OUTPUT);
  }
}

void displayOnClock(int num){
  if (num <= 11) {
    digitalWrite(num,HIGH);
  }
}

void clearClock(){
	//TODO: Clear 12 LEDs on Clock
  	for (int i = 0; i <= 11; i++)  digitalWrite(i,LOW);
}

void loop()
{
  for (int i = 0; i < 12; i++){
    displayOnClock(i);     
  }
  clearClock();
  while (hour < 24) {
    clearClock();
    
    if (second == 60) {
    	second = 0;
      	minute++;
    };
    if (minute == 60) {
    	minute = 0;
      	hour++;
    };
    
  
    if (second / 5 - 1 >= 0) 
      	displayOnClock(second / 5 - 1);
    else
      	displayOnClock(11); //Moi bong LED tuong ung voi 5s.
     
    
    if (minute / 5 - 1 >= 0) 
      	displayOnClock(minute / 5 -	1);
    else 
      	displayOnClock(11); //Moi bong LED tuong ung voi 5 phut.
    
    
    if (hour % 12 - 1 >= 0) 
        displayOnClock(hour % 12 - 1);
    else 
      	displayOnClock(11); //Hien thi so chi gio tuong ung voi LED.
    
    
    delay(1000);
    second++;
  } 
}