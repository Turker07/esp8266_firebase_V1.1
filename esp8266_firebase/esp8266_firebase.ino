
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>




//1. Change the following info
#define WIFI_SSID "wifi_name"
#define WIFI_PASSWORD "wifi_password"

#define FIREBASE_HOST "https://example.firebaseio.com/"
#define FIREBASE_AUTH "firabase_auth"


FirebaseData fbdo;

void setup()
{

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();



  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

 
  Firebase.reconnectWiFi(true);

  
}
  void loop()
  {



  
  if(Firebase.setInt(fbdo, "data1", data1))
  {
    //Success
     Serial.println("Set int data success");

  }
  else{
    
    Serial.print("Error in setInt, ");
    Serial.println(fbdo.errorReason());
  }
if(Firebase.setInt(fbdo, "data2", data2))
  {
    //Success
     Serial.println("Set int data success");

  }else{
    

    Serial.print("Error in setInt, ");
    Serial.println(fbdo.errorReason());
  }


  
  if(Firebase.getInt(fbdo, "/LED_Status"))
  {
   
    Serial.print("Get int data success, int = ");
    Serial.println(fbdo.intData());

  }else{
    

    Serial.print("Error in getInt, ");
    Serial.println(fbdo.errorReason());
  }


 if(Firebase.get(fbdo, "/LED_Status"))
  {
    //Success
    Serial.print("Get variant data success, type = ");
    Serial.println(fbdo.dataType());

    if(fbdo.dataType() == "int"){
      Serial.print("data = ");
      Serial.println(fbdo.intData());
    }else if(fbdo.dataType() == "bool"){
      if(fbdo.boolData())
        Serial.println("data = true");
      else
        Serial.println("data = false");
    }

  }else{
    //Failed?, get the error reason from fbdo

    Serial.print("Error in get, ");
    Serial.println(fbdo.errorReason());
  }








  
}
