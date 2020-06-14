int purplePin = 2 ;
int yellowPin = 4 ;
int greenPin = 5 ;
int redPin = 7 ; 
int ledPin = 9 ;

int speakPin = 6 ;

int pressPin = 3;

int judge = 1 ;
int kg = 1;
int timer = 0 ;
int i = 0 ;

void setup() {
  pinMode(purplePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(pressPin, INPUT_PULLUP);
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
    kg = 0;
  }
  
  if (kg == 0) {
    for (timer = 1 ; timer <= 6 ; timer++){
      for (i = 1; i <= 60 ; i++){
       delay(1000*60);
      }
    }  
   digitalWrite(redPin, HIGH);
   digitalWrite(speakPin, HIGH);
   delay(30000);
   digitalWrite(redPin, LOW); 
   digitalWrite(speakPin, LOW);
 }
}  
  
