#ifndef Disk_Header
#define Disk_Header

#include <string>
#include <iostream>

class Disk
{
private:
	int size;
	std::string disk;
	//...
public:
	Disk(int s);
	void Print() const { std::cout << disk << std::endl; }
	int GetSize() const { return size;  }
};

#endif