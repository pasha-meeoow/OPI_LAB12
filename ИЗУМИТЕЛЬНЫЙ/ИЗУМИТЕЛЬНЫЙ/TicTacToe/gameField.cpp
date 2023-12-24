#include "gameField.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include "colors.h"
#include "movement.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

void initField(Cell (&field)[3][3])
{
	CONSOLE_CURSOR_INFO cursorInfo = { 100, false };
	SetConsoleCursorInfo(hConsole, &cursorInfo);

	system("cls");

	SetConsoleTextAttribute(hConsole, FG_GRAY);
	cout << FIELD0 << FIELD1 << FIELD0 << FIELD1 << FIELD0;
	SetConsoleTextAttribute(hConsole, FG_WHITE);
	
	for (char i = 0; i < 3; i++)
	{
		for (char j = 0; j < 3; j++)
		{
			field[i][j].value = 32;
			field[i][j].color = FG_WHITE;
		}
	}
}

void setCursorPosition(char x, char y)
{
	const unsigned char cells[2][4] = {
		{0, 1, 5, 9},
		{7, 0, 2, 4}
	};

	COORD cursor;
	cursor.X = cells[0][x + 1];
	cursor.Y = cells[1][y + 1];
	SetConsoleCursorPosition(hConsole, cursor);
}

void setColor(unsigned char color)
{
	SetConsoleTextAttribute(hConsole, color);
}

bool checkWin(unsigned char currentMove, COORD currentPos, Cell(&field)[3][3])
{
	bool win = false;

	currentMove = currentMove ? 'X' : 'O';

	for (char i = 0; i < 3; i++)
	{
		win |= (field[i][0].value & field[i][1].value & field[i][2].value) == currentMove;
		win |= (field[0][i].value & field[1][i].value & field[2][i].value) == currentMove;
	}
	win |= (field[0][0].value & field[1][1].value & field[2][2].value) == currentMove;
	win |= (field[2][0].value & field[1][1].value & field[0][2].value) == currentMove;

	return win;
}