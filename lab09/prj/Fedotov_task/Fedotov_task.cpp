#include <iostream>
#include <windows.h>
#include <OutputName.h>
#include <ModulesFedotov.h>
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(65001);
	SetConsoleCP(1251);
	Information();
	char b;
	do {
		char a;
		cout << "Виберіть функцію\n" <<
			"Введіть \\ щоб викликати функцію s_calculation()\n" <<
			"Введіть 5 щоб викликати функцію задачі 9.1\n" <<
			"Введіть 4 щоб викликати функцію задачі 9.2\n" <<
			"Введіть 3 щоб викликати функцію задачі 9.3\n";
		cin >> a;

		switch (a)
		{
		case '\\':
			double x, y, z;
			cout << "Введіть три числа для x, y, z: ";
			cin >> x >> y >> z;
			cout << "Результат роботи функції s_calculation: " << s_calculation(x, y, z) << endl;
			break;
		case '5':
			int bofort;
			while (true) {
				cout << "Введіть бал Бафорта від 0-12: ";
				cin >> bofort;
				if (bofort > 12) {
					cout << "Неправильне значення, спробуйте ще раз: ";
				}
				else {
					cout << "Результат роботи задачі 9.1: " << printWindSpeedInfo(bofort) << endl;
					break;
				}
			}

			break;
		case '4':
			int headCircumferenc;
			cout << "Введіть обхвад голови.\nДля дорослих від 53 або 54, 55 або 56, 57 або 58, 59 або 60, 61 або 62.\nДля дітей від 48 або 49, 50 або 51, 52 або 53 " << endl;
			while (true) {
				cin >> headCircumferenc;
				if (headCircumferenc == 53 || headCircumferenc == 54 || headCircumferenc == 55 || headCircumferenc == 56 ||
					headCircumferenc == 57 || headCircumferenc == 58 || headCircumferenc == 59 || headCircumferenc == 60 ||
					headCircumferenc == 61 || headCircumferenc == 62 || headCircumferenc == 48 || headCircumferenc == 49 ||
					headCircumferenc == 50 || headCircumferenc == 51 || headCircumferenc == 52 || headCircumferenc == 53) {
					cout << "Результат роботи задачі 9.2: " << headCircumference(headCircumferenc) << endl;
					break;
				}
				else {
					cout << "Неправильне значення, спробуйте ще раз: ";
				}
			}
			break;
		case '3':
			unsigned int number;
			while (true) {
				cout << "Введіть натуральне число від 0 до 8999: ";
				cin >> number;
				if (number > 8999) {
					cout << "Неправильне значення, спробуйте ще раз: ";
				}
				else {
					cout << "Результат роботи задачі 9.3: " << countBits(number) << endl;
					break;
				}
			}
			break;
		default:
			cout << "Помилкове введеня!" << endl;
			Beep(1000, 500);
			break;

		}
		cout << "Бажаєте завершити програму ? Якщо ні — введіть будь - який символ.Якщо так — введіть t, T або С :";
		cin >> b;

	} while (b != 't' && b != 'T' && b != 'C');
	system("pause");
}