// Fraction.cpp
#include "Fraction.h"
#include <iostream>

int Fraction::LongLong::count = 0;
int Fraction::count = 0;

Fraction::LongLong::LongLong() : highPart(0), lowPart(0) { count++; }

Fraction::LongLong::LongLong(long high, unsigned long low) : highPart(high), lowPart(low) { count++; }

Fraction::LongLong::LongLong(const LongLong& other) : highPart(other.highPart), lowPart(other.lowPart) { count++; }

Fraction::LongLong Fraction::LongLong::operator+(const LongLong& other) const {
    LongLong result;
    result.lowPart = lowPart + other.lowPart;
    result.highPart = highPart + other.highPart + (result.lowPart < lowPart);
    return result;
}

Fraction::LongLong Fraction::LongLong::operator-(const LongLong& other) const {
    LongLong result;
    result.lowPart = lowPart - other.lowPart;
    result.highPart = highPart - other.highPart - (result.lowPart > lowPart);
    return result;
}

Fraction::LongLong Fraction::LongLong::operator*(const LongLong& other) const {
    LongLong result;
    result.lowPart = lowPart * other.lowPart;
    result.highPart = highPart * other.highPart;
    return result;
}

bool Fraction::LongLong::operator==(const LongLong& other) const {
    return (highPart == other.highPart) && (lowPart == other.lowPart);
}

bool Fraction::LongLong::operator!=(const LongLong& other) const {
    return !(*this == other);
};

bool Fraction::LongLong::operator<(const LongLong& other) const {
    if (highPart == other.highPart) {
        return lowPart < other.lowPart;
    }
    return highPart < other.highPart;
}

bool Fraction::LongLong::operator>(const LongLong& other) const {
    if (!(*this == other)) {
        return other < *this;
    };

    return 0;
}

bool Fraction::LongLong::operator<=(const LongLong& other) const {
    if (*this == other) {
        return 1;
    };

    return !(*this > other);
}

bool Fraction::LongLong::operator>=(const LongLong& other) const {
    if (*this == other) {
        return 1;
    };
    return !(*this < other);
}

Fraction::LongLong Fraction::LongLong::operator*(const int& other) const {
    LongLong result;
    result.lowPart = lowPart * other;
    result.highPart = highPart * other;
    return result;
}

Fraction::LongLong Fraction::LongLong::operator/(const int& other) const {
    LongLong result;
    result.lowPart = lowPart / other;
    result.highPart = highPart / other;
    result.lowPart += (ULONG_MAX + 1ull) / other * (result.highPart % other);
    return result;
}

Fraction::LongLong Fraction::LongLong::operator=(const LongLong& other)
{
    highPart = other.highPart;
	lowPart = other.lowPart;
	return *this;
}

long Fraction::LongLong::GetHighPart() const {
    return highPart;
}

unsigned long Fraction::LongLong::GetLowPart() const {
    return lowPart;
}

void Fraction::LongLong::SetHighPart(long a) {
    highPart = a;
}

void Fraction::LongLong::SetLowPart(unsigned long a) {
    lowPart = a;
}

void Fraction::LongLong::Display() const {
    std::cout << "LongLong: " << highPart << " " << lowPart << std::endl;
}

void Fraction::LongLong::Read() {
    std::cout << "Enter LongLong (highPart lowPart): ";
    std::cin >> highPart >> lowPart;
}

void Fraction::LongLong::Init(long high, unsigned long low) {
    highPart = high;
    lowPart = low;
}

std::string Fraction::LongLong::ToString() const {
    std::stringstream ss;
    ss << highPart << " " << lowPart;
    return ss.str();
}

Fraction::Fraction() : fractionalPart(0) {}

Fraction::Fraction(const LongLong& intPart, unsigned short fracPart) : integerPart(intPart), fractionalPart(fracPart) {}

Fraction::Fraction(const Fraction& other) : integerPart(other.integerPart), fractionalPart(other.fractionalPart) {}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction result;
    result.integerPart = integerPart + other.integerPart;
    result.fractionalPart = fractionalPart + other.fractionalPart;
    while (result.fractionalPart >= 10) {
        result.integerPart = result.integerPart + LongLong(0, 1);
        result.fractionalPart -= 10;
    }
    return result;
}

Fraction Fraction::operator-(const Fraction& other) const {
    Fraction result;
    result.integerPart = integerPart - other.integerPart;
    result.fractionalPart = fractionalPart - other.fractionalPart;
    while (result.fractionalPart < 0) {
        result.integerPart = result.integerPart - LongLong(0, 1);
        result.fractionalPart += 10;
    }
    return result;
}

Fraction Fraction::Calculator::Add(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.integerPart = a.integerPart + b.integerPart;
    result.fractionalPart = a.fractionalPart + b.fractionalPart;
    while (result.fractionalPart >= 10) {
        result.integerPart = result.integerPart + Fraction::LongLong(0, 1);
        result.fractionalPart -= 10;
    }
    return result;
}

Fraction Fraction::Calculator::Subtract(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.integerPart = a.integerPart - b.integerPart;
    result.fractionalPart = a.fractionalPart - b.fractionalPart;
    while (result.fractionalPart < 0) {
        result.integerPart = result.integerPart - Fraction::LongLong(0, 1);
        result.fractionalPart += 10;
    }
    return result;
}

Fraction Fraction::Calculator::Multiply(const Fraction& a, const Fraction& b) {
    Fraction result;
    result.integerPart = a.integerPart * b.integerPart;
    Fraction::LongLong num = b.integerPart * a.fractionalPart + a.integerPart * b.fractionalPart + Fraction::LongLong(0, a.fractionalPart * b.fractionalPart / 10);
    result.integerPart = result.integerPart + num / 10;
    result.fractionalPart = num.GetLowPart() % 10;
    return result;
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction result;
    result.integerPart = integerPart * other.integerPart;
    LongLong num = other.integerPart * fractionalPart + integerPart * other.fractionalPart + LongLong(0, fractionalPart * other.fractionalPart / 10);
    result.integerPart = result.integerPart + num / 10;
    result.fractionalPart = num.GetLowPart() % 10;
    return result;
}

bool Fraction::operator==(const Fraction& other) const {
    return (integerPart == other.integerPart) && (fractionalPart == other.fractionalPart);
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    if (integerPart == other.integerPart) {
        return fractionalPart < other.fractionalPart;
    }
    return integerPart < other.integerPart;
}

bool Fraction::operator<=(const Fraction& other) const {
    if (*this == other) {
        return 1;
    };

    return !(*this > other);
}

bool Fraction::operator>(const Fraction& other) const {
    if (!(*this == other)) {
        return other < *this;
    };

    return 0;
}

bool Fraction::operator>=(const Fraction& other) const {
    if (*this == other) {
        return 1;
    };
    return !(*this < other);
}

Fraction Fraction::operator=(const Fraction& other)
{
    integerPart = other.integerPart;
	fractionalPart = other.fractionalPart;
	return *this;
}

Fraction::operator std::string() const
{
	std::stringstream ss;
	ss << integerPart.GetHighPart() << " " << integerPart.GetLowPart() << " " << fractionalPart;
	return ss.str();
}

Fraction::LongLong& Fraction::LongLong::operator++()
{
    highPart = highPart + 1;
	return *this;
}

Fraction::LongLong Fraction::LongLong::operator++(int)
{
	LongLong temp(*this);
	highPart = highPart + 1;
	return temp;
}

Fraction::LongLong& Fraction::LongLong::operator--()
{
	highPart = highPart - 1;
	return *this;
}

Fraction::LongLong Fraction::LongLong::operator--(int)
{
	LongLong temp(*this);
	highPart = highPart - 1;
	return temp;
}

Fraction& Fraction::operator++()
{
	integerPart = integerPart + LongLong(0, 1);
	return *this;
}

Fraction& Fraction::operator--()
{
    integerPart = integerPart - LongLong(0, 1);
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction temp(*this);
	integerPart = integerPart + LongLong(0, 1);
	return temp;
}

Fraction Fraction::operator--(int)
{
	Fraction temp(*this);
	integerPart = integerPart - LongLong(0, 1);
	return temp;
}


void Fraction::Display() const {
    std::cout << "Fraction: ";
    integerPart.Display();
    std::cout << "Fractional part: " << fractionalPart << std::endl;
}

void Fraction::Read() {
    integerPart.Read();
    std::cout << "Enter Fraction (fractionalPart): " << std::endl;
    std::cin >> fractionalPart;
}

void Fraction::Init(const LongLong& intPart, unsigned short fracPart) {
    integerPart = intPart;
    fractionalPart = fracPart;
}


unsigned short Fraction::GetFractionalPart() const {
    return fractionalPart;
}

void Fraction::SetIntegerPart(const LongLong& a) {
    integerPart = a;
}

void Fraction::SetFractionalPart(unsigned short a) {
    fractionalPart = a;
}

std::string Fraction::ToString() const {
    std::stringstream ss;
    ss << integerPart.GetHighPart() << " " << integerPart.GetLowPart() << " " << fractionalPart;
    return ss.str();
}

std::istream& operator>>(std::istream& in, Fraction& a)
{
    long long highPart, lowPart;
    unsigned short fractionalPart;
    in >> highPart >> lowPart >> fractionalPart;
    a.SetIntegerPart(Fraction::LongLong(highPart, lowPart));
    a.SetFractionalPart(fractionalPart);
    return in;
}



std::ostream& operator<<(std::ostream& out, const Fraction::LongLong& a)
{
    out << a.highPart << " " << a.lowPart;
	return out;
}

std::istream& operator>>(std::istream& in, Fraction::LongLong& a)
{
	long long highPart;
	unsigned long lowPart;
	in >> highPart >> lowPart;
	a.SetHighPart(highPart);
	a.SetLowPart(lowPart);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& a)
{
	out << a.integerPart.GetHighPart() << " " << a.integerPart.GetLowPart() << " " << a.fractionalPart;
	return out;
}
