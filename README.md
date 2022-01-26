## esp8266_firebase_V1.1
IOT

Wifi modülleri ile iot cihazları ortaya çıkarılabilir. 
Iot cihazları ile veriler local veya global sunuculara aktarılabilir veya cihazlar yönetilebilir. 
Iot cihazların local de kullanılması gerekli yerlerde ihtiyaç olsa da benim tercihim  global de kullanmak. 

### Veri Tabanı 
Veritabanları verilerin depolandığı veya kontrol ediliği ortamdım. ıot cihazları da  istenilen verileri veritabanına gönderir veya kontrol edilmek istenen
verileri veritanından çekebilmektedir.

### Firebase
Firabase; güveniir, erişilebilir, kolay kullanımı ve belirli süre ücretsiz kullanımı olan bir veritabanıdır. 

### Detaylar

Wifi modülü olarak esp8266 modülü kullanılmıştır ve arduino IDE ile programlanmıştır. 

##### Kodlar

Esp8266 ve firabese veritabanı için kütüphaneleri ekliyoruz. 

`#include "FirebaseESP8266.h"` 

`#include <ESP8266WiFi.h>
`

Bağlanmak istenilen wifi ismini ve şifresini ekliyoruz. 

`
#define WIFI_SSID "wifi_name" `

`#define WIFI_PASSWORD "wifi_password" 
`

Firebase bağlanmak için host ve auth değerlerini girmek gereklidir. 
Bu değerleri oluşturulan firebase kullanıcı realtime database ekranından çekmek gereklidir. Bu kısım en önemli kısımdır. yanlış yazılması halinde iletişim kurulamaz.

`
#define FIREBASE_HOST "https://example.firebaseio.com/" `

`
#define FIREBASE_AUTH "firabase_auth"`


firebase host ve auth değerlerine göre bağlanılmaya çalışır eğer doğru ise işlemleri yapmaya geçilebilir. 

 `Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);`
 

 `
  Firebase.reconnectWiFi(true);`
  
  Evet buraya kadar firebase ile başarılı bir iletişim kurulduysa veriler gönderme işlemlerine geçilebilir. 
  Firebase kütüphanesi içerisinde bulunan setInt fonksinonu ile istenilen değerler database gönderilebilir. 
  örnek olarak data1 değeri data1'e aktarılmıştır. 
  ````````
   if(Firebase.setInt(fbdo, "data1", data1))
  {
    
     Serial.println("Set int data success");

  }
  else{
    
    Serial.print("Error in setInt, ");
    Serial.println(fbdo.errorReason());
  }
  ````````
  Verileri gönderme işleminden sonra verileri database den çekme kısmı.
  
  Daha önceden firabase database'i oluşturulan  /LED_Status int değerini çekilebilir. 
  Böylece çekilen değere göre kontrol edilebilir. 
  
  ````````
    if(Firebase.getInt(fbdo, "/LED_Status"))
  {
   
    Serial.print("Get int data success, int = ");
    Serial.println(fbdo.intData());

  }else{
    

    Serial.print("Error in getInt, ");
    Serial.println(fbdo.errorReason());
  }

  ````````
