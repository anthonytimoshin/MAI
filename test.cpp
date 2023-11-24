/****************************************************************
*                    КАФЕДРА № 304 1 КУРС                       *
*---------------------------------------------------------------*
* Project Type : Win32 Console Application                      *
* Project Name : function_tabulation                            *
* File Name    : main.cpp                                       *
* Language     : C/C++                                          *
* Programmer(s): Тимошин А.А., Воробьёв А.Н.                    *
* Modified By  :                                                *
* Lit source   :                                                *
* Created      : 23/11/23                                       *
* Last Revision: 24/11/23                                       *
* Comment(s)   : Табулирование функций                          *
****************************************************************/


#include <iostream>
#include "cmath"
#include "iomanip"

using namespace std;


int YesNo(string YN) {
    cout << "(Y/N): ";
    cin >> YN;
    if (YN == "YES" or YN == "yes" or YN == "y" or YN == "Y") {
        return 1;
    } else if (YN == "NO" or YN == "no" or YN == "n" or YN == "N") {
        cout << "Rerun program, please.";
        exit(0);
    } else {
        cout << "I don't understand you. Please, print 'Y' for YES or 'N' for NO." << "\n";
        YesNo(YN);
    }
    return -1;
}


int main() {
    int points, i = 0;
    double A, B, N, h, x, Fx, Gx;
    string YN;

    cout << "Enter the values of A, B, N:" << "\n";
    cout << "The left border of the interval (A) = ";
    if (!(cin >> A)) {
        cout << "Error! Wrong type of variable (expected: double). Rerun program, please.";
        exit(0);
    }

    cout << "The right border of the interval (B) = ";
    if (!(cin >> B)) {
        cout << "Error! Wrong type of variable (expected: double). Rerun program, please.";
        exit(0);
    }

    if (B == A) {
        N = 0;
    } else {
        cout << "The number of intervals (N) = ";
        if (!(cin >> N)) {
            cout << "Error! Wrong type of variable (expected: integer). Rerun program, please.";
            exit(0);
        }
        if (N != round(N)) {
            cout << "Error! Wrong type of variable (expected: integer). Rerun program, please.";
            exit(0);
        }
        if (N <= 0) {
            cout << "Error! N should be more or equal to zero. Rerun program, please.";
            exit(0);
        }
    }

    if (A > B) {
        double temp = A;
        A = B;
        B = temp;
        cout << "A should be less than or equal to B. Do you accept new values of variables?" << "\n";
        cout << "(print 'Y' for YES or 'N' for NO)" << "\n";
        cout << "A = " << A << "\t" << "B = " << B << "\n";
        if (YesNo(YN) == 0) exit(0);
    }

    cout << endl;
    cout << "Are the values correct? (print 'Y' for YES or 'N' for NO)" << "\n";
    cout << "A = " << A << "\t" << "B = " << B << "\t" << "N = " << N << "\n";
    if (YesNo(YN) == 0) exit(0);

    points = (int)N + 1;
    h = (B - A) / N;
    x = A;

    cout << endl;
    cout << "┌─────────┬─────────┬─────────┬─────────┐" << "\n";
    cout << "│    N    │    x    │    Fx   │    Gx   │" << "\n";
    cout << "├─────────┼─────────┼─────────┼─────────┤" << "\n";
    for(i; i < points; i++) {
        x += i * h;
        Fx = sin(x) + cos(x) - 1;
        Gx = pow((x+5), 3) / (1 + pow(sin(x), 2));
        cout << "│" << setw(9) << i << "│" << setw(9) << x << "│" << setw(9) << Fx << "│" << setw(9) << Gx << "│" << "\n";
        cout << "├─────────┼─────────┼─────────┼─────────┤" << "\n";
    }

    return 0;
}