#include<iostream>
#include<string>
using namespace std;

#include"ScoreBoard.h"
#include"Rules.h"

//점수판기본 설정 및 플레이어 입력
ScoreBoard::ScoreBoard() {
	for (int i = 0; i < 12; i++)
		board[i] = 0;
	cout << "플레이어의 이름을 입력해주세요!" << endl;
	getline(cin, pn);
}

//점수판에 점수를 입력하고, 점수가 입력되있으면 다시 선택하라고 안내.
bool ScoreBoard::inputScore(int a, int dice[]) {
	while (true) {
		if (board[a - 1] == 0) {
			switch (a) {
			case(1):case(2):case(3):case(4):case(5):case(6):
			{for (int i = 0; i < 5; i++) {
				if (dice[i] == a) {
					board[a - 1] += dice[i];
				}
			}
			return true;
			}

			case(7): {for (int i = 0; i < 5; i++)
				board[a - 1] += dice[i];
				return true; }
			case(8): {board[7] = rules::result; return true; }
			case(9): {for (int i = 0; i < 5; i++)
				board[a - 1] += dice[i]; return true; }
			case(10):case(11): {board[a - 1] = 30; return true; }
			case(12): {board[a - 1] = 50; return true; }
			case(13):return true;
			}
		}
		else {
			cout << "이미 점수가 입력되어 있습니다! 다른 곳에 점수를 입력하세요!" << endl;
			return false;
		}
	}
	return 0;
}

//subtotal점수를 알려줌
void ScoreBoard::Subtotal() {
	int st = 0;
	for (int i = 0; i < 6; i++)
		st += board[i];
	if (st >= 63)
		st += 35;

	cout << "Subtotal : " << st << endl;
}

//total 점수를 알려줌
void ScoreBoard::total() {
	int st = 0, t = 0;

	for (int i = 0; i < 6; i++)
		st += board[i];
	for (int i = 0; i < 12; i++)
		t += board[i];
	if (st >= 63)
		t += 35;

	cout << "Total  : " << t << endl << endl << endl;

}

//점수판 출력함
void ScoreBoard::showboard(int turn) {
	cout << "Turn : " << turn << "/12" << endl << "(1) Aces   : " << board[0] << endl << "(2) Deuces : " << board[1] << endl << "(3) Threes : " << board[2] << endl << "(4) Fours  : " << board[3]
		<< endl << "(5) Fives  : " << board[4] << endl << "(6) Sixes  : " << board[5] << endl;
	Subtotal();
	cout << "******************************************" << endl;
	cout << "(7) Choice : " << board[6] << endl << "(8) 4 of kind : " << board[7] << endl << "(9) Full House : " << board[8] << endl << "(10) S.Straight : " << board[9]
		<< endl << "(11) L.Straight : " << board[10] << endl << "(12) Yachu : " << board[11] << endl << "(13) 생략" << endl;
	total();
}

//플레이어 이름 리턴
string ScoreBoard::getname() {
	return pn;
}
