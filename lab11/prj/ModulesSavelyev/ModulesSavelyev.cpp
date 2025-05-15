#include "struct_type_project_1.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <locale>
#include <regex>

const std::string DATA_FILE = "benefit_data.bin";

// Додавання нового запису
void addBenefit(std::vector<Benefit>& list) {
    Benefit b;

    std::cout << "Введіть код пільги: ";
    while (!(std::cin >> b.benefitCode) || b.benefitCode <= 0) {
        std::cout << "Невірне значення. Введіть додатне ціле число: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    std::cin.ignore();

    std::cout << "Введіть зміст пільги: ";
    std::cin.getline(b.description, sizeof(b.description));

    std::cout << "Введіть назву документа: ";
    std::cin.getline(b.documentName, sizeof(b.documentName));

    std::cout << "Введіть номер документа: ";
    std::cin.getline(b.documentNumber, sizeof(b.documentNumber));

    std::regex datePattern(R"((\d{4})-(\d{2})-(\d{2}))");
    std::cmatch match;

    do {
        std::cout << "Введіть дату прийняття документа (РРРР-ММ-ДД): ";
        std::cin.getline(b.documentDate, sizeof(b.documentDate));
        if (std::regex_match(b.documentDate, match, datePattern)) {
            int y = std::stoi(match[1]);
            int m = std::stoi(match[2]);
            int d = std::stoi(match[3]);
            int maxDay[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) maxDay[1] = 29;
            if (m >= 1 && m <= 12 && d >= 1 && d <= maxDay[m - 1]) break;
        }
        std::cout << "Некоректна дата. Повторіть.\n";
    } while (true);

    do {
        std::cout << "Введіть дату початку дії пільги (РРРР-ММ-ДД): ";
        std::cin.getline(b.startDate, sizeof(b.startDate));
        if (std::regex_match(b.startDate, match, datePattern)) {
            int y = std::stoi(match[1]);
            int m = std::stoi(match[2]);
            int d = std::stoi(match[3]);
            int maxDay[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) maxDay[1] = 29;
            if (m >= 1 && m <= 12 && d >= 1 && d <= maxDay[m - 1]) break;
        }
        std::cout << "Некоректна дата. Повторіть.\n";
    } while (true);

    do {
        std::cout << "Введіть дату закінчення дії пільги (РРРР-ММ-ДД): ";
        std::cin.getline(b.endDate, sizeof(b.endDate));
        if (std::regex_match(b.endDate, match, datePattern)) {
            int y = std::stoi(match[1]);
            int m = std::stoi(match[2]);
            int d = std::stoi(match[3]);
            int maxDay[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) maxDay[1] = 29;
            if (m >= 1 && m <= 12 && d >= 1 && d <= maxDay[m - 1]) break;
        }
        std::cout << "Некоректна дата. Повторіть.\n";
    } while (true);

    std::cout << "Введіть ознаку цільового призначення: ";
    std::cin.getline(b.targetPurpose, sizeof(b.targetPurpose));

    std::cout << "Введіть коментар: ";
    std::cin.getline(b.comment, sizeof(b.comment));

    list.push_back(b);
    std::cout << "Пільгу додано.\n";
}

// Видалення запису
void deleteByCode(std::vector<Benefit>& list, int code) {
    if (code <= 0) {
        std::cout << "Некоректний код пільги.\n";
        return;
    }
    auto it = list.begin();
    while (it != list.end()) {
        if (it->benefitCode == code) {
            it = list.erase(it);
            std::cout << "Запис із кодом " << code << " вилучено.\n";
            return;
        }
        ++it;
    }
    std::cout << "Запис із кодом " << code << " не знайдено.\n";
}