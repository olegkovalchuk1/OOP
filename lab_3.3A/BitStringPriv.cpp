#include "BitStringPriv.h"

BitStringPriv::BitStringPriv() : BitStringBase() {}
BitStringPriv::BitStringPriv(long h, long l) : BitStringBase(h, l) {}
BitStringPriv::BitStringPriv(const BitStringPriv& other) : BitStringBase(other) {}
BitStringPriv::~BitStringPriv() {}

// ќператори ≥нкременту, декременту та поб≥тов≥ реал≥зуютьс€ ≥дентично до Pub
BitStringPriv BitStringPriv::operator~() const { return BitStringPriv(~getHigh(), ~getLow()); }
BitStringPriv operator&(const BitStringPriv& a, const BitStringPriv& b) { return BitStringPriv(a.getHigh() & b.getHigh(), a.getLow() & b.getLow()); }
BitStringPriv operator|(const BitStringPriv& a, const BitStringPriv& b) { return BitStringPriv(a.getHigh() | b.getHigh(), a.getLow() | b.getLow()); }
BitStringPriv operator^(const BitStringPriv& a, const BitStringPriv& b) { return BitStringPriv(a.getHigh() ^ b.getHigh(), a.getLow() ^ b.getLow()); }

BitStringPriv& BitStringPriv::operator++() { setLow(getLow() + 1); if (getLow() == 0) setHigh(getHigh() + 1); return *this; }
BitStringPriv BitStringPriv::operator++(int) { BitStringPriv t(*this); ++(*this); return t; }
BitStringPriv& BitStringPriv::operator--() { if (getLow() == 0) setHigh(getHigh() - 1); setLow(getLow() - 1); return *this; }
BitStringPriv BitStringPriv::operator--(int) { BitStringPriv t(*this); --(*this); return t; }

// явне приведенн€ до базового класу дл€ використанн€ його оператор≥в
ostream& operator<<(ostream& out, const BitStringPriv& obj) {
    return out << (const BitStringBase&)obj;
}

istream& operator>>(istream& in, BitStringPriv& obj) {
    return in >> (BitStringBase&)obj;
}