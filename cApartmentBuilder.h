#pragma once

#include "cApartment.h"
#include <map>
#include <string>
class cApartmentBuilder
{
	int number;
	std::string buildingName;
	std::string streetName;
	std::map <int,cApartment*> Apartments;
	static int allBuilding;
public:
	cApartmentBuilder(int Number=0,std::string BuildingName=" ",std::string StreetName=" "): number(Number),buildingName(BuildingName),streetName(StreetName)
	{
		allBuilding++;
	}

	static int getAllBuilding()
	{
		return allBuilding;
	}
	void setNumber(int Number) { number = Number; }
	void setBuilding(std::string BuildingName) { buildingName = BuildingName; }
	void setNumber(std::string StreetName) { streetName = StreetName; }

	int getNumber() { return number; }
	std::string getBuilding() { return buildingName; }
	std::string getStreetName() { return streetName ; }

	friend std::ostream& operator<<(std::ostream& out, cApartmentBuilder& b)
	{
		out << "Улица: " << b.streetName << " номер дома: " << b.number<<" "<<b.buildingName<<"\n";
		out << "Квартир: " << b.Apartments.size() << " Жильцов: " << b.countAllResidents() << /*" этажность: " << b.flooring <<*/ " Общая жилая площадь:"<<b.countAllApartmentSquare()<<"\n";
	//	for (auto r : a.residents)
	//	{
	//		out << *r;
	//	}
		return out;
	}

	void addApartment( cApartment *a)
	{
		Apartments[a->getNumber()] = a;
	}

	float countAllApartmentSquare()
	{
		float square = 0;
		for (auto a : Apartments)
		{
			square += a.second->getSquare();
		}
		return square;
	}

	int countAllResidents()
	{
		int residents = 0;
		for (auto a : Apartments)
		{
			residents += a.second->getCountResidents();
		}
		return residents;
	}

};

#endif