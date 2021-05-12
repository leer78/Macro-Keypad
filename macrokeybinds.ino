#include <Keypad.h>
#include <Keyboard.h>


// Currently the code is quite incomplete as I haven't found a use for every single key in each page.

const byte ROWS = 3; 
const byte COLS = 3; 
int page = 1;
String google = String("chrome");
String taskmanager = String("taskmgr");
String spotify = String("C:\\Users\\email\\AppData\\Roaming\\Spotify\\Spotify.exe");
String discord = String ("C:\\Users\\email\\AppData\\Local\\Discord\\Update.exe --processStart Discord.exe");
String fileexplorer = String("explorer");
String stickynotes = String("stikynot.exe");
String calculator = String("calc");
String calendar = String("outlookcal:");


// initializing which ports the LED circuits are hooked up to
int led1 = 3;
int led2 = 1;
int led3 = 21;

// setting each keyswitch to a 3X3 array
char hexaKeys[ROWS][COLS] = {
  {'7', '4', '1'},
  {'8', '5', '2'},
  {'9', '6', '3'}
};

byte rowPins[ROWS] = {10, 14, 18}; 
byte colPins[COLS] = {9, 7, 5}; 

// import does the work for us! If this were to be done manually, a series of if statements would need to check each row and column for HIGHs
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

//page values
//1 = general computer
//2 = general computer shortcuts
//3 = discord


void setup(){
  Serial.begin(9600);
  Keyboard.begin();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}


void loop(){
  char customKey = customKeypad.getKey();

  if (page == 1){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    if (customKey){
      Serial.println(customKey);
      switch(customKey){
        case ('1'):
          led(led1);
          delay(50);
          Keyboard.print(KEY_F4);
          break;
        case ('2'):
          led(led2);
          delay(50);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press('s');
          delay(50);
          Keyboard.releaseAll();
          break;
        case ('3'):
          led(led3);
          delay(200);
          break;
        case ('4'):
          led(led1);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('c');
          delay(50);
          Keyboard.releaseAll();
          break;
  
        case ('5'): 
          led(led2);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('v');
          delay(50);
          Keyboard.releaseAll();
          break;
  
        case ('6'):
          led(led3);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press('z');
          delay(50);
          Keyboard.releaseAll();
          break;
  
        case ('7'):
          led(led1);
          Keyboard.press(KEY_F1);
          delay(50);
          Keyboard.releaseAll();
          break;
        case ('8'):
          led(led2);
          Keyboard.press(KEY_F2);
          delay(50);
          Keyboard.releaseAll();
          break;
        case ('9'):
          page = page + 1;
          led(led3);
          //Keyboard.press(KEY_F3);
          //delay(50);
          //Keyboard.releaseAll();
          break;
        default:
          Serial.println(customKey);
      }
  
    }
  }
  else if (page == 2){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    if (customKey){
      Serial.println(customKey);
      switch(customKey){
        case ('1'):
          led(led1);
          cmdPrompt(google);
          break;
        case ('2'):
          led(led2);
          cmdPrompt(fileexplorer);
          break;
        case ('3'):
          led(led3);
          break;
        case ('4'):
          led(led1);
          cmdPrompt(spotify);
          break;
        case ('5'):
          led(led2);
          cmdPrompt(discord);
          break;
        case ('6'):
          led(led3);
          //cmdPrompt(onenote);
          break;
        case ('7'):
          led(led1);
          //cmdPrompt(stickynotes);
          break;
        case ('8'):
          led(led2);
          cmdPrompt(calendar);
          break;
        case ('9'):
          page = page + 1;
          led(led3);
          cmdPrompt(calculator);
          break;
        
  
    }
  } 
  }
  else if (page == 3){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    if (customKey){
      Serial.println(customKey);
      switch(customKey){
        case ('1'):
          led(led1);
          discordKeybind('m');
          break;
        case ('2'):
          led(led2);
          discordKeybind('d');
          break;
        case ('3'):
          led(led3);
          discordKeybind('o');
          break;
        case ('4'):
          led(led1);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_UP_ARROW);
          delay(50);
          Keyboard.releaseAll();
          break;
        case ('5'):
          led(led2);
          Keyboard.press(KEY_LEFT_ALT);
          Keyboard.press(KEY_LEFT_CTRL);
          Keyboard.press(KEY_DOWN_ARROW);
          delay(50);
          Keyboard.releaseAll();
          break;
        case ('6'):
          led(led3);
          discordKeybind('e');
          break;
        case ('7'):
          led(led1);
          
          //cmdPrompt(stickynotes);
          break;
        case ('8'):
          led(led2);
          //cmdPrompt(calendar);
          break;
        case ('9'):
          page = page + 1;
          led(led3);
          //cmdPrompt(calculator);
          break;
        
  
    }
  } 
  }
}

void led(int led){
  digitalWrite(led, LOW);
  delay(50);
  digitalWrite(led,HIGH);
  delay(10);
}

void cmdPrompt(String address){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(50);
  Keyboard.releaseAll();
  delay(100);

  Keyboard.print(address);
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(50);
  Keyboard.releaseAll();
}

void discordKeybind(char keybind){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(keybind);
  delay(50);
  Keyboard.releaseAll();
  
}
