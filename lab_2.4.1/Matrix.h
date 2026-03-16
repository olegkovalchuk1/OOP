
#pragma once
#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 50; // Максимально можливий розмір масиву (рядків)

class Matrix
{
    int size;     // максимальна кількість елементів масиву (рядків)
    int count;    // поточна кількість елементів (K - рядків)
    int N;        // кількість стовпців
    int** data;   // вказівник на масив

    void allocateMemory();
    void freeMemory();

public:
    Matrix();
    Matrix(int, int);
    Matrix(string); // Конструктор ініціалізації літерним рядком
    Matrix(const Matrix&);
    ~Matrix();

    // Методи доступу
    int Size() const; // Метод size(), що повертає встановлену максимальну довжину
    int getCount() const;
    int getN() const;
    void setElement(int r, int c, int value);
    int getElement(int r, int c) const;

    double calculateNorm() const; // Обчислення норми матриці

    // Перевантаження згідно з правилами (Методи класу)
    Matrix& operator = (const Matrix&);
    int* operator [] (int); // Індексування
    operator string () const; // Приведення до рядка

    // Інкремент та декремент для числових полів (всіх елементів матриці)
    Matrix& operator ++ ();    // Префіксний
    Matrix& operator -- ();    // Префіксний
    Matrix operator ++ (int);  // Постфіксний
    Matrix operator -- (int);  // Постфіксний

    // Зовнішні дружні функції (Бінарні операції + ввід/вивід)
    friend Matrix operator - (const Matrix&, const Matrix&);
    friend bool operator == (Matrix&, Matrix&);
    friend ostream& operator << (ostream&, const Matrix&);
    friend istream& operator >> (istream&, Matrix&);
};