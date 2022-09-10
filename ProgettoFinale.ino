#define triggerpin 2 //Pin a cui è collegato il pin trigger del sensore
#define echopin 3 //Pin a cui è collegato il pin echo del sensore ultrasuoni


void setup() {
  pinMode(triggerpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
}

int puntiGiocatore1 = 0;
int puntiGiocatore2 = 0;
int pressione = 0;
int altezza = 0;
int turno = 1;

void loop() {
  if(turno == 1){
     delay(2000);
    Serial.print("Benvenuti!\n");
    delay(5000);
  }
  
  Serial.print("Turno del ");
  if(turno%2 != 0) Serial.println("giocatore 1!");
  else Serial.println("giocatore 2!");
  delay(4000);
  Serial.println("Imposta l'altezza!");
  delay(4000);

  digitalWrite(triggerpin, LOW);
  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin, LOW);
  long durata = pulseIn(echopin, HIGH);
  altezza = 0.034 * durata / 2;

  Serial.print("Altezza: ");
  Serial.println(altezza);
  delay(4000);

  Serial.print("Turno del ");
  if(turno%2 == 0) Serial.println("giocatore 1!");
  else Serial.println("giocatore 2!");
  delay(4000);
  Serial.println("Imposta la pressione!");
  delay(4000);

  pressione = analogRead(A0);

  Serial.print("Pressione: ");
  Serial.println(pressione);
  delay(4000);

  if(pressione*10 <= altezza){

    Serial.print("Congratulazioni ");
    if(turno%2 != 0){ 
      Serial.println("giocatore 1!");
      puntiGiocatore1 = puntiGiocatore1 + 1;
    }
    else{
      Serial.println("giocatore 2!");
      puntiGiocatore2 = puntiGiocatore2 + 1;
    }
    delay(4000);

    Serial.println("======================================");

    if(puntiGiocatore1 == 3 || puntiGiocatore2 == 3){
      Serial.print("Vittoria ");
      if(turno%2 != 0) Serial.println("giocatore 1!");
      else Serial.println("giocatore 2!");
      delay(4000);
      exit(0);
    }

    Serial.println();
    Serial.println("Punteggi:");
    Serial.print("Giocatore 1: ");
    Serial.println(puntiGiocatore1);
    Serial.print("Giocatore 2: ");
    Serial.println(puntiGiocatore2);
    delay(4000);
    
  }

  else{
    Serial.print("Congratulazioni ");
    if(turno%2 == 0){ 
      Serial.println("giocatore 1!");
      puntiGiocatore1 = puntiGiocatore1 + 1;
    }
    else{
      Serial.println("giocatore 2!");
      puntiGiocatore2 = puntiGiocatore2 + 1;
    }
    delay(4000);

    Serial.println("======================================");

    if(puntiGiocatore1 == 3 || puntiGiocatore2 == 3){
      Serial.print("Vittoria ");
      if(turno%2 == 0) Serial.println("giocatore 1!");
      else Serial.println("giocatore 2!");
      delay(4000);
      exit(0);
    }

    Serial.println();
    Serial.println("Punteggi:");
    Serial.print("Giocatore 1: ");
    Serial.println(puntiGiocatore1);
    Serial.print("Giocatore 2: ");
    Serial.println(puntiGiocatore2);
    delay(4000);
  }

  Serial.println();
  Serial.println("======================================");
  turno = turno + 1;
  
}
