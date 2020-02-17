void connectToMqtt() {
  if ( WiFi.isConnected() ) {
    Serial.println();
    Serial.println("Connecting to MQTT...");
    mqttClient.connect();
  } else {
    xTimerStart(wifiReconnectTimer, 0);
  }
}

void onMqttConnect(bool sessionPresent) {
  uint16_t packetIdPub = 0;
  uint16_t packetIdSub = 0;
  digitalWrite(OnboardLED, HIGH);
  Serial.println();
  Serial.println("Connected to MQTT.");
  Serial.print("Session present: ");
  Serial.println(sessionPresent);
  // HASS discoverry
  /*for ( int i=1; i<=NumRelays; ++i ) {
    mqttClient.publish("homeassistant/switch/lab/relay"+i+"/config", 2, true, "{\"name\": \"Relay "+i+"\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay"+i+"/state\", \"command_topic\": \"homeassistant/switch/lab/relay"+i+"/set\", \"availability_topic\": \"homeassistant/switch/lab/relay"+i+"/available\"}");
    mqttClient.subscribe("homeassistant/switch/lab/relay"+i+"/set", 1);
    mqttClient.publish("homeassistant/switch/lab/relay"+i+"/available", 1, true, "online");
    //mqttClient.publish("homeassistant/switch/lab/relay"+i+"/available", 1, true, "offline");
    }*/
  Serial.println("\nStarting HASS config...");
  mqttClient.publish("homeassistant/switch/lab/relay01/config", 2, true, "{\"name\": \"Relay 01\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay01/state\", \"command_topic\": \"homeassistant/switch/lab/relay01/set\", \"availability_topic\": \"homeassistant/switch/lab/relay01/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay02/config", 2, true, "{\"name\": \"Relay 02\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay02/state\", \"command_topic\": \"homeassistant/switch/lab/relay02/set\", \"availability_topic\": \"homeassistant/switch/lab/relay02/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay03/config", 2, true, "{\"name\": \"Relay 03\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay03/state\", \"command_topic\": \"homeassistant/switch/lab/relay03/set\", \"availability_topic\": \"homeassistant/switch/lab/relay03/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay04/config", 2, true, "{\"name\": \"Relay 04\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay04/state\", \"command_topic\": \"homeassistant/switch/lab/relay04/set\", \"availability_topic\": \"homeassistant/switch/lab/relay04/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay05/config", 2, true, "{\"name\": \"Relay 05\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay05/state\", \"command_topic\": \"homeassistant/switch/lab/relay05/set\", \"availability_topic\": \"homeassistant/switch/lab/relay05/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay06/config", 2, true, "{\"name\": \"Relay 06\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay06/state\", \"command_topic\": \"homeassistant/switch/lab/relay06/set\", \"availability_topic\": \"homeassistant/switch/lab/relay06/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay07/config", 2, true, "{\"name\": \"Relay 07\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay07/state\", \"command_topic\": \"homeassistant/switch/lab/relay07/set\", \"availability_topic\": \"homeassistant/switch/lab/relay07/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay08/config", 2, true, "{\"name\": \"Relay 08\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay08/state\", \"command_topic\": \"homeassistant/switch/lab/relay08/set\", \"availability_topic\": \"homeassistant/switch/lab/relay08/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay09/config", 2, true, "{\"name\": \"Relay 09\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay09/state\", \"command_topic\": \"homeassistant/switch/lab/relay09/set\", \"availability_topic\": \"homeassistant/switch/lab/relay09/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay10/config", 2, true, "{\"name\": \"Relay 10\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay10/state\", \"command_topic\": \"homeassistant/switch/lab/relay10/set\", \"availability_topic\": \"homeassistant/switch/lab/relay10/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay11/config", 2, true, "{\"name\": \"Relay 11\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay11/state\", \"command_topic\": \"homeassistant/switch/lab/relay11/set\", \"availability_topic\": \"homeassistant/switch/lab/relay11/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay12/config", 2, true, "{\"name\": \"Relay 12\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay12/state\", \"command_topic\": \"homeassistant/switch/lab/relay12/set\", \"availability_topic\": \"homeassistant/switch/lab/relay12/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay13/config", 2, true, "{\"name\": \"Relay 13\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay13/state\", \"command_topic\": \"homeassistant/switch/lab/relay13/set\", \"availability_topic\": \"homeassistant/switch/lab/relay13/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay14/config", 2, true, "{\"name\": \"Relay 14\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay14/state\", \"command_topic\": \"homeassistant/switch/lab/relay14/set\", \"availability_topic\": \"homeassistant/switch/lab/relay14/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay15/config", 2, true, "{\"name\": \"Relay 15\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay15/state\", \"command_topic\": \"homeassistant/switch/lab/relay15/set\", \"availability_topic\": \"homeassistant/switch/lab/relay15/available\"}");
  mqttClient.publish("homeassistant/switch/lab/relay16/config", 2, true, "{\"name\": \"Relay 16\", \"retain\": \"true\", \"state_topic\": \"homeassistant/switch/lab/relay16/state\", \"command_topic\": \"homeassistant/switch/lab/relay16/set\", \"availability_topic\": \"homeassistant/switch/lab/relay16/available\"}");
  Serial.println("\nFinished HASS config!\n");

  /*Serial.println("\nStarting HASS sync...");
  mqttClient.publish("homeassistant/switch/lab/relay01/state", 1, true, valueFromPin(Relay01, statusGP0) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay02/state", 1, true, valueFromPin(Relay02, statusGP1) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay03/state", 1, true, valueFromPin(Relay03, statusGP0) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay04/state", 1, true, valueFromPin(Relay04, statusGP1) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay05/state", 1, true, valueFromPin(Relay05, statusGP0) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay06/state", 1, true, valueFromPin(Relay06, statusGP1) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay07/state", 1, true, valueFromPin(Relay07, statusGP0) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay08/state", 1, true, valueFromPin(Relay08, statusGP1) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay09/state", 1, true, valueFromPin(Relay09, statusGP0) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay10/state", 1, true, valueFromPin(Relay10, statusGP1) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay11/state", 1, true, valueFromPin(Relay11, statusGP0) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay12/state", 1, true, valueFromPin(Relay12, statusGP1) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay13/state", 1, true, valueFromPin(Relay13, statusGP0) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay14/state", 1, true, valueFromPin(Relay14, statusGP1) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay15/state", 1, true, valueFromPin(Relay15, statusGP0) == 0 ? "ON" : "OFF");
  mqttClient.publish("homeassistant/switch/lab/relay16/state", 1, true, valueFromPin(Relay16, statusGP1) == 0 ? "ON" : "OFF");
  Serial.println("\nFinished HASS sync!\n");
  */
  Serial.println("\nStarting HASS subscribe...");
  mqttClient.subscribe("homeassistant/switch/lab/relay01/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay02/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay03/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay04/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay05/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay06/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay07/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay08/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay09/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay10/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay11/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay12/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay13/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay14/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay15/set", 1);
  mqttClient.subscribe("homeassistant/switch/lab/relay16/set", 1);
  Serial.println("\nFinished HASS subscribe!\n");

  if (reconection) { //Update HASS state
    Serial.println("\nStarting HASS sync...");
    mqttClient.publish("homeassistant/switch/lab/relay01/state", 1, true, ledState01 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay02/state", 1, true, ledState02 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay03/state", 1, true, ledState03 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay04/state", 1, true, ledState04 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay05/state", 1, true, ledState05 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay06/state", 1, true, ledState06 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay07/state", 1, true, ledState07 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay08/state", 1, true, ledState08 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay09/state", 1, true, ledState09 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay10/state", 1, true, ledState10 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay11/state", 1, true, ledState11 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay12/state", 1, true, ledState12 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay13/state", 1, true, ledState13 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay14/state", 1, true, ledState14 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay15/state", 1, true, ledState15 ? "OFF" : "ON");
    mqttClient.publish("homeassistant/switch/lab/relay16/state", 1, true, ledState16 ? "OFF" : "ON");
    Serial.println("\nFinished HASS sync!\n");
  }

  /*
    Serial.println("\nStarting HASS available...");
    mqttClient.publish("homeassistant/switch/lab/relay16/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay15/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay14/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay13/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay12/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay11/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay10/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay09/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay08/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay07/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay06/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay05/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay04/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay03/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay02/available", 2, true, "online");
    mqttClient.publish("homeassistant/switch/lab/relay01/available", 2, true, "online");
    Serial.println("\nFinished HASS available!\n");
  */
  //mqttClient.publish("homeassistant/switch/lab/relay01/available", 1, true, "offline");
  xTimerStop(mqttReconnectTimer, 0);
}

void onMqttMessage(char* topic, char* payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total) {
  Serial.println();
  Serial.println("Publish received.");
  //uint8_t state = ( strcmp(payload, "ON") == 0 ) ? LOW : HIGH;
  uint8_t state = ( strncmp("ON", payload, 2) == 0 ) ? LOW : HIGH;
  Serial.print("  LedState: ");
  Serial.println(state);
  //Serial.println(topic);
  if ( strcmp(topic, "homeassistant/switch/lab/relay01/set") == 0 ) {
    if ( boot01 || ledState01 != state ) {
      Serial.println("  Relay01");
      setPinData(Relay01, state, GP0);
      ledState01 = state;
      boot01 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay01/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay02/set") == 0 ) {
    if ( boot02 || ledState02 != state ) {
      Serial.println("  Relay02");
      setPinData(Relay02, state, GP1);
      ledState02 = state;
      boot02 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay02/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay03/set") == 0 ) {
    if ( boot03 || ledState03 != state ) {
      Serial.println("  Relay03");
      setPinData(Relay03, state, GP0);
      ledState03 = state;
      boot03 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay03/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay04/set") == 0 ) {
    if ( boot04 || ledState04 != state ) {
      Serial.println("  Relay04");
      setPinData(Relay04, state, GP1);
      ledState04 = state;
      boot04 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay04/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay05/set") == 0 ) {
    if ( boot05 || ledState05 != state ) {
      Serial.println("  Relay05");
      setPinData(Relay05, state, GP0);
      ledState05 = state;
      boot05 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay05/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay06/set") == 0 ) {
    if ( boot06 || ledState06 != state ) {
      Serial.println("  Relay06");
      setPinData(Relay06, state, GP1);
      ledState06 = state;
      boot06 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay06/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay07/set") == 0 ) {
    if ( boot07 || ledState07 != state ) {
      Serial.println("  Relay07");
      setPinData(Relay07, state, GP0);
      ledState07 = state;
      boot07 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay07/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay08/set") == 0 ) {
    if ( boot08 || ledState08 != state ) {
      Serial.println("  Relay08");
      setPinData(Relay08, state, GP1);
      ledState08 = state;
      boot08 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay08/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay09/set") == 0 ) {
    if ( boot09 || ledState09 != state ) {
      Serial.println("  Relay09");
      setPinData(Relay09, state, GP0);
      ledState09 = state;
      boot09 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay09/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay10/set") == 0 ) {
    if ( boot10 || ledState10 != state ) {
      Serial.println("  Relay10");
      setPinData(Relay10, state, GP1);
      ledState10 = state;
      boot10 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay10/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay11/set") == 0 ) {
    if ( boot11 || ledState11 != state ) {
      Serial.println("  Relay11");
      setPinData(Relay11, state, GP0);
      ledState11 = state;
      boot11 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay11/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay12/set") == 0 ) {
    if ( boot12 || ledState12 != state ) {
      Serial.println("  Relay12");
      setPinData(Relay12, state, GP1);
      ledState12 = state;
      boot12 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay12/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay13/set") == 0 ) {
    if ( boot13 || ledState13 != state ) {
      Serial.println("  Relay13");
      setPinData(Relay13, state, GP0);
      ledState13 = state;
      boot13 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay13/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay14/set") == 0 ) {
    if ( boot14 || ledState14 != state ) {
      Serial.println("  Relay14");
      setPinData(Relay14, state, GP1);
      ledState14 = state;
      boot14 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay14/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay15/set") == 0 ) {
    if ( boot15 || ledState15 != state ) {
      Serial.println("  Relay15");
      setPinData(Relay15, state, GP0);
      ledState15 = state;
      boot15 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay15/state", 0, true, payload);
  } else if ( strcmp(topic, "homeassistant/switch/lab/relay16/set") == 0 ) {
    if ( boot16 || ledState16 != state ) {
      Serial.println("  Relay16");
      setPinData(Relay16, state, GP1);
      ledState16 = state;
      boot16 = false;
    }
    mqttClient.publish("homeassistant/switch/lab/relay16/state", 0, true, payload);
  }
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason) {
  Serial.println();
  Serial.println("Disconnected from MQTT.");
  digitalWrite(OnboardLED, LOW);
  reconection = true;
  if ( WiFi.isConnected() ) {
    xTimerStart(mqttReconnectTimer, 0);
  }
}

void onMqttSubscribe(uint16_t packetId, uint8_t qos) {
  Serial.println();
  Serial.println("Subscribe acknowledged.");
  Serial.print("  packetId: ");
  Serial.println(packetId);
  Serial.print("  qos: ");
  Serial.println(qos);
}

void onMqttUnsubscribe(uint16_t packetId) {
  Serial.println();
  Serial.println("Unsubscribe acknowledged.");
  Serial.print("  packetId: ");
  Serial.println(packetId);
}

void onMqttPublish(uint16_t packetId) {
  Serial.println();
  Serial.println("Publish acknowledged.");
  Serial.print("  packetId: ");
  Serial.println(packetId);
}
