void HTTP_init(void) {

  HTTP.on("/motor1", handle_motor1);    // при запросе на мотор1 выполняем функ motor1Pover 
 
  HTTP.begin();
}



// Установка мощности 1 мотора по запросу вида http://192.168.0.101/motor1?value=199
void handle_motor1() {
  motor1Pover = HTTP.arg("value").toInt(); // Получаем значение из запроса сохраняем в глобальной переменной
  HTTP.send(200, "text/plain", "OK"); // отправляем ответ о выполнении
  Serial.print(motor1Pover);
}
