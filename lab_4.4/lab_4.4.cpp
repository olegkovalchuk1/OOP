
#include <iostream>
#include <typeinfo>
#include "Complex.h"
#include "Rational.h"

// Функція виводу, яка отримує параметри базового класу за посиланням
void displayPairInfo(const Pair& p) {
    // Вивід справжнього типу поліморфного об'єкта (RTTI)
    std::cout << "[Type: " << typeid(p).name() << "] Value: ";
    p.print();
    std::cout << std::endl;
}

int main() {
    std::cout << "=== Demonstration of polymorphism via base class pointers ===" << std::endl;

    Pair* p1 = new Complex(3, 4);
    Pair* p2 = new Complex(1, 2);

    Pair* p3 = new Rational(1, 2);
    Pair* p4 = new Rational(1, 3);

    // Демонстрація функції виводу
    displayPairInfo(*p1);
    displayPairInfo(*p3);

    std::cout << "\n--- Virtual addition (Complex) ---" << std::endl;
    Pair* sumComplex = p1->add_ptr(p2);
    if (sumComplex) {
        displayPairInfo(*sumComplex);
        delete sumComplex;
    }

    std::cout << "\n--- Virtual multiplication (Rational) ---" << std::endl;
    Pair* mulRational = p3->mul_ptr(p4);
    if (mulRational) {
        displayPairInfo(*mulRational);
        delete mulRational;
    }

    std::cout << "\n=== Demonstration of pass-by-value methods (as in the task) ===" << std::endl;
    Rational z1(1, 2), z2(1, 4);
    Rational z3 = z1.add(z2); // Зверніть увагу: Reduce() викликається в конструкторі

    std::cout << "z1 = "; z1.print(); std::cout << std::endl;
    std::cout << "z2 = "; z2.print(); std::cout << std::endl;
    std::cout << "z1 + z2 = "; z3.print(); std::cout << " (Reduced automatically)" << std::endl;
    std::cout << "Value(z3) = " << z3.value() << std::endl;

    // Звільнення пам'яті
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}