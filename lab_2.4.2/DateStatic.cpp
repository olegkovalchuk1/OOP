#include "DateStatic.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>

// Ініціалізація статичного масиву
MonthInfo DateStatic::staticMonthsArray[12] = {
    {"January", 31}, {"February", 28}, {"March", 31}, {"April", 30},
    {"May", 31}, {"June", 30}, {"July", 31}, {"August", 31},
    {"September", 30}, {"October", 31}, {"November", 30}, {"December", 31}
};

bool DateStatic::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

void DateStatic::validateDate(int d, month m, int y) const {
    if (m < JAN || m > DEC) throw std::invalid_argument("Invalid month");
    int daysInMonth = staticMonthsArray[m].days;
    if (m == FEB && isLeapYear(y)) daysInMonth = 29;
    if (d < 1 || d > daysInMonth) {
        throw std::invalid_argument("Invalid day for the given month and year");
    }
}

// Конструктори (звертаються до сетера)
DateStatic::DateStatic() : day(1), current_month(JAN), year(2000), current_count(12) {
    setDate(1, JAN, 2000); // Сетер
}

DateStatic::DateStatic(int d, month m, int y) : day(1), current_month(JAN), year(2000), current_count(12) {
    setDate(d, m, y); // Сетер
}

DateStatic::DateStatic(const std::string& dateStr) : day(1), current_month(JAN), year(2000), current_count(12) {
    int d, y, m_int;
    char dot1, dot2;
    std::istringstream ss(dateStr);
    if (ss >> d >> dot1 >> m_int >> dot2 >> y && dot1 == '.' && dot2 == '.') {
        setDate(d, static_cast<month>(m_int - 1), y); // Сетер
    }
    else {
        throw std::invalid_argument("Invalid string format");
    }
}

DateStatic::DateStatic(const DateStatic& other) : current_count(other.current_count) {
    setDate(other.day, other.current_month, other.year); // Сетер
}

// Гетери
int DateStatic::getDay() const { return day; }
month DateStatic::getMonth() const { return current_month; }
int DateStatic::getYear() const { return year; }
int DateStatic::size() const { return max_size; }
int DateStatic::count() const { return current_count; }

// Сетери
void DateStatic::setDay(int d) { setDate(d, current_month, year); }
void DateStatic::setMonth(month m) { setDate(day, m, year); }
void DateStatic::setYear(int y) { setDate(day, current_month, y); }

void DateStatic::setDate(int d, month m, int y) {
    validateDate(d, m, y);
    day = d; current_month = m; year = y;
}

// Оператори
DateStatic& DateStatic::operator=(const DateStatic& other) {
    if (this != &other) {
        setDate(other.day, other.current_month, other.year); // Використання сетера
    }
    return *this;
}

MonthInfo DateStatic::operator[](month m) const {
    if (m < JAN || m > DEC) throw std::out_of_range("Invalid month index");
    return staticMonthsArray[m];
}

DateStatic::operator std::string() const {
    std::ostringstream ss;
    ss << std::setfill('0') << std::setw(2) << day << "."
        << std::setw(2) << (current_month + 1) << "."
        << year << " [" << staticMonthsArray[current_month].name << "]";
    return ss.str();
}

std::istream& operator>>(std::istream& is, DateStatic& dt) {
    int d, y, m_int;
    std::cout << "Enter date (day month year separated by space): ";
    if (is >> d >> m_int >> y) {
        dt.setDate(d, static_cast<month>(m_int - 1), y); // Використання сетера для вводу!
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const DateStatic& dt) {
    os << static_cast<std::string>(dt); // Використання приведення до рядка для виводу
    return os;
}