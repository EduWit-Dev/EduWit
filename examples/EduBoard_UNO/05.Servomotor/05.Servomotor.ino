// Kits, tarjetas y codigos disenados para aprender mas facil. Busca mas informacion en https://eduwit.com.mx/
// Ejemplo: Control simple del servomotor
// Tarjeta: Arduino UNO + EduBoard UNO

#include <EduWit.h>

void setup() {
  eduwit.iniciar();
}

void loop() {
  eduwit.servo(0);
  delay(1000);

  eduwit.servo(90);
  delay(1000);

  eduwit.servo(180);
  delay(1000);
}
