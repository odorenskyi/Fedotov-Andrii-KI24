#include "struct_type_project_1.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <locale>

const std::string DATA_FILE = "benefit_data.bin";

// Збереження у файл
void saveToFile(const std::vector<Benefit>& list) {
    std::ofstream fout(DATA_FILE, std::ios::binary);
    if (!fout) {
        std::cerr << "Помилка при відкритті файлу для запису.\n";
        return;
    }
    for (const Benefit& b : list) {
        if (b.benefitCode <= 0) continue; // Пропускаємо некоректні записи
        fout.write(reinterpret_cast<const char*>(&b), sizeof(Benefit));
    }
    if (!fout.good()) {
        std::cerr << "Сталася помилка при записі у файл.\n";
    }
    fout.close();
    std::cout << "Дані збережено у файл: " << DATA_FILE << "\n";
}

// Пошук за кодом
void searchByCode(const std::vector<Benefit>& list, int code) {
    bool found = false;
    for (const Benefit& b : list) {
        if (b.benefitCode == code && b.benefitCode > 0) {
            std::cout << "\nЗапис знайдено:\n";
            std::cout << "Код пільги: " << b.benefitCode << "\n";
            std::cout << "Зміст пільги: " << (b.description[0] ? b.description : "Немає") << "\n";
            std::cout << "Документ: " << (b.documentName[0] ? b.documentName : "Немає") << "\n";
            std::cout << "Номер документа: " << (b.documentNumber[0] ? b.documentNumber : "Немає") << "\n";
            std::cout << "Дата прийняття документа: " << (b.documentDate[0] ? b.documentDate : "Немає") << "\n";
            std::cout << "Початок дії пільги: " << (b.startDate[0] ? b.startDate : "Немає") << "\n";
            std::cout << "Кінець дії пільги: " << (b.endDate[0] ? b.endDate : "Немає") << "\n";
            std::cout << "Ознака цільового призначення: " << (b.targetPurpose[0] ? b.targetPurpose : "Немає") << "\n";
            std::cout << "Коментар: " << (b.comment[0] ? b.comment : "Немає") << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Запис із кодом " << code << " не знайдено.\n";
    }
}