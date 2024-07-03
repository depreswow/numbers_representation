#pragma once
#include <iostream>
#include "Fraction.h"

class Money {
private:

	friend class Fraction;

	Fraction value;

	static int object_c;
	
	Money& round_to_hundred(); //конвертирует лишние копейки в рубли, если копеек больше 99. Возвращает Money& просто на всякий случай.

public:

	Money();
	Money(const Fraction& n_2);
	explicit Money(double n_2);
	Money(const Money& in_money);
	~Money();

	Money operator+(const Money& n_2) const;
	Money operator-(const Money& n_2) const;

	Money operator*(const Money& n_2) const;
	Money operator*(double n_2) const;

	Money operator/(const Money& n_2) const;
	Money operator/(double n_2) const;

	bool operator>(const Money& n_2) const;
	bool operator<(const Money& n_2) const;

	friend std::istream& operator>>(std::istream& in, Money& n);
	friend std::ostream& operator<<(std::ostream& out, const Money& n);
};