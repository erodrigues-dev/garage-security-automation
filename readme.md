# Garage Security Automation

Este projeto é uma iniciativa para automatizar o sistema de segurança em minha garagem/oficina
ele vai controlar o sistema de alarme, controle de presença, iluminação e portão.

Será integrado com um aplicativo mobile, para realizar configurações e executar comandos

Será integrado com a Alexa para realizar tarefas como ligar iluminação ou ativar/desativar 
o alarme.

# Hardware

- [ESP32 DOIT DEVKIT V1](https://www.robocore.net/wifi/esp32-wifi-bluetooth)
- [modulo RF 433mhz](https://www.robocore.net/radio-frequencia-infravermelho/receptor-rf-434mhz)
- [display oled](https://www.robocore.net/display/display-oled-96-i2c-azul)
- [module rele](https://www.robocore.net/atuador-rele/modulo-rele)
- [sensor de presença](https://www.robocore.net/sensor-ambiente/sensor-de-presenca-pir-hc-sr501)

## Pinout
![pinout](https://www.adrobotica.com/wp-content/uploads/2020/04/ESP32-DOIT-DEVKIT-V1-Board-Pinout-30-GPIOs-Copy.jpg)

## Datasheet

[ESP32-WROOM-32](https://html.alldatasheet.com/html-pdf/1148026/ESPRESSIF/ESP32-WROOM-32/573/1/ESP32-WROOM-32.html)

# Ambiente de Desenvolvimento

- Arduino IDE ([download](https://www.arduino.cc/en/software))
- Visual Studio Code ([Arduino Extension](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino))

# Referencias

- https://www.arduino.cc/
- https://www.fernandok.com/2018/03/esp32-detalhes-internos-e-pinagem.html
- https://www.fernandok.com/2018/09/instalando-esp32-no-arduino-ide-metodo.html
- https://www.fernandok.com/search/label/esp32