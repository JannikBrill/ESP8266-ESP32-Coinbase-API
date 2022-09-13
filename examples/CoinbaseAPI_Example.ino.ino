/*  You have to install!
 *  Arduino Json
 *  ESP8266 Board testet (NodeMcu0.9 ESP12-Module)!
 *  
 *  Created by Jannik Brill September,2022
 */

#include <CoinbaseAPI.h>

char ssid[] = "BrillHouse";
char password[] = "27072017";

CoinbaseAPI coin("EUR");

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  coin.LoadValue("BTC");
  Serial.print(coin.get_Base());
  Serial.print(" : ");
  Serial.print(coin.get_Amount());
  Serial.print(" ");
  Serial.println(coin.get_Currency());
  delay(1000);
}
