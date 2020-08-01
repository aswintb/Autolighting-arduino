int night_limit=800;
int walk_relay_pin = 9;
int pir_pin = 7; 
int pirValue; 
int ldr_pin=A0;
int ldr_value;
int buzzer_pin= 8;


void setup() 
{
  pinMode(walk_relay_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  
  pinMode(pir_pin, INPUT);
  welcome();

}
 


 
void loop() 
{


  

pirValue = digitalRead(pir_pin);
ldr_value = analogRead(ldr_pin);
  
  
 
 
if((pirValue == 1)&&(ldr_value>night_limit))
  
  {
   digitalWrite(walk_relay_pin, LOW);
   delay(15000);
   digitalWrite(walk_relay_pin, HIGH);
  
  } 
  
  else if((pirValue == 1)&&(ldr_value<night_limit))
  {
     buzzer(2,50);
     delay(9000);
  }
  
  
  
}



void  buzzer(int buzzer_loop,int buzzer_duration)
 {  
  for(int i=0;i<buzzer_loop;i++)
  {
  digitalWrite(buzzer_pin, HIGH);
  delay(buzzer_duration); 
  digitalWrite(buzzer_pin,LOW);
  delay(buzzer_duration); 
 
  }

}


void welcome()
{
  
  digitalWrite(walk_relay_pin, LOW);
  buzzer(1,1000);
  digitalWrite(walk_relay_pin, HIGH);
  delay(59000);
  buzzer(2,300);
}
