#include <WiFi.h>
#include <esp_now.h>

#define LAMP_PIN 2

typedef struct {
  int command;
} GestureData;

GestureData receivedData;

void onReceive(const esp_now_recv_info_t *info,
               const uint8_t *incomingData,
               int len) {

  memcpy(&receivedData, incomingData, sizeof(receivedData));

  Serial.print("Received Command: ");
  Serial.println(receivedData.command);

  switch(receivedData.command) {

    case 1:
      digitalWrite(LAMP_PIN, HIGH);
      Serial.println("Lamp ON");
      break;

    case 2:
      digitalWrite(LAMP_PIN, LOW);
      Serial.println("Lamp OFF");
      break;

    case 3:
      Serial.println("Brightness Up");
      break;

    case 4:
      Serial.println("Brightness Down");
      break;
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(LAMP_PIN, OUTPUT);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Init Failed");
    return;
  }

  esp_now_register_recv_cb(onReceive);

  Serial.println("Receiver Ready");
}

void loop() {

}
