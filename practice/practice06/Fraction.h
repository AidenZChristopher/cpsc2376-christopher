#pragma once
#include <stdexcept>


class Fraction {
private:
	int num;
	int den;
public:
	Fraction(int n=0, int d=1) : num(n), den(d) 
	{
		if (den == 0) throw std::invalid_argument("Denominator cannot be zero");
	}

	int getNum() const;
	int getDen() const;
	void setNum(int n);
	void setDen(int d); //execption if d== 0

	void simplify();


	friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};
