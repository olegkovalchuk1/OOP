#pragma once
#include <string>

class Figure {
protected:
    std::string name;
public:
    Figure(std::string n);
    virtual ~Figure(); // Віртуальний деструктор обов'язковий

    virtual double volume() const = 0; // Чисто віртуальна функція
    std::string getName() const;
};