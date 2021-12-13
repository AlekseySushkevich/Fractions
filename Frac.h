#pragma once
#include <iostream>
using namespace std;

class Fraction
{
protected:
	long numer;
	long denom;

public:
	
	Fraction(long num = 0, long den = 1):numer(num), denom(den)
	{
		denomPolicy();
		Reduction();
	}

	void denomPolicy();
	void Reduction();
	double getDouble();

	void setNumerator(long& numerator);
	int getNumerator();
	void setDenominator(long& denominator);
	int getDenominator(); 

	void signChange();

	friend Fraction operator+(const Fraction& frac1, const Fraction& frac2);
	friend Fraction operator-(const Fraction& frac1, const Fraction& frac2);
	friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
	friend Fraction operator/(const Fraction& frac1, const Fraction& frac2);

	bool operator == (const Fraction&) const;
	bool operator != (const Fraction&) const;
	bool operator > (const Fraction&) const;
	bool operator < (const Fraction&) const;
	bool operator >= (const Fraction&) const;
	bool operator <= (const Fraction&) const;

	friend ostream& operator<< (ostream& out, const Fraction& frac);
	friend istream& operator>> (istream& in, Fraction& frac);
};
