/**
 * ============================================================================
 *  Name        : RealDash_CAN.ino
 *  Part of     : RealDash
 *  Author      : Jani Immonen
 *  Created     : 15.10.2017
 *
 * Arduino example sketch of how to use RealDash CAN protocol.
 * 
 * This example code is free for any use.
 * 
 * www.realdash.net
 * ============================================================================
 * 
 * Variaveis/Variables:
 * 
 * km/h | mp/h;
 * km...;
 * tripe A;
 * tripe B;
 * Conta giro;
 * marcha(N,1,2,3,4,5,6);
 * setas;
 * farol;
 * combustível(tanque L | Galon);
 * odometro;
 * temperatura(motor,clima);
 * vacumetro;
 * tenção de bateria;
 * pressão de olho;
 * pressão de combustivel;
 * --- Conexões/Wirings --
 * Entradas Analogico(s)/ Inputs Analogic(s):
 * pressão de oleo;
 * temp. ambiente;
 * temp. motor;
 * litragem combustivel;
 * tensão de bateria;
 * Digital(On/Off):
 * velocimetro;
 * rpm;
 * cebolao oleo motor;
 * nivel fluido freio;
 * pisca lerta;
 * setas;
 * limpador;
 * farois;
 * portas;
 * vazão combustivel;
 * cebolão temp. motor;
 * PWM():
**/

// Include lib Demux 16 channel
#include <Mux.h>
using namespace admux;

// Arduino digital and analog pins
int A=19; //Pino A0 fisico
int B=20; //Pino A1 fisico
int C=9;  //Pino D0 fisico
int D=8;  //Pino D1 fisico
int S0=5;  //Pino D2 fisico
int S1=7;  //Pino D4 fisico
int S2=10; //Pino D7 fisico
int S3=11; //Pino D8 fisico

/*
 * Creates a Mux instance.
 * 1st argument is the SIG (signal) pin (Arduino analog input pin A0).
 * 2nd argument is the S0-S3 (channel control) pins (Arduino pins 8, 9, 10, 11).
 */
Mux muxA(Pin(A, INPUT, PinType::Analog), Pinset(S0,S1,S2,S3));
Mux muxB(Pin(B, INPUT, PinType::Analog), Pinset(S0,S1,S2,S3));
Mux muxC(Pin(C, INPUT, PinType::Digital), Pinset(S0,S1,S2,S3));
Mux muxD(Pin(D, INPUT, PinType::Digital), Pinset(S0,S1,S2,S3));
Mux muxCo(Pin(C, OUTPUT, PinType::Digital), Pinset(S0,S1,S2,S3)); // muxCo - Mux digital C for OUTPUT(5V)
Mux muxDo(Pin(D, OUTPUT, PinType::Digital), Pinset(S0,S1,S2,S3)); // muxDo - Mux digital D for OUTPUT(5V)
unsigned int digitalPins = 0;
int analogPins[7] = {0};

unsigned int rpm = 0;
unsigned int kpa = 992; // 99.2
unsigned int tps = 965; // 96.5
unsigned int clt = 80;  // 80 - 100
unsigned int textCounter = 0;


void setup()
{
  // init serial
  S0=HIGH;
  S1=HIGH;
  S2=HIGH;
  S3=HIGH;
  Serial.begin(115200);
  delay(100);
}


void loop()
{
  Serial.print("\n------------------");
  ReadDigitalStatuses();
  //delay(500);
  ReadAnalogStatuses();
  Serial.print("------------------\n");
  //delay(500);
  //Serial.print();
  /*
  SendCANFramesToSerial();

  // just some dummy values for simulated engine parameters
  if (rpm++ > 10000)
  {
    rpm = 500;
  }
  if (kpa++ > 2500)
  {
    kpa = 10;
  }
  if (tps++ > 1000)
  {
    tps = 0;
  }
  if (clt++ > 230)
  {
    // all values in frame are handled as unsigned values. To have negative values,
    // offset actual value and write corresponding conversion to xml file imported to RealDash
    clt = 0;
  }
  if (textCounter++ > 4000)
  {
    textCounter = 0;
  }
  */
}

/*
// Função para enderecar o leitor no pino correto
void boolean Pos(int bdx){
  if (bdx == 15){
    SO=LOW;S1=LOW;S2=LOW;S3=LOW;
    if (S0==LOW and S1==LOW and S2==LOW and S3==LOW){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 14){
    SO=HIGH;S1=HIGH;S2=HIGH;S3=LOW;
    if (S0==HIGH and S1==HIGH and S2==HIGH and S3==LOW){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 13){
    SO=HIGH;S1=HIGH;S2=LOW;S3=HIGH;
    if (S0==HIGH and S1==HIGH and S2==LOW and S3==HIGH){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 12){
    SO=HIGH;S1=HIGH;S2=LOW;S3=LOW;
    if (S0==HIGH and S1==HIGH and S2==LOW and S3==LOW){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 11){
    SO=HIGH;S1=LOW;S2=HIGH;S3=HIGH;
    if (S0==HIGH and S1==LOW and S2==HIGH and S3==HIGH){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 10){
    SO=HIGH;S1=LOW;S2=HIGH;S3=LOW;
    if (S0==HIGH and S1==LOW and S2==HIGH and S3==LOW){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 9){
    SO=HIGH;S1=LOW;S2=LOW;S3=HIGH;
    if (S0==HIGH and S1==LOW and S2==LOW and S3==HIGH){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 8){
    SO=HIGH;S1=LOW;S2=LOW;S3=LOW;
    if (S0==HIGH and S1==LOW and S2==LOW and S3==LOW){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 7){
    SO=LOW;S1=HIGH;S2=HIGH;S3=HIGH;
    if (S0==LOW and S1==HIGH and S2==HIGH and S3==HIGH){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 6){
    SO=LOW;S1=HIGH;S2=HIGH;S3=LOW;
    if (S0==LOW and S1==HIGH and S2==HIGH and S3==LOW){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 5){
    SO=LOW;S1=HIGH;S2=LOW;S3=HIGH;
    if (S0==LOW and S1==HIGH and S2==LOW and S3==HIGH){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 4){
    SO=LOW;S1=HIGH;S2=LOW;S3=LOW;
    if (S0==LOW and S1==HIGH and S2==LOW and S3==LOW){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 3){
    SO=LOW;S1=LOW;S2=HIGH;S3=HIGH;
    if (S0==LOW and S1==LOW and S2==HIGH and S3==){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 2){
    SO=LOW;S1=LOW;S2=HIGH;S3=LOW;
    if (S0==LOW and S1==LOW and S2==HIGH and S3==LOW){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 1){
    SO=LOW;S1=LOW;S2=LOW;S3=HIGH;
    if (S0==LOW and S1==LOW and S2==LOW and S3==HIGH){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  if (bdx == 0){
    SO=LOW;S1=LOW;S2=LOW;S3=LOW;
    if (S0==LOW and S1==LOW and S2==LOW and S3==LOW){
      return TRUE;
    }else{
      return FALSE;
    }
  }
}

// Função para retonar a leitura do pino demultiplexado pela id BDX(vide o arquivo ITENS-NECESSIDADES.xlxs)
void boolean int Demux(bdx){
  if(Pos(bdx)){
    return analogRead=(A0);analogRead(A1);digitalRead(D0);digitalRead(D1);
  }  
}

void boolean Demux2(int bdx, port){
  if(Pos(bdx){
    = (analogRead(port) or digitalRead(port));
    return TRUE;
  }else{
    return FALSE;
  }
}

void Demux3(byte bdx){
}
*/

void ReadDigitalStatuses()
{
  Serial.print("\n++++++++++++++++++++++++++++\n");
  // read status of digital pins (1-13)
  digitalPins = 0;

  int bitposition = 0;
  for (int i=1; i<14; i++)
  {
    if (digitalRead(i) == HIGH) digitalPins |= (1 << bitposition);
    bitposition++;
    Serial.print("\nReadDigitalStatuses: ");
    Serial.print(digitalPins);
    Serial.print(", BitPosition: ");
    Serial.print(bitposition);
  }
  // debug
  Serial.print("\n\nReadDigitalStatuses final: ");
  Serial.print(digitalPins);
  Serial.print("\n++++++++++++++++++++++++++++\n");
  //delay(2000);
}


void ReadAnalogStatuses()
{
  Serial.print("\n============================\n");
  //analogPins[0] = analogRead(0);
  // read analog pins (0-7)
  for (int i=0; i<7; i++)
  {
    analogPins[i] = analogRead(i);
    Serial.print("\nReadAnalogStatuses:(");
    Serial.print(i);
    Serial.print("):");
    Serial.print(analogPins[i]);
    //Serial.print("\n");
  }
  Serial.print("\nFinal: ");
  Serial.print(analogPins[0]);
  Serial.print(",");
  Serial.print(analogPins[1]);
  Serial.print(",");
  Serial.print(analogPins[2]);
  Serial.print(",");
  Serial.print(analogPins[3]);
  Serial.print(",");
  Serial.print(analogPins[4]);
  Serial.print(",");
  Serial.print(analogPins[5]);
  Serial.print(",");
  Serial.print(analogPins[6]);
  Serial.print("\n============================\n");
}


void SendCANFramesToSerial()
{
  byte buf[8];

  // build & send CAN frames to RealDash.
  // a CAN frame payload is always 8 bytes containing data in a manner
  // described by the RealDash custom channel description XML file
  // all multibyte values are handled as little endian by default.
  // endianess of the values can be specified in XML file if it is required to use big endian values

  // build 1st CAN frame, RPM, MAP, CLT, TPS (just example data)
  memcpy(buf, &rpm, 2);
  memcpy(buf + 2, &kpa, 2);
  memcpy(buf + 4, &clt, 2);
  memcpy(buf + 6, &tps, 2);

  // write first CAN frame to serial
  SendCANFrameToSerial(3200, buf);

  // build 2nd CAN frame, Arduino digital pins and 2 analog values
  memcpy(buf, &digitalPins, 2);
  memcpy(buf + 2, &analogPins[0], 2);
  memcpy(buf + 4, &analogPins[1], 2);
  memcpy(buf + 6, &analogPins[2], 2);

  // write 2nd CAN frame to serial
  SendCANFrameToSerial(3201, buf);

  // build 3rd CAN frame, rest of Arduino analog values
  memcpy(buf, &analogPins[3], 2);
  memcpy(buf + 2, &analogPins[4], 2);
  memcpy(buf + 4, &analogPins[5], 2);
  memcpy(buf + 6, &analogPins[6], 2);

  // write 3rd CAN frame to serial
  SendCANFrameToSerial(3202, buf);

  // build 4th frame, this is a text extension frame
  // only send once at 1000 loops
  if (textCounter == 0)
  {
    SendTextExtensionFrameToSerial(3203, "Hello RealDash, this is Arduino sending some text data");
  }
  else if (textCounter == 1000)
  {
    SendTextExtensionFrameToSerial(3203, "Tomorrow's forecast: Lots of sun and 30 degrees centigate");
  }
  else if (textCounter == 2000)
  {
    SendTextExtensionFrameToSerial(3203, "Now Playing: Insert your favorite song info here");
  }
  else if (textCounter == 3000)
  {
    SendTextExtensionFrameToSerial(3203, "Message from Arduino: All systems running at nominal efficiency");
  }
}


void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
{
  // the 4 byte identifier at the beginning of each CAN frame
  // this is required for RealDash to 'catch-up' on ongoing stream of CAN frames
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  Serial.write(serialBlockTag, 4);

  // the CAN frame id number (as 32bit little endian value)
  Serial.write((const byte*)&canFrameId, 4);

  // CAN frame payload
  Serial.write(frameData, 8);
}


void SendTextExtensionFrameToSerial(unsigned long canFrameId, const char* text)
{
  if (text)
  {
    // the 4 byte identifier at the beginning of each CAN frame
    // this is required for RealDash to 'catch-up' on ongoing stream of CAN frames
    const byte textExtensionBlockTag[4] = { 0x55, 0x33, 0x22, 0x11 };
    Serial.write(textExtensionBlockTag, 4);

    // the CAN frame id number (as 32bit little endian value)
    Serial.write((const byte*)&canFrameId, 4);

    // text payload
    Serial.write(text, strlen(text) + 1);
  }
}
