#pragma once
class Vector2
{
public:
	union {
		float x;
		float r;
	};

	union {
		float y;
		float g;

	};

	Vector2(int sx, int sy)
	{
		x = (float)sx;
		y = (float)sy;
	}
	~Vector2() {};
	Vector2() {};
};

class Vector3
{
public:

	union {
		float x;
		float r;
	};

	union {
		float y;
		float g;

	};

	union {
		float z;
		float b;

	};

	Vector3(int sx, int sy, int sz)
	{
		x = (float)sx;
		y = (float)sy;
		z = (float)sz;
	}
	Vector3() {};
	~Vector3() {};

	bool operator!= (const Vector3 &v)
	{
		if (x == v.x)
		{
			if (y == v.y)
			{
				if (z == v.z)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}

	bool operator== (const Vector3 &v)
	{
		if (x == v.x)
		{
			if (y == v.y)
			{
				if (z == v.z)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	

};

