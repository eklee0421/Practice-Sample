/*////////////////////////////////////////////////////////////////////////////////////////
7개의 LED를 갖는 LEDs 라는 unsigned char 변수에 이진수 00000001을 대입하면, 0번째 LED 가 켜지고,
이진수 00000010 을 대입하면 1번째 LED 가 켜지고, … 이진수 1000000을 대입하면 7번째 LED 가 켜지는 변수 LEDs 를 가정하자.
- unsigned char LEDs;
- LEDs=0x01;
- LEDs=0x02;

0부터 7까지 숫자를 입력받아서, LEDs 값을 다음과 같이 바꾸어주는 함수를 작성하시오.
//////////////////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>

int LED_function(int input) {
	
	unsigned char LEDs = 0;
	for (int i = 0; i < input; i++) {
		LEDs += 0x01;
	}
	return LEDs;
}

int main() {

	for (int i = 1; i <= 7; i++) {
		int return_value;
		return_value = LED_function(i);
		printf("return_value: %d\n", return_value);
	}

}

/*///////////////////////////////////////////////////////
output:
return_value: 1
return_value: 2
return_value: 3
return_value: 4
return_value: 5
return_value: 6
return_value: 7
////////////////////////////////////////////////////////*/
