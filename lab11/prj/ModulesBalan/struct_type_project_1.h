#ifndef STRUCT_TYPE_PROJECT_1_H
#define STRUCT_TYPE_PROJECT_1_H

#include <cstring>

struct Benefit {
    int benefitCode;
    char description[100];
    char documentName[100];
    char documentNumber[50];
    char documentDate[20];
    char startDate[20];
    char endDate[20];
    char targetPurpose[50];
    char comment[100];

    Benefit() : benefitCode(0) {
        std::memset(description, 0, sizeof(description));
        std::memset(documentName, 0, sizeof(documentName));
        std::memset(documentNumber, 0, sizeof(documentNumber));
        std::memset(documentDate, 0, sizeof(documentDate));
        std::memset(startDate, 0, sizeof(startDate));
        std::memset(endDate, 0, sizeof(endDate));
        std::memset(targetPurpose, 0, sizeof(targetPurpose));
        std::memset(comment, 0, sizeof(comment));
    }
};

#endif