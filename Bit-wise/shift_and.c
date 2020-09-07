#pragma warning(disable: 4996) 
#include <stdio.h>

int main() {

	unsigned char LEDs = 0;
	scanf_s("%uc", &LEDs);

	int cnt = 0;
	unsigned char u = 0x01;
	unsigned char s = 0x00;

	for (int i = 0; i < 8; i++) {
		if (LEDs & u) {
			s = s >> 1;
			s += 0x80;
			cnt++;
		}
		u = u << 1;
	}

	printf("1의 개수: %d\n", cnt);
	printf("shift의 값은?: %d\n", s);
}
