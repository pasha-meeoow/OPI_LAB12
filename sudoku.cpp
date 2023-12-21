#include <iostream>
#include <cstdlib>
#include <cstring>
#include"isSafe.h"
#include"printBoard.h"
using namespace std;
bool solveSudoku(int board[N][N], int row, int col) 
{
	//игра решена, если все пустые яйчейки заполнены
	if (row == N - 1 && col == N)
		return true;

	// переместитесь на след ряд если в этом нет пустых яйчеек
	if (col == N) 
	{
		row++;
		col = 0;
	}

	// пропустите уже полные яйчейки
	if (board[row][col] != 0)
		return solveSudoku(board, row, col + 1);

	// заполните яйчейку числом от 1 до 9
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
	setlocale(LC_ALL, "rus");
	int row, col, num;
	while (true) 
	{
		printBoard(board);
		cout << endl << endl;
		cout << " введите -1 в качестве строки, чтобы увидеть решенное судоку" << endl;
		cout << "введите строку: ";
		cin >> row;
		cout << "введите колонку: ";
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
			cout << "некорректный выбор, попробуйте снова." << endl;
			continue;
		}
		board[row][col] = num;
	}

	// Check if the user has solved it correctly or not
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

	if (solved) 
	{
		cout << "поздравляю, вы решили судоку." << endl;
		printBoard(board);
	}
	else 
	{
		cout << "попробуйте еще раз." << endl;
	}

}

int main() 
{
	setlocale(LC_ALL, "rus");
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
		cout << "\t\t2) увидеть решенное судоку" << endl;
		cout << "\t\t3) выход" << endl;
		cout << "\t\tвведите выбор: ";
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
				cout << "не найдено решение" << endl;
			break;
		case 3:
			exit(0);
		default:
			cout << "некорректный выбор" << endl;
		}
		return 0;
	}

}