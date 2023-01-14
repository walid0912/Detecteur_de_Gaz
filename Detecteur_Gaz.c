#include &lt;Servo.h&gt;
Servo myservo;
int flame = 10;
int smoke = 9;
int red = 6;
int green = 7 ;
int buzzer = 13 ;
void setup ()
{
pinMode (flame, INPUT) ;
pinMode (smoke, INPUT) ;
pinMode (red, OUTPUT) ;
pinMode (green, OUTPUT) ;
pinMode (buzzer, OUTPUT) ;
Serial.begin(9600);
myservo.attach(8);
myservo.write(0);
}
void loop ()
{
int fval = digitalRead (flame) ;
int sval = digitalRead(smoke);
Serial.print(&quot;fval = &quot;);
Serial.println(fval);
Serial.print(&quot;sval = &quot;);
Serial.println(sval);

if ( sval == HIGH or fval == HIGH)
{
Serial.println(&quot; WARNING! &quot;);
digitalWrite(red, HIGH);
digitalWrite(buzzer, HIGH);
digitalWrite(green, LOW);
myservo.write(180);
}
else
{
Serial.println(&quot; SAFE &quot;);
digitalWrite(red, LOW);
digitalWrite(green, HIGH);
digitalWrite(buzzer, LOW);
myservo.write(0);
}
delay(100);
}
