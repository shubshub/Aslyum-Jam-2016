#include "globals.h"
int current_x = 0;
int current_y = 0;
int current_z = 0;

void GlobalOffsetX(int _x)
{
	current_x += _x;
}

void GlobalOffsetY(int _y)
{
	current_y += _y;
}

void GlobalOffsetZ(int _z)
{
	current_z += _z;
}

int GlobalGetX()
{
	return current_x;
}

int GlobalGetY()
{
	return current_y;
}

int GlobalGetZ()
{
	return current_z;
}