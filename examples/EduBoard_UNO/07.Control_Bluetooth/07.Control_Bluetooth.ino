// Kits, tarjetas y codigos disenados para aprender mas facil. Busca mas informacion en https://eduwit.com.mx/
// Ejemplo: Control remoto por Bluetooth
// Tarjeta: Arduino UNO + EduBoard UNO

#include <EduWit.h>

void setup() {
  eduwit.iniciar(9600);
}

void loop() {
  eduwit.leerBluetooth();

  switch (eduwit.COMANDO) {
    case 'F':
      eduwit.mover(AMBOS, ADELANTE, 100);
      break;
    case 'B':
      eduwit.mover(AMBOS, ATRAS, 100);
      break;
    case 'L':
      eduwit.mover(MA, ATRAS, 90);
      eduwit.mover(MB, ADELANTE, 90);
      break;
    case 'R':
      eduwit.mover(MA, ADELANTE, 90);
      eduwit.mover(MB, ATRAS, 90);
      break;
    case 'S':
      eduwit.apagar(AMBOS);
      break;
  }
}
