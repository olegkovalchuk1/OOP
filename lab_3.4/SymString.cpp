#include "SymString.h"

// Конструктори (звертаються виключно до сетерів)
SymString::SymString() {
    setId("unknown");
    setState("");
}

SymString::SymString(const std::string& id, const std::string& state) {
    setId(id);
    setState(state);
}

SymString::SymString(const SymString& other) {
    setId(other.getId());
    setState(other.getState());
}

SymString::~SymString() {}

// Сетери
void SymString::setId(const std::string& newId) { id = newId; }
void SymString::setState(const std::string& newState) { state = newState; }

// Гетери
std::string SymString::getId() const { return id; }
std::string SymString::getState() const { return state; }

// ToString
std::string SymString::ToString() const {
    return "[SymString] ID: " + id + " | Значення: " + state;
}

void SymString::Show() const {
    std::cout << ToString() << std::endl;
}

// Індексування []
char& SymString::operator[](size_t index) {
    if (index >= state.length()) {
        throw std::out_of_range("Індекс поза межами рядка");
    }
    return state[index];
}

const char& SymString::operator[](size_t index) const {
    if (index >= state.length()) {
        throw std::out_of_range("Індекс поза межами рядка");
    }
    return state[index];
}

// Оператор присвоєння =
SymString& SymString::operator=(const SymString& other) {
    if (this != &other) {
        setId(other.getId());
        setState(other.getState());
    }
    return *this;
}

// Оператор +
SymString operator+(const SymString& s1, const SymString& s2) {
    SymString result;
    result.setId(s1.getId() + "+" + s2.getId());
    result.setState(s1.getState() + s2.getState());
    return result;
}

// Оператор виводу <<
std::ostream& operator<<(std::ostream& os, const SymString& obj) {
    os << obj.ToString();
    return os;
}

// Оператор вводу >>
std::istream& operator>>(std::istream& is, SymString& obj) {
    std::string newId, newState;
    is >> newId >> newState;
    obj.setId(newId);
    obj.setState(newState);
    return is;
}