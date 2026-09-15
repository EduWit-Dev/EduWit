# Historial de cambios

## 1.1.2

### API principal

- Se adoptaron nombres que expresan acciones: `moverMotor()`, `frenarMotor()`,
  `apagarMotor()`, `girarServo()`, `fijarLed()`, `botonPresionado()`,
  `detectaLinea()`, `medirDistancia()`, `tocarTono()`, `tocarNota()` y
  `detenerSonido()`.
- `medirDistancia()` utiliza U1 de manera predeterminada y permite seleccionar
  U1, U2 o U3.
- `detectaObjeto()` acepta los caracteres `<` y `>` como comparaciones estrictas.
- Los nombres de 1.1.1 se conservan como alias no documentados para mantener la
  compatibilidad con sketches anteriores.

### Bluetooth y Serial

- Se agregó `leerComandoBluetooth()` como lectura no bloqueante.
- La lectura nueva procesa un comando visible por llamada y evita descartar
  comandos anteriores cuando varios llegan juntos.
- Se conservan `configurarSerial()`, `enviarSerial()` y `enviarBluetooth()`.
- `COMANDO`, `leerBluetooth()`, `comandoBluetooth()` y `comandoEs()` permanecen
  únicamente por compatibilidad.

### Simplificación

- Se retiraron `iniciarI2C()` e `i2cActivo()` porque no tienen consumidores en la
  versión actual.
- La colección se redujo de 24 a 10 ejemplos progresivos.
- Los encabezados contienen solo autoría, conexiones y una sección compacta de
  prueba y observación.
- Se agregaron comentarios directos `//` dentro de `setup()` y `loop()`.

## 1.1.1

- Se incorporó la primera ruta pedagógica de ejemplos.
- Se agregaron lecturas digitales, analógicas, ultrasónicas, sonido por software
  y protección de recursos compartidos de EduBoard UNO REV3.
