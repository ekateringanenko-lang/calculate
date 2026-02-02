// В этом файле объявления функций.
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

// Псевдоним типа
using Number = double;

// Сигнатуры функций
bool ReadNumber(Number& result);
bool RunCalculatorCycle();

#endif  // CALCULATOR_H
