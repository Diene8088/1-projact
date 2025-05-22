#include <iostream>
#include "addElement.h"
#include "findMinMax.h"
#include "printTable.h"
#include "removeElement.h"
#include "menu.h"
#include "sorting.h"
#include "filemanager.h"
#include <thread>
#include <chrono>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    char repeat;
    do {
        try {
            double x1, x2, a;
            int steps, choice;
            
            cout << "Введите начальное значение x: ";
            if (!(cin >> x1)) throw runtime_error("Ошибка ввода x1.");
            cout << "Введите конечное значение x: ";
            if (!(cin >> x2)) throw runtime_error("Ошибка ввода x2.");
            if (x2 < x1) throw invalid_argument("Конечное значение меньше начального.");
            cout << "Введите количество шагов: ";
            if (!(cin >> steps) || steps <= 0) throw invalid_argument("Некорректное количество шагов.");
            cout << "Введите значение a: ";
            if (!(cin >> a)) throw runtime_error("Ошибка ввода a.");

            choice = showMainMenu();
            if (choice < 1 || choice > 3) throw invalid_argument("Неверный выбор функции.");

            double stepSize = (x2 - x1) / steps;
            double** data = new double*[steps + 1];
            int count = 0;

            for (int i = 0; i <= steps; i++) {
                double x = x1 + i * stepSize;
                double result = 0;
                bool error = false;
                if (choice == 1) result = calculateG(a, x, error);
                else if (choice == 2) result = calculateF(a, x);
                else if (choice == 3) result = calculateY(a, x, error);

                if (!error) {
                    data[count] = new double[2]{x, result};
                    count++;
                }
            }

            printTable(data, count);
            findMinMax(data, count);

            int sortCol;
            cout << "Выберите столбец для сортировки (0 - x, 1 - функция): ";
            cin >> sortCol;
            if (sortCol != 0 && sortCol != 1) throw invalid_argument("Неверный выбор столбца.");

            cout << "Выберите метод сортировки:\n1. Пузырьковая\n2. Быстрая\nВаш выбор: ";
            int sortMethod;
            cin >> sortMethod;

            int operations = 0;
            if (sortMethod == 1) bubbleSort(data, count, sortCol, operations);
            else if (sortMethod == 2) quickSort(data, 0, count - 1, sortCol, operations);
            else throw invalid_argument("Неверный выбор метода сортировки.");

            cout << "Отсортированная таблица:\n";
            printTable(data, count);
            cout << "Количество операций: " << operations << endl;

            // Редактирование таблицы
            int editChoice;
            do {
                editChoice = showEditMenu();
                clearInputBuffer(); // Очищаем буфер после ввода числа

                switch (editChoice) {
                    case 1:
                        addElement(&data, count);
                        printTable(data, count);
                        break;
                    case 2:
                        removeElement(&data, count);
                        printTable(data, count);
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Неверный выбор. Попробуйте снова.\n";
                }
            } while (editChoice != 3);

            cout << "Хотите сохранить результаты? (y/n): ";
            char save;
            cin >> save;
            clearInputBuffer();
            if (save == 'y' || save == 'Y') {
                saveToFile(data, count, "results.txt");
                this_thread::sleep_for(chrono::milliseconds(100));
            }

            cout << "Хотите просмотреть сохранённые результаты? (y/n): ";
            char view;
            cin >> view;
            clearInputBuffer();
            if (view == 'y' || view == 'Y') {
                readFromFile("results.txt");
            }


            for (int i = 0; i < count; i++) delete[] data[i];
            delete[] data;

        } catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
            clearInputBuffer();
        }

        cout << "\nХотите начать заново? (y/n): ";
        cin >> repeat;
        clearInputBuffer(); // Очищаем буфер после ввода символа

    } while (repeat == 'y' || repeat == 'Y');

    cout << "Программа завершена.\n";
    return 0;
}
