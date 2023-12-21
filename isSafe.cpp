#include"isSafe.h"
using namespace std;
bool isSafe(int board[N][N], int row, int col, int num)
{
	// проверка есть ли число в ряду
	for (int i = 0; i < N; i++)
		if (board[row][i] == num)
			return false;

	// проверка есть ли число в колонке
	for (int i = 0; i < N; i++)
		if (board[i][col] == num)
			return false;

	// проверка есть ли число в яйчейке 3 на 3
	int boxRowStart = row - row % 3;
	int boxColStart = col - col % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i + boxRowStart][j + boxColStart] == num)
				return false;

	return true;
}