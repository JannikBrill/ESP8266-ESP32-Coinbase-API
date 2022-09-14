#ifndef COINBASEAPI_H
#define COINBASEAPI_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

class CoinbaseAPI
{
	private:
		HTTPClient sender;
		WiFiClientSecure client;
		char* currency;
		String Base;
		String Currency;
		double Amount;
	
	public:
		CoinbaseAPI(char* currency);
		void LoadValue(char* coin);
		String get_Base();
		String get_Currency();
		double get_Amount();
};
#endif
