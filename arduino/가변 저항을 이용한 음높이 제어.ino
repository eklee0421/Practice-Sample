#include "pitched.h"

int speaker = 13; // 스피커 연결 핀
int notes[] = {0, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};

void setup() {
}

void loop() {
  int volume = analogRead(A0); //볼륨 읽기
  
  int index = map(volume, 0, 1023, 8);  //디지털화된 값을 9 구간으로 나눔
  tone(speaker, notes[index], 30);  //선택된 음 출력
}
