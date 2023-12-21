#include"isSafe.h"
using namespace std;
bool isSafe(int board[N][N], int row, int col, int num)
{
	// �������� ���� �� ����� � ����
	for (int i = 0; i < N; i++)
		if (board[row][i] == num)
			return false;

	// �������� ���� �� ����� � �������
	for (int i = 0; i < N; i++)
		if (board[i][col] == num)
			return false;

	// �������� ���� �� ����� � ������� 3 �� 3
	int boxRowStart = row - row % 3;
	int boxColStart = col - col % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i + boxRowStart][j + boxColStart] == num)
				return false;

	return true;
}