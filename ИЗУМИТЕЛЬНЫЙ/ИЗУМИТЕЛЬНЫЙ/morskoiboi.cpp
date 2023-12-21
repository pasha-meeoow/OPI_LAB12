#include "morskoiboi.h"
#include <stdlib.h>
#include <vector>
#include <iostream>


using namespace std;
void morskoiboi()
{
    setlocale(LC_ALL, "RU");


    cout << "Ниже вы можете ознакомится с правилами игры или приступить к ней: " << endl;

    while (true) {

        cout << "1.Приступить к игре " << endl;
        cout << "2.Правила игры: " << endl;
        char choice;
        cin >> choice;
        switch (choice) {
        case '1':
            break;
        case '2':
            cout << "Тут должны быть правила получившейся игры." << endl;
            break;
        default:
            cout << "Не корректный выбор.Продолжаем" << endl;
            break;
        }
        if (choice == '1') {
            break;
        }
    }

    int koroblyza = 20;
    int koroblyprotiv = 20;
    int moreza[10][10] = {};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            moreza[i][j] = 0;
        }
    }
    //генерация случайного поля противника
    srand(time(NULL));
    int generation = rand() % 3;
    int moreprotiv[10][10] = {};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            moreprotiv[i][j] = 0;
        }
    }
    switch (generation)
    {
    case 0: {
        moreprotiv[0][0] = 1;
        moreprotiv[1][2] = 1;
        moreprotiv[0][2] = 1;
        moreprotiv[2][0] = 1;
        moreprotiv[4][0] = 1;
        moreprotiv[6][0] = 1;
        moreprotiv[0][4] = 1;
        moreprotiv[1][4] = 1;
        moreprotiv[0][6] = 1;
        moreprotiv[1][6] = 1;
        moreprotiv[3][2] = 1;
        moreprotiv[3][3] = 1;
        moreprotiv[3][4] = 1;
        moreprotiv[3][6] = 1;
        moreprotiv[3][7] = 1;
        moreprotiv[3][8] = 1;
        moreprotiv[5][4] = 1;
        moreprotiv[5][5] = 1;
        moreprotiv[5][6] = 1;
        moreprotiv[5][7] = 1;
        break;
    }
    case 1: {
        moreprotiv[0][0] = 1;
        moreprotiv[0][2] = 1;
        moreprotiv[0][4] = 1;
        moreprotiv[0][6] = 1;
        moreprotiv[2][1] = 1;
        moreprotiv[2][2] = 1;
        moreprotiv[2][4] = 1;
        moreprotiv[2][5] = 1;
        moreprotiv[2][7] = 1;
        moreprotiv[2][8] = 1;
        moreprotiv[4][2] = 1;
        moreprotiv[5][2] = 1;
        moreprotiv[6][2] = 1;
        moreprotiv[4][5] = 1;
        moreprotiv[5][5] = 1;
        moreprotiv[6][5] = 1;
        moreprotiv[8][4] = 1;
        moreprotiv[8][5] = 1;
        moreprotiv[8][6] = 1;
        moreprotiv[8][7] = 1;
        break;
    }
    case 2: {
        moreprotiv[0][1] = 1;
        moreprotiv[0][2] = 1;
        moreprotiv[0][5] = 1;
        moreprotiv[0][6] = 1;
        moreprotiv[2][0] = 1;
        moreprotiv[4][1] = 1;
        moreprotiv[6][1] = 1;
        moreprotiv[8][0] = 1;
        moreprotiv[2][3] = 1;
        moreprotiv[3][3] = 1;
        moreprotiv[3][5] = 1;
        moreprotiv[3][6] = 1;
        moreprotiv[3][7] = 1;
        moreprotiv[5][5] = 1;
        moreprotiv[5][6] = 1;
        moreprotiv[5][7] = 1;
        moreprotiv[6][3] = 1;
        moreprotiv[7][3] = 1;
        moreprotiv[8][3] = 1;
        moreprotiv[9][3] = 1;
        break;
    }

    default:
        break;

    }


    int moreotob[10][10] = {};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            moreotob[i][j] = 0;
        }
    }
    int morehranit[10][10] = {};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            morehranit[i][j] = 0;
        }
    }

    system("cls");
    cout << "\n";
    cout << "      A   B   C   D   E   F   G   H   I   J   \n";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << " " << i + 1;
        else
        {
            cout << " " << i + 1 << " ";
        }

        //0 это пустая клетка 1 это корабль 2 это подпитый корабль
        for (int j = 0; j < 10; j++) {
            cout << " | ";
            if (moreza[i][j] == 0)
                cout << " ";
            else if (moreza[i][j] == 1)
                cout << "W";
            else if (moreza[i][j] == 2)
                cout << "X";
        }
        cout << " | \n    ----------------------------------------- \n";
    }

    cout << "Введите позицию 4-ного корабля\n";
    for (int i = 0; i < 4; i++) {
        int b;
        char a;
        cout << "Введите " << i + 1 << "координату\n";
        cin >> a >> b;
        if (moreza[b - 1][int(toupper(a)) - 65] != 0)
        {
            i--;
            cout << "Введена неверная координата" << endl;

        }
        else
        {
            moreza[b - 1][int(toupper(a)) - 65] = 1;

        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
        {
            if (moreza[i][j] == 1) {
                if (moreza[abs(i - 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j - 1) % 10] = 4;
            }
        }
    }
    system("cls");
    cout << "\n";
    cout << "      A   B   C   D   E   F   G   H   I   J   \n";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << " " << i + 1;
        else
        {
            cout << " " << i + 1 << " ";
        }

        //0 это пустая клетка 1 это корабль 2 это подпитый корабль
        for (int j = 0; j < 10; j++) {
            cout << " | ";
            if (moreza[i][j] == 0)
                cout << " ";
            else if (moreza[i][j] == 1)
                cout << "W";
            else if (moreza[i][j] == 2)
                cout << "X";
            else if (moreza[i][j] == 4)
                cout << " ";
        }
        cout << " | \n    ----------------------------------------- \n";
    }
    cout << "Введите позицию 3-ного корабля \n";
    for (int i = 0; i < 3; i++) {
        int b;
        char a;
        cout << "Введите " << i + 1 << "координату\n";
        cin >> a >> b;
        if (moreza[b - 1][int(toupper(a)) - 65] != 0)
        {
            i--;
            cout << "Введена неверная координата" << endl;

        }
        else
        {
            moreza[b - 1][int(toupper(a)) - 65] = 1;

        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
        {
            if (moreza[i][j] == 1) {
                if (moreza[abs(i - 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j - 1) % 10] = 4;
            }
        }
    }
    system("cls");
    cout << "\n";
    cout << "      A   B   C   D   E   F   G   H   I   J   \n";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << " " << i + 1;
        else
        {
            cout << " " << i + 1 << " ";
        }

        //0 это пустая клетка 1 это корабль 2 это подпитый корабль
        for (int j = 0; j < 10; j++) {
            cout << " | ";
            if (moreza[i][j] == 0)
                cout << " ";
            else if (moreza[i][j] == 1)
                cout << "W";
            else if (moreza[i][j] == 2)
                cout << "X";
            else if (moreza[i][j] == 4)
                cout << " ";
        }
        cout << " | \n    ----------------------------------------- \n";
    }
    cout << "Введите позицию 3-ного корабля \n";
    for (int i = 0; i < 3; i++) {
        int b;
        char a;
        cout << "Введите " << i + 1 << "координату\n";
        cin >> a >> b;
        if (moreza[b - 1][int(toupper(a)) - 65] != 0)
        {
            i--;
            cout << "Введена неверная координата" << endl;

        }
        else
        {
            moreza[b - 1][int(toupper(a)) - 65] = 1;

        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
        {
            if (moreza[i][j] == 1) {
                if (moreza[abs(i - 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j - 1) % 10] = 4;
            }
        }
    }
    system("cls");
    cout << "\n";
    cout << "      A   B   C   D   E   F   G   H   I   J   \n";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << " " << i + 1;
        else
        {
            cout << " " << i + 1 << " ";
        }

        //0 это пустая клетка 1 это корабль 2 это подпитый корабль
        for (int j = 0; j < 10; j++) {
            cout << " | ";
            if (moreza[i][j] == 0)
                cout << " ";
            else if (moreza[i][j] == 1)
                cout << "W";
            else if (moreza[i][j] == 2)
                cout << "X";
            else if (moreza[i][j] == 4)
                cout << " ";
        }
        cout << " | \n    ----------------------------------------- \n";
    }
    cout << "Введите позицию 2-ного корабля \n";
    for (int i = 0; i < 2; i++) {
        int b;
        char a;
        cout << "Введите " << i + 1 << "координату \n";
        cin >> a >> b;
        if (moreza[b - 1][int(toupper(a)) - 65] != 0)
        {
            i--;
            cout << "Введена неверная координата" << endl;

        }
        else
        {
            moreza[b - 1][int(toupper(a)) - 65] = 1;

        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
        {
            if (moreza[i][j] == 1) {
                if (moreza[abs(i - 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j - 1) % 10] = 4;
            }
        }
    }
    system("cls");
    cout << "\n";
    cout << "      A   B   C   D   E   F   G   H   I   J   \n";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << " " << i + 1;
        else
        {
            cout << " " << i + 1 << " ";
        }

        //0 это пустая клетка 1 это корабль 2 это подпитый корабль
        for (int j = 0; j < 10; j++) {
            cout << " | ";
            if (moreza[i][j] == 0)
                cout << " ";
            else if (moreza[i][j] == 1)
                cout << "W";
            else if (moreza[i][j] == 2)
                cout << "X";
            else if (moreza[i][j] == 4)
                cout << " ";
        }
        cout << " | \n    ----------------------------------------- \n";
    }
    cout << "Введите позицию 2-ного корабля \n";
    for (int i = 0; i < 2; i++) {
        int b;
        char a;
        cout << "Введите " << i + 1 << "координату \n";
        cin >> a >> b;
        if (moreza[b - 1][int(toupper(a)) - 65] != 0)
        {
            i--;
            cout << "Введена неверная координата" << endl;

        }
        else
        {
            moreza[b - 1][int(toupper(a)) - 65] = 1;

        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
        {
            if (moreza[i][j] == 1) {
                if (moreza[abs(i - 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j - 1) % 10] = 4;
            }
        }
    }
    system("cls");
    cout << "\n";
    cout << "      A   B   C   D   E   F   G   H   I   J   \n";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << " " << i + 1;
        else
        {
            cout << " " << i + 1 << " ";
        }

        //0 это пустая клетка 1 это корабль 2 это подпитый корабль
        for (int j = 0; j < 10; j++) {
            cout << " | ";
            if (moreza[i][j] == 0)
                cout << " ";
            else if (moreza[i][j] == 1)
                cout << "W";
            else if (moreza[i][j] == 2)
                cout << "X";
            else if (moreza[i][j] == 4)
                cout << " ";
        }
        cout << " | \n    ----------------------------------------- \n";
    }
    cout << "Введите позицию 2-ного корабля \n";
    for (int i = 0; i < 2; i++) {
        int b;
        char a;
        cout << "Введите " << i + 1 << "координату \n";
        cin >> a >> b;
        if (moreza[b - 1][int(toupper(a)) - 65] != 0)
        {
            i--;
            cout << "Введена неверная координата" << endl;

        }
        else
        {
            moreza[b - 1][int(toupper(a)) - 65] = 1;

        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
        {
            if (moreza[i][j] == 1) {
                if (moreza[abs(i - 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j - 1) % 10] = 4;
            }
        }
    }
    system("cls");
    cout << "\n";
    cout << "      A   B   C   D   E   F   G   H   I   J   \n";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << " " << i + 1;
        else
        {
            cout << " " << i + 1 << " ";
        }

        //0 это пустая клетка 1 это корабль 2 это подпитый корабль
        for (int j = 0; j < 10; j++) {
            cout << " | ";
            if (moreza[i][j] == 0)
                cout << " ";
            else if (moreza[i][j] == 1)
                cout << "W";
            else if (moreza[i][j] == 2)
                cout << "X";
            else if (moreza[i][j] == 4)
                cout << " ";
        }
        cout << " | \n    ----------------------------------------- \n";
    }
    cout << "Введите позицию 1-ного корабля\n";
    for (int i = 0; i < 1; i++) {
        int b;
        char a;
        cout << "Введите " << i + 1 << "координату\n";
        cin >> a >> b;
        if (moreza[b - 1][int(toupper(a)) - 65] != 0)
        {
            i--;
            cout << "Введена неверная координата" << endl;

        }
        else
        {
            moreza[b - 1][int(toupper(a)) - 65] = 1;

        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
        {
            if (moreza[i][j] == 1) {
                if (moreza[abs(i - 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j - 1) % 10] = 4;
            }
        }
    }
    system("cls");
    cout << "\n";
    cout << "      A   B   C   D   E   F   G   H   I   J   \n";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << " " << i + 1;
        else
        {
            cout << " " << i + 1 << " ";
        }

        //0 это пустая клетка 1 это корабль 2 это подпитый корабль
        for (int j = 0; j < 10; j++) {
            cout << " | ";
            if (moreza[i][j] == 0)
                cout << " ";
            else if (moreza[i][j] == 1)
                cout << "W";
            else if (moreza[i][j] == 2)
                cout << "X";
            else if (moreza[i][j] == 4)
                cout << " ";
        }
        cout << " | \n    ----------------------------------------- \n";
    }
    cout << "Введите позицию 1-ного корабля\n";
    for (int i = 0; i < 1; i++) {
        int b;
        char a;
        cout << "Введите " << i + 1 << "координату\n";
        cin >> a >> b;
        if (moreza[b - 1][int(toupper(a)) - 65] != 0)
        {
            i--;
            cout << "Введена неверная координата" << endl;

        }
        else
        {
            moreza[b - 1][int(toupper(a)) - 65] = 1;

        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
        {
            if (moreza[i][j] == 1) {
                if (moreza[abs(i - 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j - 1) % 10] = 4;
            }
        }
    }
    system("cls");
    cout << "\n";
    cout << "      A   B   C   D   E   F   G   H   I   J   \n";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << " " << i + 1;
        else
        {
            cout << " " << i + 1 << " ";
        }

        //0 это пустая клетка 1 это корабль 2 это подпитый корабль
        for (int j = 0; j < 10; j++) {
            cout << " | ";
            if (moreza[i][j] == 0)
                cout << " ";
            else if (moreza[i][j] == 1)
                cout << "W";
            else if (moreza[i][j] == 2)
                cout << "X";
            else if (moreza[i][j] == 4)
                cout << " ";
        }
        cout << " | \n    ----------------------------------------- \n";
    }
    cout << "Введите позицию 1-ного корабля\n";
    for (int i = 0; i < 1; i++) {
        int b;
        char a;
        cout << "Введите " << i + 1 << "координату\n";
        cin >> a >> b;
        if (moreza[b - 1][int(toupper(a)) - 65] != 0)
        {
            i--;
            cout << "Введена неверная координата" << endl;

        }
        else
        {
            moreza[b - 1][int(toupper(a)) - 65] = 1;

        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
        {
            if (moreza[i][j] == 1) {
                if (moreza[abs(i - 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j - 1) % 10] = 4;
            }
        }
    }
    system("cls");
    cout << "\n";
    cout << "      A   B   C   D   E   F   G   H   I   J   \n";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << " " << i + 1;
        else
        {
            cout << " " << i + 1 << " ";
        }

        //0 это пустая клетка 1 это корабль 2 это подпитый корабль
        for (int j = 0; j < 10; j++) {
            cout << " | ";
            if (moreza[i][j] == 0)
                cout << " ";
            else if (moreza[i][j] == 1)
                cout << "W";
            else if (moreza[i][j] == 2)
                cout << "X";
            else if (moreza[i][j] == 4)
                cout << " ";
        }
        cout << " | \n    ----------------------------------------- \n";
    }
    cout << "Введите позицию 1-ного корабля\n";
    for (int i = 0; i < 1; i++) {
        int b;
        char a;
        cout << "Введите " << i + 1 << "координату\n";
        cin >> a >> b;
        if (moreza[b - 1][int(toupper(a)) - 65] != 0)
        {
            i--;
            cout << "Введена неверная координата" << endl;

        }
        else
        {
            moreza[b - 1][int(toupper(a)) - 65] = 1;

        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
        {
            if (moreza[i][j] == 1) {
                if (moreza[abs(i - 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j + 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j + 1) % 10] = 4;
                if (moreza[abs(i + 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i + 1) % 10][abs(j - 1) % 10] = 4;
                if (moreza[abs(i - 1) % 10][abs(j - 1) % 10] == 0)
                    moreza[abs(i - 1) % 10][abs(j - 1) % 10] = 4;
            }
        }
    }
    vector<int> alabay;
    vector<int> strelok;
    //отображение поля и условие на поподания
    while (true) {
        system("cls");

        cout << "Ваше поле\n";
        cout << "      A   B   C   D   E   F   G   H   I   J   \n";
        for (int i = 0; i < 10; i++)
        {
            if (i == 9)
                cout << " " << i + 1;
            else
            {
                cout << " " << i + 1 << " ";
            }

            //0 это пустая клетка 1 это корабль 2 это подпитый корабль 3 нету
            for (int j = 0; j < 10; j++) {
                cout << " | ";
                if (moreza[i][j] == 0)
                    cout << " ";
                else if (moreza[i][j] == 1)
                    cout << "W";
                else if (moreza[i][j] == 2)
                    cout << "X";
                else if (moreza[i][j] == 3)
                    cout << "O";
                else if (moreza[i][j] == 4)
                    cout << " ";
            }



            cout << " | \n    ----------------------------------------- \n";
        }
        cout << "Поле противника\n";
        cout << "      A   B   C   D   E   F   G   H   I   J   \n";
        for (int i = 0; i < 10; i++)
        {
            if (i == 9)
                cout << " " << i + 1;
            else
            {
                cout << " " << i + 1 << " ";
            }

            //0 это пустая клетка 1 попал  2 не попал
            for (int j = 0; j < 10; j++) {
                cout << " | ";
                if (moreotob[i][j] == 0)
                    cout << " ";
                else if (moreotob[i][j] == 1)
                    cout << "X";
                else if (moreotob[i][j] == 2)
                    cout << "O";
            }
            cout << " | \n    ----------------------------------------- \n";
        }
        int b;
        char a;
        bool can1 = false;
        while (!can1) {
            cout << "Введите координату выстрела \n";
            cin >> a >> b;
            int x1 = b, y1 = int(toupper(a)) - 64;
            int x1y1 = x1 * 10 + y1;
            bool ind = true;
            for (int i : alabay) {
                if (i == x1y1)
                    ind = false;
            }
            if (ind == false)
                cout << "Введина некоректная координата" << endl;
            else
            {
                alabay.push_back(x1y1);
                break;
            }
        }
        if (moreprotiv[b - 1][int(toupper(a)) - 65] == 1) {
            moreprotiv[b - 1][int(toupper(a)) - 65] = 2;
            moreotob[b - 1][int(toupper(a)) - 65] = 1;
            koroblyprotiv--;

        }
        else
        {
            moreotob[b - 1][int(toupper(a)) - 65] = 2;
        }
        bool can = false;
        int x, y;
        while (!can) {
            srand(time(NULL));
            x = rand() % 10 + 1;

            y = rand() % 10 + 1;
            int xy = x * 10 + y;
            bool ind = true;
            for (int i : strelok) {
                if (i == xy)
                    ind = false;
            }
            if (ind == true) {
                can = true;
                strelok.push_back(xy);
                if (moreza[x - 1][y - 1] == 1) {
                    moreza[x - 1][y - 1] = 2;
                    koroblyza--;
                }
                else
                    moreza[x - 1][y - 1] = 3;
            }

        }
        if (koroblyza == 0) {
            system("cls");
            cout << "Командир,мы проиграли -_-";
            break;
        }
        if (koroblyprotiv == 0) {
            system("cls");
            cout << "Командир,мы выйиграли!!!!!!!!!!!\n";
            break;
        }

    }

}
