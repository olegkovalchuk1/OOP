#include <iostream>
#include "average.h" 

int main() {
    // Демонстрація для int
    int intArray[] = { 10, 20, 30, 40 };
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "--- INT ---" << std::endl;
    std::cout << calculateAverage(intArray, intSize) << "\n\n";

    // Демонстрація double
    double doubleArray[] = { 1.5, 2.5, 5.0 };
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "--- DOUBLE ---" << std::endl;
    std::cout  << calculateAverage(doubleArray, doubleSize) << std::endl;

    return 0;
}