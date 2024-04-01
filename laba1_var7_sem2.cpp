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
* Last Revision: 23/03/24                                       *
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
    string path = "/Users/anton/code/stepik/test4.txt";

    ifstream file(path); // чтение данных из файла

    // Проверка существования файла
    if (!file) {
        cout << "Файл не найден" << endl;
        return 0;
    } else {
        if (file.peek() == -1) { // файл пустой?
            cout << "Файл пустой";
            file.close();
            return 0;
        }
        cout << "Файл открыт" << endl;
    }

    string constant;
    getline(file, constant);

    cout << "Искомая фамилия: " << constant << endl;
    cout << endl;

    // подсчет количества строк
    int count = 0;

    int m = 0; // 0 - фамилия не совпала, 1 - фамилия совпала
    string surname; // фамилия и инициалы
    string s;
    string found_surnames; // найденные фамилии и их инициалы

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
                if (surname == constant + ' ') {
                    m++;
                }
                i++;
                surname += s[j + 1];
                surname += ". ";
            }
            if (m == 1 && i == 2) {
                found_surnames += surname + "\n";
                m = 0;
            }
        }
        cout << surname << endl;
    }

    if (count == 0) { // проверка наличия введенных ФИО
        cout << "Фамилии не введены";
        return 0;
    }

    if (found_surnames == "") {
        cout << endl << "Искомой фамилии в списке нет";
        return 0;
    }
    cout << endl;
    cout << "Найденные фамилии: " << endl;
    cout << found_surnames << endl;

    return 0;
}
