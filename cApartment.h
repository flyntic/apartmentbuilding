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
	cApartment(int number=0, int floor=0, float square=0) :number{ number }, floor{ floor }, square{ square }
	{
	//	residents = new std::list <cPeople>;
	}
	
	//cApartment() :cApartment(0, 0, 0) {}

	int   getNumber() const{ return number; }
	int   getNloor()  const{ return floor; }
	float getSquare() const{ return square; }

	void setNumber(int n) { number = n; }
	void setFloor(int f)  { floor = f; }
	void setSquare(float s) { square = s; }

	void addResident(cPeople presidents)
	{
		residents.push_back(presidents);
	}

	void delResident(cPeople p)
	{
		for(auto r:residents)
			if (r == p)
			{
				residents.remove(r);
				//r.~cPeople();
			}
			 
	}

	friend std::ostream& operator<<(std::ostream& out,cApartment& a)
	{
		out << "�������� �����: " << a.number << " ����: " << a.floor << " �������: " << a.square << "��.�\n";
		for(auto r:a.residents)
		{
			out << r;
		}
		return out;
	}

};

