#include "TicTacToe.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include "keyboardControls.h"
#include "gameField.h"
#include "movement.h"
#include "colors.h"

unsigned char upKey = 0,
	downKey = 0,
	leftKey = 0,
	rightKey = 0,
	actionKey = 0,

	emptyCells = 9;

bool currentMove = true,
	escapeKey = false,
	win = false;

Cell field[3][3];

COORD currentPos = { 1, 1 }, moveVector;

void clamp(short& value, char minValue, char maxValue)
{
	if (value < minValue) {
		value = minValue;
		return;
	}

	if (value > maxValue) {
		value = maxValue;
	}

	return;
}

void tripleT()
{
	using namespace std;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char answer;

	cout << "\tкрестики-нолики" << endl << endl << "Начать игру? (y/n): ";
	cin.get(answer);

	if (answer != 'y') {
		return;
	}

	resetKeyStates();
	initField(field);

	setCursorPosition(CPX, CPY);
	setColor(field[CPX][CPY].color.swap());
	cout << field[CPX][CPY].value;
	setCursorPosition(CPX, CPY);

	while (!escapeKey && emptyCells > 0 && !win)
	{
		getKeyStates(upKey, downKey, leftKey, rightKey, actionKey, escapeKey);

		MVX = RIGHT - LEFT;
		MVY = DOWN - UP;

		if (ACTION) {
			resetKeyStates();
			if (field[CPX][CPY].value != ' ') {
				cout << "\7";
				continue;
			}

			if (currentMove)
			{
				field[CPX][CPY].value = 'X';
				field[CPX][CPY].color = FG_RED + BG_BLACK;
			}
			else
			{
				field[CPX][CPY].value = 'O';
				field[CPX][CPY].color = FG_BLUE + BG_BLACK;
			}

			currentMove ^= true;
			emptyCells -= 1;
		}

		if (MVX || MVY || ACTION)
		{
			setCursorPosition(CPX, CPY);
			setColor(field[CPX][CPY].color);
			cout << field[CPX][CPY].value;
			setCursorPosition(CPX, CPY);
			CPX += MVX;
			CPY += MVY;
			clamp(CPX, 0, 2);
			clamp(CPY, 0, 2);

			setCursorPosition(CPX, CPY);
			setColor(field[CPX][CPY].color.swap());
			cout << field[CPX][CPY].value;
			setCursorPosition(CPX, CPY);

			if (emptyCells < 5)
			{
				win = checkWin(!currentMove, currentPos, field);
			}
		}

		Sleep(33);
	}

	setColor(field[CPX][CPY].color);
	cout << field[CPX][CPY].value;
	setCursorPosition(-1, -1);
	
	if (escapeKey)
	{
		setColor(FG_WHITE + BG_BLACK);
		cout << "Игрок ";

		if (currentMove)
		{
			setColor(FG_RED + BG_BLACK);
			cout << "X";
		}
		else
		{
			setColor(FG_BLUE + BG_BLACK);
			cout << "O";
		}

		setColor(FG_WHITE + BG_BLACK);
		cout << " отказывается продолжать..." << endl;

		Sleep(2000);
		return;
	}

	if (win)
	{
		setColor(FG_WHITE + BG_BLACK);
		cout << "Игрок ";

		if (!currentMove)
		{
			setColor(FG_RED + BG_BLACK);
			cout << "X";
		}
		else
		{
			setColor(FG_BLUE + BG_BLACK);
			cout << "O";
		}

		setColor(FG_GREEN + BG_BLACK);
		cout << " - победитель!" << endl;
		setColor(FG_WHITE + BG_BLACK);

		Sleep(2000);
		return;
	}

	setColor(FG_YELLOW + BG_BLACK);
	cout << "Ничья" << endl << endl;
	setColor(FG_WHITE + BG_BLACK);
	
	Sleep(2000);
	return;
}