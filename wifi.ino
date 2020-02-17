void connectToWifi() {
  if ( ! WiFi.isConnected() ) {
    Serial.println();
    Serial.println("Connecting to Wi-Fi...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  }
}

void WiFiEvent(WiFiEvent_t event) {
  Serial.println();
  Serial.printf("[WiFi-event] event: %d\n", event);
  switch (event) {
    case SYSTEM_EVENT_STA_GOT_IP:
      Serial.println("WiFi connected");
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
      xTimerStop(wifiReconnectTimer, 0); // ensure we don't try to reconnect to Wi-Fi while reconnected
      xTimerStart(mqttReconnectTimer, 0);
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      Serial.println("WiFi lost connection");
      xTimerStop(mqttReconnectTimer, 0); // ensure we don't reconnect to MQTT while reconnecting to Wi-Fi
      xTimerStart(wifiReconnectTimer, 0);
      break;
  }
}

