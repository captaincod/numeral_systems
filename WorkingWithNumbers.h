/*
Определить класс «Число», позволяющий работать с числами в разных системах счисления (основание >= 2 и основание<=36). 
Реализовать в классе методы, позволяющие:
	менять систему счисления, 
	выполнять операции сложения, 
	вычитания, 
	деления
	и умножения, 
	возведения в степень
	и операции сравнения. 
В программе продемонстрировать использование объектов класса «Число». 
*/


const int DEFAULT_SYSTEM = 10;

class Chislo
{
	
	Chislo(int number, int numeralSystem = DEFAULT_SYSTEM); // конструктор

	~Chislo(); // деструктор

	void changeSystem(int new_numeralSystem = DEFAULT_SYSTEM); // меняет систему счисления

	Chislo adding(Chislo summand, int system_of_output = DEFAULT_SYSTEM); // суммирует числа, вывод в указанной СС, иначе в десятичной

	Chislo subtracting(Chislo subtract, int system_of_output = DEFAULT_SYSTEM); // вычитание, вывод в указанной СС

	Chislo dividing(Chislo divider, int system_of_output = DEFAULT_SYSTEM); // деление, если делитель = 0 - кидает ошибку

	Chislo multiplication(Chislo multiplier, int system_of_output = DEFAULT_SYSTEM); // умножение

	Chislo powering(int power); // возводит в степень

	Chislo comparing(Chislo compared); // сравнение - выводит наибольшее число

	friend ostream& operator <<(ostream& out, Chislo chislo); // вывод

};

int power_int(int a, int n); // возведение в степень целого числа
class DividingException {}; // на случай деления на ноль
