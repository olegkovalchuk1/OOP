
#include <iostream>
#include "Matrix.h"

using namespace std;

#pragma pack(push, 1)
struct PackedMatrix {
    int size;
    int count;
    int N;
    int** data;
};
#pragma pack(pop)

int menu()
{
    int i;
    cout << endl;
    cout << "Enter your choice:" << endl << endl;
    cout << " 1 - Input matrix from keyboard" << endl;
    cout << " 2 - Print matrix" << endl;
    cout << " 3 - Test prefix increment (++m)" << endl;
    cout << " 4 - Test postfix decrement (m--)" << endl;
    cout << " 5 - Calculate matrix norm" << endl;
    cout << " 6 - Subtract another matrix (m = m - m2)" << endl;
    cout << " 0 - Exit" << endl << endl;
    cin >> i;
    return i;
}

int main()
{
    cout << "Size of Matrix: " << sizeof(Matrix) << " bytes" << endl;
    cout << "Size of Matrix with #pragma pack(1): " << sizeof(PackedMatrix) << " bytes" << endl;
    cout << "---------------------------------------" << endl;

    // Демонстрація різних способів створення
    Matrix m1; // Без аргументів
    Matrix m2(2, 2); // Ініціалізації
    Matrix m3 = m2;  // Копіювання
    Matrix m4("2 2 1 2 3 4"); // Ініціалізація рядком (2х2, елементи 1,2,3,4)

    // Масив об'єктів
    Matrix arr[2] = { Matrix(1, 1), Matrix(2, 2) };

    int i;
    do {
        switch (i = menu())
        {
        case 1:
            cin >> m1;
            break;
        case 2:
            cout << m1;
            // Демонстрація приведення типу
            cout << "As a string: " << endl << string(m1) << endl;
            break;
        case 3:
            ++m1;
            cout << "After ++m1:" << endl << m1;
            break;
        case 4:
            m1--;
            cout << "After m1--:" << endl << m1;
            break;
        case 5:
            cout << "Matrix norm: " << m1.calculateNorm() << endl;
            break;
        case 6:
            cout << "Enter matrix to subtract:" << endl;
            cin >> m2;
            m3 = m1 - m2;
            cout << "Subtraction result:" << endl << m3;
            break;
        case 0:
            break;
        default:
            cout << "Incorrect input!" << endl << endl;
        }
    } while (i != 0);

    return 0;
}