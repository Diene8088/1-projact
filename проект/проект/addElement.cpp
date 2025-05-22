#include "addElement.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void addElement(double*** data, int& count) {
    double x, value;
    cout << "Введите x и значение функции: ";
    cin >> x >> value;

    double** newData = new double*[count + 1];
    for (int i = 0; i < count; i++) newData[i] = (*data)[i];

    newData[count] = new double[2]{x, value};
    delete[] *data;
    *data = newData;
    count++;
}
