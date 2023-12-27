#pragma once

#include <Windows.h>

#define FIELD0 "   |   |   " << endl
#define FIELD1 "---+---+---" << endl

struct Cell
{
	struct Color
	{
		unsigned char value;

		unsigned char swap()
		{
			unsigned char foreground = this->value >> 4,
				background = (this->value - (foreground << 4)) << 4;

			return foreground + background;
		}

		Color operator = (const unsigned char rhs)
		{
			value = rhs;

			return *this;
		}

		operator unsigned char() const
		{
			return value;
		}
	} color;

	unsigned char value;
	
};

void setCursorVisibility(bool visibility);
void initField(Cell(&field)[3][3]);
void setCursorPosition(char x, char y);
void setColor(unsigned char color = 15);
bool checkWin(unsigned char currentMove, COORD currentPos, Cell(&field)[3][3]);