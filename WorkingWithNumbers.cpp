#include <iostream>
#include <string>
#include "WorkingWithNumbers.h"
using namespace std;



class Chislo
{
	//Само число
	int* number;
	// Текущая система счисления
	int* system;

public:
	Chislo(int number, int numeralSystem = DEFAULT_SYSTEM);

	~Chislo();

	void changeSystem(int new_numeralSystem = DEFAULT_SYSTEM);

	Chislo adding(Chislo summand, int system_of_output = DEFAULT_SYSTEM);

	Chislo subtracting(Chislo subtract, int system_of_output = DEFAULT_SYSTEM);

	Chislo dividing(Chislo divider, int system_of_output = DEFAULT_SYSTEM);

	Chislo multiplication(Chislo multiplier, int system_of_output = DEFAULT_SYSTEM);

	Chislo powering(int power);

	Chislo comparing(Chislo compared);

	friend ostream& operator <<(ostream& out, Chislo chislo);

};

Chislo::Chislo(int _number, int numeralSystem)
{
	if ((numeralSystem <= 2) or (numeralSystem >= 10))
		numeralSystem = DEFAULT_SYSTEM;
	else
		*system = numeralSystem;
	number = (int*)_number;
}

Chislo::~Chislo()
{
	delete number;
	delete system;
}

int power_int(int a, int n) {
	if (n % 2 == 0)
		power_int(a, n / 2)* power_int(a, n / 2);
	else
		a * power_int(a, n / 2);
}

void Chislo::changeSystem(int new_numeralSystem = DEFAULT_SYSTEM) {
	
	int new_number = 0;

	for (int i = 0; *number > 0; i++) {
		new_number += (*number % (power_int(10, i + 1))) * (*system);
	}

	if (new_numeralSystem == DEFAULT_SYSTEM) {
		*number = new_number;
		*system = DEFAULT_SYSTEM;
	}
	else {
		string perevernutoe_chislo;
		while (new_number > 0) {
			int delitel = new_number / new_numeralSystem;
			perevernutoe_chislo += new_number - delitel * new_numeralSystem;
			new_number /= new_numeralSystem;
		}
		perevernutoe_chislo.pop_back();
		string normal_chislo;
		for (int j = perevernutoe_chislo.length; j > 0 ; j--) {
			char symbol = perevernutoe_chislo[j];
			normal_chislo += symbol;
		}
		new_number = stoi(normal_chislo);
		*number = new_number;
		*system = new_numeralSystem;
	}
}

Chislo Chislo::adding(Chislo summand, int system_of_output = DEFAULT_SYSTEM) {
	Chislo first = Chislo(*number, *system);
	first.changeSystem();
	int prev_number = *number;
	int prev_system = *system;
	number = summand.number;
	system = summand.system;
	summand.changeSystem();

	int summa = prev_number + *number;

	*number = prev_number;
	*system = prev_system;

	Chislo adding = Chislo(summa);
	if (system_of_output != DEFAULT_SYSTEM)
		adding.changeSystem(system_of_output);

	return(adding);
}

Chislo Chislo::subtracting(Chislo subtract, int system_of_output = DEFAULT_SYSTEM) {
	Chislo first = Chislo(*number, *system);
	first.changeSystem();
	int prev_number = *number;
	int prev_system = *system;
	number = subtract.number;
	system = subtract.system;
	subtract.changeSystem();

	int vychitanie = prev_number - *number;

	*number = prev_number;
	*system = prev_system;

	Chislo subtracting = Chislo(vychitanie);
	if(system_of_output != DEFAULT_SYSTEM)
		subtracting.changeSystem(system_of_output);

	return(subtracting);
}

class DividingException {};

Chislo Chislo::dividing(Chislo divider, int system_of_output = DEFAULT_SYSTEM) {
	Chislo first = Chislo(*number, *system);
	first.changeSystem();
	int prev_number = *number;
	int prev_system = *system;
	number = divider.number;
	system = divider.system;
	divider.changeSystem();

	if (number == 0) {
		throw DividingException();
		*number = prev_number;
		*system = prev_system;
		return(first);
	}
	else {
		int delenie = prev_number / *number;

		*number = prev_number;
		*system = prev_system;

		Chislo dividing = Chislo(delenie);
		if (system_of_output != DEFAULT_SYSTEM)
			dividing.changeSystem(system_of_output);

		return(dividing);
	}
	
}

Chislo Chislo::multiplication(Chislo multiplier, int system_of_output = DEFAULT_SYSTEM) {
	Chislo first = Chislo(*number, *system);
	first.changeSystem();
	int prev_number = *number;
	int prev_system = *system;
	number = multiplier.number;
	system = multiplier.system;
	multiplier.changeSystem();

	int umnozhenie = prev_number - *number;

	*number = prev_number;
	*system = prev_system;

	Chislo multiplication = Chislo(umnozhenie);
	if (system_of_output != DEFAULT_SYSTEM)
		multiplication.changeSystem(system_of_output);

	return(multiplication);
}

Chislo Chislo::powering(int power) {
	Chislo first = Chislo(*number, *system);
	first.changeSystem();
	int powered_number = power_int(*number, power);
	Chislo powered = Chislo(powered_number);
	powered.changeSystem(*system);

	return(powered);

}

Chislo Chislo::comparing(Chislo compared) {
	Chislo first = Chislo(*number, *system);
	first.changeSystem();
	int prev_number = *number;
	int prev_system = *system;
	number = compared.number;
	system = compared.system;
	compared.changeSystem();
	if (prev_number >= *number) {
		*number = prev_number;
		*system = prev_system;
		Chislo the_bigger_one = Chislo(*number, *system);
		return(the_bigger_one);
	}
	else {
		Chislo the_bigger_one = Chislo(*number, *system);
		*number = prev_number;
		*system = prev_system;
		return(the_bigger_one);
	}
}

ostream& operator <<(ostream& out,Chislo chislo){

	out << "Число: " << chislo.number << endl;
	out << "Система счисления: " << chislo.system << endl;
	
	return out;
}
