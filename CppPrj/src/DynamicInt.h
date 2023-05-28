#pragma once

class FriendClass
{

};

class DynamicInt
{
public: // the public interface.
	DynamicInt();

	//the big five.
	//if none of these are customly made, then defaults ones will be provided automatically, and do shallow copy.

	//if you create any of these, you probabaly need to create the other ones.
	//in fact, others will not be automatically provided.

	//copy con
	DynamicInt(const DynamicInt& other); // copy constructor.
	
	//move con
	DynamicInt(DynamicInt&& other) noexcept; // move constructor
	
	//destructor
	~DynamicInt();

	//copy assignment operator
	DynamicInt& operator=(const DynamicInt& rhs) noexcept; // a copy assignment operator.
	
	//move assignment operator
	DynamicInt& operator=(DynamicInt&& rhs) noexcept;// move assignment operator

	bool operator==(const DynamicInt& other) const; // defines what happens when a == b.

	bool operator!=(const DynamicInt& other) const;

	bool operator>(const DynamicInt& other) const;

	bool operator<(const DynamicInt& other) const;

	bool operator<=(const DynamicInt& other) const;

	bool operator>=(const DynamicInt& other) const;

	void SetValue(int newValue);

	int GetValue() const;

	//one param con
	explicit DynamicInt(int value);

	//only saying that this funtion is a friend of the DynamicInt class. friend breaks the private protection, all together.
	friend DynamicInt operator*(const DynamicInt& lhs, const DynamicInt& rhs);
	friend FriendClass; // enables FriendClass to access intPtr. no recommended if you can manage with out friend.

private: // private members.
	int* intPtr;
};


//how does template work with classes.

//friend keyword 

//favor facility functions like this instead of member.
DynamicInt operator*(const DynamicInt& lhs, const DynamicInt& rhs);

DynamicInt operator*(int lhs, const DynamicInt& rhs);

DynamicInt operator*(const DynamicInt& lhs, int rhs);

//static keyword.