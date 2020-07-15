int relay_pin=12;
int ldr_pin=A0;
int ldr_value = 0;
int pir_value=LOW;
int night_limit=800;
int pir_in=10;


void setup() 


{

Serial.begin(9600);
pinMode(relay_pin, OUTPUT);
digitalWrite(relay_pin, HIGH);
int i;
 /* for( i=0;i<=60;i++)
  {
    delay(1000);
  }
  
  
  if(i!=0)
{
  for(int i=0;i<=3;i++)
 digitalWrite(relay_pin, LOW); 
 delay(100);
 digitalWrite(relay_pin, HIGH);
  delay(100);
}

*/

pinMode(pir_in, INPUT);

}


void loop() {
  pir_value = digitalRead(pir_in);
  ldr_value = analogRead(ldr_pin);
  Serial.println(ldr_value);
 Serial.println(  pir_value);
  

  
  if((ldr_value>night_limit)&&(pir_value== HIGH))
  {
  digitalWrite(relay_pin, LOW); 
digitalWrite(13, HIGH); 
     Serial.println( "LIght on");
  }

  else
  {                 
    digitalWrite(13, LOW);      
  digitalWrite(relay_pin, HIGH);    
   Serial.println( "LIght of");
  
  }                       
delay(500);

}
