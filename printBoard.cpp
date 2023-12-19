#include"isSafe.h"
#include <iostream>
using namespace std;
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