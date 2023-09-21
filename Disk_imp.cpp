#include "Disk.h"

Disk::Disk(int s) 
{
	size = s;
	for (int i = 0; i < s; i++)
		disk += '_';
}