#include "WorkingWithNumbers.h"
#include "WorkingWithNumbers.cpp"
using namespace std;
int main(void)
{
	setlocale(LC_ALL, "Russian");
	
	Chislo first_one(4);
	Chislo second_one(10,2);
	Chislo third_one(1021,3);

	cout << first_one << endl;
	cout << second_one << endl;
	cout << third_one << endl;

	first_one.powering(6);
	cout << first_one << endl;

	second_one.multiplication(third_one);
	cout << first_one.comparing(second_one) << endl;

	Chislo devider(10);
	first_one.dividing(devider);
	third_one.dividing(devider);

	cout << first_one << endl;
	cout << second_one << endl;
	cout << third_one << endl;




}
