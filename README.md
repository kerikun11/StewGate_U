# StewGate_U

Twitter Tweeting Library via [StewGate U](http://stewgate-u.appspot.com/) for [Arduino core for the ESP32](https://github.com/espressif/arduino-esp32)

## example

~~~cpp
#include <Arduino.h>

#include "StewGate_U.h"

// Put StewGate U Token
const std::string token = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

// object
StewGate_U sg(token);

void setup() {
  // put your setup code here, to run once:
  WiFi.begin("WiFi-2.4GHz", "psk");
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    log_e("WiFi Error");
    vTaskDelay(portMAX_DELAY);
  }

  sg.tweet("Hello, from M5Stack!");
}

void loop() {
  // put your main code here, to run repeatedly:
}
~~~
