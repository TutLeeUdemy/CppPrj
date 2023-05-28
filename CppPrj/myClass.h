#pragma once
class myClass
{
public:
	myClass();
	~myClass();

	//static member function, can only access the static member variables.
	static int GetCount();

private:
	int member;
	static int count; // it is a variable that does not belong to any instance, it is a independent variable that is shared by all instances, means there is only one.
};
