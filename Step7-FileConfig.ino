
#include <ESP8266WiFi.h>        //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step1-wifi
#include <ESP8266WebServer.h>   //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step2-webserver
#include <FS.h>                 //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step4-fswebserver

#include <ArduinoJson.h>        //Установить из менеджера библиотек.
IPAddress apIP(192, 168, 4, 1);

// Web интерфейс для устройства
ESP8266WebServer HTTP(80);
// Для файловой системы
File fsUploadFile;

// Определяем переменные wifi
String _ssid     = "home"; // Для хранения SSID
String _password = "i12345678"; // Для хранения пароля сети
String _ssidAP = "WiFi";   // SSID AP точки доступа
String _passwordAP = ""; // пароль точки доступа
int motor1Pover = 0;


void setup() {
  Serial.begin(115200);
  Serial.println("");
  //Запускаем файловую систему
  Serial.println("Start 4-FS");
  FS_init();
  Serial.println("Start 1-WIFI");
  //Запускаем WIFI
  //Настраиваем и запускаем HTTP интерфейс
  Serial.println("Start 2-WebServer");
  HTTP_init();

}

void loop() {
  HTTP.handleClient();
  delay(1);
}
