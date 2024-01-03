#ifndef dice_h
#define dice_h

class Dice {
	int dice[5];
	int count;
public:
	int* ReturnDice();
	void RollDice();
	void ShowDice();
	void TakeDice();
	void reRoll(int a);
};

#endif // !dice_h
