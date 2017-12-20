
int ledpin = 13;
int ledpin2 = 12;
int ledpin3 = 11;
int ledpin4 = 10;
int summer = 9;
char junk;
String inputString="";
bool b2 = false;
bool b3 = false;
bool b4 = false;
unsigned long firstTime = 0;

void setup()                    
{
 Serial.begin(9600);            
 pinMode(ledpin, OUTPUT);
 pinMode(ledpin2, OUTPUT);
 pinMode(ledpin3, OUTPUT);
 pinMode(ledpin4, OUTPUT);
 pinMode(summer, OUTPUT);

}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { 
      junk = Serial.read() ; 
      
    }      // clear the serial buffer
    if(inputString == "a"){         //in case of 'a' turn the LED on
      digitalWrite(ledpin, HIGH);  
    }else if(inputString == "b"){   //incase of 'b' turn the LED off
      digitalWrite(ledpin, LOW);
    }else if(inputString == "c"){
      b2 = true;
    }else if(inputString == "d"){
      b2 = false;
    }else if(inputString == "e"){
      b3 = true;
    }else if(inputString == "f"){
      b3 = false;
    }else if(inputString == "g"){
      b4 = true;
    }else if(inputString == "h"){
      b4 = false;
    }
  }
    if(b2){
      if(digitalRead(ledpin2)){
      digitalWrite(ledpin2, LOW);
      }else{
        digitalWrite(ledpin2, HIGH);
      }
    }
 //   digitalWrite(ledpin2, HIGH);
    if(b3){
      if(digitalRead(ledpin3)){
        digitalWrite(ledpin3, LOW);
        digitalWrite(ledpin4, HIGH);
        Serial.println("1");
      }else{
        digitalWrite(ledpin3, HIGH);
        digitalWrite(ledpin4, LOW);
        Serial.println("2");
      }
    }else{
       digitalWrite(ledpin3, LOW);
       digitalWrite(ledpin4, LOW);
       Serial.println("3");
    }
     unsigned long loopT = 0; //millis() - firstTime;
    if(b4){
      Serial.println("4");
      
      while(loopT <= 100){
        
        digitalWrite(summer, LOW);
        delay(2);
        digitalWrite(summer, HIGH);
        delay(2);
        loopT++;
      }
      //delay(300);
    }else{
     delay(500);  
     Serial.println("5");
    }
    //delay(800);
    inputString = "";
    //if(loopT > 1000){
    //  firstTime = millis();
    //}
  }

