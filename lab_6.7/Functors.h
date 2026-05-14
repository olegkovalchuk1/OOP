#pragma once

// Функтор: перевіряє, чи є число парним
template <typename T>
struct IsEven {
    bool operator()(const T& value) const {
        return static_cast<int>(value) % 2 == 0;
    }
};

// Функтор: перевіряє, чи є число додатнім
template <typename T>
struct IsPositive {
    bool operator()(const T& value) const {
        return value > 0;
    }
};