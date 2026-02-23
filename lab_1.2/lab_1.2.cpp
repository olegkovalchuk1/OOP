#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	Vector v;
	v.Read();
	v.Display();
	cout << " norm = " << v.getNorm() << endl;

	cout << " --- Testing makeVector --- " << endl;
	Vector v2 = makeVector(3);
	v2.setElement(0, 5);
	v2.setElement(1, 10);
	v2.setElement(2, 15);
	v2.Display();

	cout << " --- Testing out of bounds --- " << endl;
	v2.getElement(5);
	cout << " state after invalid index = " << v2.getState() << endl;

	return 0;
}