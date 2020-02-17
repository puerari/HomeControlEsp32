// Configura o GPIO (GP0 ou GP1). Como parametros passamos:
// port: GP0 ou GP1
// custom: INPUT para todos as portas do GP trabalharem como entrada
//        OUTPUT para todos as portas do GP trabalharem como saida
//        custom um valor de 0-255 indicando o modo das portas (1=INPUT, 0=OUTPUT). Ex: 0x01 ou B00000001 ou  1 : indica que apenas o GPX.0 trabalhará como entrada, o restando como saida
void configurePort(uint8_t port, uint8_t custom) {
  if (custom == OUTPUT) {
    writeBlockData(port, 0x00);
  } else if (custom == INPUT) {
    writeBlockData(port, 0xFF);
  } else {
    writeBlockData(port, custom);
  }
}

//envia dados para o MCP23016 através do barramento i2c
//reg: REGISTRADOR
//data: dados (0-255)
void writeBlockData(uint8_t gp, uint8_t cmd) {
  //portENTER_CRITICAL( &myMutex );
  Serial.print("writeBlockData: ");
  Serial.println(cmd, BIN);
  
  Wire.beginTransmission(MCP_ADDRESS);
  Wire.write(gp);
  Wire.write(cmd);
  Wire.endTransmission();
  //portEXIT_CRITICAL( &myMutex );
  delay(10);
}

//seta o valor de um pino especifico
//pin: pino desejado (0-7)
//value: 0 ou 1
//gp : GP0 ou GP1
void setPinData(uint8_t pin, uint8_t value, uint8_t gp) {
  portENTER_CRITICAL( &myMutex );
  uint8_t * statusGP;
  //requisita a leitura de 1 byte vindo do GP
  if (gp == GP0) {
    statusGP = &statusGP0;
  } else if (gp == GP1) {
    statusGP = &statusGP1;
  } else {
    Serial.println("Invalid GP on setPinData!");
    return;
  }
  //se o valor a setar for ZERO fazemos uma operação de subtração binária
  Serial.print("statusGP ANTES:  ");
  Serial.println(*statusGP, BIN);
  if (value == 0) {
    *statusGP &= ~(B00000001 << (pin)); // muda o pino passado para ZERO (LOW)
  } else if (value == 1) {//caso seja UM, faremos uma operação de soma binária
    *statusGP |= (B00000001 << (pin)); // muda o pino passado para UM (HIGH)
  }
  Serial.print("statusGP DEPOIS: ");
  Serial.println(*statusGP, BIN);
  if ( ! Wire.available() ) {
    Serial.print("Wire available: ");
    Serial.println(Wire.available());
    Wire.beginTransmission(MCP_ADDRESS);
    Wire.write(gp);
    Wire.write(*statusGP);
    Wire.endTransmission();
  } else {
    Serial.println("Wire not available!");
  }
  portEXIT_CRITICAL( &myMutex );
  delay(10);
}

//faz a leitura de um pino específico
//pin: pino desejado (0-7)
//gp: GP0 ou GP1
//retorno: 0 ou 1
uint8_t readPin(uint8_t pin, uint8_t gp) {
  //portENTER_CRITICAL( &myMutex );
  uint8_t statusGP = 0;
  Wire.beginTransmission(MCP_ADDRESS);
  Wire.write(gp);
  Wire.endTransmission();
  Wire.requestFrom(MCP_ADDRESS, 1); // ler do chip 1 byte
  statusGP = Wire.read();
  uint8_t value = valueFromPin(pin, statusGP);
  //portEXIT_CRITICAL( &myMutex );
  return value;
}

//retorna o valor do bit na posição desejada
//pin: posição do bit (0-7)
//statusGP: valor lido do GP (0-255)
uint8_t valueFromPin(uint8_t pin, uint8_t statusGP) {
  return (statusGP & ( 0x0001 << pin)) == 0 ? 0 : 1;
}

