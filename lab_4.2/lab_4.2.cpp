#include <iostream>
#include <vector>
#include <typeinfo>
#include <Windows.h>

#include "IFigure.h"
#include "Parallelepiped.h"
#include "Pyramid.h"
#include "Tetrahedron.h"
#include "Sphere.h"

using namespace std;

int main() {
    // Налаштування для коректного виведення кирилиці в консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Масив вказівників на інтерфейс
    vector<IFigure*> figures;

    figures.push_back(new Parallelepiped(2.0, 3.0, 4.0));
    figures.push_back(new Pyramid(3.0, 4.0, 6.0));
    figures.push_back(new Tetrahedron(3.0));
    figures.push_back(new Sphere(5.0));

    cout << "--- Демонстрація роботи через інтерфейс IFigure ---\n\n";

    for (IFigure* fig : figures) {
        // Виведення справжнього типу (RTTI)
        cout << "Тип об'єкта (typeid): " << typeid(*fig).name() << endl;

        // Виклик поліморфних методів
        cout << "Назва: " << fig->getName() << endl;
        cout << "Об'єм: " << fig->volume() << endl;
        cout << "--------------------------------------\n";
    }

    // Звільнення динамічної пам'яті
    for (IFigure* fig : figures) {
        delete fig;
    }

    return 0;
}