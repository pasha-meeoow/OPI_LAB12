#include <iostream>
#include "morskoiboi.h"//модуль "морской бой"
#include "guess_num.h"//модуль "угадай число"
#include <ctime>
int main()
{
	setlocale(LC_ALL, "rus");
	char choice;
	cout << "Добро пожаловать в нашу сборку мини-игр!\n";
	Sleep(2000);
	system("cls");
	while(true){
		char yn = 'y';
		cout << "Выбирете игру:\n\t1. Морской бой\n\t2. Угадай число\n\t3. Судоку\n\t4. Крестики-нолики\n\t5. Не хочу играть\nДля выбора введите номер игры: ";
		cin >> choice;
		switch (choice)//выбор игры
		{
		case '1': {
			system("cls");
			cout << "Приятной игры";
			Sleep(2000);
			system("cls");
			morskoiboi();//морской бой
			cout << "Желаете продолжить? Y/N\n";
			cin >> yn;
			break;
		}
		case '2': {
			system("cls");
			cout << "Приятной игры";
			Sleep(2000);
			system("cls");
			Extreme();//угадай число
			cout << "Желаете продолжить? Y/N\n";
			cin >> yn;
			break;
		}
		case '3': {
			system("cls");
			cout << "Приятной игры";
			Sleep(2000);
			system("cls");
			//cудоку
			cout << "Желаете продолжить? Y/N\n";
			cin >> yn;
			break;
		}
		case '4': {
			system("cls");
			cout << "Приятной игры";
			Sleep(2000);
			system("cls");
			//крестики нолики
			cout << "Желаете продолжить? Y/N\n";
			cin >> yn;
			break;
		}
		case '5': {
			cout << "Вы уверенны?\nМожет все же поиграете? Y/N\n";
			cin >> yn;
			break;
		}
		default:
		{
			system("cls");
			cout << "Вы ввели некорректный символ\n";
			Sleep(2000);
			break;
		}
		}
		if (toupper(yn) == 'N')
		{
			system("cls");
			break;
		}
		system("cls");
	}
	cout << "Спасибо за игру!\nДо новых встреч\n\n";
}