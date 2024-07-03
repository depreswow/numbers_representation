#pragma once
#include <iostream>

class Fraction {
private:

	friend class Money;

	long int whole;
	unsigned short int fraction;
	short decimal_amount;

public:

	Fraction();
	Fraction(long int in_whole, unsigned short int in_fraction, short in_decimal_amount);
	//Fraction(const Fraction& n_2);
	//Fraction(double n_2);

	//Fraction& operator=(const Fraction& n_2);

	Fraction operator+(const Fraction& n_2) const;
	Fraction operator-(const Fraction& n_2) const;

	Fraction operator*(const Fraction& n_2) const;

	bool operator>(const Fraction& n_2) const;
	bool operator<(const Fraction& n_2) const;

	friend std::istream& operator>>(std::istream& in, Fraction& n);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& n);
};