#include "Array.h"
#include <iostream>
#include <cstdlib> // Для exit()

using namespace std;

Array::Array(int s, unsigned char initVal) : size(s) {
    if (size > MAX_SIZE) size = MAX_SIZE;
    for (int i = 0; i < MAX_SIZE; ++i) {
        arr[i] = (i < size) ? initVal : 0;
    }
}

Array::~Array() {}

bool Array::rangeCheck(int index) const {
    return index >= 0 && index < size;
}

unsigned char& Array::operator[](int index) {
    if (!rangeCheck(index)) {
        cout << "\nПомилка: індекс поза межами масиву!" << endl;
        exit(1);
    }
    return arr[index];
}

void Array::add(const Array& other) {
    int maxSize = (size > other.size) ? size : other.size;
    for (int i = 0; i < maxSize; ++i) {
        if (i >= MAX_SIZE) break;
        if (i >= size) { arr[i] = 0; size = i + 1; }
        unsigned char val = (i < other.size) ? other.arr[i] : 0;
        arr[i] += val;
    }
}

void Array::print() const {
    for (int i = size - 1; i >= 0; --i) cout << (int)arr[i] << " ";
    cout << endl;
}