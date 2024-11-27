
// Initialisation des pin
const int led_R = 8;
const int led_V = 9;
const int led_B = 10;
const int MLI = 11;
const int BP_dec = 12;
const int BP_inc = 13;

int status_bouton;
int memoire_inc = HIGH;
int memoire_dec = HIGH;
int couleur;

void setup()
{
  // Initialiation du type de sortie des pin
  pinMode(BP_dec, INPUT);
  pinMode(BP_inc, INPUT);
  digitalWrite(BP_dec, HIGH);
  digitalWrite(BP_inc, HIGH);
  
  pinMode(MLI, OUTPUT);
  pinMode(led_R, OUTPUT);
  pinMode(led_V, OUTPUT);
  pinMode(led_B, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  status_bouton = digitalRead(BP_inc);

  if((status_bouton != memoire_inc) && (status_bouton == LOW))
  {
      couleur++;
  }
  
  memoire_inc = status_bouton;
  
  status_bouton = digitalRead(BP_dec);
  
  if((status_bouton != memoire_dec) && (status_bouton == LOW))
  {
    couleur--;
  }
  memoire_dec = status_bouton;

  // Blocage des valeur entre 0 et 10
  if(couleur > 10)
  {
    couleur = 10;
  }
  
  if(couleur < 0)
  {
    couleur = 0;
  }
  
  // Chaque valeur de MLI et des couleurs
  switch(couleur) {
    case 0:
      // Vert pur
      Serial.println("Vitesse = 0");
      analogWrite(MLI, 0);
      analogWrite(led_R, 0);
      analogWrite(led_B, 0);
      analogWrite(led_V, 255);
      break;
      
    case 1:
      // Transition vers cyan
      Serial.println("Vitesse = 1");
      analogWrite(MLI, 25);
      analogWrite(led_R, 0);
      analogWrite(led_B, 64);
      analogWrite(led_V, 255);
      break;
      
    case 2:
      // Cyan pur
      Serial.println("Vitesse = 2");
      analogWrite(MLI, 51);
      analogWrite(led_R, 0);
      analogWrite(led_B, 128);
      analogWrite(led_V, 255);
      break;

    case 3:
      // Transition vers bleu clair
      Serial.println("Vitesse = 3");
      analogWrite(MLI, 76);
      analogWrite(led_R, 0);
      analogWrite(led_B, 191);
      analogWrite(led_V, 255);
      break;
      
    case 4:
      // Bleu pur
      Serial.println("Vitesse = 4");
      analogWrite(MLI, 102);
      analogWrite(led_R, 0);
      analogWrite(led_B, 255);
      analogWrite(led_V, 0);
      break;
      
    case 5:
      // Transition vers violet
      Serial.println("Vitesse = 5");
      analogWrite(MLI, 127);
      analogWrite(led_R, 64);
      analogWrite(led_B, 255);
      analogWrite(led_V, 0);
      break;
      
    case 6:
      // Violet
      Serial.println("Vitesse = 6");
      analogWrite(MLI, 153);
      analogWrite(led_R, 128);
      analogWrite(led_B, 255);
      analogWrite(led_V, 0);
      break;
      
    case 7:
      // Transition vers magenta
      Serial.println("Vitesse = 7");
      analogWrite(MLI, 178);
      analogWrite(led_R, 191);
      analogWrite(led_B, 255);
      analogWrite(led_V, 0);
      break;
      
    case 8:
      // Magenta pur
      Serial.println("Vitesse = 8");
      analogWrite(MLI, 204);
      analogWrite(led_R, 255);
      analogWrite(led_B, 255);
      analogWrite(led_V, 0);
      break;

    case 9:
      // Transition vers rouge
      Serial.println("Vitesse = 9");
      analogWrite(MLI, 229);
      analogWrite(led_R, 255);
      analogWrite(led_B, 128);
      analogWrite(led_V, 0);
      break;

    case 10:
      // Rouge pur
      Serial.println("Vitesse = 10");
      analogWrite(MLI, 255);
      analogWrite(led_R, 255);
      analogWrite(led_B, 0);
      analogWrite(led_V, 0);
      break;
  }
}
