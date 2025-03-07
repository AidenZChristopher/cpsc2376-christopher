#include "Fraction.h"
#include <iostream>
#include <stdexcept>

int Fraction::getNum() const
{
    return num;
}

int Fraction::getDen() const
{
    return den;
}

void Fraction::setNum(int n)
{
    num = n;
}

void Fraction::setDen(int d)
{
	if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
	den = d;
}

void Fraction::simplify() {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero");

    // Compute GCD using Euclidean algorithm
    int a = num, b = den;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a; // GCD is stored in 'a' after loop exits

    // Simplify the fraction
    num /= gcd;
    den /= gcd;
}


Fraction operator+(const Fraction& lhs, const Fraction& rhs) //lhs = left hand side, rhs = right hand side
{
    return Fraction(lhs.num * rhs.den + rhs.num * lhs.den, lhs.den * rhs.den);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs)
{
    return Fraction(lhs.num * rhs.den - rhs.num * lhs.den, lhs.den * rhs.den);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
    return Fraction(lhs.num * rhs.num, lhs.den * rhs.den);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs)
{
    if (rhs.num == 0)
    {
        throw std::invalid_argument("Cannot divide by a fraction with numerator zero");
    }
    return Fraction(lhs.num * rhs.den, lhs.den * rhs.num);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
    os << f.num << "/" << f.den;
    return os;
}