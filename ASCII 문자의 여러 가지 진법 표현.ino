//아스키 코드 값을 2진, 8진, 10진, 16진 숫자로 표현하는 

void setup() {
  Serial.begin(9600); //시리얼 통신 초기화
  Serial.println("ASCII Table");
  Serial.println("CH\tDEC\tOCT\tHEX\tBIN");
 }
 
 void loop() {
  for(int i = 33; i<= 40; i++){
    Serial.write(i);  //2진 숫자로 전송
    Serial.print("\t" + Srting(i, DEC));  //10진 문자열로 변경하여 전송
    Serial.print("\t" + String(i, OCT));  //8진 문자열로 변경하여 전송
    Serial.print("\t" + String(i, HEX));  //16진 문자열로 변경하여 전송
    Serial.print("\t" + String(i, BIN));  //2진 문자열로 변경하여 전송
  }
}
  
  while(1);
}
