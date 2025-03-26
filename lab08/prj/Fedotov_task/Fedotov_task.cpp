#include <iostream>
#include <cmath>
#include <windows.h>
#include "ModulesFedotov.h"
#include "OutputName.h"

using namespace std;
//Функція для підзадачі 8.2.2 (Результат логічного виразу a + 1 = b + 2)
void LogicaLexpression(double a, double b) {
    bool result = (a + 1 == b + 2);
    if ((a + 1 == b + 2) == true) {
        cout << "Значення " << a << " + 1 = " << b << " + 2" << endl;
        cout << "True" << endl;
    }
    else {
        cout << "Значення " << a << " + 1 = " << b << " + 2" << endl;
        cout << "False" << endl;
    }      
}

// Основна функція
int main() {
    SetConsoleOutputCP(1251);
    Information();

    double x, y, z;
    double a, b;

    //Введення значень для задачі
    cout << "Введіть x, y, z числа: ";
    cin >> x >> y >> z;

    cout << "Введіть числа a і b щоб перевірити логічний вираз (a + 1 = b + 2): ";
    cin >> a >> b;

    //Підзадача 8.2.2
    LogicaLexpression(a, b);

    //Підзадача 8.2.3
    double result = s_calculation(x, y, z);
    cout << "Результат функції s_calculation: " << result << endl;

    // Виведення значень x, y, z у десятковій та шістнадцятковій системах
    cout << "x: " << dec << x << " (десяткова), 0x" << hex << (int)x << " (шістнадцяткова)" << endl;
    cout << "y: " << dec << y << " (десяткова), 0x" << hex << (int)y << " (шістнадцяткова)" << endl;
    cout << "z: " << dec << z << " (десяткова), 0x" << hex << (int)z << " (шістнадцяткова)" << endl;
    system("pause");

    return 0;
}
