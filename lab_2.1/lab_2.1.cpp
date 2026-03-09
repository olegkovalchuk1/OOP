#include <iostream>
#include "Time.h"

using namespace std;

#pragma pack(push, 1)
class TimePacked
{
	int first, second;
};
#pragma pack(pop)

int main() {
	Time a(2, 30);
	Time b;
	Time c(a);

	cout << "Testing increments:" << endl;
	cout << a++ << endl;
	cout << a << endl;
	cout << ++a << endl;
	cout << a << endl;

	cout << "Testing decrements:" << endl;
	cout << a-- << endl;
	cout << a << endl;
	cout << --a << endl;
	cout << a << endl;

	Time x;
	cout << "Input time ->" << endl;
	cin >> x;

	b = x;
	cout << "Result of assignment (b = x):" << endl;
	cout << b;

	cout << "Total minutes in b = " << b.minutes() << endl;

	cout << "Array of objects:" << endl;
	Time arr[2];
	arr[0] = Time(1, 15);
	arr[1] = Time(2, 45);
	cout << arr[0] << arr[1];

	cout << "Size without pack: " << sizeof(Time) << endl;
	cout << "Size with pack(1): " << sizeof(TimePacked) << endl;

	cin.get();
	return 0;
}