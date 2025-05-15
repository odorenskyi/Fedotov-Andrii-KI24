#ifndef MODULESBALAN_H
#define MODULESBALAN_H

#include <vector>
#include <string>
#include "struct_type_project_1.h"
// Виведення всіх записів
void displayAll(const std::vector<Benefit>& list);

// Експорт у текстовий файл
void exportToTextFile(const std::vector<Benefit>& list, const std::string& filename);

#endif