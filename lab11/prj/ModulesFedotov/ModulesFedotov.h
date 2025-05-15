#ifndef MODULESFEDOTOV_H
#define MODULESFEDOTOV_H

#include <vector>
#include <string>
#include "struct_type_project_1.h"
// Збереження у файл
void saveToFile(const std::vector<Benefit>& list);

// Пошук за кодом
void searchByCode(const std::vector<Benefit>& list, int code);

#endif