#pragma once
#include <vector>
#include <iostream>
#include "Defination.h"

UTILITY_API std::vector<int> generateRandomNumbers(int numberOfNumbers);
UTILITY_API void sortVector(std::vector<int>& vectorToSort);

template<typename T>
void printVector(const std::vector<T>& vectorToPrint);

template<typename T>
void printMsg(T msg, bool newLine);

template<typename... Others>
std::string sum(std::string argOne, Others... others);

template<typename T>
T sum(T t);

template<typename ArgOne, typename... Others>
ArgOne sum(ArgOne argOne, Others... others);

#include "utility.inl"

//make another visual studio solution.