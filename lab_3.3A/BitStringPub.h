#pragma once
#include "BitStringBase.h"

class BitStringPub : public BitStringBase {
public:
    BitStringPub();
    BitStringPub(long h, long l);
    BitStringPub(const BitStringBase& base);
    BitStringPub(const BitStringPub& other);
    ~BitStringPub();

    // Перевантаження інших операцій
    BitStringPub operator~() const;
    friend BitStringPub operator&(const BitStringPub& a, const BitStringPub& b);
    friend BitStringPub operator|(const BitStringPub& a, const BitStringPub& b);
    friend BitStringPub operator^(const BitStringPub& a, const BitStringPub& b);

    BitStringPub& operator++();       // Префіксний
    BitStringPub operator++(int);     // Постфіксний
    BitStringPub& operator--();
    BitStringPub operator--(int);
};