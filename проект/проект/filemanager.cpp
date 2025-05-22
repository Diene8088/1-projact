#include "filemanager.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void saveToFile(double** data, int count, const char* filename) {
    ofstream file(filename, ios::out | ios::trunc);  // Явно указываем режимы открытия
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла для записи.\n";
        return;
    }
    
    file << fixed << setprecision(5);
    for (int i = 0; i < count; i++) {
        file << data[i][0] << "\t" << data[i][1] << endl;
    }
    
    file.close();  // Явно закрываем файл
    cout << "Результаты успешно сохранены в " << filename << endl;
}

void readFromFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << filename << " для чтения.\n";
        cerr << "Убедитесь, что файл существует и доступен для чтения.\n";
        return;
    }
    
    cout << "\nСодержимое файла " << filename << ":\n";
    cout << setw(10) << "x" << setw(20) << "Функция\n";
    
    double x, value;
    while (file >> x >> value) {
        cout << setw(10) << x << setw(20) << value << endl;
    }
    
    if (file.bad()) {
        cerr << "Ошибка при чтении файла.\n";
    }
    
    file.close();
}
