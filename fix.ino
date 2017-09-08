#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "863 Studio - Office";
const char* password = "8cadb11f56";
 
void setup () {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting..");
  }
}
 
void loop() {
  if(Serial.available()){
    String server = "http://192.168.0.101/lampu/index.php";
    String incoming = Serial.readString();
    String kirim = server + incoming;
    if (WiFi.status() == WL_CONNECTED) { 
      HTTPClient http;  
      http.begin(kirim);  
      int httpCode = http.GET();                                                       
      if (httpCode > 0) { 
        String payload = http.getString();  
        Serial.println(payload);  
      }
      http.end();   
    }
  }else{
    Serial.println("Nothing");
  }delay(1000);
}
