void oddButtonsControl( void * pvParameters ) {
  String taskMessage = "Task oddButtonsControl running on core ";
  taskMessage = taskMessage + xPortGetCoreID();
  Serial.println(taskMessage);  //log to serial monitor
  while (true) {
    timerWrite(timer1, 0); //reset timer0 (feed watchdog)
    //Serial.println( taskMessage );  //log to serial monitor
    if ( digitalRead(Input01) == LOW ) {
      if (btnState01 != LOW) { // btnState is used to avoid sequential toggles
        btnState01 = LOW;
        ledState01 = !ledState01;  // Toggle LED state
        setPinData(Relay01, ledState01, GP0);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay01/set", 1, true, ( ledState01 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState01 == LOW) {
      btnState01 = HIGH;
    }
    if ( digitalRead(Input03) == LOW ) {
      if (btnState03 != LOW) { // btnState is used to avoid sequential toggles
        btnState03 = LOW;
        ledState03 = !ledState03;  // Toggle LED state
        setPinData(Relay03, ledState03, GP0);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay03/set", 1, true, ( ledState03 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState03 == LOW) {
      btnState03 = HIGH;
    }
    if ( digitalRead(Input05) == LOW ) {
      if (btnState05 != LOW) { // btnState is used to avoid sequential toggles
        btnState05 = LOW;
        ledState05 = !ledState05;  // Toggle LED state
        setPinData(Relay05, ledState05, GP0);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay05/set", 1, true, ( ledState05 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState05 == LOW) {
      btnState05 = HIGH;
    }
    if ( digitalRead(Input07) == LOW ) {
      if (btnState07 != LOW) { // btnState is used to avoid sequential toggles
        btnState07 = LOW;
        ledState07 = !ledState07;  // Toggle LED state
        setPinData(Relay07, ledState07, GP0);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay07/set", 1, true, ( ledState07 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState07 == LOW) {
      btnState07 = HIGH;
    }
    if ( digitalRead(Input09) == LOW ) {
      if (btnState09 != LOW) { // btnState is used to avoid sequential toggles
        btnState09 = LOW;
        ledState09 = !ledState09;  // Toggle LED state
        setPinData(Relay09, ledState09, GP0);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay09/set", 1, true, ( ledState09 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState09 == LOW) {
      btnState09 = HIGH;
    }
    if ( digitalRead(Input11) == LOW ) {
      if (btnState11 != LOW) { // btnState is used to avoid sequential toggles
        btnState11 = LOW;
        ledState11 = !ledState11;  // Toggle LED state
        setPinData(Relay11, ledState11, GP0);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay11/set", 1, true, ( ledState11 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState11 == LOW) {
      btnState11 = HIGH;
    }
    if ( digitalRead(Input13) == LOW ) {
      if (btnState13 != LOW) { // btnState is used to avoid sequential toggles
        btnState13 = LOW;
        ledState13 = !ledState13;  // Toggle LED state
        setPinData(Relay13, ledState13, GP0);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay13/set", 1, true, ( ledState13 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState13 == LOW) {
      btnState13 = HIGH;
    }
    if ( digitalRead(Input15) == LOW ) {
      if (btnState15 != LOW) { // btnState is used to avoid sequential toggles
        btnState15 = LOW;
        ledState15 = !ledState15;  // Toggle LED state
        setPinData(Relay15, ledState15, GP0);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay15/set", 1, true, ( ledState15 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState15 == LOW) {
      btnState15 = HIGH;
    }
    delay(100);
  }
}


void evenButtonsControl( void * pvParameters ) {
  String taskMessage = "Task evenButtonsControl running on core ";
  taskMessage = taskMessage + xPortGetCoreID();
  Serial.println(taskMessage);  //log to serial monitor
  while (true) {
    timerWrite(timer0, 0); //reset timer (feed watchdog)
    //Serial.println( taskMessage );  //log to serial monitor
    if ( digitalRead(Input02) == LOW ) {
      if (btnState02 != LOW) { // btnState is used to avoid sequential toggles
        btnState02 = LOW;
        ledState02 = !ledState02;  // Toggle LED state
        setPinData(Relay02, ledState02, GP1);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay02/set", 1, true, ( ledState02 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState02 == LOW) {
      btnState02 = HIGH;
    }
    if ( digitalRead(Input04) == LOW ) {
      if (btnState04 != LOW) { // btnState is used to avoid sequential toggles
        btnState04 = LOW;
        ledState04 = !ledState04;  // Toggle LED state
        setPinData(Relay04, ledState04, GP1);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay04/set", 1, true, ( ledState04 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState04 == LOW) {
      btnState04 = HIGH;
    }
    if ( digitalRead(Input06) == LOW ) {
      if (btnState06 != LOW) { // btnState is used to avoid sequential toggles
        btnState06 = LOW;
        ledState06 = !ledState06;  // Toggle LED state
        setPinData(Relay06, ledState06, GP1);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay06/set", 1, true, ( ledState06 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState06 == LOW) {
      btnState06 = HIGH;
    }
    if ( digitalRead(Input08) == LOW ) {
      if (btnState08 != LOW) { // btnState is used to avoid sequential toggles
        btnState08 = LOW;
        ledState08 = !ledState08;  // Toggle LED state
        setPinData(Relay08, ledState08, GP1);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay08/set", 1, true, ( ledState08 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState08 == LOW) {
      btnState08 = HIGH;
    }
    if ( digitalRead(Input10) == LOW ) {
      if (btnState10 != LOW) { // btnState is used to avoid sequential toggles
        btnState10 = LOW;
        ledState10 = !ledState10;  // Toggle LED state
        setPinData(Relay10, ledState10, GP1);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay10/set", 1, true, ( ledState10 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState10 == LOW) {
      btnState10 = HIGH;
    }
    if ( digitalRead(Input12) == LOW ) {
      if (btnState12 != LOW) { // btnState is used to avoid sequential toggles
        btnState12 = LOW;
        ledState12 = !ledState12;  // Toggle LED state
        setPinData(Relay12, ledState12, GP1);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay12/set", 1, true, ( ledState12 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState12 == LOW) {
      btnState12 = HIGH;
    }
    if ( digitalRead(Input14) == LOW ) {
      if (btnState14 != LOW) { // btnState is used to avoid sequential toggles
        btnState14 = LOW;
        ledState14 = !ledState14;  // Toggle LED state
        setPinData(Relay14, ledState14, GP1);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay14/set", 1, true, ( ledState14 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState14 == LOW) {
      btnState14 = HIGH;
    }
    if ( digitalRead(Input16) == LOW ) {
      if (btnState16 != LOW) { // btnState is used to avoid sequential toggles
        btnState16 = LOW;
        ledState16 = !ledState16;  // Toggle LED state
        setPinData(Relay16, ledState16, GP1);
        if ( mqttClient.connected() ) {
          mqttClient.publish("homeassistant/switch/lab/relay16/set", 1, true, ( ledState16 ) ? "OFF" : "ON"); // Update Button Widget by MQTT
        }
      }
    } else if (btnState16 == LOW) {
      btnState16 = HIGH;
    }
    delay(100);
  }
}

