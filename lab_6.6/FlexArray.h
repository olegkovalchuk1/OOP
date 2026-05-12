#ifndef FLEXARRAY_H
#define FLEXARRAY_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Попереднє оголошення шаблону класу та зовнішньої функції вводу
template <typename T> class FlexArray;
template <typename T> istream& operator>>(istream& in, FlexArray<T>& a);

template <typename T>
class FlexArray {
public:
    typedef unsigned int UINT;
    typedef T value_type;
    typedef size_t size_type;
    typedef T& reference;
    typedef const T& const_reference;

private:
    static const size_type minsize = 10;
    size_type Size;  // ємність
    size_type Count; // кількість елементів
    size_type First; // початковий індекс 
    value_type* elems;

public:
    
    // ІТЕРАТОРИ
    
    class iterator {
    private:
        value_type* ptr;
    public:
        iterator(value_type* p = nullptr) : ptr(p) {}
        reference operator*() { return *ptr; }
        iterator& operator++() { ++ptr; return *this; }
        iterator operator++(int) { iterator tmp = *this; ++ptr; return tmp; }
        bool operator==(const iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const iterator& other) const { return ptr != other.ptr; }
        iterator operator+(size_type n) const { return iterator(ptr + n); }
        iterator operator-(size_type n) const { return iterator(ptr - n); }
        size_type operator-(const iterator& other) const { return ptr - other.ptr; }
    };

    class const_iterator {
    private:
        const value_type* ptr;
    public:
        const_iterator(const value_type* p = nullptr) : ptr(p) {}
        const_reference operator*() const { return *ptr; }
        const_iterator& operator++() { ++ptr; return *this; }
        bool operator!=(const const_iterator& other) const { return ptr != other.ptr; }
    };

    
    // КОНСТРУКТОРИ ТА ДЕСТРУКТОР
    
    FlexArray(const size_type& n = minsize) {
        First = 0;
        Count = Size = n;
        elems = new value_type[Size];
        for (UINT i = 0; i < Size; i++) elems[i] = value_type();
    }

    FlexArray(const iterator first, const iterator last) {
        First = 0;
        if (last - first >= 0) {
            Count = Size = (last - first);
            elems = new value_type[Size];
            size_type i = 0;
            for (iterator it = first; it != last; ++it, ++i) elems[i] = *it;
        }
        else {
            throw invalid_argument("Invalid iterator range");
        }
    }

    FlexArray(const FlexArray& t) : Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[t.Size]) {
        for (UINT i = 0; i < Count; ++i) elems[i] = t.elems[i];
    }

    FlexArray& operator=(const FlexArray& t) {
        if (this != &t) {
            FlexArray tmp(t);
            swap(tmp);
        }
        return *this;
    }

    ~FlexArray() { delete[] elems; }

    // МЕТОДИ ІТЕРАТОРІВ ТА РОЗМІРИ
   
    iterator begin() { return iterator(elems); }
    const_iterator begin() const { return const_iterator(elems); }
    iterator end() { return iterator(elems + Count); }
    const_iterator end() const { return const_iterator(elems + Count); }

    size_type size() const { return Count; }
    bool empty() const { return Count == 0; }
    size_type capacity() const { return Size; }

    void resize(size_type newsize) {
        if (newsize > capacity()) {
            value_type* data = new value_type[newsize];
            for (size_type i = 0; i < Count; ++i) data[i] = elems[i];
            delete[] elems;
            elems = data;
            Size = newsize;
        }
    }


    // ДОСТУП ТА МОДИФІКАЦІЯ
    
    reference operator[](size_type index) {
        if (index >= First && index < First + Count) return elems[index - First];
        throw out_of_range("Index out of range!");
    }
    const_reference operator[](size_type index) const {
        if (index >= First && index < First + Count) return elems[index - First];
        throw out_of_range("Index out of range!");
    }

    reference front() { return elems[0]; }
    const_reference front() const { return elems[0]; }
    reference back() { return elems[Count - 1]; }
    const_reference back() const { return elems[Count - 1]; }

    void push_back(const value_type& v) {
        if (Count == Size) resize(Size == 0 ? 1 : Size * 2);
        elems[Count++] = v;
    }

    void pop_back() { if (Count > 0) Count--; }
    void assign(const value_type& v) { for (size_type i = 0; i < Count; ++i) elems[i] = v; }
    void clear() { Count = 0; }

    void swap(FlexArray& other) {
        std::swap(elems, other.elems);
        std::swap(Size, other.Size);
        std::swap(Count, other.Count);
        std::swap(First, other.First);
    }


    // АРИФМЕТИЧНІ ОПЕРАЦІЇ 

    FlexArray& operator+=(const FlexArray& other) {
        if (Count != other.Count) throw invalid_argument("Sizes mismatch");
        for (size_type i = 0; i < Count; ++i) elems[i] += other.elems[i];
        return *this;
    }

    FlexArray& operator-=(const FlexArray& other) {
        if (Count != other.Count) throw invalid_argument("Sizes mismatch");
        for (size_type i = 0; i < Count; ++i) elems[i] -= other.elems[i];
        return *this;
    }

    FlexArray& operator*=(const FlexArray& other) {
        if (Count != other.Count) throw invalid_argument("Sizes mismatch");
        for (size_type i = 0; i < Count; ++i) elems[i] *= other.elems[i];
        return *this;
    }

    FlexArray& operator/=(const FlexArray& other) {
        if (Count != other.Count) throw invalid_argument("Sizes mismatch");
        for (size_type i = 0; i < Count; ++i) {
            if (other.elems[i] == 0) throw runtime_error("Division by zero");
            elems[i] /= other.elems[i];
        }
        return *this;
    }

    FlexArray operator+(const FlexArray& other) const { FlexArray res(*this); res += other; return res; }
    FlexArray operator-(const FlexArray& other) const { FlexArray res(*this); res -= other; return res; }
    FlexArray operator*(const FlexArray& other) const { FlexArray res(*this); res *= other; return res; }
    FlexArray operator/(const FlexArray& other) const { FlexArray res(*this); res /= other; return res; }


    // ОПЕРАЦІЇ ПОРІВНЯННЯ 
    
    bool operator==(const FlexArray& other) const {
        if (Count != other.Count) return false;
        for (size_type i = 0; i < Count; ++i) {
            if (elems[i] != other.elems[i]) return false;
        }
        return true;
    }

    bool operator!=(const FlexArray& other) const { return !(*this == other); }

    
    bool operator<(const FlexArray& other) const {
        size_type min_count = (Count < other.Count) ? Count : other.Count;
        for (size_type i = 0; i < min_count; ++i) {
            if (elems[i] < other.elems[i]) return true;
            if (other.elems[i] < elems[i]) return false;
        }
        return Count < other.Count;
    }

    bool operator>(const FlexArray& other) const { return other < *this; }
    bool operator<=(const FlexArray& other) const { return !(other < *this); }
    bool operator>=(const FlexArray& other) const { return !(*this < other); }

    
    // ДРУЖНІ ФУНКЦІЇ ВВОДУ/ВИВОДУ
    
    // 1. Як «нешаблонна» функція, визначена всередині класу (Вивід)
    friend ostream& operator<<(ostream& out, const FlexArray& a) {
        for (size_type i = 0; i < a.Count; ++i) out << a.elems[i] << " ";
        return out;
    }

    // 2. Як зовнішня функція-шаблон (Ввід)
    friend istream& operator>> <>(istream& in, FlexArray<T>& a);
};

// Реалізація зовнішньої функції-шаблону для вводу
template <typename T>
istream& operator>>(istream& in, FlexArray<T>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        in >> a[i];
    }
    return in;
}

#endif 