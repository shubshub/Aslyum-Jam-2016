#pragma once
#include "vector.h"
#include <iostream>
class Text
{
private:
	char* word;
	Vector3 color;
public:
	Text(char* word_);
	Text() {};
	~Text() {};

	char* GetText();

	Vector3 GetColor();

	void Print();

};