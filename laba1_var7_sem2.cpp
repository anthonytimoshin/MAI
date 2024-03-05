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
#include "vector"


using namespace std;


int main() {

    // инициализация переменной файла
//    string path = "data.txt";

    // некорректные тесты
     string path = "/Users/anton/code/stepik/test2.txt";

    // корректные тесты
//    string path = "/Users/anton/code/stepik/test.txt";

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
    cout << constant;

    // Проверка ввода
    if (file.fail()) {
        cout << "Не удалось считать значение" << endl;
        file.close();
        return -1;
    }

    // подсчет количества строк
    int count = 0;

    string surname;
    string fullname;
    string s;


    while (getline(file, s)) {  //нельзя использовать getline
        count++;
        fullname = "";
        surname = "";
        int i = 0;
        for (int j = 0; j < s.size(); j++) { //нельзя использовать size
            char c = s[j];
            if (c == ' ') {
                i++;
                fullname += " ";
                fullname += s[j + 1];
                fullname += ".";
            }
            if (i == 0) {
                fullname += c;
                surname += c;
            }
        }

        vector<string> a;
        vector<string> b;
        a.push_back(fullname);// заполнение массива фамилий с инициаламиa
        b.push_back(surname); // заполнение массива только фамилий

        for (int l=0; l <= size(b); l++) {
            if (b[l] == constant) {
                cout << count << " строка с заданной фамилией: ";
            }
            cout << a[l] << endl;
        } // печать людей с совпадающей фамилией
    }
    file.close();
}
