#pragma once
#include <string>

// Інтерфейс: не містить полів, всі методи (крім деструктора) чисто віртуальні
class IFigure {
public:
    virtual ~IFigure() = default; // Віртуальний деструктор

    virtual double volume() const = 0;
    virtual std::string getName() const = 0;
};