void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  float  ans=0;
  int j=0;
  for(int i=0;i<2000;i++){
    int k=analogRead(2);
    if (k>3065){
    ans+=k;
    j++;
    }
  }
  ans=ans/j;
  ans=ans-3112;
  Serial.println("ans = "+String(ans));
  if (ans>0){
  Serial.println("Voltage = "+String(250*ans/403));
  }
  else{
    Serial.println("Voltage = "+String(0));
  }
  delay(100);
  }
