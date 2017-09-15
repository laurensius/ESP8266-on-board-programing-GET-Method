#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "863 Studio - Office";
const char* password = "8cadb11f56";
 
void setup () {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Setting ESP8266");
  delay(1000);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Menghubungkang ke Access Point..");
    delay(2000);
  }
}
 
void loop() {
  if(Serial.available()){
    String incoming = Serial.readString();
    if (WiFi.status() == WL_CONNECTED) { 
      HTTPClient http;  
      http.begin(incoming);  
      int httpCode = http.GET();                                                       
      if (httpCode > 0) { 
        String payload = http.getString();
        String response = (String)httpCode + "*_*" + payload ; 
        Serial.println(response); 
      }
      http.end();   
    }else{
      Serial.println("ESP8266 tidak terhubung ke Access Point");
    }
  }else{
    Serial.println("Menunggu paket data untuk dikirim ke server . . . .");
  }
  delay(1000);
}
