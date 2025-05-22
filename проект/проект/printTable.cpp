#include "printTable.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void printTable(double** data, int count) {
    cout << fixed << setprecision(5);
    cout << "\nТаблица значений:\n";
    cout << setw(10) << "x" << setw(20) << "Функция\n";
    for (int i = 0; i < count; i++) {
        cout << setw(10) << data[i][0] << setw(20) << data[i][1] << endl;
    }
}

