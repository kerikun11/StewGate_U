#pragma once

#include <WiFi.h>
#include <WiFiClient.h>
#include <esp32-hal-log.h>
#include <string>

class StewGate_U {
public:
  static constexpr const char *hostname = "stewgate-u.appspot.com";
  static constexpr const int port = 80;

public:
  StewGate_U(std::string token) : token(token) {}

  bool tweet(std::string msg) {
    log_d("connecting to %s", hostname);
    WiFiClient client;
    if (!client.connect(hostname, port)) {
      log_e("server connection failed");
      return false;
    }

    log_d("Post Message: %s", msg.c_str());
    // HTTP header
    client.println("POST /api/post/ HTTP/1.0");
    client.print("Host: ");
    client.println(hostname);
    int msgLength = 40;
    msgLength += msg.length();
    client.print("Content-length:");
    client.println(msgLength);
    client.println("");
    // HTTP content
    client.print("_t=");
    client.print(token.c_str());
    client.print("&msg=");
    client.println(msg.c_str());

    // wait for response
    while (client.available()) {
      String line = client.readStringUntil('\r');
      log_v(line);
    }

    // HTTP end
    client.stop();
    return true;
  }

private:
  std::string token;
};
