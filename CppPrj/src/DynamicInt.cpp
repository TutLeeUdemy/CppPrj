#include "DynamicInt.h"
#include <iostream>

DynamicInt::DynamicInt()
	:intPtr{ new int{0} }
{

}

DynamicInt::DynamicInt(const DynamicInt& other)
	: intPtr{ new int {other.GetValue()} } // a deep copy.
{
	std::cout << "copy con\n";
}

DynamicInt::DynamicInt(DynamicInt&& other) noexcept
	: intPtr{ other.intPtr } // a shallow copy.
{
	std::cout << "move con\n";
	other.intPtr = nullptr; // the other one no longer owns the ptr.
}

DynamicInt::~DynamicInt()
{
	std::cout << "destructed" << std::endl;
	delete intPtr; // frees the memory
}

DynamicInt& DynamicInt::operator=(const DynamicInt& rhs) noexcept
{
	std::cout << "copy assignment\n";
	if (*this == rhs) return *this; //do a self assignment check. //not the best solution here, because we should use the ==. 
	//deep copy
	*intPtr = rhs.GetValue();

	return *this; //this is the pointer that points to the current object we are working on.
}

DynamicInt& DynamicInt::operator=(DynamicInt&& rhs) noexcept
{
	std::cout << "move assignment\n";
	if (*this == rhs) return *this; // self assignment guard. needed to prevent deletion of this.ptr.

	delete intPtr; // free this memory.
	intPtr = rhs.intPtr; // giveing ownership to this
	rhs.intPtr = nullptr; // rhs giving up ownership
	return *this;
}

bool DynamicInt::operator==(const DynamicInt& other) const
{
	if (intPtr == other.intPtr)
	{
		return true;
	}

	if (GetValue() == other.GetValue()) return true;

	return false;
}

bool DynamicInt::operator!=(const DynamicInt& other) const
{
	return !(*this == other);
}

bool DynamicInt::operator>(const DynamicInt& other) const
{
	return GetValue() > other.GetValue();
}

bool DynamicInt::operator<(const DynamicInt& other) const
{
	return GetValue() < other.GetValue();
}

bool DynamicInt::operator<=(const DynamicInt& other) const
{
	return GetValue() <= other.GetValue();
}

bool DynamicInt::operator>=(const DynamicInt& other) const
{
	return GetValue() >= other.GetValue();
}

void DynamicInt::SetValue(int newValue)
{
	*intPtr = newValue;
}

int DynamicInt::GetValue() const
{
	if (intPtr)
		return *intPtr;

	return 0;
}

DynamicInt::DynamicInt(int value)
	: intPtr{ new int {value} }
{
	std::cout << "one param constructor" << std::endl;
}

DynamicInt operator*(const DynamicInt& lhs, const DynamicInt& rhs)
{
	return DynamicInt{lhs.GetValue() * rhs.GetValue()};
}

DynamicInt operator*(int lhs, const DynamicInt& rhs)
{
	return DynamicInt{lhs * rhs.GetValue()};
}

DynamicInt operator*(const DynamicInt& lhs, int rhs)
{
	return DynamicInt{lhs.GetValue() * rhs};
}
