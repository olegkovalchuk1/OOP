#ifndef STRING_H
#define STRING_H

#include "Array.h"
#include <string>

class String : public Array {
public:
    String();
    String(size_t max_s);
    String(const char* str, size_t max_s = 256);
    String(const String& other);

    // Гетери та Сетери для рядка
    size_t getLength() const;
    void setString(const char* str);

    // Операції згідно завдання
    int find(const String& sub) const;                     // Пошук підрядка
    void remove(size_t pos, size_t len);                   // Видалення підрядка
    void insert(size_t pos, const String& sub);            // Вставка підрядка

    // Перевантаження операторів
    String& operator=(const String& other);
    unsigned char& operator[](size_t index);               // Індексування для символів рядка
    const unsigned char& operator[](size_t index) const;
    explicit operator std::string() const;                 // Приведення до std::string

    // Дружні функції (бінарна операція та ввід/вивід)
    friend String operator+(const String& s1, const String& s2); // Зчеплення (конкатенація)
    friend std::istream& operator>>(std::istream& is, String& s);
    friend std::ostream& operator<<(std::ostream& os, const String& s);
};

// Структури для демонстрації #pragma pack(1)
#pragma pack(push, 1)
struct StringPacked {
    unsigned char* data;
    size_t max_size;
    size_t current_count;
};
#pragma pack(pop)

struct StringUnpacked {
    unsigned char* data;
    size_t max_size;
    size_t current_count;
};

#endif // STRING_H