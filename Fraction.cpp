#include <iostream>
#include <execution>
#include "Frac.h"
using namespace std;

int main()
{
	Fraction fr1, fr2, fr3;
	try
	{
		cout << "Enter 1st fraction: "; 
		cin >> fr1;
		cout << "Enter 2nd fraction: "; 
		cin >> fr2;
	}
	catch (const exception& err)
	{
		cout << err.what() << endl;
		return 0;
	}
	system("cls");
	cout << "1st fraction: " << fr1 << endl << "In-double: " << fr1.getDouble() << endl;
	cout << "2nd fraction: " << fr2 << endl << "In-double: " << fr2.getDouble() << endl;

	fr3 = fr1 + fr2;
	cout << "'+': " << fr3 << endl;

	fr3 = fr1 - fr2;
	cout << "'-': " << fr3 << endl;

	fr3 = fr1 / fr2;
	cout << "'/': " << fr3 << endl;

	fr3 = fr1 * fr2;
	cout << "'*': " << fr3 << endl;


	cout << endl << "Comparsion " << fr1 << " with " << fr2 << endl;
	if (fr1 == fr2)
		cout << " == is true " << endl;
	if (fr1 != fr2)
		cout << " != is true " << endl;
	if (fr1 >= fr2)
		cout << " >= is true " << endl;
	if (fr1 <= fr2)
		cout << " <= is true " << endl;
	if (fr1 > fr2)
		cout << " > is true " << endl;
	if (fr1 < fr2)
		cout << " < is true " << endl;
}
