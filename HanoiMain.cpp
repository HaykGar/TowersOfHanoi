// Tower of Hanoi

#include <iostream>
#include "Disk.h"
#include "Puzzle.h"


int main() 
{
	int x;
	std::cout << "enter the number of disks\n";
	std::cin >> x;

	Puzzle p(x);

	p.Print();
	p.Solve();
	p.Print();

	p.~Puzzle();
}