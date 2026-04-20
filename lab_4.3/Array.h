#pragma once

class Array {
protected:
    static const int MAX_SIZE = 100;
    unsigned char arr[MAX_SIZE];
    int size;

    bool rangeCheck(int index) const;

public:
    Array(int s = 0, unsigned char initVal = 0);
    virtual ~Array();

    unsigned char& operator[](int index);

    virtual void add(const Array& other);
    virtual void print() const;
};