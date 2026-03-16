#include "RightAngled.h"
using namespace std;

struct DefaultStruct {
	char c;
	double d;
};

#pragma pack(push, 1)
struct PackedStruct {
	char c;
	double d;
};
#pragma pack(pop)

int main()
{
	cout << "--- Demonstration of #pragma pack(1) ---" << endl;
	cout << "Size without pack: " << sizeof(DefaultStruct) << " bytes" << endl;
	cout << "Size with pack(1): " << sizeof(PackedStruct) << " bytes\n" << endl;

	RightAngled t1;
	RightAngled t4(3.0, 4.0);

	cout << t4 << endl;

	t1 = ++t4;
	cout << t1 << endl;
	cout << t4 << endl;

	t1 = t4++;
	cout << t1 << endl;
	cout << t4 << endl;

	const int N = 2;
	RightAngled* arr = new RightAngled[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}

	delete[] arr;
	return 0;
}