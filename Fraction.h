#pragma once
#include <iostream>
using namespace std;

class Fraction
{
protected:
	long numeratorNum;
	long denominatorNum;

public:

	Fraction(long num = 0, long den = 1):numeratorNum(num), denominatorNum(den)
	{
		Reduction();
	}

	void Reduction();
	double getDouble();

	void setNumerator(long& numerator);
	int getNumerator();
	void setDenominator(long& denominator);
	int getDenominator(); 

	void signChange();
	void Ñomparison(const Fraction& frac1, const Fraction& frac2);

	friend Fraction operator+(const Fraction& frac1, const Fraction& frac2);
	friend Fraction operator-(const Fraction& frac1, const Fraction& frac2);
	friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
	friend Fraction operator/(const Fraction& frac1, const Fraction& frac2);

	friend ostream& operator<< (ostream& out, const Fraction& frac);
	friend istream& operator>> (istream& in, Fraction& frac);
};
