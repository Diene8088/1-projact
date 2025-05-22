#include <iostream>
#include "findMinMax.h"
#include <iomanip>
#include <cmath>

using namespace std;

void findMinMax(double** data, int count) {
    if (count == 0) return;

    double minVal = data[0][1], maxVal = data[0][1];
    for (int i = 1; i < count; i++) {
        if (data[i][1] < minVal) minVal = data[i][1];
        if (data[i][1] > maxVal) maxVal = data[i][1];
    }

    cout << "\nМинимальное значение функции: " << minVal << endl;
    cout << "Максимальное значение функции: " << maxVal << endl;
}
