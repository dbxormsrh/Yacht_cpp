#ifndef ScoreBoard_h
#define ScoreBoard_h

#include"Rules.h"


class ScoreBoard {
	string pn;
public:
	ScoreBoard();

	int board[12]; //점수판

	bool inputScore(int a, int dice[]);		//점수판에 주사위값을 입력
	void Subtotal();						//서브토탈 점수를 알려줌
	void total();							//토탈 점수를 알려줌
	void showboard(int turn);				//점수판을 출력함
	string getname();						//플레이어의 이름을 리턴함
};
#endif // !ScoreBoard_h
