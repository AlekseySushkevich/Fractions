#include "Fraction.h"
using namespace std;

void Fraction::Reduction()
{
	int a = abs(numeratorNum);
	int b = abs(denominatorNum);
	while (a != 0 && b != 0) {
		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	numeratorNum /= (a + b);
	denominatorNum /= (a + b);
}

double Fraction::getDouble()
{
	return numeratorNum * 1.0 / denominatorNum * 1.0;
}

void Fraction::setNumerator(long& numerator)
{
	numeratorNum = numerator;
}

int Fraction::getNumerator()
{
	return numeratorNum;
}

void Fraction::setDenominator(long& denominator)
{
	denominatorNum = denominator;
}

int Fraction::getDenominator()
{
	return denominatorNum;
}

void Fraction::signChange() 
{
	numeratorNum *= -1;
}

void Fraction::Сomparison(const Fraction& frac1, const Fraction& frac2)
{
	int a = frac1.numeratorNum * frac2.denominatorNum;
	int b = frac2.numeratorNum * frac1.denominatorNum;
	double compar = a * 1.0 / b * 1.0;
	if (compar < 1.0)
		cout << frac1 << " < " << frac2 << endl;
	if (compar == 1.0)
		cout << frac1 << " = " << frac2 << endl;
	if (compar > 1.0)
		cout << frac1 << " > " << frac2 << endl;
}

Fraction operator+(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction(frac1.numeratorNum * frac2.denominatorNum + frac1.denominatorNum * frac2.numeratorNum, frac1.denominatorNum * frac2.denominatorNum);
}

Fraction operator-(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction(frac1.numeratorNum * frac2.denominatorNum - frac1.denominatorNum * frac2.numeratorNum, frac1.denominatorNum * frac2.denominatorNum);
}

Fraction operator*(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction(frac1.numeratorNum * frac2.numeratorNum, frac1.denominatorNum * frac2.denominatorNum);
}

Fraction operator/(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction(frac1.numeratorNum * frac2.denominatorNum, frac1.denominatorNum * frac2.numeratorNum);
}

ostream& operator<< (ostream& out, const Fraction& frac)
{
	out << frac.numeratorNum << "/" << frac.denominatorNum;
	return out;
}

istream& operator>> (istream& in, Fraction& frac)
{
	char c;
	while (!(in >> frac.numeratorNum) || !(in >> c) || !(in >> frac.denominatorNum) || frac.denominatorNum == 0)
	{
		cout << "Некорректный ввод. Попробуйте снова." << endl << "> ";
		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (frac.denominatorNum < 0) {
		frac.numeratorNum *= -1;
		frac.denominatorNum *= -1;
	}
	frac.Reduction();

	return in;
}
