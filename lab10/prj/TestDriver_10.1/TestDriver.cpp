#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ModulesFedotov.h>
using namespace std;

//Допоміжна функція для створення тимчасового вхідного файлу з заданим вмістом 
void createInputFile(const string& filename, const string& content) {
    ofstream file(filename);
    file << content;
    file.close();
}

// Допоміжна функція для читання вмісту вихідного файлу
string readOutputFile(const string& filename) {
    ifstream file(filename);
    string content, line;
    while (getline(file, line)) {
        content += line + "\n";
    }
    file.close();
    return content;
}

void test_processSentence() {
    // Тестові кейси
    struct TestCase {
        string inputContent;
        string expectedOutput;
    };

    TestCase testCases[] = {
        {
            "Hello! How are you? Great!!",
            "Розробник: Андрій Фкдотов\n"
            "Установа: ЦНТУ\n"
            "Місто: Кропивницький\n"
            "Країна: Україна\n"
            "Рік розробки: 2025\n\n"
            "Кількість знаків '!': 3\n"
            "Кількість знаків '?': 1\n\n"
            "Речення без голосних літер:\n"
            "Hll! Hw r y? Grt!!\n"
        },
        {
            "Це тестове речення.",
            "Розробник: Андрій Фкдотов\n"
            "Установа: ЦНТУ\n"
            "Місто: Кропивницький\n"
            "Країна: Україна\n"
            "Рік розробки: 2025\n\n"
            "Кількість знаків '!': 0\n"
            "Кількість знаків '?': 0\n\n"
            "Речення без голосних літер:\n"
            "Ц тств рчння.\n"
        },
        {
            "aeiouAEIOUаеиіоу",
            "Розробник: Андрій Фкдотов\n"
            "Установа: ЦНТУ\n"
            "Місто: Кропивницький\n"
            "Країна: Україна\n"
            "Рік розробки: 2025\n\n"
            "Кількість знаків '!': 0\n"
            "Кількість знаків '?': 0\n\n"
            "Речення без голосних літер:\n"
            "\n"
        }
    };

    for (int i = 0; i < 3; i++) {
        // Створення тимчасових вхідних і вихідних файлів
        string inputFile = "test_input_" + to_string(i + 1) + ".txt";
        string outputFile = "test_output_" + to_string(i + 1) + ".txt";

        // Підготуйте вхідний файл
        createInputFile(inputFile, testCases[i].inputContent);

        // Відкрийте файли та запустіть функцію
        ifstream inFile(inputFile);
        ofstream outFile(outputFile);
        processSentence(inFile, outFile);
        inFile.close();
        outFile.close();

        // Зчитайте фактичний вихід
        string actualOutput = readOutputFile(outputFile);

        // Вивести детальну інформацію про тестовий приклад
        cout << "Тест кейс " << (i + 1) << " | Вхід: \"" << testCases[i].inputContent << "\"\n";
        cout << "Очікуваний результат:\n" << testCases[i].expectedOutput << "\n";
        cout << "Фактичний результат:\n" << actualOutput << "\n";

        // Перевірте, чи пройдено тест
        if (actualOutput == testCases[i].expectedOutput) {
            cout << "Результат: PASSED\n";
        }
        else {
            cout << "Результат: FAILED\n";
        }
        cout << "--------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251); 
    test_processSentence();
    system("pause");
    return 0;
}