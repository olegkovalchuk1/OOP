#pragma once
#include "BitStringBase.h"

class BitStringPriv : private BitStringBase {
public:
    BitStringPriv();
    BitStringPriv(long h, long l);
    BitStringPriv(const BitStringPriv& other);
    ~BitStringPriv();

    // Робимо гетери доступними для зручності перевантажень
    using BitStringBase::getHigh;
    using BitStringBase::getLow;

    BitStringPriv operator~() const;
    friend BitStringPriv operator&(const BitStringPriv& a, const BitStringPriv& b);
    friend BitStringPriv operator|(const BitStringPriv& a, const BitStringPriv& b);
    friend BitStringPriv operator^(const BitStringPriv& a, const BitStringPriv& b);

    BitStringPriv& operator++();
    BitStringPriv operator++(int);
    BitStringPriv& operator--();
    BitStringPriv operator--(int);

    // Ввід/вивід для закритого нащадка
    friend ostream& operator<<(ostream& out, const BitStringPriv& obj);
    friend istream& operator>>(istream& in, BitStringPriv& obj);
};