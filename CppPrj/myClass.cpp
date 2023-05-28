#include "myClass.h"
#include <iostream>

//this is where we define the variable.
int myClass::count = 0;

myClass::myClass()
	: member{0}
{
	count++;
	std::cout << "count is now: " << count << std::endl;
}

myClass::~myClass()
{
	count--;
	std::cout << "count is now: " << count << std::endl;
}

int myClass::GetCount()
{
	return count;
}
