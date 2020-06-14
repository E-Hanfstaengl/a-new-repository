int purplePin = 2 ;
int redPin = 4 ;
int greenPin = 5 ;
int ledPin = 9 ;

int speakPin = 6 ;

int pressPin = 3;

int judge = 1 ;


void setup() {
  // put your setup code here, to run once:
  pinMode(purplePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(pressPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
    
  if ( digitalRead(pressPin) == LOW){
    judge = 0;
    digitalWrite(redPin, HIGH);
    delay(30000);
  }
  
  if (judge == 0) {
    digitalWrite(purplePin, HIGH);
    digitalWrite(redPin, HIGH);
    delay(1000*60*30);
    digitalWrite(purplePin, LOW);
    digitalWrite(redPin, LOW);
    digitalWrite(speakPin, HIGH);
    digitalWrite(greenPin, HIGH);
    delay(10000);
    digitalWrite(speakPin, LOW);
    digitalWrite(greenPin, LOW);
  }
  

}
