#pragma once

#include "cApartmentBuilder.h"
#include "cPeople.h"
#include <list>

class cApartment
{   
	int number;
	int floor;
	float square;
	std::list <cPeople *> residents; //Если в списке хранить объекты, а не  указатели, то будут создаваться копии при добавлении в список;
	
//	cApartmentBuilder* building; //Как сделать ссылку на объект в который входит текущий объект?
	static int allApartment;
public:
	cApartment(int number=0, int floor=0, float square=0) :number{ number }, floor{ floor }, square{ square }
	{
		allApartment++;
	}
	
	static int getAllApartment()
	{
		return allApartment;
	}

	int   getNumber() const{ return number; }
	int   getNloor()  const{ return floor; }
	float getSquare() const{ return square; }
	//friend cApartmentBuilder* getBuilding() { return building; }

	void setNumber(int n) { number = n; }
	void setFloor(int f)  { floor = f; }
	void setSquare(float s) { square = s; }
	//friend void setBuilding(cApartmentBuilder *a) { building = a; }

	void addResident(cPeople *resident)
	{
		residents.push_back(resident); //в список кладется новый скопированный объект,а не переданный //из-за этого номеров больше чем реально 
	}

	void delResident(cPeople *p)
	{
		for (auto i = residents.begin(); i != residents.end();)
			if (**i == *p)
			{
				std::cout << "Найден жилец для удаления " << **i;
				delete* i; //вроде бы деструктор сPeople для *i здесь сработал
				i = residents.erase(i);

			}
			else ++i;
	}

	friend std::ostream& operator<<(std::ostream& out,cApartment& a)
	{
		out << "Квартира номер: " << a.number << " этаж: " << a.floor << " площадь: " << a.square << "кв.м\n";
		for(auto r:a.residents)
		{
			out << *r;
		}
		return out;
	}

	int getCountResidents()
	{
		return residents.size();
	}
};
