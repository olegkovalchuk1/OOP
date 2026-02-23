
#include <iostream>
#include <cstdlib>
#include "Time.h"

using namespace std;

Time makeTime(int x, int y)
{
	Time t;
	if (!t.Init(x, y))
	{
		cout << "Wrong arguments to Init!" << endl;
		exit(1); // Завершення роботи при передачі помилкових параметрів
	}
	return t;
}

int main()
{
	Time t;
	t.Read();
	t.Display();
	cout << "Total minutes = " << t.minutes() << endl << endl;

	int x, y;
	cout << "Input time values:" << endl << endl;
	cout << " Hours = "; cin >> x;
	cout << " Minutes = "; cin >> y;

	t = makeTime(x, y);
	t.Display();
	cout << "Total minutes = " << t.minutes() << endl;

	cin.get();
	return 0;
}