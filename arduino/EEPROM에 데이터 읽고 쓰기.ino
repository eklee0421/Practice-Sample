#include <EEPROM.h> // 라이브러리 가져오기 메뉴를 이용하면 자동 추가된다

int address = 10; //EEPROM 주소
int value = 100;  // EEPROM에 기록할 값

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("EEPROM Write: " + String(value));
  EEPROM.write(address, value); //EEPROM에 쓰기
  
  Serial.print("EEPROM Read: ");
  int inMemory = EEPROM.read(address);  //EEPROM에서 읽기
  Serial.println(inMemory);
  
  while(true);
 
  }
