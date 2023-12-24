#include "keyboardControls.h"
#include <Windows.h>

void resetKeyStates()
{
	GetAsyncKeyState(VK_UP);
	GetAsyncKeyState(VK_DOWN);
	GetAsyncKeyState(VK_LEFT);
	GetAsyncKeyState(VK_RIGHT);
	GetAsyncKeyState(VK_RETURN);
	GetAsyncKeyState(VK_SPACE);
	GetAsyncKeyState(VK_ESCAPE);
}

void getKeyStates(unsigned char& up, unsigned char& down, unsigned char& left, unsigned char& right, unsigned char& action, bool& escape)
{
	up = (up + 1) & - (bool) GetAsyncKeyState(VK_UP);
	down = (down + 1) & - (bool) GetAsyncKeyState(VK_DOWN);
	left = (left + 1) & - (bool) GetAsyncKeyState(VK_LEFT);
	right = (right + 1) & - (bool) GetAsyncKeyState(VK_RIGHT);
	action = (action + 1) & - (bool) GetAsyncKeyState(VK_SPACE);
	escape = GetAsyncKeyState(VK_ESCAPE);
}