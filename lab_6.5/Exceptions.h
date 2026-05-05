#pragma once
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>
#include <stdexcept>

// ВИМОГА: Виняток власного класу
class MyCustomException {
private:
    std::string message;
public:
    MyCustomException(const std::string& msg) : message(msg) {}
    std::string getMessage() const { return message; }
};

// ВИМОГА: Виняток, який є нащадком стандартного класу
class DerivedException : public std::logic_error {
public:
    DerivedException(const std::string& msg) : std::logic_error(msg) {}
};

#endif