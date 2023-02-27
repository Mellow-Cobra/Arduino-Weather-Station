#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipeIn = 0xE8E8F0F0E1LL;

RF24 radio(7, 8); // CE, CSN create radio object from RF24 class
struct MyData{
  byte h;
  byte t;
  byte m;
};
MyData data;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_1MBPS);
  radio.openReadingPipe(1, pipeIn);
  radio.startListening();
  
}
void recvData(){
  if(radio.available()){
    radio.read(&data, sizeof(MyData));
  }
}

void loop() {  
  recvData();
  Serial.println(data.h);
  delay(1000);
  Serial.println(data.t);
  delay(1000);
  Serial.println(data.m);
  
}
