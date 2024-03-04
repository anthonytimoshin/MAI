/****************************************************************
*                    КАФЕДРА № 304 1 КУРС                       *
*---------------------------------------------------------------*
* Project Type : Win32 Console Application                      *
* Project Name : one_dimensional arrays                         *
* File Name    : main.cpp                                       *
* Language     : C/C++                                          *
* Programmer(s): Тимошин А.А., Воробьёв А.Н.                    *
* Modified By  :                                                *
* Lit source   :                                                *
* Created      : 21/12/23                                       *
* Last Revision: 21/12/23                                       *
* Comment(s)   : Одномерные массивы                             *
****************************************************************/


#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    // инициализация переменной файла

    string path = "data.txt";

    // некорректные тесты

//    string path = "/Users/anton/code/stepik/test1.txt"; // отсутсвуют входные данные
//    string path = "/Users/anton/code/stepik/test2.txt"; // отсутсвует файл
//    string path = "/Users/anton/code/stepik/test3.txt"; // недостаточное количество входных данных (вводится только N)
//    string path = "/Users/anton/code/stepik/test4.txt"; // недостаточное количество вхордных данных (вводится N и неполный массив)
//    string path = "/Users/anton/code/stepik/test5.txt"; // недостаточное количество входных данных (вводится только массив)
//    string path = "/Users/anton/code/stepik/test6.txt"; // некорректный тип переменных
//    string path = "/Users/anton/code/stepik/test7.txt"; // лишние данные в файле
//    string path = "/Users/anton/code/stepik/test8.txt"; // неккоректное значение N
//    string path = "/Users/anton/code/stepik/test9.txt"; // неккоректное значение N

    // корректные тесты

//    string path = "/Users/anton/code/stepik/test10.txt"; // корректные данные
//    string path = "/Users/anton/code/stepik/test11.txt"; // N = 0
//    string path = "/Users/anton/code/stepik/test12.txt"; // массив содержит отрицательные числа

    ifstream file(path); // чтение данных из файла

    // Проверка существования файла
    if (!file)
    {
        cout << "Файл не найден" << endl;
        return -1;
    }
    else
    {
        cout << "Файл открыт" << endl;
    }

    int N; // значение заданное по условию
    file >> N; // чтение переменной N из файла

    if (N < 0 or N > 10) {
        cout << "Не удалось считать значение" << endl;
        return -1;
    }

    // Проверка ввода
    if (file.fail())
    {
        cout << "Не удалось считать значение" << endl;
        return -1;
    }

    // Эхо-печать
    cout << "Значение величины N = " << N << endl;

    int VEC[10]; // задание одномерного массива
    cout << "Значения элементов массива VEC: ";
    // Вывод элементов массива
    for (int i = 0; i < 10; i++)
    {
        file >> VEC[i];
        // Проверка ввода
        if (file.fail())
        {
            cout << "\n" << "Не удалось считать значение" << endl;
            return -1;
        }
        cout << VEC[i] << " ";
    }
    cout << endl;

    // Проверка количества элементов в файле
    if (!file.eof())
    {
        cout << "Ошибка: В файле находится больше значений, чем ожидается" << endl;
        return -1;
    }

    int NEWVEC[10]; // задание нового одномерного массива
    int Sum = 0; // сумма для каждого элемента нового массива
    int SumP = 0; // сумма положительных элементов массива
    int SumN = 0; // значение суммы первых N элементов массива
    int Min; // значение наименьшего по абсолютной величине элемента массива
    int MinNom; // индекс наименьшего по абсолютной величине элемента массива

    // заполнение нового массива
    for (int i = 0; i < 10; i++)
    {
        if (VEC[i] > 0)
        {
            SumP = SumP + VEC[i]; // нахождение суммы положительных элементов массива
        }
        Sum = Sum + VEC[i];
        if (i != (N - 1)) // проверка, что элемент не является исключением
        {
            NEWVEC[i] = Sum; // значения элементов нового массива
        }
    }

    NEWVEC[N - 1] = SumP; // значание элемента "исключения"
    for (int i = 0; i < N; i++)
    {
        SumN = SumN + NEWVEC[i];
    }
    cout << "Значения элементов полученного массива: ";
    // нахождение значения суммы первых N элементов массива
    for (int i = 0; i < 10; i++)
    {
        cout << NEWVEC[i] << " ";
    }
    cout << "\n" << "Значение суммы первых N элементов массива = " << SumN << endl;

    int Check; // переменная проверки
    Min = NEWVEC[0]; // определение минимального элемента
    MinNom = 1; // определение индекса минимального элемента
    // нахождение значения минимального по абсолютной величине элемента и его индекса
    for (int i = 0; i < 10; i++)
    {
        Check = NEWVEC[i];
        if (abs(Check) < abs(Min))
        {
            Min = Check;
            MinNom = i + 1;
        }
    }
    cout << "Наименьший по абсолютной величине элемент номер " << MinNom << " со значением " << Min << endl;

    file.close(); // закрытие файла
    return 0;
}
