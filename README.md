
# HomeControlEsp32

## Projeto desenvolvido para uso na automação/controle de luzes da minha casa.

Pequeno projeto desenvolvido em plataforma [Arduino](https://www.arduino.cc/) que programa um microcontrolador [ESP32](https://www.espressif.com/en/products/hardware/esp32/overview) para controlar uma Shield Relay de 16 Canais. Uma placa de circuito impresso própria foi desenvolvida para integrar o componentes de hardware utilizados.

### Características e funcionalidades do projeto:
- 16 portas do ESP32 são utilizadas como entrada para gerir os push buttons/entradas que controlam cada relé;
- As 16 saídas, necessárias para gerir os relés, são disponibilizadas através do expansor de I/Os [MCP23017](https://www.microchip.com/wwwproducts/en/MCP23017), com comunicação I2C;
- O projeto faz uso do SO [FreeRTOS](https://www.freertos.org/), para, através de programação paralela, dividir o processamento entre os dois núcleos disponíveis no ESP32;
- Além do acionamento físico dos relés, estes também são controlados pela internet através do protocolo [MQTT](http://mqtt.org/), de forma que este projeto pode ser facilmente integrado ao [HomeAssitant](https://www.home-assistant.io/). Inclusive fazendo uso do [Discovery](https://www.home-assistant.io/docs/mqtt/discovery/) e Last Will Testament (LWT);
- O projeto também implementa watchdog que monitora travamentos e reinicia o microcontrolador;
