#include "Array.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Функція для виконання завдання за Варіантом 9
Array processArray(const double* arr, int n) {
    bool hasNegative = false;
    double firstNegative = 1.0;

    // 1. Знаходимо перше від'ємне число
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            firstNegative = arr[i];
            hasNegative = true;
            break;
        }
    }

    // 2. Створюємо динамічний масив-результат
    Array result(n);
    double sumAbs = 0; // Сума за абсолютною величиною

    // 3. Формуємо новий масив
    for (int i = 0; i < n; i++) {
        double val = arr[i];

        // Перевіряємо чи число парне (оскільки масив double, переводимо в int для перевірки)
        if (static_cast<int>(val) % 2 == 0) {
            if (hasNegative) {
                val *= firstNegative; // Множимо кожне парне число на перше від'ємне
            }
        }

        result[i] = val;
        sumAbs += std::abs(val); // Додаємо до суми абсолютних величин
    }

    // 4. Обчислюємо середнє арифметичне за абсолютною величиною
    double meanAbs = 0;
    if (n > 0) {
        meanAbs = sumAbs / n;
    }

    // 5. Збільшуємо довжину і дописуємо суму та середнє арифметичне (працює метод push_back)
    result.push_back(sumAbs);
    result.push_back(meanAbs);

    return result;
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    int n;

    cout << "Введіть розмір звичайного масиву: ";
    cin >> n;

    if (n <= 0) {
        cout << "Розмір має бути більшим за 0!" << endl;
        return 1;
    }

    // Звичайний масив
    double* regularArray = new double[n];

    cout << "Початковий звичайний масив (від -50 до +50):" << endl;
    for (int i = 0; i < n; i++) {
        // Генеруємо випадкові числа від -50 до 50
        regularArray[i] = (rand() % 101) - 50;
        cout << regularArray[i] << " ";
    }
    cout << endl << endl;

    // Викликаємо функцію згідно із завданням
    Array dynamicResult = processArray(regularArray, n);

    cout << "Результат (динамічний масив з доданими елементами):" << endl;
    cout << dynamicResult;

    // Очищення пам'яті
    delete[] regularArray;

    return 0;
}