/*
  Desarrollado por EduWit: https://eduwit.com.mx

  CONEXIONES:
  No necesitas componentes externos. LED1, LED2 y LED3 están integrados en la
  EduBoard UNO.

  PRUEBA Y OBSERVA:
  LED1 alterna entre ENCENDIDO y APAGADO porque loop() repite ambas órdenes.
  Cambia LED1 por LED2 o LED3 y modifica los tiempos para observar cómo cada
  argumento cambia el resultado.
*/

#include <EduWit.h>

void setup() {
  eduwit.iniciar(); // Prepara la EduBoard antes de controlar sus componentes.
}

void loop() {
  eduwit.fijarLed(LED1, ENCENDIDO); // Enciende el LED1 integrado.
  delay(1000);                      // Conserva el estado durante 1 segundo.

  eduwit.fijarLed(LED1, APAGADO);   // Apaga el mismo LED.
  delay(1000);                      // Espera 1 segundo antes de repetir.
}
