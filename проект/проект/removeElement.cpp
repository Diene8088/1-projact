#include "removeElement.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
void removeElement(double*** data, int& count) {
    if (count == 0) {
        cout << "Нет элементов для удаления.\n";
        return;
    }

    int index;
    cout << "Введите индекс для удаления (0.." << count - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= count) {
        cout << "Ошибка: неверный индекс.\n";
        return;
    }

    double** newData = new double*[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i == index) {
            delete[] (*data)[i];
            continue;
        }
        newData[j++] = (*data)[i];
    }

    delete[] *data;
    *data = newData;
    count--;
}

double calculateG(double a, double x, bool& error) {
    double denom = -9 * a * a + 37 * a * x + 40 * x * x;
    if (denom == 0) {
        error = true;
        return 0;
    }
    return 3 * (14 * a * a + 23 * a * x - 30 * x * x) / denom;
}

double calculateF(double a, double x) {
    double expr = 18 * a * a - a * x - 4 * x * x;
    return -tan(expr);
}

double calculateY(double a, double x, bool& error) {
    double arg = 35 * a * a - 27 * a * x + 4 * x * x + 1;
    if (arg <= 0) {
        error = true;
        return 0;
    }
    return log2(arg);
}
