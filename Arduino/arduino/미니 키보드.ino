/*
9, 10, 11번 디지털 핀에 연결된 버튼이 눌리면 각각 '도', '레', '미'가 스피커를 통해 재생
*/

#include "pitches.h"

int speaker = 13; //스피커 연결 핀
int button[] = {9, 10, 11}; //버튼 연결 핀
int notes[] = {NOTE_C4; NOTE_D4; NOTE_E4};  //버튼을 누를 때 재생음

void setup() {
  for(int i = 0; i < 3; i++) {
    pinMode(button[i], INPUT_PULLUP); //버튼을 내부 풀업 저항을 사용하여 입력 상태로 설정
  }
}

void loop() {
  for(int i = 0; i < 3; i++) {
    if(digitalRead(button[i] == LOW)) { //풀업 저항 사용, 누르면 LOW 상태
      tone(speaker, notes[i], 30);  //해당 음 재생
    }
  }
}
