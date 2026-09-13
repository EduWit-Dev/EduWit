// Kits, tarjetas y codigos disenados para aprender mas facil. Busca mas informacion en https://eduwit.com.mx/
// Ejemplo: Seguidor de linea simple con 2 sensores
// Tarjeta: Arduino UNO + EduBoard UNO

#include <EduWit.h>

void setup() {
  eduwit.iniciar();
  eduwit.esperarBoton();
}

void loop() {
  if (eduwit.linea(S1, NEGRO) && eduwit.linea(S2, BLANCO)) {
    eduwit.mover(MA, ADELANTE, 100);
    eduwit.mover(MB, ATRAS, 100);
  } 
  else if (eduwit.linea(S1, BLANCO) && eduwit.linea(S2, NEGRO)) {
    eduwit.mover(MA, ATRAS, 100);
    eduwit.mover(MB, ADELANTE, 100);
  } 
  else if (eduwit.linea(S1, BLANCO) && eduwit.linea(S2, BLANCO)) {
    eduwit.mover(AMBOS, ADELANTE, 100);
  } 
  else {
    eduwit.apagar(AMBOS);
  }
}
