
//global variables
int dotDelay = 200;
int ledPin = 13;

char* letters[] = {".-", "-...", "-.-.", "-..", //A-I
                  "..-.", "--.", "....", "..", 
                  ".---", "-.-", ".-..", "--", "-.", //J-R
                  "---", ".--.", "--.-", ".-.",
                  "...", "-", "..-", "..._", ".--", //S-Z
                  "-..-", "-.--", "--.." };
                  
char* numbers[] = {"-----", ".----", "..---", "...--", "....-", //0-4
                  ".....", "-....", "--...", "---..", "----."}; //5-9
                  



void setup() {
  
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  
  char ch;
  if (Serial.available() > 0) {
    
    ch = Serial.read();
    if (ch >= 'a' && ch <= 'z') {
    
      flashSequence(letters[ch-'a']);
    }
  
    else if (ch >= 'A' && ch <= 'Z') {
    
      flashSequence(letters[ch-'A']);
    } 
  
    else if (ch >= '0' && ch <= '9') {
  
      flashSequence (numbers[ch-'0']);  
    }
  
    else if (ch == ' ') {
    
      delay (dotDelay * 4);  //gap between words
    }

  }
}

//function clashSequence
void flashSequence (char* sequence) {
  
  int i = 0;
  while (sequence[i] != '\0') {
    
    flashDotOrDash(sequence[i]);
    i++; 
  
  }
  
  delay(dotDelay * 3);  
}

//function flashDotOrDash
void flashDotOrDash(char dotOrDash) {

  digitalWrite(ledPin, HIGH);
  if (dotOrDash == '.') {
    delay(dotDelay);
  }

  else {  //it's a dash
  
    delay(dotDelay * 3);
  
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay);   
}
