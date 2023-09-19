#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <string.h>
#include <string>

using namespace std;


class fraction {
private:
	int numerator;
	int denominator;
public:
	fraction() : numerator(0), denominator(1) {}
	fraction(int n, int d) : numerator(n), denominator(d) {}

	void get_fraction();
	void total(fraction);
	void standart_format();
	void average_fr(int c);
	void output_fraction()const;
	void output_fr()const;

	fraction operator+(fraction) const;
	fraction operator-(fraction) const;
	fraction operator*(fraction) const;
	fraction operator/(fraction) const;
	bool operator==(fraction) const;
	bool operator!=(fraction) const;
};

int main() {
	const int MAX = 10;

	fraction f1, f2, f3;
	f1.get_fraction();
	f2.get_fraction();
	f3 = f1 / f2;
	if (f1 != f2)
		cout << "Fractions aren't equal" << endl;
	else
		cout << "Fractions are equal" << endl;
	f3.output_fr(); cout << endl;
	

	fraction fr[MAX], average, total;
	char ch;
	int count = 0;
	for (int i = 0; i < MAX; i++) {
		fr[i].get_fraction();
		count++;
		cout << "Continue? (y/n) ";
		ch = _getche();
		cout << endl << endl;
		if (ch == 'n') break;
	}

	for (int i = 0; i < count; i++) {
		fr[i].output_fraction();
	} cout << endl;

	for (int i = 0; i < count; i++) {
		average.total(fr[i]);
	}
	//total.standart_format();
	cout << "Total ";
	total = average;
	total.standart_format();
	total.output_fr();//average.output_fr();
	
	average.average_fr(count);
	average.standart_format();
	cout << "Average "; average.output_fr();

	return 0;
}

fraction fraction::operator+(fraction f2) const {
	int num, den;
	num = numerator * f2.denominator + f2.numerator * denominator;
	den = denominator * f2.denominator;
	fraction f(num, den);
	f.standart_format();
	return f;
}

fraction fraction::operator-(fraction f2) const {
	int num, den;
	num = numerator * f2.denominator - f2.numerator * denominator;
	den = denominator * f2.denominator;
	fraction f(num, den);
	f.standart_format();
	return f;
}

fraction fraction::operator*(fraction f2) const {
	int num, den;
	num = numerator * f2.numerator;
	den = denominator * f2.denominator;
	fraction f(num, den);
	f.standart_format();
	return f;
}

fraction fraction::operator/(fraction f2) const {
	int num, den;
	num = numerator * f2.denominator;
	den = denominator * f2.numerator;
	fraction f(num, den);
	f.standart_format();
	return f;
}

bool fraction::operator==(fraction f2) const {
	fraction f1(numerator, denominator);
	f1.standart_format();
	f2.standart_format();
	bool check;
	check = (f1.numerator == f2.numerator) && (f1.denominator == f2.denominator) ? true : false;
	return check;
}

bool fraction::operator!=(fraction f2) const {
	fraction f1(numerator, denominator);
	f1.standart_format();
	f2.standart_format();
	bool check;
	check = (f1.numerator != f2.numerator) && (f1.denominator != f2.denominator) ? true : false;
	return check;
}

void fraction::get_fraction() {
	cout << "Numerator: "; cin >> numerator;
	cout << "Denominator: "; cin >> denominator;
	while (denominator == 0) {
		cout << "Incorrect denominator! Try again: ";
		cin >> denominator;
	}
	cout << endl;
}

void fraction::total(fraction f1) {
	numerator *= f1.denominator;
	numerator += f1.numerator * denominator;
	denominator *= f1.denominator;
}

void fraction::standart_format() {
	if (numerator % denominator != 0 || numerator != 0) {
		for (int i = (denominator / 2) + 1; i > 1; i--) {
			if (numerator % i == 0 && denominator % i == 0) {
				numerator /= i; denominator /= i;
			}
		}
	}
	else if(numerator==0) {
		numerator = 0;
	}
	else {
		numerator = 1;
		denominator = 1;
	}
}

void fraction::average_fr(int c) {
	if (numerator % c != 0) {
		denominator *= c;
	}
	else numerator /= c;
}

void fraction::output_fraction() const {
	static int total = 0;
	total++;
	cout << total << " fraction: " << numerator << "/" << denominator << endl;
}

void fraction::output_fr() const {
	cout << "fraction: " << numerator << "/" << denominator << endl;
}
