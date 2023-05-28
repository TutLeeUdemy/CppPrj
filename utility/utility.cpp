#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <limits>
#include <sstream>
#include <random>
#include "utility.h"



//creates a function called printHelloWorld.
void printHelloWorld()
{
	//body of the function
	printMsg("hello world!", true);
}

//a defination of a function.
std::vector<int> generateRandomNumbers(int numberOfNumbers)
{
	std::vector<int> randomNumbers;

	std::srand(std::time(nullptr));

	for (int i = 0; i < numberOfNumbers; ++i)
	{
		int number = std::rand() % 100 - 50;
		randomNumbers.push_back(number);
	}

	return randomNumbers;
}

//make another function here, that takes an std::vector<int> as an argument, and returns a sorted std::vector<int>.
//& means taking the argument as a reference. 
//not having & means pass by value/copy, with & means pass by reference.
//does alter the argument. a missing const ussually indicates that the variable will be altered.
//modifier.
void sortVector(std::vector<int>& vectorToSort)
{
	for (int i = 0; i < vectorToSort.size(); ++i)
	{
		for (int j = i + 1; j < vectorToSort.size(); ++j)
		{
			if (vectorToSort[i] > vectorToSort[j])
			{
				std::swap(vectorToSort[i], vectorToSort[j]);
			}
		}
	}
}

std::string sum(std::string t)
{
	return t;
}

