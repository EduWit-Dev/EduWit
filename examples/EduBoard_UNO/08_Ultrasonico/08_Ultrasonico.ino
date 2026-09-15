/*
  Desarrollado por EduWit: https://eduwit.com.mx

  CONEXIONES:
  Conecta un sensor ultrasónico en U1 respetando V, T, E y G.

  PRUEBA Y OBSERVA:
  medirDistancia() convierte el tiempo de un eco en centímetros. detectaObjeto()
  compara una nueva medición con '<' o '>'. Abre el Monitor Serie a 9600 baudios,
  mueve un objeto y cambia U1, el signo o el límite de 30 cm.
*/

#include <EduWit.h>

void setup() {
  eduwit.iniciar(); // Prepara la EduBoard y abre Serial a 9600 baudios.
}

void loop() {
  int centimetros = eduwit.medirDistancia(U1); // Mide la distancia desde U1.

  Serial.print("Distancia: "); // Escribe una etiqueta antes del valor.
  Serial.print(centimetros);   // Muestra la distancia medida.
  Serial.println(" cm");      // Añade la unidad y termina la línea.

  delay(60); // Separa las mediciones para evitar que un eco interfiera con otro.

  if (eduwit.detectaObjeto(U1, '<', 30)) { // Comprueba si el objeto está a menos de 30 cm.
    eduwit.fijarLed(LED1, ENCENDIDO);       // Enciende LED1 cuando se cumple la comparación.
  } else {
    eduwit.fijarLed(LED1, APAGADO);         // Apaga LED1 cuando no se cumple.
  }

  delay(250); // Espera antes de iniciar otra pareja de mediciones.
}
