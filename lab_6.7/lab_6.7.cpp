#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"
#include "Algorythms.h"
#include "Functors.h"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int n = 8;
    Array arr(n);

    // Заповнюємо масив випадковими числами від -10 до 10
    for (int i = 0; i < n; ++i) {
        arr[i] = (rand() % 21) - 10;
    }

    cout << "=== Array ===" << endl;
    cout << arr << endl << endl;

    // 1. Тест custom_sort_if (сортуємо лише парні числа)
    IsEven<double> evenCondition;
    custom_sort_if(arr.begin(), arr.end(), evenCondition);

    cout << "=== (custom_sort_if) ===" << endl;
    cout << arr << endl << endl;

    // 2. Тест custom_sort (сортуємо весь масив)
    custom_sort(arr.begin(), arr.end());

    cout << "=== (custom_sort) ===" << endl;
    cout << arr << endl;

    return 0;
}