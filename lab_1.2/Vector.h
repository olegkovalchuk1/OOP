#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Vector
{
private:
	int* data;
	int size;
	int state;

public:
	int* getData() const { return data; }
	int getSize() const { return size; }
	int getState() const { return state; }

	bool setSize(int);
	void setState(int);

	bool allocateMemory(int);
	bool setElement(int, int);
	int getElement(int);

	double getNorm() const;

	bool Init(int);
	void Read();
	void Display() const;
};

Vector makeVector(int size);