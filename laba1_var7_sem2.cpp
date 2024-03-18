/****************************************************************
*                    КАФЕДРА № 304 1 КУРС                       *
*---------------------------------------------------------------*
* Project Type : Win32 Console Application                      *
* Project Name : character_data                                 *
* File Name    : main.cpp                                       *
* Language     : C/C++                                          *
* Programmer(s): Тимошин А.А., Воробьёв А.Н.                    *
* Modified By  :                                                *
* Lit source   :                                                *
* Created      : 24/02/24                                       *
* Last Revision: 27/02/24                                       *
* Comment(s)   : Символьные данные                              *
****************************************************************/


#include "iostream"
#include <fstream>
#include "string"

using namespace std;

// некорректные тесты
//    const string path = "/Users/anton/code/stepik/test2.txt";

// корректные тесты
const string path = "/Users/anton/code/stepik/test4.txt";

int main() {
    char constant[255]; // искомая фамилия

    int count = 0; // количество искомой фамилии в списке
    int count0 = 0; // количество фамилий в списке

    char surname[255];
    char name[255];
    char secondName[255];
    char found[50][255];

    ifstream file(path); // чтение данных из файла

    // Проверка существования файла
    if (!file) {
        cout << "Файл не найден" << endl;
        return 0;
    } else {
        if (file.peek() == -1) {
            cout << "Файл пустой";
            file.close();
            return 0;
        }
        cout << "Файл открыт" << endl;
    }
    
    
    file >> constant;
    cout << "Искомая фамилия: " << constant << endl;


    while (file >> surname >> name >> secondName) {
        count0++;
        cout << "\n" << surname << " " << name[0] << ". " << secondName[0] << ".";
        if (strcmp(constant, surname) == 0) {
            count++;
            strcpy(found[count], surname);
            strcat(found[count], " ");
            strncat(found[count], name, 1);
            strcat(found[count], ". ");
            strncat(found[count], secondName, 1);
            strcat(found[count], ".");
        }
    }

    file.close();

    if (count0 == 0) {
        cout << "Фамилии не введены";
        return 0;
    }

    cout << endl;

    if (count != 0) {
        cout << "\n" << "Найденные фамилии: ";
        for (int i = 0; i <= count; i++) {
            cout << found[i] << endl;
        }
    } else {
        cout << "\n" << "Искомой фамилии в списке нет";
    }

    return (0);
}
