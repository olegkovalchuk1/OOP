#include "DateCommon.h"
#include "DateNormal.h"
#include "DateStatic.h"
#include <iostream>

void demonstrateSize() {
    std::cout << "\n=== Demonstration of object size (#pragma pack) ===\n";
    std::cout << "Size of structure WITHOUT #pragma pack(1): " << sizeof(DateUnpacked) << " bytes\n";
    std::cout << "Size of structure WITH #pragma pack(1):    " << sizeof(DatePacked) << " bytes\n";
    std::cout << "--------------------------------------------------\n";
}

int main() {
    try {
        std::cout << "=== Testing DateNormal (Module 1) ===\n";

        DateNormal d1;
        std::cout << "Default: " << d1 << "\n"; // Виклик оператора << 

        DateNormal d2("28.02.2023");
        std::cout << "From string: " << d2 << "\n";

       

        std::cout << "\n=== Testing DateStatic (Module 2) ===\n";

        const int ARR_SIZE = 2;
        DateStatic dateArray[ARR_SIZE] = {
            DateStatic(29, FEB, 2024),
            DateStatic("01.01.2025")
        };

        for (int i = 0; i < ARR_SIZE; ++i) {
            std::cout << "Element [" << i << "]: " << dateArray[i] << "\n";
        }

        // Перевірка індексатора
        std::cout << "\nMonth at index 1 (FEB) has " << dateArray[0][FEB].days << " days (in a regular year).\n";

        demonstrateSize();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}