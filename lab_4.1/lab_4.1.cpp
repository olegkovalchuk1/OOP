#include <iostream>
#include <vector>
#include <typeinfo>
#include "Figure.h"
#include "Parallelepiped.h"
#include "Pyramid.h"
#include "Tetrahedron.h"
#include "Sphere.h"
#include <Windows.h>


using namespace std;

int main() {
    SetConsoleCP(1251);        
    SetConsoleOutputCP(1251);
    // Створюємо масив вказівників на базовий клас
    vector<Figure*> figures;

    // Створюємо поліморфні об'єкти
    figures.push_back(new Parallelepiped(2, 3, 4));
    figures.push_back(new Pyramid(3, 4, 6));
    figures.push_back(new Tetrahedron(3));
    figures.push_back(new Sphere(5));

    cout << "--- Демонстрація поліморфізму та RTTI ---\n\n";

    for (Figure* fig : figures) {
        // Виведення справжнього типу об'єкта за допомогою typeid
        cout << "Тип об'єкта: " << typeid(*fig).name() << endl;
        cout << "Назва: " << fig->getName() << endl;
        cout << "Об'єм: " << fig->volume() << endl;
        cout << "--------------------------------------\n";
    }

    // Звільнення пам'яті
    for (Figure* fig : figures) {
        delete fig;
    }

    return 0;
}