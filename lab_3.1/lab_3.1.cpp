#include "RightAngled.h"
#include <iostream>

using namespace std;

int main() {
    RightAngled t1;               // За замовчуванням
    RightAngled t2(5.0, 12.0);    // Ініціалізації
    RightAngled t3(t2);           // Копіювання

    cout << "t1 (default): " << t1 << endl;
    cout << "t2 (init): " << t2 << endl;
    cout << "t3 (copy): " << t3 << endl;

    cout << "\nInput new triangle data:" << endl;
    cin >> t1;
    cout << "Updated t1: " << t1 << endl;

    return 0;
}