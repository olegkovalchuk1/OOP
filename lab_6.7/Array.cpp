#include "Array.h"
#include <algorithm>

Array::Array(const Array::size_type& n) throw(std::bad_alloc, std::invalid_argument) {
    First = 0;
    Count = Size = (n > minsize ? n : minsize);
    Count = n;
    elems = new value_type[Size];
    for (UINT i = 0; i < Size; i++) elems[i] = 0;
}

Array::Array(const Array& t) throw(std::bad_alloc)
    : Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[Size]) {
    for (UINT i = 0; i < Size; ++i) elems[i] = t.elems[i];
}

Array::~Array() {
    delete[] elems;
    elems = nullptr;
}

Array& Array::operator =(const Array& t) {
    if (this != &t) {
        Array tmp(t);
        swap(tmp);
    }
    return *this;
}

void Array::push_back(const value_type& v) {
    if (Count == Size) resize(Size * 2);
    elems[Count++] = v;
}

Array::reference Array::operator [](size_type index) throw(std::out_of_range) {
    if ((First <= index) && (index < First + Size)) return elems[index - First];
    else throw std::out_of_range("Index out of range!");
}

Array::const_reference Array::operator [](size_type index) const throw(std::out_of_range) {
    if ((First <= index) && (index < First + Size)) return elems[index - First];
    else throw std::out_of_range("Index out of range!");
}

void Array::resize(size_type newsize) throw(std::bad_alloc) {
    if (newsize > capacity()) {
        value_type* data = new value_type[newsize];
        for (size_type i = 0; i < Count; ++i) data[i] = elems[i];
        delete[] elems;
        elems = data;
        Size = newsize;
    }
}

void Array::swap(Array& other) {
    std::swap(elems, other.elems);
    std::swap(Size, other.Size);
    std::swap(Count, other.Count);
    std::swap(First, other.First);
}

Array::size_type Array::capacity() const { return Size; }
Array::size_type Array::size() const { return Count; }
bool Array::empty() const { return Count == 0; }

std::ostream& operator <<(std::ostream& out, const Array& tmp) {
    for (std::size_t j = 0; j < tmp.Count; j++) out << tmp[j] << " ";
    return out;
}

std::istream& operator >>(std::istream& in, Array& tmp) {
    for (std::size_t j = 0; j < tmp.Count; j++) in >> tmp[j];
    return in;
}