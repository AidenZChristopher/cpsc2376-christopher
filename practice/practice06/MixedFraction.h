#pragma once
#include "Fraction.h"
#include <iostream>

class MixedFraction : public Fraction
{
private:
	int whole;
	int numerator;
	int denominator;
public:
	MixedFraction(int w = 0, int n = 0, int d = 1) : Fraction(n, d), whole(w) {}

	MixedFraction(const Fraction& fraction) {
		whole = fraction.getNum() / fraction.getDen(); // Integer part
		numerator = fraction.getNum() % fraction.getDen(); // Remainder part
		denominator = fraction.getDen(); // Denominator remains the same
	}

	friend std::ostream& operator<<(std::ostream& os, const MixedFraction& f);
};