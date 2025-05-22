#include "menu.h"
#include <iostream>

using namespace std;

int showMainMenu() {
    int choice;
    cout << "\nВыберите действие:\n";
    cout << "1. Вычислить функцию G\n";
    cout << "2. Вычислить функцию F\n";
    cout << "3. Вычислить функцию Y\n";
    cout << "Ваш выбор: ";
    cin >> choice;
    return choice;
}
int showEditMenu() {
    int choice;
    cout << "\nРедактирование таблицы:\n";
    cout << "1. Добавить элемент\n";
    cout << "2. Удалить элемент\n";
    cout << "3. Продолжить без изменений\n";
    cout << "Ваш выбор: ";
    cin >> choice;
    return choice;
}
