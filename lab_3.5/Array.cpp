#include "Array.h"

// Конструктор за замовчуванням (викликає сетери)
Array::Array() : data(nullptr), max_size(0), current_count(0) {
    setMaxSize(256); // За замовчуванням масив на 256 байт
    setCount(0);
}

// Конструктор ініціалізації (викликає сетери)
Array::Array(size_t max_s) : data(nullptr), max_size(0), current_count(0) {
    setMaxSize(max_s);
    setCount(0);
}

// Конструктор копіювання
Array::Array(const Array& other) : data(nullptr), max_size(0), current_count(0) {
    setMaxSize(other.max_size);
    setCount(other.current_count);
    for (size_t i = 0; i < max_size; ++i) {
        data[i] = other.data[i];
    }
}

Array::~Array() {
    delete[] data;
}

size_t Array::size() const { return max_size; }
size_t Array::count() const { return current_count; }

void Array::setMaxSize(size_t max_s) {
    if (max_s == 0) throw std::invalid_argument("Size must be greater than 0");

    unsigned char* newData = new unsigned char[max_s];
    for (size_t i = 0; i < max_s; ++i) newData[i] = 0; // Ініціалізація нулями

    if (data != nullptr) {
        size_t copyLimit = (current_count < max_s) ? current_count : max_s;
        for (size_t i = 0; i < copyLimit; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
    }

    data = newData;
    max_size = max_s;
    if (current_count > max_size) current_count = max_size;
}

void Array::setCount(size_t c) {
    if (c > max_size) throw std::invalid_argument("Count cannot exceed max size");
    current_count = c;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        setMaxSize(other.max_size);
        setCount(other.current_count);
        for (size_t i = 0; i < max_size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

unsigned char& Array::operator[](size_t index) {
    if (index >= max_size) throw std::out_of_range("Index out of bounds");
    return data[index];
}

const unsigned char& Array::operator[](size_t index) const {
    if (index >= max_size) throw std::out_of_range("Index out of bounds");
    return data[index];
}