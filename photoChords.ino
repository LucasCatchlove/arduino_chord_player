
 


int val = 120; // delay value for piezo buzzer 
int potPin = A0; //potentiometer 
int photorPin = A1; //photo resistror 
int ledPin = 11; //flashing led
int piezoPin = 9; //The "speaker" (Piezo buzzer)

//globals 
int potVal;
int photorVal;

// array of frequencies correspdonding to notes part of A major scale. 
float majScale[8] = { 440.00, 493.88, 554.37, 587.33, 659.25, 739.99, 830.61, 880.00};  





//reads the numerical value from photoresistor and constrains its range to that of the potentiometer.

int ledAutoAdj() {
  photorVal = analogRead(photorPin);
  Serial.print("auto adj working running");
  
  photorVal = constrain(photorVal, 20, 255);

  int low = 1023;
  int high = 0;
  if (photorVal < low)
    low = photorVal;
  else if (photorVal > high)
    high = photorVal;
  
  return photorVal; 
  
}

//plays chord appergiators in the key of A major (A major, C# Minor, D major) 

void playMusic() {
  
  analogWrite(ledPin, photorVal);

    

    //A major 
  if (photorVal > 20 && photorVal <= 116) {
  
    tone(piezoPin, majScale[0], val);
    delay(potVal);
    digitalWrite(ledPin, HIGH);
 
    tone(piezoPin, majScale[2], val);
    delay(potVal);
    digitalWrite(ledPin, LOW);
    
    tone(piezoPin, majScale[4], val);
    delay(potVal);
    digitalWrite(ledPin, HIGH);
   
    }
    //c#Minor 
  else if (photorVal > 116 && photorVal <= 182) {
  
    tone(piezoPin, majScale[2], val);
    delay(potVal);
    digitalWrite(ledPin, HIGH);
    
    tone(piezoPin, majScale[4], val);
    delay(potVal);
    digitalWrite(ledPin, LOW);
    
    tone(piezoPin, majScale[6], val);
    delay(potVal);
    digitalWrite(ledPin, HIGH);
   
    }
    
  //D major 
  else if (photorVal > 182 && photorVal <= 255) {
  
    tone(piezoPin, majScale[3], val);
    delay(potVal);
    digitalWrite(ledPin, HIGH);
    
    
    
    tone(piezoPin, majScale[5], val);
    delay(potVal);
    digitalWrite(ledPin, LOW);
    
    
    tone(piezoPin, majScale[7], val);
    delay(potVal);
    digitalWrite(ledPin, HIGH);
    
  }

}



//reads potentiometer value and maps it 

void readPot() {
  
  potVal = analogRead(potPin);
  potVal = map(potVal, 0, 2000, 0, 255);

}





//setup code; relays information to serial montior on computer via the serial.print("message") function
void setup() {
  
  pinMode(ledPin, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  Serial.begin(9600); 
  
}
//begingging of the loop and function calls
void loop() {
  
  ledAutoAdj(); 
  readPot(); 
  playMusic(); 

}


