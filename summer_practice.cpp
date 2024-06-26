/************************************************************************************************
*                                 ОЗНАКОМИТЕЛЬНАЯ ПРАКТИКА                                      *
*************************************************************************************************
* Project type  : Win64 Console Application                                                     *
* Project name  : Practice                                                                      *
* File name     : practice.cpp                                                                  *
* Language      : CPP                                                                           *
* Programmers   : Тимошин Антон Алексеевич, Воробьев Андрей Николаевич                          *
* Modified By   :                                                                               *
* Created       : 10.06.2024                                                                    *
* Last Revision : 14.06.2024                                                                    *
* Comment       :                                                                               *
************************************************************************************************/

#include <iostream>
#include "fstream"


using namespace std;

/**************************************************************
*                      ВХОДНЫЕ ДАННЫЕ                         *
**************************************************************/

//const char* filename = "non_existent_file.txt";               // несуществующий файл
//const char* filename = "empty_file.txt";                      // пустой файл
const string path = "/Users/anton/code/stepik/info.txt";        // файл с корректными исходными данными
//... всякие тесты

/**************************************************************
*                         КОНСТАНТЫ                           *
**************************************************************/

const int data_len = 10;        // фиксированная максимальная длина строки в ячейке структуры
const int max_len = 100;        // максимальное количество элементов в массиве
const int table_width = 30;     // ширина ячеек таблицы

/**************************************************************
*                         СТРУКТУРЫ                           *
**************************************************************/

struct Aircraft     // Структура для хранения данных о приземлившихся самолетах
{
    int flight_number;                  // номер рейса
    char tail_number[data_len];         // бортовой номер
    float cargo_weight;                 // вес груза
    int box_quantity;                   // количество контейнеров
    int id;                             // индекс самолета
};

struct indexSort           // Структура для индексной сортировки
{
    int index;              // индекс сортировки (позиция в исходной структуре)
    int flight_number;      // номер рейса (поле, которое нужно отсортировать)
};

/**************************************************************
*                     ПРОТОТИПЫ ФУНКЦИЙ                       *
**************************************************************/
void readDataFromFile(Aircraft &plane,
                      Aircraft *planes,
                      int &massiveLen); // функция чтения данных из файла

void echoPrint(Aircraft *planes,
               int massiveLen); // функция эхопечати исходной структуры данных


/**************************************************************
*                     ОСНОВНАЯ ПРОГРАММА                      *
**************************************************************/

int main() {
    Aircraft plane; // переменная для хранения информации об одном самолёте
    Aircraft planes[max_len]; // массив для хранения информации о всех самолётах
    indexSort massiveSort[max_len]; // массив для индексной сортировки

    int massiveLen = 0; // так как в массивах отсчет элементов начинается с 0 (строка 87)

    readDataFromFile(plane, planes, massiveLen);
    echoPrint(planes, massiveLen);

    return 0;
}

/**************************************************************
*                    ОПРЕДЕЛЕНИЕ ФУНКЦИЙ                      *
**************************************************************/

void readDataFromFile(Aircraft &plane,
                     Aircraft *planes,
                     int &massiveLen) { // функция чтения из файла
    ifstream file(path);
    while (!file.eof()) {
        massiveLen++;
        plane.id = massiveLen;
        file >> plane.flight_number >> plane.tail_number >> plane.cargo_weight >> plane.box_quantity;
        planes[massiveLen - 1] = plane; // так как в массивах отсчет элементов начинается с 0 (строка 71)
    }
}

void echoPrint(Aircraft *planes,
               int massiveLen) { // функция эхопечати данных
    for (int i = 0; i < massiveLen; i++) {
        cout << planes[i].flight_number << " " << planes[i].tail_number << " " << planes[i].cargo_weight << " " <<
        planes[i].box_quantity << endl;
    }
}
