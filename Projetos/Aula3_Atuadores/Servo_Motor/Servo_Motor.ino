/* Esse exemplo lê valores inteiros no monitor serial e imprime como posição do servo motor
 * Lembre-se de digitar valores entre 0 e 180 
 */

#include <Servo.h> // Inclui biblioteca do servo motor
#define pin_servo 8 // Define pino do servo motor

Servo servo; // Cria objeto da classe para o servo
int pos; // Declara variável que armazenará a posição do servo motor

void setup() {
  Serial.begin (9600); // Inicia Monitor Serial
  servo.attach (pin_servo); // Seta o servo motor no pino que definimos para ele
  servo.write (0); // Inicia servo motor na posição 0
  
}

void loop() {
  if (Serial.available() > 0){ // Condição verifica se dados foram inseridos no monitor serial
    pos = Serial.parseInt();
    Serial.print ("Servo motor esta na posição: ");
    Serial.println (pos);
    servo.write (pos);
  }
}
