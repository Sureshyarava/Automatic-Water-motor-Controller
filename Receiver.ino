# include <RH_ASK.h>
# include <SPI.h> 
RH_ASK rf_driver;
String vol;
void setup()
{
    pinMode(9, OUTPUT);
    rf_driver.init();
   Serial.begin(9600);

}

void loop()
{
    uint8_t buf[6];
    uint8_t buflen = sizeof(buf);
    if (rf_driver.recv(buf, & buflen))
{
    vol = String((char *)buf);
float k = vol.toFloat();
digitalWrite(9, HIGH);
Serial.print("Vol:");
Serial.println(k);
Serial.print("Delay:");


Serial.println((k * 1000) / 27.7);


delay(((k * 1000) / 27.7) * 1000);


digitalWrite(9, LOW);
}

}
