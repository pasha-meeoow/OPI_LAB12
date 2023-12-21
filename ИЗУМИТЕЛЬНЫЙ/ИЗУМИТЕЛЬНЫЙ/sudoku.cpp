#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int N = 9;

bool isSafe(int board[N][N], int row, int col, int num) 
{
	// проверка, есть ли число в строке
	for (int i = 0; i < N; i++)
		if (board[row][i] == num)
			return false;

	// проверка, есть ли число в колонке
	for (int i = 0; i < N; i++)
		if (board[i][col] == num)
			return false;

	// проверка, есть ли число в яйчейке 3 на 3
	int boxRowStart = row - row % 3;
	int boxColStart = col - col % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i + boxRowStart][j + boxColStart] == num)
				return false;

	return true;
}

void printBoard(int grid[N][N]) 
{
	for (int row = 0; row < N; row++) 
	{
		for (int col = 0; col < N; col++) 
		{
			if (col == 3 || col == 6)
				cout << " | ";
			cout << grid[row][col] << " ";
		}
		if (row == 2 || row == 5) 
		{
			cout << endl;
			for (int i = 0; i < N; i++)
				cout << "---";
		}
		cout << endl;
	}
}


bool solveSudoku(int board[N][N], int row, int col) 
{
	// конец игры если все яйчейки заполнены
	if (row == N - 1 && col == N)
		return true;

	// переход на следующий ряд, если в этой колонке нет пустых яйчеек
	if (col == N) 
	{
		row++;
		col = 0;
	}

	// пропуск ненулевых яйчеек
	if (board[row][col] != 0)
		return solveSudoku(board, row, col + 1);

	// если число в диапазоне от 1 до 9, его можно вписать в яйчейку
	for (int num = 1; num <= 9; num++) 
	{
		if (isSafe(board, row, col, num)) 
		{
			board[row][col] = num;

			if (solveSudoku(board, row, col + 1))
				return true;

			board[row][col] = 0;
		}
	}
	return false;
}

bool isSolvedCompletely(int grid[N][N]) 
{
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			if (grid[row][col] == 0)
				return false;

	return true;
}

void playGame(int board[N][N]) 
{
	int ch;
	int row, col, num;
	while (true) 
	{
		printBoard(board);
		cout << endl << endl;
		cout << "введите в качестве ряда -1, чтобы увидеть решенное судоку." << endl;
		cout << "введите ряд: ";
		cin >> row;
		cout << "введите столбец: ";
		cin >> col;
		cout << "введите число: ";
		cin >> num;

		if (row == -1 || col == -1 || num == -1) 
		{
			solveSudoku(board, 0, 0);
			printBoard(board);
			cout << endl;
			cout << "удачи в следующий раз" << endl;
			return;
		}
		if (isSolvedCompletely(board))
			break;
		row--;
		col--;
		if (!isSafe(board, row, col, num)) 
		{
			cout << "некорректное действие, попробуйте еще раз." << endl;
			continue;
		}
		board[row][col] = num;
	}

	// проверка на правильное заполнение
	bool solved = true;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (board[i][j] == 0) 
			{
				solved = false;
				break;
			}
		}
	}

	if (solved) {
		cout << "поздравляю, вы правильно решили." << endl;
		printBoard(board);
	}
	else {
		cout << "судоку решено неверно, попробуйте еще раз." << endl;
	}

}

int main() 
{
	int board[N][N] = 
	{
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}
	};
	while (true) 
	{

		int choice;
		cout << endl << endl;
		cout << "\t\t1) решить судоку" << endl;
		cout << "\t\t2) увидеть решенную игру" << endl;
		cout << "\t\t3) выход" << endl;
		cout << "\t\tвведите вариант: ";
		cin >> choice;

		switch (choice) 
		{
		case 1:
			playGame(board);
			break;
		case 2:
			if (solveSudoku(board, 0, 0))
			{
				cout << "решенное судоку: " << endl;
				cout << endl << endl;
				for (int row = 0; row < N; row++) 
				{
					for (int col = 0; col < N; col++) 
					{
						if (col == 3 || col == 6)
							cout << " | ";
						cout << board[row][col] << " ";
					}
					if (row == 2 || row == 5)
					{
						cout << endl;
						for (int i = 0; i < N; i++)
							cout << "---";
					}
					cout << endl;
				}
				cout << endl;
				cout << "удачи в следующий раз" << endl;
			}
			else
				cout << "решение не найдено" << endl;
			break;
		case 3:
			exit(0);
		default:
			cout << "некорректный выбор" << endl;
		}
		return 0;
	}

}
