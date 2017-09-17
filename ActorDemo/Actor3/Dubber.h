#pragma once
#ifndef _DUBBER_H_
#define _DUBBER_H_
#include "MovieActor.h"

class Dubber :public MovieActor
{
public:
	//¼Ógetº¯Êý¡¢setº¯Êý
	Dubber(const char *name, Character c, Date d, int num) : MovieActor(name, c, d), num_movie(num) {};
	Dubber(int num, MovieActor & ma) :MovieActor(ma.getName(), ma.getCharacter(), ma.getBirthday()), num_movie(num) {};
	Dubber(const Dubber& d);
	const char *getName() const
	{
		return name;
	}
	Character getCharacter() const
	{
		return character;
	}
	Date getBirthday() const
	{
		return date;
	}
	int getNum() const
	{
		return num_movie;
	}
	void setName(const char *n)
	{
		name = n;
	}
	void setCharacter(Character c)
	{
		character = c;
	}
	void setBirthday(Date d)
	{
		date = d;
	}
	void setNum(int n)
	{
		num_movie = n;
	}
	friend ostream& operator<<(ostream& os, Dubber& d);
	~Dubber();
private:
	int num_movie;
};
ostream& operator<<(ostream& os, Dubber& d)
{
	os << "name:" << d.name << " character:";
	switch (d.character)
	{
	case Tragedy:
		cout << "Tragedy" << setfill(' ') << setw(20);
		break;
	case Comedy:
		cout << "Comedy" << setfill(' ') << setw(20);
		break;
	case WomanDressedLikeMan:
		cout << "WomanDressedLikeMan";
		break;
	case Juvenile:
		cout << "Juvenile" << setfill(' ') << setw(20);
		break;
	default:
		break;
	}
	os << " birthday:" << d.date.getYear() << "/" << d.date.getMonth() << "/" << d.date.getDay() << " movie number:" << d.num_movie << endl;
	return os;
}

Dubber::Dubber(const Dubber& d) : MovieActor(d), num_movie(d.num_movie) {};

Dubber::~Dubber()
{
}

#endif // !_DUBBER_H_
