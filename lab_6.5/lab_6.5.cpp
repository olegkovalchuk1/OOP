#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

int main() {
    // Інстанціювання для типів int, double, std::string
    Queue<int> intQueue;
    Queue<double> doubleQueue;
    Queue<string> stringQueue;

    cout << "--- Testing Exception Handling ---" << endl;

    // 1. Опрацювання ЗА ПОСИЛАННЯМ (Виняток-нащадок стандартного класу)
    try {
        intQueue.dequeue();
    }
    catch (const DerivedException& e) { // <-- catch за посиланням
        cout << "1. Caught BY REFERENCE (derived from std): " << e.what() << endl;
    }

    // 2. Опрацювання ЗА ЗНАЧЕННЯМ (Власний клас винятку)
    try {
        stringQueue.front();
    }
    catch (MyCustomException e) { // <-- catch за значенням
        cout << "2. Caught BY VALUE (custom class): " << e.getMessage() << endl;
    }

    // 3. Опрацювання ЗА ВКАЗІВНИКОМ (Власний клас винятку)
    try {
        Vect<double> v;
        v.front();
    }
    catch (MyCustomException* e) { // <-- catch за вказівником
        cout << "3. Caught BY POINTER (custom class): " << e->getMessage() << endl;
        delete e; // Звільняємо пам'ять
    }

    // 4. Виняток СТАНДАРТНОГО КЛАСУ
    try {
        Vect<int> v;
        v.erase_front();
    }
    catch (const std::out_of_range& e) {
        cout << "4. Caught STANDARD exception: " << e.what() << endl;
    }

    return 0;
}