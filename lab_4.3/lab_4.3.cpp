#include <iostream>
#include <typeinfo>
#include <clocale>
#include "Array.h"
#include "Hex.h"
#include "Money.h"

using namespace std;

// Глобальна функція для перевірки віртуального виклику через посилання
void virtualAddTest(Array& target, const Array& source) {
    target.add(source);
}

int main() {
    // Налаштування української мови для консолі
#ifdef _WIN32
    system("chcp 1251 > nul");
#endif
    setlocale(LC_ALL, "uk_UA.utf8");

    cout << "=== Демонстрація поліморфізму та RTTI ===" << endl;
    Array* poly1 = new Hex(2, 5);
    Array* poly2 = new Money(3, 1);

    cout << "Справжній тип poly1: " << typeid(*poly1).name() << endl;
    cout << "Справжній тип poly2: " << typeid(*poly2).name() << endl << endl;

    // --- Тестування Hex ---
    cout << "=== Тестування класу Hex (база 16) ===" << endl;
    Hex h1(2, 10); // 0xAA
    Hex h2(1, 6);  // 0x6
    cout << "h1 = "; h1.print();
    cout << "h2 = "; h2.print();

    Hex hAdd = h1 + h2; cout << "h1 + h2 = "; hAdd.print(); // 0xB0
    Hex hSub = h1 - h2; cout << "h1 - h2 = "; hSub.print(); // 0xA4
    Hex hMul = h1 * h2; cout << "h1 * h2 = "; hMul.print(); // 0x3FC
    Hex hDiv = h1 / h2; cout << "h1 / h2 = "; hDiv.print(); // 0x1C

    if (h1 > h2) cout << "h1 більше за h2" << endl;

    // --- Тестування Money ---
    cout << "\n=== Тестування класу Money (база 10) ===" << endl;
    Money m1(4, 0); m1[0] = 0; m1[1] = 5; m1[2] = 5; m1[3] = 2; // 25,50 грн
    Money m2(3, 0); m2[0] = 0; m2[1] = 5; m2[2] = 1;          // 1,50 грн

    cout << "m1 = "; m1.print();
    cout << "m2 = "; m2.print();

    Money mAdd = m1 + m2; cout << "m1 + m2 = "; mAdd.print(); // 27,00 грн
    Money mSub = m1 - m2; cout << "m1 - m2 = "; mSub.print(); // 24,00 грн
    Money mDiv2 = m1 / m2; cout << "m1 / m2 (у разах) = "; mDiv2.print(); // 17

    // --- Віртуальний виклик ---
    cout << "\n=== Демонстрація віртуальної функції add() ===" << endl;
    virtualAddTest(m1, m2);
    cout << "m1 після virtualAddTest(m1, m2): "; m1.print();

    delete poly1;
    delete poly2;

    return 0;
}