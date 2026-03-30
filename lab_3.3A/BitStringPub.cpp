#include "BitStringPub.h"

BitStringPub::BitStringPub() : BitStringBase() {}
BitStringPub::BitStringPub(long h, long l) : BitStringBase(h, l) {}
BitStringPub::BitStringPub(const BitStringBase& base) : BitStringBase(base) {}
BitStringPub::BitStringPub(const BitStringPub& other) : BitStringBase(other) {}
BitStringPub::~BitStringPub() {}

BitStringPub BitStringPub::operator~() const {
    return BitStringPub(~getHigh(), ~getLow());
}

BitStringPub operator&(const BitStringPub& a, const BitStringPub& b) {
    return BitStringPub(a.getHigh() & b.getHigh(), a.getLow() & b.getLow());
}

BitStringPub operator|(const BitStringPub& a, const BitStringPub& b) {
    return BitStringPub(a.getHigh() | b.getHigh(), a.getLow() | b.getLow());
}

BitStringPub operator^(const BitStringPub& a, const BitStringPub& b) {
    return BitStringPub(a.getHigh() ^ b.getHigh(), a.getLow() ^ b.getLow());
}

BitStringPub& BitStringPub::operator++() {
    setLow(getLow() + 1);
    if (getLow() == 0) setHigh(getHigh() + 1); // ≈мул€ц≥€ переповненн€ 64-bit
    return *this;
}

BitStringPub BitStringPub::operator++(int) {
    BitStringPub temp(*this);
    ++(*this);
    return temp;
}

BitStringPub& BitStringPub::operator--() {
    if (getLow() == 0) setHigh(getHigh() - 1);
    setLow(getLow() - 1);
    return *this;
}

BitStringPub BitStringPub::operator--(int) {
    BitStringPub temp(*this);
    --(*this);
    return temp;
}