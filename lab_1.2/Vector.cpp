#include "Vector.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

bool Vector::setSize(int value)
{
	if (value > 0)
	{
		size = value;
		return true;
	}
	else
	{
		size = 0;
		return false;
	}
}

void Vector::setState(int value)
{
	state = value;
}

bool Vector::allocateMemory(int value)
{
	if (setSize(value))
	{
		data = new (nothrow) int[size];
		if (!data)
		{
			setState(1); // 1 - out of memory
			return false;
		}
		setState(0);
		return true;
	}
	return false;
}

bool Vector::Init(int value)
{
	if (allocateMemory(value))
	{
		for (int i = 0; i < size; i++)
		{
			data[i] = 0;
		}
		return true;
	}
	return false;
}

bool Vector::setElement(int index, int value)
{
	if (index >= 0 && index < size)
	{
		data[index] = value;
		setState(0);
		return true;
	}
	else
	{
		setState(2); // 2 - out of bounds
		return false;
	}
}

int Vector::getElement(int index)
{
	if (index >= 0 && index < size)
	{
		setState(0);
		return data[index];
	}
	else
	{
		setState(2); // 2 - out of bounds
		return 0;
	}
}

double Vector::getNorm() const
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += data[i] * data[i];
	}
	return sqrt(sum);
}

void Vector::Read()
{
	int s;
	do
	{
		cout << " size = ? "; cin >> s;
	} while (!Init(s));

	for (int i = 0; i < size; i++)
	{
		int val;
		cout << " element [" << i << "] = ? "; cin >> val;
		setElement(i, val);
	}
}

void Vector::Display() const
{
	cout << " size = " << size << endl;
	cout << " state = " << state << endl;
	for (int i = 0; i < size; i++)
	{
		cout << " element [" << i << "] = " << data[i] << endl;
	}
}

Vector makeVector(int size)
{
	Vector v;
	if (!v.Init(size))
	{
		cout << " Error: invalid parameters or out of memory!" << endl;
		exit(1);
	}
	return v;
}