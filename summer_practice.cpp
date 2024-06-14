/*********************************************************************************************************
*                               Курс ПРОГРАММИРОВАНИЕ                                                    *
**********************************************************************************************************
* Project type  : Win64 Console Application                                                              *
* Project name  : Practice                                                                               *
* File name     : test.cpp                                                                               *
* Language      : CPP                                                                                    *
* Programmers   : Тимошин Антон Алексеевич, Воробьев Андрей Николаевич                                   *
* Modified By   :                                                                                        *
* Created       : 10.06.2024                                                                             *
* Last Revision : 14.06.2024                                                                             *
* Comment       :                                                                                        *
*********************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**************************************************************/
/*           Г Л О Б А Л Ь Н Ы Е   К О Н С Т А Н Т Ы          */
/**************************************************************/

const char file[] = "/Users/anton/code/stepik/info.txt";    // файл исходных данных

bool Input_Error = false;  // булевая переменная-флаг ошибки ввода

struct Aircraft // Структура для хранения данных о самолетах
{
    char  Number[40];   // номер рейса
    int Num;            // бортовой номер
    float Weight;       // вес груза
    int boxCount;       // количество контейнеров
};

struct Index // Структура для индексной сортировки
{
    int Ind;            // индекс сортировки
    int Num;            // номер рейса
};

/********************************************************************
*              П Р О Т О Т И П Ы    Ф У Н К Ц И Й                   *
*********************************************************************/

//Функция вывода ошибок пользователю
void Error(int ErrorCode);

//Функция счетчик строк
int StrCount();

//Функция ввода из файла
void Input(Aircraft* AGroup);

//Функция эхо-вывода
void Print(Aircraft* AGroup, int Count);

//Функция обмена значением
void swap(Index* IndexVec, int i, int j);

//Функция выбор-сортировки
void selection_sort(Index* IndexVec, int Size);

//Функция вывода результата
void PrintResult(Aircraft* AGroup, Index* IndexVec, int Count);

//Функция начала сортировки
void Sort(Aircraft* AGroup, Index* IndexVec, int Count);

//Функция подсчета общего числа контейнеров
int BoxSumm(Aircraft* AGroup, int Count);

/**************************************************************/
/*            О С Н О В Н А Я     П Р О Г Р А М М А           */
/**************************************************************/

int main()
{
//    setlocale(LC_ALL, "RUSSIAN");

    int Size = StrCount();
    Aircraft* Plane = new Aircraft[Size];
    Index* IndexVec = new Index[Size];

    if (!Input_Error) {
        Input(Plane);
        if (!Input_Error) {
            Print(Plane, Size);
            Sort(Plane, IndexVec, Size);
            PrintResult(Plane, IndexVec, Size);
        }
    }

    delete[] Plane;
    delete[] IndexVec;
    return 0;
}

/**************************************************************/
/*           О П Р Е Д Е Л Е Н И Е  Ф У Н К Ц И Й             */
/**************************************************************/
