#include <iostream>
#include <vector>
#include "Factory.h"

// Функція для виводу меню
void PrintMenu() {
    std::cout << "\n--- MENU ---" << std::endl;
    std::cout << "1. Create SymString object (T1)" << std::endl;
    std::cout << "2. Create OctString object (T2)" << std::endl;
    std::cout << "3. Show all objects (via operator<<)" << std::endl;
    std::cout << "4. Execute ShowDec() for OctString" << std::endl;
    std::cout << "5. Execute operation + (SymString concatenation)" << std::endl;
    std::cout << "6. Execute operation + (OctString math addition)" << std::endl;
    std::cout << "7. Test indexing operator []" << std::endl;
    std::cout << "8. Delete object" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose action: ";
}

int main() {
    std::vector<SymString*> objects;
    int choice;

    do {
        PrintMenu();
        std::cin >> choice;

        if (choice == 1 || choice == 2) {
            std::cout << "Enter ID and value separated by space: ";
            if (choice == 1) {
                SymString* temp = Factory::CreateSymString("", "");
                std::cin >> *temp; // Використання оператора вводу >>
                objects.push_back(temp);
                std::cout << "SymString created successfully!" << std::endl;
            }
            else {
                OctString* temp = Factory::CreateOctString("", "");
                std::cin >> *temp; // Використання оператора вводу >>
                objects.push_back(temp);
                std::cout << "OctString created successfully!" << std::endl;
            }
        }
        else if (choice == 3) {
            if (objects.empty()) {
                std::cout << "Object list is empty." << std::endl;
            }
            else {
                for (size_t i = 0; i < objects.size(); ++i) {
                    std::cout << i << ". " << *objects[i] << std::endl; // Використання operator<<
                }
            }
        }
        else if (choice == 4) {
            int index;
            std::cout << "Enter index of OctString object: ";
            std::cin >> index;

            if (index >= 0 && index < objects.size()) {
                OctString* octObj = dynamic_cast<OctString*>(objects[index]);
                if (octObj) {
                    octObj->ShowDec();
                }
                else {
                    std::cout << "Object at this index is not an OctString!" << std::endl;
                }
            }
            else {
                std::cout << "Invalid index!" << std::endl;
            }
        }
        else if (choice == 5 || choice == 6) {
            int idx1, idx2;
            std::cout << "Enter index of the first object: ";
            std::cin >> idx1;
            std::cout << "Enter index of the second object: ";
            std::cin >> idx2;

            if (idx1 >= 0 && idx1 < (int)objects.size() && idx2 >= 0 && idx2 < (int)objects.size()) {
                if (choice == 5) {
                    SymString result = *objects[idx1] + *objects[idx2];
                    std::cout << "Result of + operation (SymString):\n" << result << std::endl;
                }
                else {
                    OctString* oct1 = dynamic_cast<OctString*>(objects[idx1]);
                    OctString* oct2 = dynamic_cast<OctString*>(objects[idx2]);

                    if (oct1 && oct2) {
                        OctString result = *oct1 + *oct2;
                        std::cout << "Result of + operation (OctString):\n" << result << std::endl;
                    }
                    else {
                        std::cout << "Both objects must be of type OctString!" << std::endl;
                    }
                }
            }
            else {
                std::cout << "Invalid indices!" << std::endl;
            }
        }
        else if (choice == 7) {
            int index;
            std::cout << "Enter object index: ";
            std::cin >> index;

            if (index >= 0 && index < (int)objects.size()) {
                int charIndex;
                std::cout << "Enter character index in state string: ";
                std::cin >> charIndex;

                try {
                    char c = (*objects[index])[charIndex]; // Виклик operator[]
                    std::cout << "Character at index " << charIndex << ": '" << c << "'" << std::endl;
                }
                catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
            }
            else {
                std::cout << "Invalid object index!" << std::endl;
            }
        }
        else if (choice == 8) {
            int index;
            std::cout << "Enter index of the object to delete: ";
            std::cin >> index;

            if (index >= 0 && index < (int)objects.size()) {
                Factory::DeleteObject(objects[index]);
                objects.erase(objects.begin() + index);
                std::cout << "Object deleted!" << std::endl;
            }
            else {
                std::cout << "Invalid index!" << std::endl;
            }
        }

    } while (choice != 0);

    // Очищення пам'яті
    for (auto obj : objects) {
        Factory::DeleteObject(obj);
    }
    objects.clear();

    return 0;
}