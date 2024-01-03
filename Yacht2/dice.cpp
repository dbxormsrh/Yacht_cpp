#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

#include "dice.h"


void Dice::RollDice() {
	for (int i = 0; i < 5; i++) {
		dice[i] = rand() % 6 + 1;
	}
}

void Dice::reRoll(int a) {
	if(a<6&&a>0)
		dice[a-1] = rand() % 6 + 1;
}

int* Dice::ReturnDice() {
	return dice;
}

void Dice::ShowDice() {
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ")  "<<dice[i]<<"  ";
    }
	cout << endl;
}

void Dice::TakeDice() {
	int a[5] = { NULL };
	int n;
	count = 0;
	string answer;
	RollDice();
	ShowDice();
	
	while (count<2) {
		answer = "";
		cout << "주사위 숫자를 바꾸시겠어요?(y / n)" << endl;
		cin >> answer;
		if (answer == "y") {
			cout << "몇 개의 주사위 값을 바꾸시겠어요?" << endl;
			cin >> n;
			if (n <= 5 && n >= 1) {
				cout << endl << "바꾸길 원하는 주사위 위치를 입력해주세요!" << endl;
				for (int i = 0; i < n; i++)
					cin >> a[i];
				for (int i = 0; i < n; i++)
					reRoll(a[i]);
				ShowDice();
				count++;
			}
			else if (n == 0)
				break;
			else
				cout << "1~5사이의 숫자를 입력해주세요!" << endl;
		}
		else if (answer == "n")
			break;
		else
			cout << "y나 n중 하나를 입력해주세요!" << endl;
	}
	
}

