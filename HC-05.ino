int tx=1;
int rx=0;
int r=11;
int reds=0;
int bs=0;
int gs=0;
int b=12;
int g=6;
int ser;
int relay1=8;
int relay2=9;

void setup() {
  // put your setup code here, to run once:
pinMode(r,OUTPUT);
pinMode(g,OUTPUT);
pinMode(b,OUTPUT);
pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT); 
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


 
 
  
 if(Serial.available()>0)
{ser=Serial.read();
Serial.println(ser);

 if(reds== 0 && ser ==255 )
{
  digitalWrite(r,HIGH);
  digitalWrite(relay1,HIGH );
  Serial.println("BULB 1 ON");
  ser = 0;
  reds = 1;
  }
if(ser == 255 && reds== 1 )
{
  digitalWrite(r,LOW);
  digitalWrite(relay1,LOW );
   Serial.println("BULB 1 OFF");
    ser = 0;
  reds = 0;
  }
  
 if( bs== 0 && ser ==254 )
{
  digitalWrite(b,HIGH);
  digitalWrite(relay2,HIGH );
  Serial.println("BULB 2 ON");
  ser = 0;
  bs = 1;
  }
if(  bs== 1 && ser ==254)
{
  digitalWrite(b,LOW);
  digitalWrite(relay2,LOW );
    Serial.println("BULB 2 OFF");
    ser = 0;
  bs = 0;
  } 

if(gs== 0 && ser== 249 )
{
  digitalWrite(g,HIGH);
  ser = 0;
  gs = 1;
  }
if(gs== 1 && ser == 249 )
{
  digitalWrite(g,LOW);
    ser = 0;
    gs = 0;
  }

}
 
}