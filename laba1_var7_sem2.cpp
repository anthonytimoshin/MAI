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

int main() {

    // инициализация переменной файла
//    string path = "data.txt";

    // некорректные тесты
//    string path = "/Users/anton/code/stepik/test2.txt";

    // корректные тесты
    string path = "/Users/anton/code/stepik/test.txt";

    ifstream file(path); // чтение данных из файла

    // Проверка существования файла
    if (!file) {
        cout << "Файл не найден" << endl;
        return 0;
    } else {
        cout << "Файл открыт" << endl;
    }

    string constant;
    file >> constant;
    cout << "Искомая фамилия: " << constant << endl;

    // Проверка ввода
    if (file.fail()) {
        cout << "Не удалось считать значение" << endl;
        file.close();
        return -1;
    }

    // подсчет количества строк
    int count = 0;

    char surname[255];
    char name[255];
    char secondName[255];
    char found[50][255];

    while (file >> surname >> name >> secondName) {
        cout << "\n" << surname << " " << name[0] << ". " << secondName[0] << ".";
        if (surname == constant) {
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
