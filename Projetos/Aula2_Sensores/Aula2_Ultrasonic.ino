#include <Ultrasonic.h>

/* Definição dos pinos responsáveis por enviar e captar o sinal do sensor */
#define pino_trigger 4
#define pino_echo 5

Ultrasonic ultrasonic(pino_trigger, pino_echo); // Criando objeto da classe Ultrasonic para coletar distância

void setup() {
  Serial.begin(9600);
  Serial.println("Dados do sensor: ");

}

void loop() {
  int dist_cm; //Criando variável que vai armazenar distância do sensor
  dist_cm = ultrasonic.distanceRead(); //Dependendo da biblioteca pode ser ultrasonic.Ranging(CM);
  Serial.print ("Distância em cm: ");
  Serial.println(dist_cm); // Exibindo no monitor Serial o valor da distância
  delay(500); // Espera meio segundo para exibir valor na tela

}
