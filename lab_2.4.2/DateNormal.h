#ifndef DATE_NORMAL_H
#define DATE_NORMAL_H

#include "DateCommon.h"
#include <iostream>
#include <string>

class DateNormal {
private:
    int day;
    month current_month;
    int year;

    MonthInfo monthsArray[12];
    const int max_size = 12;
    int current_count;

    void initMonths();
    bool isLeapYear(int y) const;
    void validateDate(int d, month m, int y) const;

public:
    DateNormal();
    DateNormal(int d, month m, int y);
    DateNormal(const std::string& dateStr);
    DateNormal(const DateNormal& other);

    int getDay() const;
    month getMonth() const;
    int getYear() const;
    int size() const;
    int count() const;

    void setDay(int d);
    void setMonth(month m);
    void setYear(int y);
    void setDate(int d, month m, int y); // «ручний сетер дл€ вс≥х пол≥в

    DateNormal& operator=(const DateNormal& other);
    MonthInfo operator[](month m) const;
    explicit operator std::string() const;

    friend std::istream& operator>>(std::istream& is, DateNormal& dt);
    friend std::ostream& operator<<(std::ostream& os, const DateNormal& dt);
};

#endif // DATE_NORMAL_H