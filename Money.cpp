#include "Fraction.h"
#include "Money.h"

int Money::object_c = 0;

Money& Money::round_to_hundred() {
	value.whole += value.fraction / 100;
	value.fraction = value.fraction % 100;
	return *this;
}

Money::Money() 
	: value() {
	object_c++;
}

Money::Money(const Fraction& n_2) 
	: value(n_2) {
	round_to_hundred();
	object_c++;
}

Money::Money(double n_2) {
	value.whole = (long int)n_2;
	value.fraction = (unsigned short)((n_2 - value.whole) * 100);
	object_c++;
}

Money::Money(const Money& in_money) : value(in_money.value) {
	object_c++;
}

Money::~Money() {
	object_c--;
}

Money Money::operator+(const Money& n_2) const {
	Money buffer;
	buffer.value = value + n_2.value;
	buffer.round_to_hundred();
	return buffer;
}

Money Money::operator-(const Money& n_2) const {
	Money buffer;
	buffer.value = value - n_2.value;
	buffer.round_to_hundred();
	return buffer;
}

Money Money::operator*(const Money& n_2) const {
	Money buffer;
	buffer.value = value * n_2.value;
	buffer.round_to_hundred();
	return buffer;
}

Money Money::operator*(double n_2) const {
	Money buffer, number(n_2);
	buffer.value = value * number.value;
	buffer.round_to_hundred();
	return buffer;
}

Money Money::operator/(const Money& n_2) const {
	if (n_2.value.whole == 0 && n_2.value.fraction == 0)
		return *this;
	Money buffer;
	double f_buffer;
	f_buffer = (value.whole * value.decimal_amount + value.fraction) / (n_2.value.whole * n_2.value.decimal_amount + n_2.value.fraction);
	buffer.value.whole = (long int)f_buffer;
	buffer.value.fraction = (unsigned short)((f_buffer - buffer.value.whole) * 100);
	return buffer;
}
Money Money::operator/(double n_2) const {
	if (n_2 == 0) return *this;
	Money buffer;
	double f_buffer;
	f_buffer = (value.whole * value.decimal_amount + value.fraction) / (int)(n_2 * 100);
	buffer.value.whole = (long int)f_buffer;
	buffer.value.fraction = (unsigned short)((f_buffer - buffer.value.whole) * 100);
	return buffer;
}

/* я написал этот код в 3 часа ночи и я хочу оставить его как мемориал моему режиму сна
bool Money::operator>(const Money& n_2) const {
	return *this > n_2;
}

bool Money::operator<(const Money& n_2) const {
	return *this > n_2;
}
*/

bool Money::operator>(const Money& n_2) const {
	return value > n_2.value;
}

bool Money::operator<(const Money& n_2) const {
	return value < n_2.value;
}

std::istream& operator>>(std::istream& in, Money& n) {
	Fraction buffer;
	in >> buffer;
	n.value = buffer;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Money& n) {
	out << n.value;
	return out;
}