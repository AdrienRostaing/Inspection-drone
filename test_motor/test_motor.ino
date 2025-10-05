// Broches de contrôle des moteurs
#define A1 5
#define A2 6
#define B1 10
#define B2 11

void setup() {
  // Définir les broches comme sorties
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
}

void loop() {
  // Faire avancer les deux moteurs
  forward();
  delay(2000);  // Attendre 2 secondes

  // Faire reculer les moteurs
  backward();
  delay(2000);  // Attendre 2 secondes

  // Arrêter les moteurs
  Stop();
  delay(2000);  // Attendre 2 secondes
}

void forward() {
  // Faire avancer les moteurs
  analogWrite(A1, 155);
  analogWrite(A2, 0);
  analogWrite(B1, 155);
  analogWrite(B2, 0);
}

void backward() {
  // Faire reculer les moteurs
  analogWrite(A1, 0);
  analogWrite(A2, 155);
  analogWrite(B1, 0);
  analogWrite(B2, 155);
}

void Stop() {
  // Arrêter les moteurs
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
}
