#ifndef VECT_H
#define VECT_H

#include "Exceptions.h"
#include <iostream>

template <typename T>
class Vect {
private:
    T* data;
    size_t capacity;
    size_t current_size;

    void resize() {
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        T* new_data = new T[new_capacity]; // Використання new за завданням
        for (size_t i = 0; i < current_size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    Vect() : data(nullptr), capacity(0), current_size(0) {}
    ~Vect() { delete[] data; }

    Vect(const Vect&) = delete;
    Vect& operator=(const Vect&) = delete;

    void push_back(const T& value) {
        if (current_size == capacity) resize();
        data[current_size++] = value;
    }

    void erase_front() {
        if (current_size == 0) {
            
            // ВИМОГА: Виняток стандартного класу

            throw std::out_of_range("Vect: attempt to erase from empty array!");
        }
        for (size_t i = 0; i < current_size - 1; ++i) {
            data[i] = data[i + 1];
        }
        current_size--;
    }

    T& front() {
        if (current_size == 0) {
           
            // ГЕНЕРУВАННЯ ВИНЯТКУ ДЛЯ ОБРОБКИ ЗА ВКАЗІВНИКОМ
        
            throw new MyCustomException("Vect: array is empty!");
        }
        return data[0];
    }

    size_t size() const { return current_size; }
    bool empty() const { return current_size == 0; }
};

#endif