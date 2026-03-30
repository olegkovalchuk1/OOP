#include "BitStringBase.h"
#include <sstream>

BitStringBase::BitStringBase() {
    setHigh(0); setLow(0);
}

BitStringBase::BitStringBase(long h, long l) {
    setHigh(h); setLow(l);
}

BitStringBase::BitStringBase(const BitStringBase& other) {
    setHigh(other.getHigh()); setLow(other.getLow());
}

BitStringBase::~BitStringBase() {}

BitStringBase::operator string() const {
    stringstream ss;
    ss << "[High: " << getHigh() << ", Low: " << getLow() << "]";
    return ss.str();
}

ostream& operator<<(ostream& out, const BitStringBase& obj) {
    return out << (string)obj;
}

istream& operator>>(istream& in, BitStringBase& obj) {
    long h, l;
    cout << "  High = "; in >> h;
    cout << "  Low = "; in >> l;
    obj.setHigh(h);
    obj.setLow(l);
    return in;
}