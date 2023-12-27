#include "TicTacToe.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include "keyboardControls.h"
#include "gameField.h"
#include "movement.h"
#include "colors.h"

unsigned char upKey, downKey, leftKey, rightKey, actionKey, emptyCells;

bool currentMove, escapeKey, win;

Cell field[3][3];

COORD currentPos, moveVector;

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

	upKey = downKey = leftKey = rightKey = actionKey = 0;
	emptyCells = 9;
	currentMove = true;
	escapeKey = win = false;
	currentPos = { 1, 1 };

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\tКрестики-нолики" << endl << endl
		<< "Управление:" << endl
		<< " стрелки - переместить курсор" << endl
		<< "  пробел - сделать ход" << endl
		<< "  escape - выйти из игры" << endl;

	setCursorVisibility(false);

	resetKeyStates();
	initField(field);

	setCursorPosition(CPX, CPY);
	setColor(FG_BLACK + BG_WHITE);
	cout << " ";

	setCursorPosition(-1, -1);
	setColor(FG_WHITE + BG_BLACK);
	cout << "Ходит ";
	setColor(FG_RED + BG_BLACK);
	cout << "X";
	setCursorPosition(CPX, CPY);

	while (!escapeKey && emptyCells > 0 && !win)
	{
		getKeysStates(upKey, downKey, leftKey, rightKey, actionKey, escapeKey);

		MVX = RIGHT - LEFT;
		MVY = DOWN - UP;

		if (ACTION)
		{
			resetKeyStates();
			if (field[CPX][CPY].value != ' ') {
				cout << "\7";
				continue;
			}

			setCursorPosition(-1, -1);
			setColor(FG_WHITE + BG_BLACK);
			cout << "Ходит ";

			if (currentMove)
			{
				field[CPX][CPY].value = 'X';
				field[CPX][CPY].color = FG_RED + BG_BLACK;

				setColor(FG_BLUE + BG_BLACK);
				cout << "O";
			}
			else
			{
				field[CPX][CPY].value = 'O';
				field[CPX][CPY].color = FG_BLUE + BG_BLACK;

				setColor(FG_RED + BG_BLACK);
				cout << "X";
			}

			setCursorPosition(CPX, CPY);

			currentMove ^= true;
			emptyCells -= 1;

			if (emptyCells < 5)
			{
				win = checkWin(!currentMove, currentPos, field);
			}
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
			
			setCursorVisibility(false);
		}

		Sleep(33);
	}

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	setCursorVisibility(true);

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

		setColor(FG_YELLOW + BG_BLACK);
		cout << " отказывается продолжать..." << endl << endl;
		setColor(FG_WHITE + BG_BLACK);

		return;
	}

	if (win)
	{
		setColor(FG_GREEN + BG_BLACK);
		cout << "Победа ";

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

		setColor(FG_WHITE + BG_BLACK);
		cout << "!" << endl << endl;

		return;
	}

	setColor(FG_YELLOW + BG_BLACK);
	cout << "Ничья  " << endl << endl;
	setColor(FG_WHITE + BG_BLACK);

	return;
}