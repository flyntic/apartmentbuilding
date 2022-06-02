#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <time.h>

//�� ����� ��� �������� � ����� ����� ������
class cPeople
{
private:
	int id;
	std::string * name;
	std::string * secondName;
	std::string * lastName;
	tm *dateOfBirthday;
	static int all_people;
	static int count_all;

private:
	cPeople(const int n, std::string name, std::string secondName, std::string lastName, tm dateOfBirthday) //� ���� ������������ ������������ id, ������� �� ���������
	{
		if (n != -1)	all_people++;
		if (n != -1)  id = n;
		this->name = new std::string(name);
		this->lastName = new std::string(lastName);
		this->secondName = new std::string(secondName);
		this->dateOfBirthday = new tm(dateOfBirthday);

		std::cout << "������ ������: " << *this;
	}

public:

	cPeople(const std::string name, std::string secondName, std::string lastName, tm dateOfBirthday) :cPeople(++count_all, name, secondName, lastName, dateOfBirthday) {}

	cPeople(const std::string name, std::string secondName, std::string lastName, int del) :cPeople((del==-1)?-1:++count_all, name, secondName, lastName, initTm(1,1,1)) {}

	cPeople() :cPeople("", "", "", initTm(1, 1, 1)) {};

	cPeople(const cPeople &p) :cPeople(*p.name, *p.secondName, *p.lastName, *p.dateOfBirthday) {};

	friend std::ostream& operator<<(std::ostream& out, const cPeople& people)
	{
		out << people.id <<" ��� :"<< *people.name<< " " << *people.secondName << " " << *people.lastName << " ���� �������� "<<printTm(people.dateOfBirthday)<< "\n";//

		return out;
	}
	cPeople(const std::string name, std::string secondName, std::string lastName):cPeople(name,secondName,lastName,initTm(1,1,1))	{	}
	~cPeople()
	{
	
		std::cout << "������ ������: " << *this;
		if (id != -1) all_people--;
		delete(name);
		delete(lastName);
		delete(secondName);
		delete(dateOfBirthday);
		
	}
	void setName(const std::string name) { *this->name = name; }
	std::string getName() {return *name;}

	void setLastName(const std::string lastname) { *this->lastName = lastname; }
	std::string getLastName() { return *lastName; }

	void setSecondName(const std::string secondname) { *this->secondName = secondname; }
	std::string getSecondName() { return *secondName; }

	void setDateOfBirthday(const tm dateOfBithday) 
	  { this->dateOfBirthday->tm_mday =  dateOfBirthday->tm_mday; 
	    this->dateOfBirthday->tm_mon  =  dateOfBirthday->tm_mon;
	    this->dateOfBirthday->tm_year =  dateOfBirthday->tm_year;
	  }
	tm getDateOfBirthday() { return *dateOfBirthday; }

	static int GetCount()
	{
		return (count_all);
	}

	static int GetAllPeople()
	{
		return (all_people);
	}

	static tm initTm(int day, int mon, int year)
	{
		tm tm;
		tm.tm_mday = day;
		tm.tm_mon  = mon;
		tm.tm_year = year;

		return tm;
	}

	static std::string printTm(tm *tm)
	{
		return std::to_string(tm->tm_mday) + "." + std::to_string(tm->tm_mon) + "." + std::to_string(tm->tm_year);
	}

	const bool operator==(const cPeople& pp)const
	{
		if ((strcmp(name->c_str(), pp.name->c_str())==0) & (strcmp(lastName->c_str(), pp.lastName->c_str())==0) & (strcmp(secondName->c_str(), pp.secondName->c_str())==0))
			return true;
		return false;
	}


};

