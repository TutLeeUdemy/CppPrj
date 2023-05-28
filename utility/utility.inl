#pragma once
#include<vector>

// impletation:
template<typename T>
void printVector(const std::vector<T>& vectorToPrint)
{
	for (T element : vectorToPrint)
	{
		std::cout << element << " ";
	}
}

template<typename T>
void printMsg(T msg, bool newLine) // the signature of a funciton.
{
	std::cout << msg;
	if (newLine)
	{
		std::cout << std::endl;
	}
}

template<typename... Others>
std::string sum(std::string argOne, Others... others)
{
	return argOne + " " + sum(others...);
}

template<typename T>
T sum(T t)
{
	return t;
}

template<typename ArgOne, typename... Others>
ArgOne sum(ArgOne argOne, Others... others)
{
	return argOne + sum(others...);
}
