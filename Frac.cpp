#include "Frac.h"
using namespace std;

void Fraction::denomPolicy() {
	if (denom == 0) {
		throw exception("Division by zero!");
	}
	if (denom < 0) {
		numer = -numer;
		denom = -denom;
	}
}

void Fraction::Reduction()
{
	int a = abs(numer);
	int b = abs(denom);
	while (a != 0 && b != 0) {
		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	numer /= (a + b);
	denom /= (a + b);
}

double Fraction::getDouble()
{
	return numer * 1.0 / denom * 1.0;
}

void Fraction::setNumerator(long& numerator)
{
	numer = numerator;
}

int Fraction::getNumerator()
{
	return numer;
}

void Fraction::setDenominator(long& denominator)
{
	denom = denominator;
	denomPolicy();
}

int Fraction::getDenominator()
{
	return denom;
}

void Fraction::signChange() 
{
	-numer;
}

Fraction operator+(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction(frac1.numer * frac2.denom + frac1.denom * frac2.numer, frac1.denom * frac2.denom);
}

Fraction operator-(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction(frac1.numer * frac2.denom - frac1.denom * frac2.numer, frac1.denom * frac2.denom);
}

Fraction operator*(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction(frac1.numer * frac2.numer, frac1.denom * frac2.denom);
}

Fraction operator/(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction(frac1.numer * frac2.denom, frac1.denom * frac2.numer);
}

bool Fraction::operator == (const Fraction& x) const {
	return(numer == x.numer && denom == x.denom);
}

bool Fraction::operator > (const Fraction& x) const {
	long a, b;
	a = numer * x.denom;
	b = x.numer * denom;
	return (a > b);
}

bool Fraction::operator < (const Fraction& x) const {
	return(!(*this == x) && !(*this > x));
}

bool Fraction::operator != (const Fraction& x) const {
	return(!(*this == x));
}

bool Fraction::operator >= (const Fraction& x) const {
	return((*this == x) || (*this > x));
}

bool Fraction::operator <= (const Fraction& x) const {
	return((*this < x) || (*this == x));
}

ostream& operator<< (ostream& out, const Fraction& frac)
{
	out << frac.numer << "/" << frac.denom;
	return out;
}

istream& operator>> (istream& in, Fraction& frac)
{
	in >> frac.numer;
	in >> frac.denom;
	frac.denomPolicy();
	frac.Reduction();

	return in;
}
