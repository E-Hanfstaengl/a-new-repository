int purplePin = 2 ;
int yellowPin = 4 ;
int greenPin = 5 ;
int redPin = 7 ; 

int speakPin = 6 ;

int pressPin = 3 ;
int clickPin = 8 ;

int judge = 1 ;
int kg = 1;
int timerOne = 0 ;
int timerTwo = 0 ;
int timerThree = 0 ;
int limit = 1000*60*60*6;

void setup() {
  pinMode(purplePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(speakPin, OUTPUT);
  pinMode(pressPin, INPUT_PULLUP);
  pinMode(clickPin, INPUT_PULLUP); 
}

void loop() {

  if ( digitalRead(pressPin) == LOW){
    judge = 0;
    digitalWrite(yellowPin, HIGH);
    delay(30000);
  }
  
  if (judge == 0) {
    digitalWrite(purplePin, HIGH);
    digitalWrite(yellowPin, HIGH);
    delay(1000*60*30);
    digitalWrite(purplePin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(speakPin, HIGH);
    digitalWrite(greenPin, HIGH);
    delay(10000);
    digitalWrite(speakPin, LOW);
    digitalWrite(greenPin, LOW);
    judge = 1;
  }
  
  if ( digitalRead(clickPin) == LOW){
    if ( kg == 1) {
      kg = 0 ;
      timerOne = millis();
    }else {
        digitalWrite(greenPin, HIGH);
        delay(10000);
        digitalWrite(greenPin, LOW);
        kg = 1;
       }  
  } 

  if (kg == 0){
   timerTwo = millis();
   timerThree = timerTwo - timerOne; 
    if (timerThree >= limit){
      digitalWrite(redPin, HIGH);
      digitalWrite(speakPin, HIGH);
      delay(10000);
      digitalWrite(redPin, LOW);
      digitalWrite(speakPin, LOW);
      kg = 1;
    }
  }
  
}  
  
