#include "OctString.h"
#include <sstream>

// Викликаємо базові конструктори (які вже використовують сетери)
OctString::OctString() : SymString() {}

OctString::OctString(const std::string& id, const std::string& state) : SymString(id, state) {}

OctString::OctString(const OctString& other) : SymString(other) {}

OctString::~OctString() {}

// Перевизначений ToString
std::string OctString::ToString() const {
    return "[OctString] ID: " + getId() + " | Вісімкове значення: " + getState();
}

void OctString::ShowDec() const {
    try {
        long long decValue = std::stoll(getState(), nullptr, 8);
        std::cout << "[OctString ShowDec] ID: " << getId() << " | Десяткове значення: " << decValue << std::endl;
    }
    catch (...) {
        std::cout << "[Помилка] Некоректне вісімкове значення у об'єкта " << getId() << std::endl;
    }
}

// Оператор присвоєння =
OctString& OctString::operator=(const OctString& other) {
    if (this != &other) {
        SymString::operator=(other); // Виклик безпечного базового оператора
    }
    return *this;
}

// Оператор +
OctString operator+(const OctString& s1, const OctString& s2) {
    long long val1 = 0, val2 = 0;

    try { if (!s1.getState().empty()) val1 = std::stoll(s1.getState(), nullptr, 8); }
    catch (...) {}
    try { if (!s2.getState().empty()) val2 = std::stoll(s2.getState(), nullptr, 8); }
    catch (...) {}

    long long sum = val1 + val2;

    std::stringstream ss;
    ss << std::oct << sum;

    OctString result;
    result.setId(s1.getId() + "_plus_" + s2.getId());
    result.setState(ss.str());
    return result;
}

// Оператор виводу <<
std::ostream& operator<<(std::ostream& os, const OctString& obj) {
    os << obj.ToString();
    return os;
}

// Оператор вводу >>
std::istream& operator>>(std::istream& is, OctString& obj) {
    std::string newId, newState;
    is >> newId >> newState;
    obj.setId(newId);
    obj.setState(newState);
    return is;
}