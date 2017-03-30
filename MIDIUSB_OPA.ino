/*
 * MIDIUSB_OPA.ino
 */ 
#include "MIDIUSB.h"
#include "OPA.h"

OPA opa;

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void setup() {
  Serial.begin(115200);
  opa.enable();
  //opa.loadInternal(OPA_PROGRAM_0, 0);
  //opa.loadInternal(OPA_PROGRAM_1, 1);

  pinMode(A0, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A5, OUTPUT);
  digitalWrite(A0, 0);
  digitalWrite(A2, 1);
  digitalWrite(A3, 0);
  digitalWrite(A5, 1);
}

// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void randomPatch(byte OPA_PROGRAM){
  
  /*
  OPA_OP_VOLUME      = 0,
  OPA_OP_COARSE     = 1,
  OPA_OP_FINE       = 2,
  OPA_OP_ENVATTACK    = 3,
  OPA_OP_ENVDECAY     = 4,
  OPA_OP_ENVSUSTAINLEVEL  = 5,
  OPA_OP_ENVINITLEVEL   = 6,
  OPA_OP_ENVRELEASE   = 7,
  OPA_OP_LFOSPEED     = 8,
  OPA_OP_LFOAMOUNT    = 9,
  OPA_OP_FEEDBACK     = 10,
  OPA_OP_FLAGS
  */
  
  //opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_2, OPA_OP_VOLUME, p1);
  //opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_ENVRELEASE, p2);
  //opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_1, OPA_OP_ENVRELEASE, p2);   
}

void random_algorithm(byte OPA_PROGRAM){
  byte volume=160;
  byte envattack=random(100);
  byte envrelease=random(100);
  
  //OPA_OPERATOR_0
  opa.writeOperatorParam(OPA_PROGRAM, 0, OPA_OP_VOLUME, volume);
  opa.writeOperatorParam(OPA_PROGRAM, 0, OPA_OP_ENVATTACK, envattack);
  opa.writeOperatorParam(OPA_PROGRAM, 0, OPA_OP_ENVRELEASE, envrelease);
  
  //OPA_OPERATOR_1
  opa.writeOperatorParam(OPA_PROGRAM, 1, OPA_OP_VOLUME, volume);
  opa.writeOperatorParam(OPA_PROGRAM, 1, OPA_OP_ENVATTACK, envattack);
  opa.writeOperatorParam(OPA_PROGRAM, 1, OPA_OP_ENVRELEASE, envrelease);
  
  /*
  opa.writeOperatorParam(OPA_PROGRAM, 2, OPA_OP_VOLUME, volume);
  opa.writeOperatorParam(OPA_PROGRAM, 2, OPA_OP_ENVATTACK, envattack);
  opa.writeOperatorParam(OPA_PROGRAM, 2, OPA_OP_ENVRELEASE, envrelease);
  
  opa.writeOperatorParam(OPA_PROGRAM, 3, OPA_OP_VOLUME, volume);
  opa.writeOperatorParam(OPA_PROGRAM, 3, OPA_OP_ENVATTACK, envattack);
  opa.writeOperatorParam(OPA_PROGRAM, 3, OPA_OP_ENVRELEASE, envrelease);
  */
  //Random algorythm
  opa.writeFMParam(OPA_PROGRAM,OPA_PROGRAM_ALGORITHM,OPA_PROGRAM);
}

void random_lfo(byte OPA_PROGRAM){
  byte spd=random(10);
  byte amt=random(10);
  opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_LFOSPEED, spd);
  opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_LFOAMOUNT, amt);
}

void loop() {
  midiEventPacket_t rx;
  do {
    
    /*
    int p1 = analogRead(1) >> 2;
    int p2 = analogRead(4) >> 2;
    opa.writeOperatorParam(OPA_PROGRAM_0, OPA_OPERATOR_2, OPA_OP_VOLUME, p1);
    opa.writeOperatorParam(OPA_PROGRAM_0, OPA_OPERATOR_0, OPA_OP_ENVRELEASE, p2);
    opa.writeOperatorParam(OPA_PROGRAM_0, OPA_OPERATOR_1, OPA_OP_ENVRELEASE, p2);
    */
  
    rx = MidiUSB.read();
    if (rx.header != 0) {
      byte msg=rx.byte1;
      byte midichannel=rx.byte1 & 0x0f;
      //byte program=OPA_PROGRAM_0;
      byte program=midichannel;
      switch(rx.header){
        
        case 8://NOTE OFF
          opa.noteOff(program,rx.byte2);
          Serial.print("NOTE OFF: ");
          Serial.print(rx.byte2, HEX);
          Serial.print("CHN: ");
          Serial.println(midichannel, HEX);
          random_algorithm(midichannel);
          random_lfo(midichannel);
          break;
        
        case 9:
          opa.noteOn(program,rx.byte2);
          Serial.print("NOTE ON: ");
          Serial.print(rx.byte2, HEX);
          Serial.print(" - VELOCITY: ");
          Serial.print(rx.byte3, HEX);
          Serial.print(" - CHN: ");
          Serial.println(midichannel, HEX);
          
          break;

        case 11://'Control change'
          Serial.print("CC: ");
          break;
        
        case 12://'Program change'
          Serial.print("PRG: ");
          break;
        
        default:
          Serial.print("Received: ");
          Serial.print(rx.header, HEX);
          Serial.print("-");
          Serial.print(rx.byte1, HEX);
          Serial.print("-");
          Serial.print(rx.byte2, HEX);
          Serial.print("-");
          Serial.println(rx.byte3, HEX);
          break;
          
      }
    }
  } while (rx.header != 0);
}
