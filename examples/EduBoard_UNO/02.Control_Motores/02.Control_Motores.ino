// Kits, tarjetas y codigos disenados para aprender mas facil. Busca mas informacion en https://eduwit.com.mx/
// Ejemplo: Control de Motores MA y MB con arranque por boton
// Tarjeta: Arduino UNO + EduBoard UNO

#include <EduWit.h>

void setup() {
  eduwit.iniciar();
  eduwit.esperarBoton(); // Pausa segura antes de iniciar
}

void loop() {
  eduwit.mover(AMBOS, ADELANTE, 100);
  delay(2000);

  eduwit.frenar(AMBOS);
  delay(1000);

  eduwit.mover(AMBOS, ATRAS, 80);
  delay(2000);

  eduwit.apagar(AMBOS);
  delay(2000);
}
