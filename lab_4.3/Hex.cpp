#include "Hex.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Hex::Hex(int s, unsigned char initVal) : Array(s, initVal) {}

void Hex::add(const Array& other) {
    const Hex* h = dynamic_cast<const Hex*>(&other);
    if (!h) return;

    int carry = 0;
    int maxSize = (size > h->size) ? size : h->size;

    for (int i = 0; i < maxSize || carry; ++i) {
        if (i >= MAX_SIZE) break;
        if (i >= size) { arr[i] = 0; size = i + 1; }

        int sum = arr[i] + (i < h->size ? h->arr[i] : 0) + carry;
        arr[i] = sum % 16;
        carry = sum / 16;
    }
}

Hex Hex::operator+(const Hex& other) const {
    Hex result = *this;
    result.add(other);
    return result;
}

Hex Hex::operator-(const Hex& other) const {
    Hex result = *this;
    if (other > *this) return result; // Віднімаємо лише від більшого

    int borrow = 0;
    for (int i = 0; i < result.size; ++i) {
        int sub = result.arr[i] - (i < other.size ? other.arr[i] : 0) - borrow;
        if (sub < 0) { sub += 16; borrow = 1; }
        else { borrow = 0; }
        result.arr[i] = sub;
    }
    while (result.size > 1 && result.arr[result.size - 1] == 0) result.size--;
    return result;
}

Hex Hex::operator*(const Hex& other) const {
    Hex result(this->size + other.size, 0);
    for (int i = 0; i < this->size; ++i) {
        int carry = 0;
        for (int j = 0; j < other.size; ++j) {
            if (i + j >= MAX_SIZE) break;
            int prod = result.arr[i + j] + (this->arr[i] * other.arr[j]) + carry;
            result.arr[i + j] = prod % 16;
            carry = prod / 16;
        }
        if (i + other.size < MAX_SIZE) result.arr[i + other.size] += carry;
    }
    while (result.size > 1 && result.arr[result.size - 1] == 0) result.size--;
    return result;
}

Hex Hex::operator/(const Hex& other) const {
    Hex zero(1, 0);
    if (other == zero) {
        cout << "\nПомилка: Ділення на нуль в класі Hex!" << endl;
        exit(1);
    }
    Hex quotient(1, 0);
    Hex one(1, 1);
    Hex remainder = *this;
    while (remainder > other || remainder == other) {
        remainder = remainder - other;
        quotient = quotient + one;
    }
    return quotient;
}

bool Hex::operator>(const Hex& other) const {
    if (size != other.size) return size > other.size;
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] != other.arr[i]) return arr[i] > other.arr[i];
    }
    return false;
}

bool Hex::operator<(const Hex& other) const { return other > *this; }

bool Hex::operator==(const Hex& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; ++i) if (arr[i] != other.arr[i]) return false;
    return true;
}

bool Hex::operator!=(const Hex& other) const { return !(*this == other); }

void Hex::print() const {
    cout << "0x";
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] < 10) cout << (int)arr[i];
        else cout << (char)('A' + arr[i] - 10);
    }
    cout << endl;
}