#include "String.h"
#include <iostream>

void demonstrateSize() {
    std::cout << "\n=== Demonstration of object size (#pragma pack) ===\n";
    std::cout << "Size of structure WITHOUT #pragma pack(1): " << sizeof(StringUnpacked) << " bytes\n";
    std::cout << "Size of structure WITH #pragma pack(1):    " << sizeof(StringPacked) << " bytes\n";
    std::cout << "--------------------------------------------------\n";
}

int main() {
    try {
        std::cout << "=== Testing Turbo Pascal String Class ===\n";

        // 1. Конструктори та розмір
        String s1("Hello", 50); // Рядок "Hello", місткість 50 байт
        std::cout << "String 1: " << s1 << "\n";
        std::cout << "Length: " << s1.getLength() << ", Max Size: " << s1.size() << "\n";

        // 2. Вставка (Insert)
        String s2(" World");
        s1.insert(s1.getLength(), s2); // Вставка в кінець
        std::cout << "After insertion: " << s1 << "\n";

        // 3. Зчеплення (Concatenation)
        String s3 = s1 + String("!!!");
        std::cout << "After concatenation (+): " << s3 << "\n";

        // 4. Пошук підрядка (Find)
        int pos = s3.find(String("World"));
        if (pos != -1) {
            std::cout << "Found 'World' at index: " << pos << "\n";
        }
        else {
            std::cout << "'World' not found\n";
        }

        // 5. Видалення підрядка (Remove)
        s3.remove(pos, 5); // Видаляємо слово "World" (5 символів)
        std::cout << "After removal: " << s3 << "\n";

        // 6. Індексація та запис
        s3[0] = 'h'; // Змінюємо 'H' на 'h'
        std::cout << "After modifying index 0: " << s3 << "\n";

        // 7. Тестування масиву об'єктів
        std::cout << "\n=== Testing Array of Objects ===\n";
        const int ARR_SIZE = 3;
        String stringArray[ARR_SIZE] = {
            String("First item"),
            String("Second item"),
            String("Third item")
        };

        for (int i = 0; i < ARR_SIZE; ++i) {
            std::cout << "Array[" << i << "]: " << stringArray[i] << "\n";
        }

        // 8. Демонстрація введення з клавіатури (розкоментуйте для перевірки)
        /*
        String inputStr;
        std::cin >> inputStr;
        std::cout << "You entered: " << inputStr << "\n";
        */

        // 9. Розмір класу
        demonstrateSize();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}