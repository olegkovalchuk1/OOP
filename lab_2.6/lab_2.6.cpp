
#include "RightAngled.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "--- 1. Initial State ---" << endl;
	cout << "RightAngled : " << RightAngled::getCounter() << endl;
	cout << "RightAngled::Pair : " << RightAngled::Pair::getCounter() << endl;

	cout << "\n--- 2. Basic object creation ---" << endl;
	RightAngled t1;
	RightAngled::Pair p1;

	p1.Init(3.0, 4.0);
	t1.Init(p1);

	// Використовуємо перевантажений оператор виводу замість Display() та toString()
	cout << "t1 details: \n" << t1 << endl;

	cout << "\n--- 3.Updating values ---" << endl;
	p1.setFirst(6.0);
	p1.setSecond(8.0);
	t1.setPair(p1);
	cout << "Updated area: " << t1.area() << endl;

	cout << "\n--- 4. Checking Counters after t1 and p1 ---" << endl;
	cout << "RightAngled : " << RightAngled::getCounter() << endl;
	cout << "RightAngled::Pair : " << RightAngled::Pair::getCounter() << endl;

	cout << "\n--- 5. Demonstration of local scope (Destructors) ---" << endl;
	{
		RightAngled local_t(5.0, 12.0); // Створюємо локальний об'єкт
		cout << "RightAngled local : " << RightAngled::getCounter() << endl;
		cout << "RightAngled::Pair local : " << RightAngled::Pair::getCounter() << endl;
	} // Тут local_t знищується (відпрацьовують деструктори)

	cout << "Counters after local scope ends:" << endl;
	cout << "RightAngled : " << RightAngled::getCounter() << endl;
	cout << "RightAngled::Pair : " << RightAngled::Pair::getCounter() << endl;

	cout << "\n--- 6. Lab 1.6 Logic: Arrays & I/O Operators ---" << endl;
	const int N = 2;
	RightAngled arr[N]; // Створення масиву (викликає конструктори 2 рази)

	for (int i = 0; i < N; i++) {
		cout << "\nElement [" << i << "]:";
		cin >> arr[i]; // Перевантажений оператор вводу (замість Read)
	}

	cout << "\n--- Array Contents ---" << endl;
	for (int i = 0; i < N; i++) {
		cout << "arr[" << i << "]: \n" << arr[i] << endl;
	}

	cout << "\n--- 7.Final Counters before exit ---" << endl;
	cout << "RightAngled : " << RightAngled::getCounter() << endl;
	cout << "RightAngled::Pair : " << RightAngled::Pair::getCounter() << endl;

	return 0;
}