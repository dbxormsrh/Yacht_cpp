#ifndef ScoreBoard_h
#define ScoreBoard_h

#include"Rules.h"


class ScoreBoard {
	string pn;
public:
	ScoreBoard();

	int board[12]; //������

	bool inputScore(int a, int dice[]);		//�����ǿ� �ֻ������� �Է�
	void Subtotal();						//������Ż ������ �˷���
	void total();							//��Ż ������ �˷���
	void showboard(int turn);				//�������� �����
	string getname();						//�÷��̾��� �̸��� ������
};
#endif // !ScoreBoard_h
