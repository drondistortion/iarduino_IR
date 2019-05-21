// Библиотека iarduino_IR для работы с ИК приёмопередатчиками разработана     http://iarduino.ru
// Для считывания данных с ИК-пульта предлагаем воспользоваться ИК-приёмником http://iarduino.ru/shop/Sensory-Datchiki/ik-priemnik-trema-modul.html

// ПРИМЕР РЕАГИРУЕТ НА УДЕРЖАНИЕ КНОПКИ ЛЮБОГО ПУЛЬТА

#include <iarduino_IR_RX.h>                      // Подключаем библиотеку для работы с ИК-приёмником
iarduino_IR_RX IR(7);                            // Объявляем объект IR, с указанием вывода к которому подключён ИК-приёмник
void setup(){
  Serial.begin(9600);                            // Инициируем передачу данных в монитор последовательного порта, на скорости 9600 бит/сек
  IR.begin();                                    // Инициируем работу с ИК-приёмником
}
void loop(){
  if(IR.check(true)){                            // Если в буфере имеются данные, принятые с пульта (удерживается кнопка)
    Serial.println(IR.data, HEX);                // Выводим код нажатой кнопки
    Serial.println(IR.length   );                // Выводим количество бит в коде
  }
}
