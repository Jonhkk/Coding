/*#include <TM1637Display.h>*/
#define CLK 6
#define DIO 7
#define LED 8
#define SENSOR 2

int sensorValue = 0;
int firstNumber = 0;
int secondNumber = 0;
int thirdNumber = 0;
int fourthNumber = 0;

char* firstChar;
char* secondChar;
char* thirdChar;
char* fourthChar;

char* firstPattern;
char* secondPattern;
char* thirdPattern;
char* fourthPattern;

/*TM1637Display display(CLK, DIO);*/

char* letters[] = {
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R 
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
};

char* numbers[] = {
"-----", ".----", "..---", "...--", "....-", ".....",
"-....", "--...", "---..", "----."
};

int dotDelay = 100;
int dashDelay = 200;

// Dot
void MorseDot()
{
  digitalWrite(LED, HIGH);
  delay(dotDelay);
  digitalWrite(LED, LOW);
}

// Dash
void MorseDash()
{
  digitalWrite(LED, HIGH); 
  delay(dashDelay);
  digitalWrite(LED, LOW);
}

void getChar(char tmpChar){
    switch (tmpChar){

        case '.':  
              MorseDot();
              break;
        case '-':  
              MorseDash();
              break;
      }
  }

void setup() {
    /*pinMode(LED, OUTPUT);*/
    Serial.begin(9600);
    srand(analogRead(0));
}

void loop() {
    sensorValue = analogRead(SENSOR); 
    /*Serial.println(numbers[1]);
    Serial.println(firstNumber);
    Serial.println(secondNumber);
    Serial.println(thirdNumber);
    Serial.println(fourthNumber);
    Serial.println(numbers[firstNumber]);
    Serial.println(numbers[secondNumber]);
    Serial.println(numbers[thirdNumber]);
    Serial.println(numbers[fourthNumber]);*/
    /*Serial.println(firstChar);*/
    // Generate 4 different patterns
    for(int i = 0; i < 1; i++)
    {
      firstNumber = random(0,8);
      firstPattern = numbers[firstNumber];
      Serial.println(firstPattern);
      secondNumber = random(0,8);
      secondPattern = numbers[secondNumber];
      Serial.println(secondPattern);
      thirdNumber = random(0,8);
      thirdPattern = numbers[thirdNumber];
      Serial.println(thirdPattern);
      fourthPattern = random(0,8);
      fourthPattern = numbers[fourthNumber];
      Serial.println(fourthPattern);
    }
    // Loop through each pattern and call a separate function to handle the LED light
    for (int i = 0; i < strlen(firstPattern) - 1; i++)
    {
      // Get the character in the current position
      char firstCharacter = firstPattern[0];
      // Call the subroutine to get the morse code equivalent for this character
      getChar(firstCharacter);
      
      char secondCharacter = firstPattern[1];
      getChar(secondCharacter);
      
      char thirdCharacter = firstPattern[2];
      getChar(thirdCharacter);
      
      char fourthCharacter = firstPattern[3];
      getChar(fourthCharacter);
      
      delay(2000);
    }
    for (int i = 0; i < strlen(secondPattern) - 1; i++)
    {
      // Get the character in the current position
      char firstCharacter = secondPattern[0];
      // Call the subroutine to get the morse code equivalent for this character
      getChar(firstCharacter);
      
      char secondCharacter = secondPattern[1];
      getChar(secondCharacter);
      
      char thirdCharacter = secondPattern[2];
      getChar(thirdCharacter);
      
      char fourthCharacter = secondPattern[3];
      getChar(fourthCharacter);
      
      delay(2000);
    }
    for (int i = 0; i < strlen(thirdPattern) - 1; i++)
    {
      // Get the character in the current position
      char firstCharacter = thirdPattern[0];
      // Call the subroutine to get the morse code equivalent for this character
      getChar(firstCharacter);
      
      char secondCharacter = thirdPattern[1];
      getChar(secondCharacter);
      
      char thirdCharacter = thirdPattern[2];
      getChar(thirdCharacter);
      
      char fourthCharacter = thirdPattern[3];
      getChar(fourthCharacter);
      
      delay(2000);
    }
    for (int i = 0; i < strlen(fourthPattern) - 1; i++)
    {
      // Get the character in the current position
      char firstCharacter = fourthPattern[0];
      // Call the subroutine to get the morse code equivalent for this character
      getChar(firstCharacter);
      
      char secondCharacter = fourthPattern[1];
      getChar(secondCharacter);
      
      char thirdCharacter = fourthPattern[2];
      getChar(thirdCharacter);
      
      char fourthCharacter = fourthPattern[3];
      getChar(fourthCharacter);
      
      delay(2000);
    }
    delay(100);
}
