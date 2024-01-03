#include<iostream>
#include<string>
#include<time.h>
#include<cstdlib>
using namespace std;

#include"Rules.h"
#include"ScoreBoard.h"
#include"dice.h"

int main() {
	srand((unsigned)time(0));
	rules r;
	ScoreBoard fp, sp;		//first player, second player
	Dice D;
	int l = 0;
	int turn = 0;
	int* dice;

	while (turn < 1) {
		cout << fp.getname() << "님의 차례입니다! 주사위를 굴려주세요!" << endl;
		fp.showboard(turn + 1);
		D.TakeDice();
		dice = D.ReturnDice();

		while (true) {
			cout << endl<<"어느 항목에 점수를 입력하시겠습니까?" << endl;
			fp.showboard(turn + 1);
			cin >> l;
			if (l <= 12 && l >= 1) {
				if (rules::judge(l, dice, fp)) {
					fp.inputScore(l, dice);
					break;
				}
				else
					cout << "해당항목에는 점수가 들어갈 수 없습니다. 다시 선택해주세요." << endl;
			}
			else if (l == 13)
				break;
			else
				cout << "*************************************\n   1~13사이의 숫자를 입력해주세요!\n*************************************" << endl;
		}

		cout << sp.getname() << "님의 차례입니다! 주사위를 굴려주세요!" << endl;
		sp.showboard(turn + 1);
		D.TakeDice();
		dice = D.ReturnDice();


		while (true) {
			cout << "어느 항목에 점수를 입력하시겠습니까?" << endl;
			sp.showboard(turn + 1);
			cin >> l;
			if (l <= 12 && l >= 1) {
				if (rules::judge(l, dice, sp)) {
					sp.inputScore(l, dice);
					break;
				}
				else
					cout << "해당항목에는 점수가 들어갈 수 없습니다. 다시 선택해주세요." << endl;
			}
			else if (l == 13)
				break;
			else
				cout << "1~13사이의 숫자를 입력해주세요!" << endl;
		}
		turn++;
	}
	cout << fp.getname() << "님의 최종 점수" << endl;
	fp.showboard(12);
	cout << sp.getname() << "님의 최종 점수" << endl;
	sp.showboard(12);
}