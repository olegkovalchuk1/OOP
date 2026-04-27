#ifndef DATE_COMMON_H
#define DATE_COMMON_H

#include <string>

// Спільний переліковий тип для місяців
enum month { JAN = 0, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

// Спільна структура для збереження інформації про місяць
struct MonthInfo {
    std::string name;
    int days;
};

// Структури для демонстрації #pragma pack(1)
#pragma pack(push, 1)
struct DatePacked {
    int day;
    month m;
    int year;
    int max_size;
    int current_count;
};
#pragma pack(pop)

struct DateUnpacked {
    int day;
    month m;
    int year;
    int max_size;
    int current_count;
};

#endif // DATE_COMMON_H