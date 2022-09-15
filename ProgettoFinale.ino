#define triggerpin 2 //Pin a cui è collegato il pin trigger del sensore
#define echopin 3 //Pin a cui è collegato il pin echo del sensore ultrasuoni

//Libreria schermo LCD.
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  pinMode(triggerpin, OUTPUT);
  pinMode(echopin, INPUT);
  
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Benvenuto!");
  delay(3000);
  
  Serial.begin(9600);
}

int puntiGiocatore1 = 0;
int puntiGiocatore2 = 0;
int pressione = 0;
int altezza = 0;
int turno = 1;

void loop() {
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Turno del");
  lcd.setCursor(1,1);
  if(turno%2 != 0) lcd.print("giocatore 1!");
  else lcd.print("giocatore 2!");
  delay(4000);

  lcd.clear();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Imposta");
  lcd.setCursor(1,1);
  lcd.print("l'altezza!");
  delay(4000);

  digitalWrite(triggerpin, LOW);
  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin, LOW);
  long durata = pulseIn(echopin, HIGH);
  altezza = 0.034 * durata / 2;

  lcd.clear();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Altezza: ");
  lcd.print(altezza);
  delay(4000);

  lcd.clear();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Turno del ");
  lcd.setCursor(1,1);
  if(turno%2 == 0) lcd.print("giocatore 1!");
  else lcd.print("giocatore 2!");
  delay(4000);

  lcd.clear();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Imposta");
  lcd.setCursor(1,1);
  lcd.print("la pressione!");
  delay(4000);

  pressione = analogRead(A0);

  lcd.clear();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Pressione: ");
  lcd.print(pressione);
  delay(4000);

  //Minimo valore pressione = 0
  //Massimo valore pressione = 22
  //Minimo valore distanza = 0
  //Massimo valore distanza = 200
  pressione = map(pressione, 0, 22, 0, 200);

  if(pressione <= altezza){

    lcd.clear();
    lcd.backlight();
    lcd.setCursor(1,0);
    lcd.print("Congratulazioni ");
    lcd.setCursor(1,1);
    if(turno%2 != 0){ 
      lcd.print("giocatore 1!");
      puntiGiocatore1 = puntiGiocatore1 + 1;
    }
    else{
      lcd.print("giocatore 2!");
      puntiGiocatore2 = puntiGiocatore2 + 1;
    }
    delay(4000);

    if(puntiGiocatore1 == 3 || puntiGiocatore2 == 3){
      lcd.clear();
      lcd.backlight();
      lcd.setCursor(1,0);
      lcd.print("Vittoria ");
      lcd.setCursor(1,1);
      if(turno%2 != 0) lcd.print("giocatore 1!");
      else lcd.print("giocatore 2!");
      delay(4000);
      exit(0);
    }   
  }
  else{
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(1,0);
    lcd.print("Congratulazioni ");
    lcd.setCursor(1,1);
    if(turno%2 == 0){ 
      lcd.print("giocatore 1!");
      puntiGiocatore1 = puntiGiocatore1 + 1;
    }
    else{
      lcd.print("giocatore 2!");
      puntiGiocatore2 = puntiGiocatore2 + 1;
    }
    delay(4000);

    if(puntiGiocatore1 == 3 || puntiGiocatore2 == 3){
      lcd.clear();
      lcd.backlight();
      lcd.setCursor(1,0);
      lcd.print("Vittoria ");
      lcd.setCursor(1,1);
      if(turno%2 == 0) lcd.print("giocatore 1!");
      else lcd.print("giocatore 2!");
      delay(4000);
      exit(0);
    }
  }

  lcd.clear();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Giocatore 1: ");
  lcd.print(puntiGiocatore1);
  lcd.setCursor(1,1);
  lcd.print("Giocatore 2: ");
  lcd.print(puntiGiocatore2);
  delay(4000);
  turno = turno + 1;

}
