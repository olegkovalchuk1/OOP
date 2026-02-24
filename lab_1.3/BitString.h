
#pragma once

class BitString
{
	long high, low;
public:
	long GetHigh() const { return high; }
	long GetLow() const { return low; }
	bool SetHigh(long value);
	bool SetLow(long value);
	bool Init(long, long);
	void Read();
	void Display() const;
	const char* toString() const;

	BitString Not() const;
	BitString And(const BitString& other) const;
	BitString Or(const BitString& other) const;
};