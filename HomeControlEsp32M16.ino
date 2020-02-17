// Include libraries
#include "esp_system.h" //watchdog
//extern "C" {
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
//}


/**
 * Ajustar os defines conforme a sua realidade
*/
//WIFI
#include <WiFi.h>
#define WIFI_SSID "SEU_SSID"
#define WIFI_PASSWORD "SENHA_DO_WIFI"

//MQTT
#include <AsyncMqttClient.h>
#define MQTT_IP IPAddress(NNN, NNN, NNN, NNN)
#define MQTT_HOST "MQTT_HOST"
#define MQTT_PORT NNNN
#define MQTT_USER "MQTT_USER"
#define MQTT_PASS "MQTT_PASSWORD
#ifndef ASYNC_TCP_SSL_ENABLED
#define ASYNC_TCP_SSL_ENABLED 0
#endif
TimerHandle_t mqttReconnectTimer;
TimerHandle_t wifiReconnectTimer;
AsyncMqttClient mqttClient;

//OTA
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#include <Wire.h> //Biblioteca I2C para comunicação serial
#define MCP_ADDRESS 0x20 //endereço I2C do MCP23016 vai de 0x20 a 0x27 (até  o chipes)
#define GP0 0x12   // DATA PORT REGISTER 0 
#define GP1 0x13   // DATA PORT REGISTER 1
#define IODIR0 0x00  // I/O DIRECTION REGISTER 0 
#define IODIR1 0x01  // I/O DIRECTION REGISTER 1
#define SCK 22 //23
#define SDA 21 //19

/*
//MCP23016
#define MCP_ADDRESS 0x20 //endereço I2C do MCP23016 vai de 0x20 a 0x27 (até  o chipes)
#define SDA 19
#define SCL 23
#define GP0 0x00   // DATA PORT REGISTER 0 
#define GP1 0x01   // DATA PORT REGISTER 1
#define IODIR0 0x06  // I/O DIRECTION REGISTER 0 
#define IODIR1 0x07  // I/O DIRECTION REGISTER 1
*/
uint8_t statusGP0 = B11111111;
uint8_t statusGP1 = B11111111;

//INPUT_PULLUP
//3(RX0),4,5,12,13,14,15,16(RX2),18,19,21,22,23,25,26,27,32,33
//PULL-UP
//2,3(RX0),4,5,13,14,15,16(RX2),18,19,21,22,23,25,26,27,32,33,34,35
//PULL-DOWN
//2,3(RX0),4,5,13,14,15,16(RX2),18,19,21,22,23,25,26,27,32,33,34,35
// Defines pins
#define OnboardLED 2 //turned on when MQTT is connected
#define Input01 15
#define Input02 4
#define Input03 16 //RX2
#define Input04 5
#define Input05 18
#define Input06 19
#define Input07 3 //RX0
#define Input08 23
#define Input09 13
#define Input10 12
#define Input11 14
#define Input12 27
#define Input13 26
#define Input14 25
#define Input15 33
#define Input16 32

#define Relay01 0
#define Relay02 0
#define Relay03 1
#define Relay04 1
#define Relay05 2
#define Relay06 2
#define Relay07 3
#define Relay08 3
#define Relay09 4
#define Relay10 4
#define Relay11 5
#define Relay12 5
#define Relay13 6
#define Relay14 6
#define Relay15 7
#define Relay16 7

uint8_t ledState01 = LOW;
uint8_t ledState02 = LOW;
uint8_t ledState03 = LOW;
uint8_t ledState04 = LOW;
uint8_t ledState05 = LOW;
uint8_t ledState06 = LOW;
uint8_t ledState07 = LOW;
uint8_t ledState08 = LOW;
uint8_t ledState09 = LOW;
uint8_t ledState10 = LOW;
uint8_t ledState11 = LOW;
uint8_t ledState12 = LOW;
uint8_t ledState13 = LOW;
uint8_t ledState14 = LOW;
uint8_t ledState15 = LOW;
uint8_t ledState16 = LOW;

uint8_t btnState01 = HIGH;
uint8_t btnState02 = HIGH;
uint8_t btnState03 = HIGH;
uint8_t btnState04 = HIGH;
uint8_t btnState05 = HIGH;
uint8_t btnState06 = HIGH;
uint8_t btnState07 = HIGH;
uint8_t btnState08 = HIGH;
uint8_t btnState09 = HIGH;
uint8_t btnState10 = HIGH;
uint8_t btnState11 = HIGH;
uint8_t btnState12 = HIGH;
uint8_t btnState13 = HIGH;
uint8_t btnState14 = HIGH;
uint8_t btnState15 = HIGH;
uint8_t btnState16 = HIGH;

bool boot01 = true;
bool boot02 = true;
bool boot03 = true;
bool boot04 = true;
bool boot05 = true;
bool boot06 = true;
bool boot07 = true;
bool boot08 = true;
bool boot09 = true;
bool boot10 = true;
bool boot11 = true;
bool boot12 = true;
bool boot13 = true;
bool boot14 = true;
bool boot15 = true;
bool boot16 = true;

bool reconection = false;

const int wdtTimeout = 3000;  //time in ms to trigger the watchdog
hw_timer_t *timer0 = NULL;
hw_timer_t *timer1 = NULL;

//Cria variáveis mutex para definição de tarefas críticas que podem ser acessadas por quaisquer dos núcleos.
// Explicação em https://youtu.be/QjhvDycyOUg?t=1651
portMUX_TYPE myMutex = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR resetModule() {
  ets_printf("\n====================\n= WHATCHDOG REBOOT =\n====================\n");
  esp_restart_noos();
}

void setup() {
  Serial.begin(115200);
  pinMode(OnboardLED, OUTPUT);
  pinMode(Input01, INPUT_PULLUP);
  pinMode(Input02, INPUT_PULLUP);
  pinMode(Input03, INPUT_PULLUP);
  pinMode(Input04, INPUT_PULLUP);
  pinMode(Input05, INPUT_PULLUP);
  pinMode(Input06, INPUT_PULLUP);
  pinMode(Input07, INPUT_PULLUP);
  pinMode(Input08, INPUT_PULLUP);
  pinMode(Input09, INPUT_PULLUP);
  pinMode(Input10, INPUT_PULLUP);
  pinMode(Input11, INPUT_PULLUP);
  pinMode(Input12, INPUT_PULLUP);
  pinMode(Input13, INPUT_PULLUP);
  pinMode(Input14, INPUT_PULLUP);
  pinMode(Input15, INPUT_PULLUP);
  pinMode(Input16, INPUT_PULLUP);
  digitalWrite(OnboardLED, LOW);

  //MCP23017
  Wire.begin(SDA, SCK, 200000);
  configurePort(IODIR0, OUTPUT); //configura o GPIO0 como OUTPUT (todos os pinos)
  configurePort(IODIR1, OUTPUT); //configura o GPIO1 como OUTPUT (todos os pinos)
  //writeBlockData(GP0, statusGP0); //seta todos os pinos do GPIO0
  //writeBlockData(GP1, statusGP1); //seta todos os pinos do GPIO1

  //Whatchdog
  timer0 = timerBegin(0, 80, true);                  //timer 0, div 80
  timerAttachInterrupt(timer0, &resetModule, true);  //attach callback
  timerAlarmWrite(timer0, wdtTimeout * 1000, false); //set time in us
  
  timer1 = timerBegin(1, 80, true);                  //timer 1, div 80
  timerAttachInterrupt(timer1, &resetModule, true);  //attach callback
  timerAlarmWrite(timer1, wdtTimeout * 1000, false); //set time in us
  
  //cria as tarefas que serão executadas na função buttonControl, com prioridade 10
  xTaskCreatePinnedToCore( oddButtonsControl, "OddButtonsCtrl", 10000, NULL, 2, NULL, 0 );
  xTaskCreatePinnedToCore( evenButtonsControl, "EvenButtonsCtrl", 10000, NULL, 2, NULL, 1 );

  mqttReconnectTimer = xTimerCreate("mqttTimer", pdMS_TO_TICKS(2000), pdFALSE, (void*)0, reinterpret_cast<TimerCallbackFunction_t>(connectToMqtt));
  wifiReconnectTimer = xTimerCreate("wifiTimer", pdMS_TO_TICKS(2000), pdFALSE, (void*)0, reinterpret_cast<TimerCallbackFunction_t>(connectToWifi));

  WiFi.onEvent(WiFiEvent);
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.onSubscribe(onMqttSubscribe);
  mqttClient.onUnsubscribe(onMqttUnsubscribe);
  mqttClient.onMessage(onMqttMessage);
  mqttClient.onPublish(onMqttPublish);
  mqttClient.setCredentials(MQTT_USER, MQTT_PASS);
  mqttClient.setServer(MQTT_HOST, MQTT_PORT); //mqttClient.setServer(MQTT_IP, MQTT_PORT);

  //Whatchdog
  timerAlarmEnable(timer0); //enable interrupt
  timerAlarmEnable(timer1); //enable interrupt

  //xTimerStart(wifiReconnectTimer, 0);
  connectToWifi();
  setupOTA();
}

void loop() {
}
