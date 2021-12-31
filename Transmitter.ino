volatile int flow_frequency;
float vol = 0.0, l_minute;
unsigned char flowsensor = 2; 
unsigned long currentTime;
unsigned long cloopTime;
#include <RH_ASK.h>
#include <SPI.h> 
RH_ASK rf_driver;
int i=0;
void flow () 
{
   flow_frequency++;
}
void setup()
{
   pinMode(flowsensor, INPUT);
   digitalWrite(flowsensor, HIGH);
   Serial.begin(9600);
   attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING); 
   currentTime = millis();
   cloopTime = currentTime;
   rf_driver.init();
}
void loop ()
{
   currentTime = millis();
   if(currentTime >= (cloopTime + 1000))
   {
    cloopTime = currentTime;
    if(flow_frequency != 0){
      l_minute = (flow_frequency / 7.5); 
      l_minute = l_minute/60;
      vol = vol +l_minute;
      Serial.print("Vol:");
      Serial.print(vol);
      Serial.print(" L");
      Serial.println("");
      flow_frequency = 0; 
    }
    else {
      Serial.print("Vol:");
      Serial.print(vol);
      Serial.print(" L");
      Serial.println("");
    }
    i+=1;
    if (i>=60){
    i=0;
    String str_out=String(vol);
    static char *msg = str_out.c_str();
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    vol=0;
    delay(1000);
    }
   }
}
