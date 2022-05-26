#pragma once
#include "cPeople.h"
#include <list>

class cApartment
{   
	int number;
	int floor;
	float square;
	std::list <cPeople> residents;
public:
	cApartment(int number, int floor, float square) :number{ number }, floor{ floor }, square{ square }
	{
		//residents = new std::list <cPeople>;
	}
	
	cApartment() :cApartment(0, 0, 0) {}

	int   getNumber() const{ return number; }
	int   getNloor()  const{ return floor; }
	float getSquare() const{ return square; }

	void setNumber(int n) { number = n; }
	void setFloor(int f) { floor = f; }
	void setSquare(float s) { square = s; }

	void addResident(cPeople &p)
	{
		residents.push_back(p);
	}

	void delResident(cPeople p)
	{
		for(auto r:residents)
			if (r == p)
			{
				residents.remove(r);
				//	remove();
				r.~cPeople();
			}
			 
	}

	friend std::ostream& operator<<(std::ostream& out,cApartment& a)
	{
		out << " вартира номер: " << a.number << " этаж: " << a.floor << " площадь: " << a.square << "кв.м\n";
		for(auto r:a.residents)
		{
			out << r;
		}
		return out;
	}

};

