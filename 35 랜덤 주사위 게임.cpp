/****************************************************

[게임 규칙]

주사위 2개를 처음 던져서 더한 합이

7이나 11 이면 승리

2, 3, 12이면 패배


만약 위의 숫자 외의 숫자가 나왔다면 주사위를 다시 던진다

이때 합이 처음 숫자와 동일하다면 플레이어의 승리,

7이라면 패배한다


승리나 패배를 할 때까지 주사위를 계속 던진다

****************************************************/

#include <iostream>
#include <ctime>
using namespace std;

int rollDice();

int main() {

	enum Status {CONTINUE, WON, LOST};
	srand(static_cast<unsigned int>(time(0)));

	int myPoint = 0;

	Status game = CONTINUE;
	
	int sumOfDice = rollDice();

	switch (sumOfDice) {
	case 7:
	case 11:
		game = WON;
		break;
	case 2: 
	case 3:
	case 12:
		game = LOST;
		break;
	default:
		game = CONTINUE;
		myPoint = sumOfDice;
		cout << "MY point: " << myPoint << endl;
		break;
	}

	while (game == CONTINUE)
	{
		sumOfDice = rollDice();
		if (sumOfDice == myPoint) {
			game = WON;
		}
		else {
			if (sumOfDice == 7)
				game = LOST;
		}

	}

	if (game == WON) {
		cout << "\nPlayer Won!" << endl;
	}
	else {
		cout << "\nPlayer Lost" << endl;
	}
}

int rollDice() {
	int num1 = rand() % 6 + 1;
	int num2 = rand()% 6 + 1;
	cout << "Player: " << num1 << " + "<< num2 << " = " << num1+num2 << endl ;
	return num1 + num2;
}
