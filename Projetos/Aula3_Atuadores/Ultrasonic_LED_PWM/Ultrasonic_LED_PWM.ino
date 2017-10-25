/* Exemplo que mostra pino digital PWM no led
 * Intensidade da luz do LED varia com a distância do ultrassônico
 */

#include <Ultrasonic.h> // Inclui biblioteca do ultrassônico 

#define pino_echo 9 // Define pino echo do sensor ultrassônico
#define pino_trigger 8 // Define pino trigger do sensor ultrassônico
#define led 10 // Define pino do led numa porta digital PWM

Ultrasonic ultrasonic (pino_trigger, pino_echo); // Cria objeto da classe Ultrasonic, setando os pinos do sensor como parâmetro
int dist; // Declara variável que armazenará o valor da distância

void setup() {
  Serial.begin (9600); // Inicia monitor serial
  pinMode (led, OUTPUT); // Define pino do led como saída
  
  digitalWrite(led, LOW); // Inicia led sempre desligado
}

void loop() {
  dist = ultrasonic.Ranging(CM); // Atualiza valor da distância na variável "dist"
  Serial.print ("Valor da distancia: ");
  Serial.println (dist); // Printa no monitor serial valor da distância
  if (dist < 10){ // Se dist < 10 cm, led fica fraco
    analogWrite (led, 25); // Valor do PWM pode ser entre 0 - 255
    delay (100);
  }
  else // Se não, led fica forte
    analogWrite (led, 200); // Valor do PWM pode ser entre 0 - 255

  delay (50);
}
