#ifndef MODULESSAVELEV_H
#define MODULESSAVELEV_H

#include <vector>
#include "struct_type_project_1.h"

// Додавання нового запису
void addBenefit(std::vector<Benefit>& list);
// Видалення запису
void deleteByCode(std::vector<Benefit>& list, int code);

#endif
