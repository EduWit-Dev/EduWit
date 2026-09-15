/*
  Desarrollado por EduWit: https://eduwit.com.mx

  CONEXIONES:
  Conecta un buzzer pasivo en S1 respetando señal, voltaje y tierra.

  PRUEBA Y OBSERVA:
  tocarTono() utiliza una frecuencia en hertz; tocarNota() utiliza un nombre
  musical como DO4. Cambia 440, DO4, la duración o S1 para experimentar con la
  altura, el tiempo y el puerto del sonido.
*/

#include <EduWit.h>

void setup() {
  eduwit.iniciar();      // Prepara la EduBoard y el puerto S1.
  eduwit.esperarBoton(); // Espera una pulsación antes de producir sonido.

  eduwit.tocarTono(440, 500, S1); // Produce 440 Hz durante medio segundo.
  delay(300);                      // Separa claramente ambos sonidos.

  eduwit.tocarNota(DO4, 500, S1); // Toca la nota DO de la cuarta octava.
  eduwit.detenerSonido(S1);       // Deja S1 libre para utilizarlo como sensor.
}

void loop() {
  // La prueba se ejecuta una sola vez desde setup().
}
