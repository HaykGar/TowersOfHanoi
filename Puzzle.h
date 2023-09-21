#ifndef Tower_Header
#define Puzzle_Header

#include<vector>
#include <iostream>
#include "Disk.h"

class Puzzle {
private:
	int nDisks;
	std::vector <Disk*> towers[3];	// 3 vectors, one for each stack
	static constexpr int BEGIN_STACK = 0;
	static constexpr int END_STACK = 2;

	void MoveOne(int startStack, int destStack);
	void MoveN(int startStack, int destStack, int n);
	
public:
	Puzzle(int n);
	~Puzzle();
	void Print() const;
	void Solve();
};







#endif