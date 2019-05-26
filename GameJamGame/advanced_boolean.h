#pragma once
class ABOOL
{
//Advanced Boolean - Holds a True False and a Type Identifier for different things
private:
	bool truthy_;
	int data_;
public:
	void operator=(bool b)
	{
		truthy_ = b;
	}

	void operator=(int d)
	{
		data_ = d;
	}

	explicit operator bool const()
	{
		return truthy_;
	}

	bool operator==(bool b)
	{
		if (truthy_ == b)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(int d)
	{
		if (data_ == d)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int data()
	{
		return data_;
	}
};