#include <WiFi.h>
#include <esp_now.h>
#include <Wire.h>

#define GESTURE_SENSOR_ADDR 0x73

uint8_t receiverAddress[] = {0x24, 0x6F, 0x28, 0xAA, 0xBB, 0xCC};

typedef struct {
  int command;
} GestureData;

GestureData data;

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  Wire.begin();
  Wire.setClock(400000);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Init Failed");
    return;
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverAddress, 6);

  esp_now_add_peer(&peerInfo);

  Serial.println("Transmitter Ready");
}

int detectGesture() {

  // Simulated gesture detection
  // Replace with PAJ7620 sensor logic

  if (Serial.available()) {
    char c = Serial.read();

    if (c == '1') return 1;
    if (c == '2') return 2;
    if (c == '3') return 3;
    if (c == '4') return 4;
  }

  return 0;
}

void loop() {

  int gesture = detectGesture();

  if (gesture != 0) {

    data.command = gesture;

    esp_now_send(receiverAddress,
                 (uint8_t *)&data,
                 sizeof(data));

    Serial.print("Gesture Sent: ");
    Serial.println(gesture);
  }

  delay(10);
}
