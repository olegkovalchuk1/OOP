#ifndef DATE_STATIC_H
#define DATE_STATIC_H

#include "DateCommon.h"
#include <iostream>
#include <string>

class DateStatic {
private:
    int day;
    month current_month;
    int year;

    static MonthInfo staticMonthsArray[12];
    const int max_size = 12;
    int current_count;

    bool isLeapYear(int y) const;
    void validateDate(int d, month m, int y) const;

public:
    DateStatic();
    DateStatic(int d, month m, int y);
    DateStatic(const std::string& dateStr);
    DateStatic(const DateStatic& other);

    int getDay() const;
    month getMonth() const;
    int getYear() const;
    int size() const;
    int count() const;

    void setDay(int d);
    void setMonth(month m);
    void setYear(int y);
    void setDate(int d, month m, int y); // «ручний сетер

    DateStatic& operator=(const DateStatic& other);
    MonthInfo operator[](month m) const;
    explicit operator std::string() const;

    friend std::istream& operator>>(std::istream& is, DateStatic& dt);
    friend std::ostream& operator<<(std::ostream& os, const DateStatic& dt);
};

#endif // DATE_STATIC_H