/*
  Desarrollado por EduWit: https://eduwit.com.mx

  CONEXIONES:
  Conecta un motor en MA y otro en MB. Mantén las ruedas levantadas durante la
  primera prueba.

  PRUEBA Y OBSERVA:
  AMBOS aplica la orden a MA y MB. ADELANTE o ATRAS cambia el giro y el número
  indica la velocidad de 0 a 100 %. Compara apagarMotor(), que retira la energía,
  con frenarMotor(), que produce un frenado eléctrico.
*/

#include <EduWit.h>

void setup() {
  eduwit.iniciar();       // Prepara los dos canales de motores.
  eduwit.esperarBoton();  // Espera una pulsación antes de iniciar el movimiento.

  eduwit.moverMotor(AMBOS, ADELANTE, 40); // Mueve ambos motores hacia adelante al 40 %.
  delay(2000);                            // Mantiene el movimiento durante 2 segundos.

  eduwit.apagarMotor(AMBOS);              // Retira la energía antes de invertir el giro.
  delay(500);                             // Hace una pausa para proteger la mecánica.

  eduwit.moverMotor(AMBOS, ATRAS, 80);    // Mueve ambos motores hacia atrás al 80 %.
  delay(2000);                            // Mantiene el movimiento durante 2 segundos.

  eduwit.frenarMotor(AMBOS);              // Aplica frenado eléctrico a ambos motores.
  delay(1000);                            // Permite observar el efecto del frenado.
  eduwit.apagarMotor(AMBOS);              // Deja los motores sin energía al terminar.
}

void loop() {
  // La prueba se ejecuta una sola vez desde setup().
}
