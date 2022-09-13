#include "CoinbaseAPI.h"

CoinbaseAPI::CoinbaseAPI(char* currency){
	this->currency = currency;
}	

void CoinbaseAPI::LoadValue(char* coin){
	client.setInsecure();
	if (sender.begin(client,"https://api.coinbase.com/v2/prices/" + String(coin) + "-" + String(currency) + "/buy")){
		int httpCode = sender.GET(); 
		if (httpCode > 0) {
			if (httpCode == 200) {
				String payload;
				payload = sender.getString();
				DynamicJsonDocument response(1024);
				DeserializationError error = deserializeJson(response, payload);
				if (error)
					return;

				String datata = response["data"]; 
				DynamicJsonDocument response2(1024);
				DeserializationError error2 = deserializeJson(response2, datata);
				if (error2)
					return;
        
				Base = String(response2["base"]);
				Currency = String(response2["currency"]);
				Amount = response2["amount"];
			}else{
				return;
			}	
		}
		sender.end();
	}else {
		return;
	}
}	

String CoinbaseAPI::get_Base(){
	return Base;
}
String CoinbaseAPI::get_Currency(){
	return Currency;
}
double CoinbaseAPI::get_Amount(){
	return Amount;
}