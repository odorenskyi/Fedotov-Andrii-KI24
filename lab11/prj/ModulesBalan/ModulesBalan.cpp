#include "struct_type_project_1.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <locale>

const std::string DATA_FILE = "benefit_data.bin";

// Виведення всіх записів
void displayAll(const std::vector<Benefit>& list) {
    if (list.empty()) {
        std::cout << "Довідник порожній.\n";
        return;
    }

    std::cout << "\nУсі записи довідника:\n";
    for (const Benefit& b : list) {
        if (b.benefitCode <= 0) {
            std::cout << "Пошкоджений запис (некоректний код пільги).\n";
            continue;
        }

        std::cout << "-------------------------\n";
        std::cout << "Код пільги: " << b.benefitCode << "\n";
        std::cout << "Зміст пільги: " << (b.description[0] ? b.description : "Немає") << "\n";
        std::cout << "Документ: " << (b.documentName[0] ? b.documentName : "Немає") << "\n";
        std::cout << "Номер документа: " << (b.documentNumber[0] ? b.documentNumber : "Немає") << "\n";
        std::cout << "Дата прийняття документа: " << (b.documentDate[0] ? b.documentDate : "Немає") << "\n";
        std::cout << "Початок дії пільги: " << (b.startDate[0] ? b.startDate : "Немає") << "\n";
        std::cout << "Кінець дії пільги: " << (b.endDate[0] ? b.endDate : "Немає") << "\n";
        std::cout << "Ознака цільового призначення: " << (b.targetPurpose[0] ? b.targetPurpose : "Немає") << "\n";
        std::cout << "Коментар: " << (b.comment[0] ? b.comment : "Немає") << "\n";
    }
}

// Експорт у текстовий файл
void exportToTextFile(const std::vector<Benefit>& list, const std::string& filename) {
    std::ofstream fout(filename);
    if (!fout) {
        std::cerr << "Не вдалося відкрити файл для запису: " << filename << "\n";
        return;
    }

    for (const Benefit& b : list) {
        if (b.benefitCode <= 0) continue; // Пропускаємо некоректні записи
        fout << "Код пільги: " << b.benefitCode << "\n";
        fout << "Зміст пільги: " << (b.description[0] ? b.description : "Немає") << "\n";
        fout << "Документ: " << (b.documentName[0] ? b.documentName : "Немає") << "\n";
        fout << "Номер документа: " << (b.documentNumber[0] ? b.documentNumber : "Немає") << "\n";
        fout << "Дата прийняття документа: " << (b.documentDate[0] ? b.documentDate : "Немає") << "\n";
        fout << "Початок дії пільги: " << (b.startDate[0] ? b.startDate : "Немає") << "\n";
        fout << "Кінець дії пільги: " << (b.endDate[0] ? b.endDate : "Немає") << "\n";
        fout << "Ознака цільового призначення: " << (b.targetPurpose[0] ? b.targetPurpose : "Немає") << "\n";
        fout << "Коментар: " << (b.comment[0] ? b.comment : "Немає") << "\n";
        fout << "---------------------------\n";
    }

    fout.close();
    std::cout << "Експортовано у файл: " << filename << "\n";
}