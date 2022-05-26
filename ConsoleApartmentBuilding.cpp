// ConsoleApartmentBuilding.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "cApartment.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	cApartment a(1, 1, 100);
	std::cout << a;


	cApartment b;
	b.setNumber(2);
  	b.addResident(cPeople("Иван", "Иванович", "Иванов"));
	b.addResident(cPeople("Жан", "Иванович", "Иванов"));

	std::cout << b;

	b.delResident( cPeople("Жан", "Иванович", "Иванов"));
	std::cout << b;
}
