//아두이노 우노는 아날로그 데이터를 입력만 받을 수 있다

int readPrevious = 0;
int readCurrent = 0;

void setup() {
  Serail.begin(9600); //시리얼 포트 초기화
}

void loop() {
  String echoStr;
  readCurrent = analogRead(A0); //ADC를 통한 아날로그 값 입력
  
  if(readCurrent != readPrevious) { //이전 값과 달라진 경우만 출력
    readPrevious = readCurre nt;  //이전 값 갱신
    
    echoStr = "Current analog input : " + String(readCurrent);
    
    serial.println(echoStr);  //시리얼 모니터로 현재 가변 저항 값 출력
    }
}
