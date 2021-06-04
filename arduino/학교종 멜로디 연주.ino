#include "pitches.h"

int speaker = 8;  //스피커 연결 핀

int melody[] = {  //학교종 멜로디, 0은 쉼표
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4, 0,
  NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, 0,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4, 0,
  NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_C4, 0
};

int noteDuration = 4; //모든 음표는 4분 음표로 통일

void setup() {
}

void loop() {
  for (int thisNote = 0; thisNode < sizeof(melody) / sizeof(int); thisNote++) {
    int noteLength = 1000 / noteDuration; //음표 길이를 시간으로 변환
    tone(speaker, melody[thisNote], noteLength);  //멜로디 재생
    
    // 음표와 음표 사이의 시간 간격 설정
    // 음표 길이에 30%를 더해서 재생
    int pauseBetweenNotes = noteLength * 1.30;
    delay(pauseBetweenNotes);
    noTone(speaker);  //재생 중지
  }
  
  while(1);
}
