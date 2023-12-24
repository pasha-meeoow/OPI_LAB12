#pragma once

void resetKeyStates();
void getKeyStates(unsigned char& up, unsigned char& down, unsigned char& left, unsigned char& right, unsigned char& action, bool& escape);