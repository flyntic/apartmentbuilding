// ConsoleApartmentBuilder.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "cApartment.h"
#include "cApartmentBuilder.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	cApartmentBuilder b1(1, "", "улица Жукова");
	
	b1.addApartment(new cApartment(1, 1, 100));

	cApartmentBuilder b2(1, "корпус А", "улица Ленина");
	cApartment a2;
	a2.setNumber(2);

	a2.addResident(new cPeople("Иван1", "Иванович", "Иванов"));
	a2.addResident(new cPeople("Жан1", "Иванович", "Иванов"));
	a2.addResident(new cPeople("Жак1", "Иванович", "Иванов"));
	b2.addApartment(&a2);

	cApartmentBuilder b3(1);
	cApartment a3;
	a3.setNumber(2);
	a3.addResident(new cPeople("Иван2", "Иванович", "Иванов"));
	a3.addResident(new cPeople("Жан2", "Иванович", "Иванов"));
	a3.addResident(new cPeople("Жак2", "Иванович", "Иванов"));
	b3.addApartment(&a3);

	cApartmentBuilder b4(1);
	//b4.addApartment(cApartment(1));

	a3.delResident(new cPeople("Жан2", "Иванович", "Иванов", -1));

	std::cout << b1;
	std::cout << b2;
	std::cout << b3;
	std::cout << b4;


	std::cout << "Всего живущих :" << cPeople::GetAllPeople()             << " ; пронумеровано " << cPeople::GetCount() << " \n";
	std::cout << "Всего квартир :" << cApartment::getAllApartment()       << "\n";
	std::cout << "Всего домов   :" << cApartmentBuilder::getAllBuilding() << "\n";

}