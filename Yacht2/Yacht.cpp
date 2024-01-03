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
		cout << fp.getname() << "���� �����Դϴ�! �ֻ����� �����ּ���!" << endl;
		fp.showboard(turn + 1);
		D.TakeDice();
		dice = D.ReturnDice();

		while (true) {
			cout << endl<<"��� �׸� ������ �Է��Ͻðڽ��ϱ�?" << endl;
			fp.showboard(turn + 1);
			cin >> l;
			if (l <= 12 && l >= 1) {
				if (rules::judge(l, dice, fp)) {
					fp.inputScore(l, dice);
					break;
				}
				else
					cout << "�ش��׸񿡴� ������ �� �� �����ϴ�. �ٽ� �������ּ���." << endl;
			}
			else if (l == 13)
				break;
			else
				cout << "*************************************\n   1~13������ ���ڸ� �Է����ּ���!\n*************************************" << endl;
		}

		cout << sp.getname() << "���� �����Դϴ�! �ֻ����� �����ּ���!" << endl;
		sp.showboard(turn + 1);
		D.TakeDice();
		dice = D.ReturnDice();


		while (true) {
			cout << "��� �׸� ������ �Է��Ͻðڽ��ϱ�?" << endl;
			sp.showboard(turn + 1);
			cin >> l;
			if (l <= 12 && l >= 1) {
				if (rules::judge(l, dice, sp)) {
					sp.inputScore(l, dice);
					break;
				}
				else
					cout << "�ش��׸񿡴� ������ �� �� �����ϴ�. �ٽ� �������ּ���." << endl;
			}
			else if (l == 13)
				break;
			else
				cout << "1~13������ ���ڸ� �Է����ּ���!" << endl;
		}
		turn++;
	}
	cout << fp.getname() << "���� ���� ����" << endl;
	fp.showboard(12);
	cout << sp.getname() << "���� ���� ����" << endl;
	sp.showboard(12);
}