#include "text.h"

Text::Text(char* word_)
{
	word = word_;
}

char* Text::GetText()
{
	return word;
}

Vector3 Text::GetColor()
{
	return color;
}

void Text::Print()
{
	printf(GetText());
}