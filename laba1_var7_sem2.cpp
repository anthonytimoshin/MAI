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


using namespace std;


int main() {

    const int size = 255;
    // инициализация переменной файла
//    string path = "data.txt";

    // некорректные тесты
//     string path = "/Users/anton/code/stepik/test2.txt";

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
    getline(file, constant);

//    cout << constant << endl;

    // Проверка ввода
    if (file.fail()) {
        cout << "Не удалось считать значение" << endl;
        file.close();
        return -1;
    }

    // подсчет количества строк
    int count = 0;

    string surname;
    string s;

    while (getline(file, s)) {
        count++;
        surname = "";
        int i = 0;
        for (int j = 0; j < size; j++) {
            char c = s[j];
            if (i == 0) {
                surname += c;
            }
            if (c == ' ') {
                i++;
                surname += s[j + 1];
                surname += ". ";
            }
        }
        cout << surname << endl;
    }
}
