#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

class Array {
protected:
    unsigned char* data;      // Масив байтів (unsigned char для коректного збереження довжини в 0-му байті)
    size_t max_size;          // Максимальний розмір (size)
    size_t current_count;     // Поточна кількість елементів (count)

public:
    Array();
    Array(size_t max_s);
    Array(const Array& other);
    virtual ~Array();

    // Методи доступу (Getters)
    size_t size() const;
    size_t count() const;

    // Методи запису (Setters)
    void setMaxSize(size_t max_s);
    void setCount(size_t c);

    // Обов'язкові перевантаження за таблицею (методи класу)
    Array& operator=(const Array& other);
    unsigned char& operator[](size_t index);
    const unsigned char& operator[](size_t index) const;
};

#endif // ARRAY_H