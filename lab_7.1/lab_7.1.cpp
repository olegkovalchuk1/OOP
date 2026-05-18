#include <iostream>  
#include <algorithm>  
#include <vector>    
#include <ctime>     
#include <numeric>    

using namespace std;
int RandomNumber() { return (std::rand() % 100); }


void print(const vector<int>& a)
{
    for (int i : a)
        cout << i << " ";
    cout << endl;
}


void createVector(vector<int>& v)
{
    generate(v.begin(), v.end(), RandomNumber);
}


int calculateUsingSTL(const vector<int>& v)
{
    // Створюємо вектор індексів 
    vector<int> indices(v.size());
    iota(indices.begin(), indices.end(), 0);

    // Вектор для результатів (відфільтрованих індексів)
    vector<int> u(v.size());

    // Використовуємо copy_if, як у вашому прикладі. 
    // Фільтруємо індекси: беремо індекс, якщо значення за цим індексом у векторі v - непарне
    auto p = copy_if(indices.begin(), indices.end(), u.begin(),
        [&v](int idx) { return v[idx] % 2 != 0; });

    // Відсікаємо порожні елементи
    u.resize(p - u.begin());

    // Знаходимо суму відфільтрованих індексів
    auto s = accumulate(u.begin(), u.end(), 0);

    return s;
}

int main()
{
    srand(unsigned(time(0)));
    int n;

    cout << "n = ? ";
    cin >> n;

    vector<int> v(n);

    // 1. Формування колекції-масиву
    createVector(v);

    // 2. Виведення її на екран
    cout << "Array:\n";
    print(v);

    // 3. Виконання вказаної дії (сума індексів непарних елементів)
    int sum = calculateUsingSTL(v);

    // 4. Виведення результату
    cout << "Sum of indices of odd elements = " << sum << endl;

    return 0;
}