// Fraction.h
#include <iostream>
#include <sstream>
#include <string>

class Fraction {
public:
    class LongLong {
    private:
        long highPart;
        unsigned long lowPart;
        static int count;

    public:
        LongLong();
        LongLong(long high, unsigned long low);
        LongLong(const LongLong& other);


        LongLong operator+(const LongLong& other) const;
        LongLong operator-(const LongLong& other) const;
        LongLong operator*(const LongLong& other) const;

        bool operator==(const LongLong& other) const;

        bool operator!=(const LongLong& other) const;

        bool operator<(const LongLong& other) const;

        bool operator>(const LongLong& other) const;

        bool operator<=(const LongLong& other) const;

        bool operator>=(const LongLong& other) const;

        LongLong operator*(const int& other) const;

        LongLong operator/(const int& other) const;

        LongLong operator=(const LongLong& other);

        friend std::ostream& operator<<(std::ostream& out, const LongLong& a);
        friend std::istream& operator>>(std::istream& in, LongLong& a);

        operator std::string() const;

        LongLong& operator++();
        LongLong operator++(int);
        LongLong& operator--();
        LongLong operator--(int);


        long GetHighPart() const;
        unsigned long GetLowPart() const;
        void SetHighPart(long a);
        void SetLowPart(unsigned long a);

        void Display() const;
        void Read();

        void Init(long high, unsigned long low);

        std::string ToString() const;
    };

private:
    LongLong integerPart;
    unsigned short int fractionalPart;
    static int count;

public:
    Fraction();
    Fraction(const LongLong& intPart, unsigned short fracPart);
    Fraction(const Fraction& other);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    bool operator==(const Fraction& other) const;

    bool operator!=(const Fraction& other) const;

    bool operator<(const Fraction& other) const;

    bool operator<=(const Fraction& other) const;

    bool operator>(const Fraction& other) const;

    bool operator>=(const Fraction& other) const;

    Fraction operator=(const Fraction& other);

    operator std::string() const;

    friend std::ostream& operator<<(std::ostream& out, const Fraction& a);
    friend std::istream& operator>>(std::istream& in, Fraction& a);

    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

    void Display() const;
    void Read();
    void Init(const LongLong& intPart, unsigned short fracPart);

    unsigned short GetFractionalPart() const;
    void SetIntegerPart(const LongLong& a);
    void SetFractionalPart(unsigned short a);

    std::string ToString() const;

public:
    class Calculator {
    public:
        static Fraction Add(const Fraction& a, const Fraction& b);
        static Fraction Subtract(const Fraction& a, const Fraction& b);
        static Fraction Multiply(const Fraction& a, const Fraction& b);
    };
};

