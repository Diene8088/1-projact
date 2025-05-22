#include "sorting.h"
#include <iostream>

using namespace std;

void bubbleSort(double** data, int count, int column, int& operations) {
    operations = 0;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            operations++;
            if (data[j][column] > data[j+1][column]) {
                swap(data[j], data[j+1]);
            }
        }
    }
}

void quickSort(double** data, int left, int right, int column, int& operations) {
    int i = left, j = right;
    double pivot = data[(left + right) / 2][column];
    while (i <= j) {
        while (data[i][column] < pivot) { i++; operations++; }
        while (data[j][column] > pivot) { j--; operations++; }
        if (i <= j) {
            swap(data[i], data[j]);
            i++; j--;
        }
    }
    if (left < j) quickSort(data, left, j, column, operations);
    if (i < right) quickSort(data, i, right, column, operations);
}