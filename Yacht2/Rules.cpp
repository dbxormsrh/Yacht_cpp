#include<iostream>
#include<string>
using namespace std;

#include"Rules.h"
#include"ScoreBoard.h"

int rules::result = 0;

//처음 시작할 때 게임 규칙을 설명
rules::rules() {
	cout << "Yachu 게임규칙을 설명합니다!" << endl << "첫번째 : 주사위를 굴립니다!" << endl << "두번째 : 점수판을 채웁니다!" << endl;
	cout << "세번째 : 상대보다 높은 점수를 얻고 게임에서 승리합니다!" << endl<<endl<<endl<<endl;
}

//주사위 값을 입력받아서 해당 항목이 가능한지 판단
bool rules::judge(int l, int dice[], ScoreBoard& a) {
	int c[6] = { 0 };
	int x = 0;
	for (int i = 0; i < 5; i++) {
		switch (dice[i]) {
		case (1):c[0]++; break;
		case (2):c[1]++; break;
		case (3):c[2]++; break;
		case (4):c[3]++; break;
		case (5):c[4]++; break;
		case (6):c[5]++; break;
		}
	}

	for (int i = 0; i < 6; i++) {
		if (c[i] != 0)
			x++;
	}

	if (a.board[l - 1] == 0) {
		switch (l) {
		case(1):case(2):case(3):case(4):case(5):case(6):case(7):return true;
		case(8):if (rules::FofKind(c, x)) {
			rules::result = rules::FofK(c); return true;
		}
			   else return false;
		case(9):if (rules::F_House(c, x)) return true; else return false;
		case(10):if (rules::S_Straight(c, x)) return true; else return false;
		case(11):if (rules::L_Straight(c, x)) return true; else return false;
		case(12):if (rules::Yacht(c, x)) return true; else return false;
		}
	}
	else return false;
}

bool rules::FofKind(int a[], int b) {
	if (b == 2)
		for (int i = 0; i < 6; i++) {
			if (a[i] == 4) return true;
		}
	else return false;
}

bool rules::F_House(int a[], int b) {
	if (b == 2)
		for (int i = 0; i < 6; i++) {
			if (a[i] == 3 || a[i]==2) {
				for (int j = 0; j < 6; j++)
					if (a[j] == 2 || a[j]==3)
						return true;
					else return false;
			}
		}
	else return false;
}

bool rules::S_Straight(int a[], int b) {
	if (b == 5 && a[5] == 0)
		for (int i = 0; i < 6; i++) {
			if (a[i] == 4) return true;
		}
	else return false;
}

bool rules::L_Straight(int a[], int b) {
	if (a[0] == 0 && b == 5)
		return true;
	else return false;
}

bool rules::Yacht(int a[], int b) {
	if (b == 1)
		return true;
	else return false;
}

int rules::FofK(int a[]) {
	for (int i = 0; i < 6; i++)
		if (a[i] == 4)
			return (i+1) * 4;
	return 0;
}