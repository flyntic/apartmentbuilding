#pragma once

#include "cApartmentBuilder.h"
#include "cPeople.h"
#include <list>

class cApartment
{   
	int number;
	int floor;
	float square;
	std::list <cPeople *> residents; //���� � ������ ������� �������, � ��  ���������, �� ����� ����������� ����� ��� ���������� � ������;
	
//	cApartmentBuilder* building; //��� ������� ������ �� ������ � ������� ������ ������� ������?
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
		residents.push_back(resident); //� ������ �������� ����� ������������� ������,� �� ���������� //��-�� ����� ������� ������ ��� ������� 
	}

	void delResident(cPeople *p)
	{
		for (auto i = residents.begin(); i != residents.end();)
			if (**i == *p)
			{
				std::cout << "������ ����� ��� �������� " << **i;
				delete* i; //����� �� ���������� �People ��� *i ����� ��������
				i = residents.erase(i);

			}
			else ++i;
	}

	friend std::ostream& operator<<(std::ostream& out,cApartment& a)
	{
		out << "�������� �����: " << a.number << " ����: " << a.floor << " �������: " << a.square << "��.�\n";
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
