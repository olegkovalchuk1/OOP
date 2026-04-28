#include "String.h"

// Конструктори (делегують ініціалізацію сетерам)
String::String() : Array() {
    setString("");
}

String::String(size_t max_s) : Array(max_s) {
    setString("");
}

String::String(const char* str, size_t max_s) : Array(max_s) {
    setString(str);
}

String::String(const String& other) : Array(other) {}

// Гетери та Сетери
size_t String::getLength() const {
    return data[0]; // Нульовий байт містить фактичну довжину
}

void String::setString(const char* str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // Turbo Pascal рядок не може бути більшим за 255 символів або max_size - 1
    size_t capacity_limit = (max_size - 1 < 255) ? (max_size - 1) : 255;
    if (len > capacity_limit) {
        len = capacity_limit; // Обрізаємо рядок, якщо він не поміщається
    }

    data[0] = static_cast<unsigned char>(len);
    for (size_t i = 0; i < len; ++i) {
        data[i + 1] = str[i];
    }
    setCount(len); // Оновлюємо поле count з базового класу
}

// Пошук підрядка (повертає індекс від 0, або -1 якщо не знайдено)
int String::find(const String& sub) const {
    size_t mainLen = getLength();
    size_t subLen = sub.getLength();

    if (subLen == 0) return 0;
    if (subLen > mainLen) return -1;

    for (size_t i = 1; i <= mainLen - subLen + 1; ++i) {
        bool match = true;
        for (size_t j = 1; j <= subLen; ++j) {
            if (data[i + j - 1] != sub.data[j]) {
                match = false;
                break;
            }
        }
        if (match) return static_cast<int>(i - 1); // Повертаємо позицію зсунуту на 0-index
    }
    return -1;
}

// Видалення підрядка
void String::remove(size_t pos, size_t len) {
    size_t currentLen = getLength();
    if (pos >= currentLen) return; // Позиція за межами рядка

    if (pos + len > currentLen) len = currentLen - pos; // Не видаляємо більше, ніж є

    // Зсуваємо елементи ліворуч
    for (size_t i = pos + 1; i <= currentLen - len; ++i) {
        data[i] = data[i + len];
    }

    data[0] = static_cast<unsigned char>(currentLen - len);
    setCount(currentLen - len);
}

// Вставка підрядка
void String::insert(size_t pos, const String& sub) {
    size_t currentLen = getLength();
    size_t subLen = sub.getLength();

    if (pos > currentLen) pos = currentLen; // Вставляємо в кінець

    size_t capacity_limit = (max_size - 1 < 255) ? (max_size - 1) : 255;
    if (currentLen + subLen > capacity_limit) {
        subLen = capacity_limit - currentLen; // Влізе тільки частина
    }

    if (subLen == 0) return;

    // Зсуваємо існуючі символи праворуч
    for (size_t i = currentLen; i > pos; --i) {
        data[i + subLen] = data[i];
    }

    // Вставляємо нові символи
    for (size_t i = 0; i < subLen; ++i) {
        data[pos + 1 + i] = sub.data[i + 1];
    }

    data[0] = static_cast<unsigned char>(currentLen + subLen);
    setCount(currentLen + subLen);
}

// Перевантаження = (метод класу)
String& String::operator=(const String& other) {
    if (this != &other) {
        Array::operator=(other); // Виклик оператора базового класу
    }
    return *this;
}

// Індексування []
unsigned char& String::operator[](size_t index) {
    if (index >= getLength()) throw std::out_of_range("String index out of bounds");
    return data[index + 1]; // Індекс 0 для користувача = data[1] (бо data[0] - це довжина)
}

const unsigned char& String::operator[](size_t index) const {
    if (index >= getLength()) throw std::out_of_range("String index out of bounds");
    return data[index + 1];
}

// Приведення типу до рядка
String::operator std::string() const {
    size_t len = getLength();
    std::string result = "";
    for (size_t i = 1; i <= len; ++i) {
        result += static_cast<char>(data[i]);
    }
    return result;
}

// Бінарна операція Зчеплення (зовнішня дружня)
String operator+(const String& s1, const String& s2) {
    String result(s1.size()); // Створюємо рядок з такою ж місткістю
    result.setString(std::string(s1).c_str()); // Ініціалізуємо першим рядком
    result.insert(result.getLength(), s2);     // Вставляємо другий рядок в кінець
    return result;
}

// Введення (звертається до сетера)
std::istream& operator>>(std::istream& is, String& s) {
    std::string temp;
    std::cout << "Enter string: ";
    std::getline(is, temp);
    s.setString(temp.c_str()); // Використання сетера!
    return is;
}

// Виведення (використовує приведення типу)
std::ostream& operator<<(std::ostream& os, const String& s) {
    os << static_cast<std::string>(s);
    return os;
}