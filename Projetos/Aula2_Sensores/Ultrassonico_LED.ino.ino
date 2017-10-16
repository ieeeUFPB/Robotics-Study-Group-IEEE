#include <Ultrasonic.h>
/* Definição dos pinos para sensor de distância, leds e buzzer */
#define pino_trigger 4
#define pino_echo 5
#define led1 8
#define led2 9
#define led3 10
#define buzzer 11

Ultrasonic ultrasonic(pino_trigger, pino_echo); // Objeto da classe Ultrasonic
int distancia = 0; // Variável para armazenar a distância

void setup() {
  Serial.begin(9600);
  Serial.println("Dados do sensor: ");
  /* Configurando pinos de saída para os leds e buzzer */
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (buzzer, OUTPUT);
  digitalWrite (buzzer, LOW);
  digitalWrite (led1, LOW);
  digitalWrite (led2, LOW);
  digitalWrite (led3, LOW);
}

void loop() {
  
  distancia = ultrasonic.distanceRead(); // Atualiza valor da distância, dependendo da biblioteca pode ser também ultrasonic.Ranging(CM);
  Serial.print ("Distância em cm: ");
  Serial.println(distancia); // Exibe valor da distância na tela, para debugar


  /* Condições para ligar 1 LED por vez de acordo com a distância e acionar buzzer em um dos intervalos */
  if (distancia > 3 && distancia < 7){
    digitalWrite (led1, HIGH);
    digitalWrite (led2, LOW);
    digitalWrite (led3, LOW);
    digitalWrite (buzzer, HIGH);
    delay (80);
    digitalWrite (buzzer, LOW);
  }

  else if (distancia > 7 && distancia < 10){
    digitalWrite (led2, HIGH);
    digitalWrite (led1, LOW);
    digitalWrite (led3, LOW);
  }

  else{
    digitalWrite (led3, HIGH);
    digitalWrite (led2, LOW);
    digitalWrite (led1, LOW);
  }

  digitalWrite (buzzer, LOW);

}
