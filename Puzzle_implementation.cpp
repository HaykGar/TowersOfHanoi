// implementations

#include "Puzzle.h"



Puzzle::Puzzle(int n) 
{
	if (n > 0)
		nDisks = n;
	else
		throw std::invalid_argument("received negative value");

	for (int i = n; i > 0; i--) 
	{
		towers[0].push_back(new Disk(i));
	}
}

Puzzle::~Puzzle() 
{
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < (int) towers[i].size(); j++) {
			if (towers[i].at(j) != nullptr)
				delete towers[i].at(j);
		}
	}
}

void Puzzle::Print() const 
{
	for (int stack = 0; stack < 3; stack++) 
	{
		std::cout << "Tower " << stack + 1 << ":\n\n";
		for (int i = nDisks - 1; i >= 0; i--) 
		{
			if (i > (int) towers[stack].size() - 1)
				std::cout << "|\n";
			else
				towers[stack].at(i)->Print();
		}
		std::cout << std::endl;
	}
	std::cout << "**********************************************************\n";
}

void Puzzle::MoveOne(int startStack, int destStack)
{
	if (startStack == destStack || startStack < 0 || startStack >= 3 || destStack < 0 || destStack >= 3)
	{
		std::cerr << "you messed up\n";
		exit(1);
	}
	else if (towers[startStack].size() == 0)
		return;
	else 
	{
		towers[destStack].push_back(towers[startStack].at(towers[startStack].size() - 1)); // append last element of start stack to dest stack
		towers[startStack].pop_back();	//get rid of disk from original tower
		//std::cout << "tower " << startStack + 1 << " to " << destStack + 1 << std::endl; //showing steps
		Print();
		std::cout << std::endl << std::endl;
	}
}

void Puzzle::MoveN(int startStack, int destStack, int n) 
{
	if (startStack == destStack || startStack < 0 || startStack >= 3 || destStack < 0 || destStack >= 3 || n > towers[startStack].size() || n < 0)
	{
		std::cerr << "you messed up\n";
		exit(1);
	}

	if (n == 0)
		return;
	else if (n == 1) 
	{
		MoveOne(startStack, destStack);
		return;
	}	
	else
	{
		int extraStack = 3 - startStack - destStack;

		MoveN(startStack, extraStack, n - 1);
		MoveOne(startStack, destStack);
		MoveN(extraStack, destStack, n - 1);
		return;
	}
}

void Puzzle::Solve() 
{
	MoveN(BEGIN_STACK, END_STACK, nDisks);
}