#include "Application.h"
#include "Fraction.h"
#include "Money.h"
#include <iostream>
#define ENTER1 1
#define ENTER2 2
#define ADD 3
#define SUBSTRACT 4
#define MULTIPLY 5
#define DIVIDE 6
#define GREATER 7
#define LOWER 8


int Application::run(Money& money_1, Money& money_2) {
	short option;
	do {
		std::cout << R"(Choose:
	1. Enter object_1
	2. Enter object_2
	3. object_1 + object_2
	4. object_1 - object_2
	5. object_1 * object_2
	6. object_1 / object_2
	7. object_1 > object_2
	8. object_1 < object_2
	9. Exit)" << std::endl;
		do
			std::cin >> option;
		while (option < 1 || option > 9);
		switch (option) {
		case ENTER1:
			std::cin >> money_1;
			std::cout << "object_1 = " << money_1 << std::endl << "object_2 = " << money_2 << std::endl;
			break;
		case ENTER2:
			std::cin >> money_2;
			std::cout << "object_1 = " << money_1 << std::endl << "object_2 = " << money_2 << std::endl;
			break;
		case ADD:
			std::cout << (money_1 + money_2) << std::endl;
			break;
		case SUBSTRACT:
			std::cout << (money_1 - money_2) << std::endl;
			break;
		case MULTIPLY:
			std::cout << (money_1 * money_2) << std::endl;
			break;
		case DIVIDE:
			std::cout << (money_1 / money_2) << std::endl;
			break;
		case GREATER:
			std::cout << (money_1 > money_2) << std::endl;
			break;
		case LOWER:
			std::cout << (money_1 < money_2) << std::endl;
			break;
		}
	}
	while (option != 9);
	return 0;
}