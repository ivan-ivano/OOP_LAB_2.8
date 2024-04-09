#include "Fraction.h"
#include <iostream>
#include <string>

int main() {
    Fraction fraction1, fraction2;

    std::cout << "Enter the first fraction:\n";
    fraction1.Read();
    std::cout << "First fraction: ";
    fraction1.Display();

    std::cout << "\nEnter the second fraction:\n";
    fraction2.Read();
    std::cout << "Second fraction: ";
    fraction2.Display();

    Fraction resultAdd = Fraction::Calculator::Add(fraction1, fraction2);
    Fraction resultSubtract = Fraction::Calculator::Subtract(fraction1, fraction2);
    Fraction resultMultiply = Fraction::Calculator::Multiply(fraction1, fraction2);

    std::cout << "\nResults:\n";
    std::cout << "Result of addition:\n";
    resultAdd.Display();

    std::cout << "\nResult of subtraction:\n";
    resultSubtract.Display();

    std::cout << "\nResult of multiplication:\n";
    resultMultiply.Display();

    std::cout << "\nEquality check:\n";
    if (fraction1 == fraction2) {
        std::cout << "Fractions are equal\n";
    }
    else {
        std::cout << "Fractions are not equal\n";
    }

    return 0;
}
