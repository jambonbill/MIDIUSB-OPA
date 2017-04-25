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


void ccParam(byte num, byte val){
  
  byte OPA_PROGRAM=0;
  
  switch(num){
    
    case 0:
      //Serial.print("CC0");
      break;
    
    case 8:
      //Serial.print("SELECT ALGORITHM");
      opa.writeFMParam(OPA_PROGRAM, OPA_PROGRAM_ALGORITHM, val);
      break;

    case 9:
      opa.writeFMParam(OPA_PROGRAM, OPA_PROGRAM_VOLUME, val*2);
      break;

    case 10:
      opa.writeFMParam(OPA_PROGRAM, OPA_PROGRAM_PANNING, val*2);
      break;
    
    case 11:
      opa.writeFMParam(OPA_PROGRAM, OPA_PROGRAM_FLAGS, val);//?
      break;

    // OPERATOR 1 //
    case 16://"Op1 Volume"
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_VOLUME, val*2);
      break;
    
    case 17://Op1 Coarse
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_COARSE, val*2);
      break;
      
    case 18://Op1 Fine
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_FINE, val*2);
      break;
      
    case 19://Op1 Attack
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_ENVATTACK, val*2);
      break;
      
    case 20://Op1 Decay
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_ENVDECAY, val*2);
      break;
      
    case 21://Op1 Sustain
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_ENVSUSTAINLEVEL, val*2);
      break;
      
    case 22://Op1 Init.lvl
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_ENVINITLEVEL, val*2);
      break;
      
    case 23://Op1 Release
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_ENVRELEASE, val*2);
      break;
      
    case 24://Op1 LFO Speed
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_LFOSPEED, val*2);
      break;
      
    case 25://Op1 LFO Amnt
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_0, OPA_OP_LFOAMOUNT, val*2);
      break;

    // OPERATOR 2 //
    // OPERATOR 2 //
    // OPERATOR 2 //
    
    case 32://OP2 Volume
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_1, OPA_OP_VOLUME, val*2);
      break;
    
    case 33://OP2 Coarse
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_1, OPA_OP_COARSE, val*2);
      break;
      
    case 34://OP2 Fine
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_1, OPA_OP_FINE, val*2);
      break;
      
    case 35://OP2 Attack
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_1, OPA_OP_ENVATTACK, val*2);
      break;
      
    case 36://OP2 Decay
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_1, OPA_OP_ENVDECAY, val*2);
      break;
      
    case 37://OP2 Sustain
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_1, OPA_OP_ENVSUSTAINLEVEL, val*2);
      break;
      
    case 38://OP2 Init.lvl
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_1, OPA_OP_ENVINITLEVEL, val*2);
      break;
      
    case 39://OP2 Release
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_1, OPA_OP_ENVRELEASE, val*2);
      break;
      
    case 40://OP2 LFO Speed
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_1, OPA_OP_LFOSPEED, val*2);
      break;
      
    case 41://OP2 LFO Amnt
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_1, OPA_OP_LFOAMOUNT, val*2);
      break;

    // OPERATOR 3
    // OPERATOR 3
    // OPERATOR 3
    
    case 48://OP3 Volume
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_2, OPA_OP_VOLUME, val*2);
      break;
    
    case 49://OP3 Coarse
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_2, OPA_OP_COARSE, val*2);
      break;
      
    case 50://OP3 Fine
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_2, OPA_OP_FINE, val*2);
      break;
      
    case 51://OP3 Attack
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_2, OPA_OP_ENVATTACK, val*2);
      break;
      
    case 52://OP3 Decay
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_2, OPA_OP_ENVDECAY, val*2);
      break;
      
    case 53://OP3 Sustain
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_2, OPA_OP_ENVSUSTAINLEVEL, val*2);
      break;
      
    case 54://OP3 Init.lvl
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_2, OPA_OP_ENVINITLEVEL, val*2);
      break;
      
    case 55://OP3 Release
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_2, OPA_OP_ENVRELEASE, val*2);
      break;
      
    case 56://OP3 LFO Speed
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_2, OPA_OP_LFOSPEED, val*2);
      break;
      
    case 57://OP3 LFO Amnt
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_2, OPA_OP_LFOAMOUNT, val*2);
      break;
    
    // OPERATOR 4
    // OPERATOR 4
    // OPERATOR 4
    case 64://OP4 Volume
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_3, OPA_OP_VOLUME, val*2);
      break;
    
    case 65://OP4 Coarse
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_3, OPA_OP_COARSE, val*2);
      break;
      
    case 66://OP4 Fine
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_3, OPA_OP_FINE, val*2);
      break;
      
    case 67://OP4 Attack
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_3, OPA_OP_ENVATTACK, val*2);
      break;
      
    case 68://OP4 Decay
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_3, OPA_OP_ENVDECAY, val*2);
      break;
      
    case 69://OP4 Sustain
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_3, OPA_OP_ENVSUSTAINLEVEL, val*2);
      break;
      
    case 70://OP4 Init.lvl
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_3, OPA_OP_ENVINITLEVEL, val*2);
      break;
      
    case 71://OP4 Release
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_3, OPA_OP_ENVRELEASE, val*2);
      break;
      
    case 72://OP4 LFO Speed
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_3, OPA_OP_LFOSPEED, val*2);
      break;
      
    case 73://OP4 LFO Amnt
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_3, OPA_OP_LFOAMOUNT, val*2);
      break;
    
    case 74://OP4 OPA_OP_FEEDBACK (not too sure about this one)
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_3, OPA_OP_FEEDBACK, val*2);//[0-254]
      break;
    
    case 75://OP4 OPA_OP_FLAGS (i'm not sure about the range of this one)
      opa.writeOperatorParam(OPA_PROGRAM, OPA_OPERATOR_3, OPA_OP_FLAGS, val);//?
      break;
    
    default:
      Serial.print("CCNOMAP#0x");
      Serial.print(num, HEX);
      Serial.print(" VAL:0x");
      Serial.println(val, HEX);
      break;  
  }
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

byte midichannel=0;

void loop() {
  midiEventPacket_t rx;
  do {
 
    rx = MidiUSB.read();
    if (rx.header != 0) {
      byte msg=rx.byte1;
      midichannel=rx.byte1 & 0x0f;
      byte program=midichannel;
      switch(rx.header){
        
        case 8://NOTE OFF
          opa.noteOff(program,rx.byte2);
          //Serial.print("NOTE OFF: ");
          //Serial.print(rx.byte2, HEX);
          //Serial.print("CHN: ");
          //Serial.println(midichannel, HEX);
          break;
        
        case 9:
          opa.noteOn(program,rx.byte2);
          //Serial.print("NOTE ON: ");
          //Serial.print(rx.byte2, HEX);
          //Serial.print(" - VELOCITY: ");
          //Serial.print(rx.byte3, HEX);
          //Serial.print(" - CHN: ");
          //Serial.println(midichannel, HEX);
          
          break;

        case 11://'Control change'
          Serial.print("CC: ");
          Serial.print("CC#");
          Serial.print(rx.byte2, HEX);
          Serial.print(" VAL:");
          Serial.println(rx.byte3, HEX);
          ccParam(rx.byte2,rx.byte3);
          break;
        
        case 12://'Program change' (104 user programs apparently)
          Serial.print("PRG: ");
          Serial.print(rx.byte2, HEX);
          opa.loadInternal(midichannel,rx.byte2);
          break;
        
        
        case 0xe://'Pitch wheel'
          Serial.print("PITCH");
          //pitchBend(program, int8_t coarse, int8_t fine);
          break;
        
        default:
          /*
          Serial.print("Received: ");
          Serial.print(rx.header, HEX);
          Serial.print("-");
          Serial.print(rx.byte1, HEX);
          Serial.print("-");
          Serial.print(rx.byte2, HEX);
          Serial.print("-");
          Serial.println(rx.byte3, HEX);
          */
          break;
          
      }
    }
  } while (rx.header != 0);
}
