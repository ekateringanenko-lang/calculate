#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>

bool ReadNumber(Number& result) {
    return static_cast<bool>(std::cin >> result);
}

bool RunCalculatorCycle() {
    Number value = 0;
    Number memory = 0;
    bool memory_set = false;
    std::string command;

    if (!ReadNumber(value)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }

    while (std::cin >> command) {
        if (command == "+") {
            Number operand;
            if (!ReadNumber(operand)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            value += operand;
        } else if (command == "-") {
            Number operand;
            if (!ReadNumber(operand)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            value -= operand;
        } else if (command == "*") {
            Number operand;
            if (!ReadNumber(operand)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            value *= operand;
        } else if (command == "/") {
            Number operand;
            if (!ReadNumber(operand)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            value /= operand;
        } else if (command == "**") {
            Number operand;
            if (!ReadNumber(operand)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            value = std::pow(value, operand);
        } else if (command == "=") {
            std::cout << value << std::endl;
        } else if (command == "c") {
            value = 0;
        } else if (command == ":") {
            Number new_value;
            if (!ReadNumber(new_value)) {
                std::cerr << "Error: Numeric operand expected" << std::endl;
                return false;
            }
            value = new_value;
        } else if (command == "s") {
            memory = value;
            memory_set = true;
        } else if (command == "l") {
            if (!memory_set) {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
            value = memory;
        } else if (command == "q") {
            return true;
        } else {
            std::cerr << "Error: Unknown token " << command << std::endl;
            return false;
        }
    }
    return true;
}
