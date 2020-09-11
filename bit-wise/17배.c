#pragma warning(disable: 4996) 
#include <stdio.h>
#include <stdlib.h>

int main() {

	while (1) {

		int n = 0;	//입력 받은 값
		scanf("%d", &n);

		if (!n) { break; }

		int t = n;
		t = t << 4;
		n += t;

		printf("%d\n", n);
	}
	
}

