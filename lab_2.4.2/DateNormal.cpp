#include "DateNormal.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>

void DateNormal::initMonths() {
    monthsArray[JAN] = { "January", 31 }; monthsArray[FEB] = { "February", 28 };
    monthsArray[MAR] = { "March", 31 };   monthsArray[APR] = { "April", 30 };
    monthsArray[MAY] = { "May", 31 };     monthsArray[JUN] = { "June", 30 };
    monthsArray[JUL] = { "July", 31 };    monthsArray[AUG] = { "August", 31 };
    monthsArray[SEP] = { "September", 30 }; monthsArray[OCT] = { "October", 31 };
    monthsArray[NOV] = { "November", 30 };  monthsArray[DEC] = { "December", 31 };
}

bool DateNormal::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

void DateNormal::validateDate(int d, month m, int y) const {
    if (m < JAN || m > DEC) throw std::invalid_argument("Invalid month");
    int daysInMonth = monthsArray[m].days;
    if (m == FEB && isLeapYear(y)) daysInMonth = 29;
    if (d < 1 || d > daysInMonth) {
        throw std::invalid_argument("Invalid day for the given month and year");
    }
}

// Конструктори (звертаються до сетера setDate)
DateNormal::DateNormal() : day(1), current_month(JAN), year(2000), current_count(12) {
    initMonths();
    setDate(1, JAN, 2000); // Делегування сеттеру
}

DateNormal::DateNormal(int d, month m, int y) : day(1), current_month(JAN), year(2000), current_count(12) {
    initMonths();
    setDate(d, m, y); // Делегування сеттеру
}

DateNormal::DateNormal(const std::string& dateStr) : day(1), current_month(JAN), year(2000), current_count(12) {
    initMonths();
    int d, y, m_int;
    char dot1, dot2;
    std::istringstream ss(dateStr);
    if (ss >> d >> dot1 >> m_int >> dot2 >> y && dot1 == '.' && dot2 == '.') {
        setDate(d, static_cast<month>(m_int - 1), y); // Делегування сеттеру
    }
    else {
        throw std::invalid_argument("Invalid string format (expected DD.MM.YYYY)");
    }
}

DateNormal::DateNormal(const DateNormal& other) : current_count(other.current_count) {
    initMonths();
    setDate(other.day, other.current_month, other.year); // Делегування сеттеру
}

// Гетери
int DateNormal::getDay() const { return day; }
month DateNormal::getMonth() const { return current_month; }
int DateNormal::getYear() const { return year; }
int DateNormal::size() const { return max_size; }
int DateNormal::count() const { return current_count; }

// Сетери
void DateNormal::setDay(int d) { setDate(d, current_month, year); }
void DateNormal::setMonth(month m) { setDate(day, m, year); }
void DateNormal::setYear(int y) { setDate(day, current_month, y); }

void DateNormal::setDate(int d, month m, int y) {
    validateDate(d, m, y); // Перевірка перед записом
    day = d;
    current_month = m;
    year = y;
}

// Оператори
DateNormal& DateNormal::operator=(const DateNormal& other) {
    if (this != &other) {
        setDate(other.day, other.current_month, other.year); // Використання сетера
    }
    return *this;
}

MonthInfo DateNormal::operator[](month m) const {
    if (m < JAN || m > DEC) throw std::out_of_range("Invalid month index");
    return monthsArray[m];
}

DateNormal::operator std::string() const {
    std::ostringstream ss;
    ss << std::setfill('0') << std::setw(2) << day << "."
        << std::setw(2) << (current_month + 1) << "."
        << year << " (" << monthsArray[current_month].name << ")";
    return ss.str();
}

std::istream& operator>>(std::istream& is, DateNormal& dt) {
    int d, y, m_int;
    std::cout << "Enter date (day month year separated by space): ";
    if (is >> d >> m_int >> y) {
        dt.setDate(d, static_cast<month>(m_int - 1), y); // Використання сетера для вводу!
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const DateNormal& dt) {
    os << static_cast<std::string>(dt); // Використання приведення до рядка для виводу
    return os;
}