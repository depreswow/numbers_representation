#include <iostream>
#include "Fraction.h"
#include <cmath>

Fraction::Fraction() 
	: whole(0), fraction(0), decimal_amount(0) {}

Fraction::Fraction(long int in_whole, unsigned short int in_fraction, short in_decimal_amount) 
	: whole(in_whole), fraction(in_fraction), decimal_amount(in_decimal_amount) {}

Fraction Fraction::operator+(const Fraction& n_2) const {
	Fraction buffer;
	if (decimal_amount >= n_2.decimal_amount) {
		buffer.decimal_amount = decimal_amount; 
		buffer.fraction = fraction + n_2.fraction * pow(10, (decimal_amount - n_2.decimal_amount));
	}
	else {
		buffer.decimal_amount = n_2.decimal_amount;
		buffer.fraction = n_2.fraction + fraction * pow(10, (n_2.decimal_amount - decimal_amount));
	}
	buffer.whole = whole + n_2.whole + (unsigned short int)(buffer.fraction / pow(10, buffer.decimal_amount));
	buffer.fraction = buffer.fraction % (int)pow(10, (buffer.decimal_amount));
	while (buffer.fraction != 0 && buffer.fraction % 10 == 0) {
		buffer.fraction /= 10;
		buffer.decimal_amount--;
	}
	return buffer;
}

Fraction Fraction::operator-(const Fraction& n_2) const {
	Fraction buffer;
	unsigned short int fraction1, fraction2;
	if (decimal_amount >= n_2.decimal_amount) {
		buffer.decimal_amount = decimal_amount;
		fraction1 = fraction;
		fraction2 = n_2.fraction * pow(10, (decimal_amount - n_2.decimal_amount));
	}
	else {
		buffer.decimal_amount = n_2.decimal_amount;
		fraction1 = fraction * pow(10, (n_2.decimal_amount - decimal_amount));
		fraction2 = n_2.fraction;
	}
	buffer.whole = whole - n_2.whole;
	if (fraction1>fraction2)
		buffer.fraction = fraction1 - fraction2;
	else {
		buffer.fraction = fraction2 - fraction1;
		if (buffer.whole != 0)
			buffer.whole--;
	}
	while (buffer.fraction != 0 && buffer.fraction % 10 == 0) {
		buffer.fraction /= 10;
		buffer.decimal_amount--;
	}
	return buffer;
}

Fraction Fraction::operator*(const Fraction& n_2) const {
	Fraction buffer;
	buffer.decimal_amount = decimal_amount + n_2.decimal_amount;
	buffer.whole = (long long int)((whole * pow(10, (decimal_amount)) + fraction) * (n_2.whole * pow(10, (n_2.decimal_amount)) + n_2.fraction)) / (int)pow(10, (buffer.decimal_amount));
	buffer.fraction = (long long int)((whole * pow(10, (decimal_amount)) + fraction) * (n_2.whole * pow(10, (n_2.decimal_amount)) + n_2.fraction)) % (int)pow(10, (buffer.decimal_amount));
	while (buffer.fraction != 0 && buffer.fraction % 10 == 0) {
		buffer.fraction /= 10;
		buffer.decimal_amount--;
	}
	return buffer;
}
bool Fraction::operator>(const Fraction& n_2) const {
	if (whole > n_2.whole)
		return true;
	if (decimal_amount >= n_2.decimal_amount) {
		if (fraction > n_2.fraction * pow(10, (decimal_amount - n_2.decimal_amount)))
			return true;
		return false;
	}
	if (fraction * pow(10, (n_2.decimal_amount - decimal_amount)) > n_2.fraction)
		return true;
	return false;
}

bool Fraction::operator<(const Fraction& n_2) const {
	if (whole < n_2.whole)
		return true;
	if (decimal_amount >= n_2.decimal_amount) {
		if (fraction < n_2.fraction * pow(10, (decimal_amount - n_2.decimal_amount)))
			return true;
		return false;
	}
	if (fraction * pow(10, (n_2.decimal_amount - decimal_amount)) < n_2.fraction)
		return true;
	return false;
}


std::istream& operator>>(std::istream& in, Fraction& n) {
	long int in_whole;
	unsigned short int in_fraction;
	short in_decimal_amount;
	std::cout << "Enter whole:" << std::endl;
	std::cin >> n.whole;
	std::cout << "Enter fraction:" << std::endl;
	std::cin >> n.fraction;
	std::cout << "Enter decimal_amount:" << std::endl;
	std::cin >> n.decimal_amount;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& n) {
	out << n.whole << "," << (short)n.fraction << "\t" << n.decimal_amount;
	return out;
}