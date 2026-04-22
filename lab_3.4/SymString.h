#ifndef SYMSTRING_H
#define SYMSTRING_H

#include <string>
#include <iostream>
#include <stdexcept>

class SymString {
protected:
    std::string id;
    std::string state;

public:
    // Конструктори
    SymString();
    SymString(const std::string& id, const std::string& state);
    SymString(const SymString& other);

    // Деструктор
    virtual ~SymString();

    // Сетери (Мутатори)
    void setId(const std::string& newId);
    void setState(const std::string& newState);

    // Гетери (Аксесори)
    std::string getId() const;
    std::string getState() const;

    // Перетворення в рядок
    virtual std::string ToString() const;

    // Вивід на екран
    virtual void Show() const;

    // Перевантаження оператора індексування []
    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    // Перевантаження оператора присвоєння =
    SymString& operator=(const SymString& other);

    // Перевантаження оператора + (конкатенація)
    friend SymString operator+(const SymString& s1, const SymString& s2);

    // Оператори вводу/виводу
    friend std::ostream& operator<<(std::ostream& os, const SymString& obj);
    friend std::istream& operator>>(std::istream& is, SymString& obj);
};

#endif // SYMSTRING_H