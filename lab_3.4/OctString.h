#ifndef OCTSTRING_H
#define OCTSTRING_H

#include "SymString.h"

class OctString : public SymString {
public:
    // Конструктори
    OctString();
    OctString(const std::string& id, const std::string& state);
    OctString(const OctString& other);

    // Деструктор
    ~OctString() override;

    // Перевизначений метод ToString
    std::string ToString() const override;

    // Специфічний метод варіанту
    void ShowDec() const;

    // Перевантаження оператора присвоєння =
    OctString& operator=(const OctString& other);

    // Перевантаження оператора + (математичне додавання у вісімковій системі)
    friend OctString operator+(const OctString& s1, const OctString& s2);

    // Оператори вводу/виводу для похідного класу
    friend std::ostream& operator<<(std::ostream& os, const OctString& obj);
    friend std::istream& operator>>(std::istream& is, OctString& obj);
};

#endif // OCTSTRING_H