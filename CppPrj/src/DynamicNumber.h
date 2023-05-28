#pragma once

template<typename T>
class DynamicNumber
{
public:
	DynamicNumber() // default con
		: ptr{ new T{} }
	{

	}

	//one param con
	explicit DynamicNumber(const T& other)
		: ptr{ new T{other} }
	{

	}

	//big five
	~DynamicNumber()
	{
		delete ptr;
	}

	DynamicNumber(const DynamicNumber& other)
		: ptr{ new T{other.GetValue()} }
	{

	}

	//copy con - deep copy
	template<typename otherT>
	DynamicNumber(const DynamicNumber<otherT>& other)
		: ptr{ new T{(T)other.GetValue()}}
	{

	}

	//move con - shallow copy
	DynamicNumber(DynamicNumber&& other)
		: ptr{other.ptr} // transfer ownership of the pointer to this.
	{
		other.ptr = nullptr; // removes the ownership of the other
	}

	//copy assignment operator
	DynamicNumber& operator=(const DynamicNumber& other)
	{
		if (*this == other) return *this; // self assignment check

		if (ptr == nullptr)
		{
			ptr = new T{other.GetValue()};
		}
		else
		{
			*ptr = other.GetValue();
		}

		return *this;
	}

	//move assignment operator
	DynamicNumber& operator=(DynamicNumber&& other)
	{
		if (*this == other) return *this;

		delete ptr;
		ptr = other.ptr;
		other.ptr = nullptr;
	}
	


	//== operator.
	bool operator==(const DynamicNumber& other) const
	{
		if (ptr == other.ptr) return true;

		if (GetValue() == other.GetValue()) return true;

		return false;
	}

	T GetValue() const
	{
		if(ptr)
			return *ptr;

		return T{};
	}

	void SetValue(const T& other)
	{
		*ptr = other;
	}

private:
	T* ptr;
};

//static keyword
//friend keyword
//...
