#include <vector>
#include <memory>
#include "utility.h"
#include "../myClass.h"

int main()
{
	myClass mc1;
	myClass mc2;
	std::cout << myClass::GetCount() << std::endl;
}

//how do you fix this problem????
//in the default setting we are copying just the memory address, this is called a shallow copy.
//how to make it a deep copy, learn a concept the copy constructor, learn how to define it on your own.

//use the move constructor. indicates a transfer of onwership.

//you need to define your own copy assignment operator. what = means when you do a = b?

//override the +, -, /, *, % operator for our DynamicInt class.