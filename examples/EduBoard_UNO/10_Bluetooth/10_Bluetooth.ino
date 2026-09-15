/*
  Desarrollado por EduWit: https://eduwit.com.mx

  CONEXIONES:
  Conecta el módulo en BLUETOOTH respetando la orientación del puerto. Desconecta
  el módulo mientras cargas el programa porque Bluetooth y USB comparten RX/TX.

  PRUEBA Y OBSERVA:
  Cada comando recibido entra en switch. Envía E para encender LED1 y A para
  apagarlo. Agrega otro case con una letra distinta para controlar una nueva
  acción. El módulo y la EduBoard deben utilizar 9600 baudios.
*/

#include <EduWit.h>

void setup() {
  eduwit.iniciar(9600); // Prepara la EduBoard y Bluetooth a 9600 baudios.
}

void loop() {
  char comando = eduwit.leerComandoBluetooth(); // Lee un comando o devuelve '\0' si no hay uno.

  if (comando != '\0') { // Continúa únicamente cuando recibió un comando visible.
    switch (comando) { // Selecciona la acción asociada con la letra recibida.
      case 'E':
        eduwit.fijarLed(LED1, ENCENDIDO);       // Enciende LED1 al recibir E.
        eduwit.enviarBluetooth("LED encendido"); // Confirma la acción al dispositivo.
        break;                                  // Termina este caso.

      case 'A':
        eduwit.fijarLed(LED1, APAGADO);       // Apaga LED1 al recibir A.
        eduwit.enviarBluetooth("LED apagado"); // Confirma la acción al dispositivo.
        break;                                // Termina este caso.

      default:
        eduwit.enviarBluetooth("Usa E o A"); // Responde cuando el comando no existe.
        break;                                // Termina el caso predeterminado.
    }
  }
}
