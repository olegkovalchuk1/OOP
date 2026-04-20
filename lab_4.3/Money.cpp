#include "Money.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Money::Money(int s, unsigned char initVal) : Array(s, initVal) {}

void Money::add(const Array& other) {
    const Money* m = dynamic_cast<const Money*>(&other);
    if (!m) return;

    int carry = 0;
    int maxSize = (size > m->size) ? size : m->size;

    for (int i = 0; i < maxSize || carry; ++i) {
        if (i >= MAX_SIZE) break;
        if (i >= size) { arr[i] = 0; size = i + 1; }

        int sum = arr[i] + (i < m->size ? m->arr[i] : 0) + carry;
        arr[i] = sum % 10;
        carry = sum / 10;
    }
}

Money Money::operator+(const Money& other) const {
    Money result = *this;
    result.add(other);
    return result;
}

Money Money::operator-(const Money& other) const {
    Money result = *this;
    if (other > *this) return result;

    int borrow = 0;
    for (int i = 0; i < result.size; ++i) {
        int sub = result.arr[i] - (i < other.size ? other.arr[i] : 0) - borrow;
        if (sub < 0) { sub += 10; borrow = 1; }
        else { borrow = 0; }
        result.arr[i] = sub;
    }
    while (result.size > 3 && result.arr[result.size - 1] == 0) result.size--;
    return result;
}

Money Money::operator*(const Money& other) const {
    Money result(this->size + other.size, 0);
    for (int i = 0; i < this->size; ++i) {
        int carry = 0;
        for (int j = 0; j < other.size; ++j) {
            if (i + j >= MAX_SIZE) break;
            int prod = result.arr[i + j] + (this->arr[i] * other.arr[j]) + carry;
            result.arr[i + j] = prod % 10;
            carry = prod / 10;
        }
        if (i + other.size < MAX_SIZE) result.arr[i + other.size] += carry;
    }
    while (result.size > 3 && result.arr[result.size - 1] == 0) result.size--;
    return result;
}

Money Money::operator/(const Money& other) const {
    Money zero(3, 0);
    if (other == zero) {
        cout << "\nПомилка: Ділення на нуль в класі Money!" << endl;
        exit(1);
    }
    Money quotient(3, 0);
    Money one(3, 0); one[0] = 1;
    Money remainder = *this;
    while (remainder > other || remainder == other) {
        remainder = remainder - other;
        quotient = quotient + one;
    }
    return quotient;
}

bool Money::operator>(const Money& other) const {
    if (size != other.size) return size > other.size;
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] != other.arr[i]) return arr[i] > other.arr[i];
    }
    return false;
}

bool Money::operator<(const Money& other) const { return other > *this; }

bool Money::operator==(const Money& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; ++i) if (arr[i] != other.arr[i]) return false;
    return true;
}

bool Money::operator!=(const Money& other) const { return !(*this == other); }

void Money::print() const {
    for (int i = (size > 3 ? size : 3) - 1; i >= 0; --i) {
        cout << (int)(i < size ? arr[i] : 0);
        if (i == 2) cout << ",";
    }
    cout << " грн" << endl;
}