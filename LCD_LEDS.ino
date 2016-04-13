// CPCDOS, RASPBERRY PI, ARDUINO par Esteban Cadic le 06/04/2016
// Partie : Arduino : C

#include <Wire.h> // bibliothèque permettant la communication I2C 
#include <LCD.h> // bibliothèque permettant la communication avec l'écran LCD 
#include <LiquidCrystal_I2C.h> // bibliothèque permettant la communication avec l'écran LCD 

#define LED1 2 // LED1, PIN 2
#define LED2 3 // LED2, PIN 3
#define LED3 4 // LED3, PIN 4

#define I2C_ADDR 0x27 // adresse I2C de l'écran LCD
#define BACKLIGHT_PIN 3 // PIN du rétroéclairage de l'écran LCD
#define En_pin  2 
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin); // on initialise l'écran LCD

String content = ""; 
char character;

void setup() // fonction appelée au démarrage de l'Arduino  
{
  pinMode(LED1, OUTPUT); // LED1, sortie
  pinMode(LED2, OUTPUT); // LED2, sortie
  pinMode(LED3, OUTPUT); // LED3, sortie
  
  Serial.begin(9600); // on initialise la communication série (pour que le raspberry pi puisse communiquer et envoyer des informations en USB)
  
  lcd.begin (16,2); // mon écran LCD est un 16 caractères par 2 lignes (16*2)

  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE); // on définie le PIN du rétroéclairage de l'écran LCD
  lcd.setBacklight(HIGH); // on active le rétroéclairage de l'écran LCD
  lcd.home (); // on positionne le curseur de l'écran LCD en haut à gauche (0,0)
  
  lcd.print("Arduino");  // on affiche sur la 1ère ligne : Arduino
  lcd.setCursor (0,1); // on positionne le curseur de l'écran LCD en bas à gauche (1er caractère, 2ème ligne)
  lcd.print("LCD"); // on affiche sur la 2ème ligne : LCD

  lcd.home ();
}

void loop() // boucle infinie
{
    
  delay(50); // on attend 50 ms
  while(Serial.available()) { // si des données entrantes sont présentes
    character = Serial.read(); // on les récupères une par une (caractère par caractère)
    content.concat(character); // on ajoute les caractères un à la suite (exemple : l + c + d = lcd) 
  }
    
      
  if (content == "##1") { // si on récupère ##1
    digitalWrite(LED1, HIGH); // alors on allume la LED1 
    content = ""; // on efface ce que le Raspberry Pi a envoyé précédemment
  }

  else if (content == "##2") { // si on récupère ##2
    digitalWrite(LED2, HIGH); // alors on allume la LED2
    content = ""; // on efface ce que le Raspberry Pi a envoyé précédemment
  }

  else if (content == "##3") { // si on récupère ##3
    digitalWrite(LED3, HIGH); // alors on allume la LED3
    content = ""; // on efface ce que le Raspberry Pi a envoyé précédemment
  }

  else if (content == "##4") { // si on récupère ##4
    digitalWrite(LED1, LOW); // alors on éteint la LED1
    content = ""; // on efface ce que le Raspberry Pi a envoyé précédemment
  }

  else if (content == "##5") { // si on récupère ##5
    digitalWrite(LED2, LOW); // alors on éteint la LED2
    content = ""; // on efface ce que le Raspberry Pi a envoyé précédemment
  }

  else if (content == "##6") { // si on récupère ##6
    digitalWrite(LED3, LOW); // alors on éteint la LED3
    content = ""; // on efface ce que le Raspberry Pi a envoyé précédemment
  }

  else if (content == "##clear") { // si on récupère ##clear
    lcd.clear(); // on efface l'écran LCD
    content = ""; // on efface ce que le Raspberry Pi a envoyé précédemment
  }

  else if (content == "##l1") { // si on récupère ##l1
    lcd.setCursor (0,0); // on positionne le curseur de l'écran LCD en haut à gauche (1er caractère, 1ère ligne)
    content = ""; // on efface ce que le Raspberry Pi a envoyé précédemment
  }

  else if (content == "##l2") { // si on récupère ##l2
    lcd.setCursor (0,1); // on positionne le curseur de l'écran LCD en bas à gauche (1er caractère, 2ème ligne)
    content = ""; // on efface ce que le Raspberry Pi a envoyé précédemment
  }
    
  else if (content != "") { // si on récupère autre chose
    lcd.print(content); // on affiche sur l'écran LCD ce que le Raspberry Pi a envoyé
    content = ""; // on efface ce que le Raspberry Pi a envoyé précédemment
  }

}
