/* Grupo-de-robotica-IEEE  - UFPB
 *  Programa : IHM  - ligando um led com botao
 * Instrutores: Abraão Állysson e Yuri Oliveira 
 */
 

int led=13;      // led no pino 13
int botao=12;  // botão no pino 12
int var=0;       // valor instantaneo enviado pelo botão
int var2=0;     // valor guardado
int estado=0;  // guarda o valor 0 ou 1 (HIGH ou LOW)
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(botao,INPUT);
}
void loop()
{
  var=digitalRead(botao); // ler o valor enviado pelo botão: "HIGH" ou "LOW"
  if ((var == HIGH) && (var2 == LOW)) {
    estado = 1 - estado;
    delay(20); // de-bouncing
  }
  var2=var;
  if (estado == 1) {
    digitalWrite(led, HIGH); // liga o led
  } else {
    digitalWrite(led, LOW);  // desliga o led
  }
}
