#ifndef Rules_h
#define Rules_h

#include"ScoreBoard.h"

class ScoreBoard;

class rules {

public:
	rules();
	static bool judge(int l, int dice[], ScoreBoard& a);	//주사위 값 판단
	static bool FofKind(int a[], int b);					//4 of kind
	static bool F_House(int a[], int b);					//Full House
	static bool S_Straight(int a[], int b);					//Small Straight
	static bool L_Straight(int a[], int b);					//Large Straight
	static bool Yacht(int a[], int b);						//Yacht

	static int result;										//4 of kind 점수값 입력
	static int FofK(int a[]);								//4 of kind 점수값 리턴

	friend ScoreBoard;
};

#endif // !Rules_h
