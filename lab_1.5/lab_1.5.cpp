#include "RightAngled.h"
#include <iostream>

using namespace std;

int main()
{
    //Демонстрацiя створення об'єкта через Init() та використання методів
    RightAngled t1;
    Pair p1;
    p1.Init(3.0, 4.0);
    t1.Init(p1);

    t1.Display();
    cout << "String representation: " << t1.toString() << endl;

    //Зміна полів через методи запису
    p1.setFirst(6.0);
    p1.setSecond(8.0);
    t1.setPair(p1);
    cout << "Updated area: " << t1.area() << endl;

    //Демонстрація створення масиву об'єктів та використання Read()
    const int N = 2;
    RightAngled arr[N];

    for (int i = 0; i < N; i++) {
        arr[i].Read();
    }

    for (int i = 0; i < N; i++) {
        arr[i].Display();
    }

    return 0;
}