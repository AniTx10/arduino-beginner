#include <IRremote.hpp>
#define IR_RECEIVE_PIN 9
uint32_t cmd;

void setup()
{
  Serial.begin(9600); // // Establish serial communication
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver, IrReceiver precoded as global object
}

void loop() {
  if (IrReceiver.decode()) { // only returns true if IR data is ready
      cmd = IrReceiver.decodedIRData.decodedRawData;
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data (32 bit signal)
      delay(1500);
      IrReceiver.resume(); // Enable receiving of the next value
      if(cmd == 0xBA45FF00){
        Serial.println("power on");
      }
  }
}
