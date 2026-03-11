

#include <iostream>
#include "BitString.h"

using namespace std;

// Структура для демонстрації розміру з #pragma pack(1)
#pragma pack(push, 1)
struct BitStringPack
{
	long high;
	long low;
};
#pragma pack(pop)

int main()
{
	// 1. Демонстрація розміру класу
	cout << "Size of BitString (without pack): " << sizeof(BitString) << " bytes" << endl;
	cout << "Size of BitString (with #pragma pack(1)): " << sizeof(BitStringPack) << " bytes\n" << endl;

	// 2. Створення об'єктів різними конструкторами
	BitString b1;                 
	BitString b2(15, 255);             
	BitString b3 = b2;                  

	cout << "Initial values:" << endl;
	cout << "b1 (default): " << b1 << endl;
	cout << "b2 (init)   : " << b2 << endl;
	cout << "b3 (copy b2): " << b3 << endl << endl;

	// 3. Перевірка вводу-виводу
	cout << "Input b1 (64-bit string parts):" << endl;
	cin >> b1;
	cout << "b1 is now   : " << b1 << endl << endl;

	// 4. Інкременти та декременти
	BitString b4;
	cout << "--- Increment / Decrement ---" << endl;
	cout << "b2 = " << b2 << endl;

	b4 = ++b2;
	cout << "b4 = ++b2:\nb2 = " << b2 << "\nb4 = " << b4 << endl << endl;

	b4 = --b2;
	cout << "b4 = --b2:\nb2 = " << b2 << "\nb4 = " << b4 << endl << endl;

	b4 = b2++;
	cout << "b4 = b2++:\nb2 = " << b2 << "\nb4 = " << b4 << endl << endl;

	b4 = b2--;
	cout << "b4 = b2--:\nb2 = " << b2 << "\nb4 = " << b4 << endl << endl;

	// 5. Побітові операції
	cout << "--- Bitwise Operations ---" << endl;
	cout << "~b2     : " << ~b2 << endl;
	cout << "b1 & b2 : " << (b1 & b2) << endl;
	cout << "b1 | b2 : " << (b1 | b2) << endl;
	cout << "b1 ^ b2 : " << (b1 ^ b2) << endl << endl;

	// 6. Масив об'єктів
	cout << "--- Array of objects ---" << endl;
	BitString arr[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "Object " << i + 1 << ":" << endl;
		cin >> arr[i];
	}

	cout << "\nDisplaying array:" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	cin.get();
	return 0;
}