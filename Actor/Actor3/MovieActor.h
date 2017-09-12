#pragma once
#include "stdafx.h"
#include "Date.h"
using namespace std;
#ifndef _MA_H_
#define _MA_H_
enum Character
{
	Tragedy, Comedy, WomanDressedLikeMan, Juvenile
};
class MovieActor
{
public:
	MovieActor(const char *n, Character c, Date d);
	MovieActor(const MovieActor& MA);
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
	~MovieActor();
	friend bool operator ==(const MovieActor& ma1, const MovieActor& ma2);
	friend ostream& operator<<(ostream& os, const MovieActor& MA);
protected:
	const char *name;
	Character character;
	Date date;
};
bool operator ==(const MovieActor& ma1, const MovieActor& ma2)
{
	return (ma1.name == ma2.name) && (ma1.character == ma2.character) && (ma1.date == ma2.date);
}
ostream& operator<<(ostream& os, const MovieActor& MA)
{
	os << "name:" << MA.name << " character:";
	switch (MA.character)
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
	os << " birthday:" << MA.date.getYear() << "/" << MA.date.getMonth() << "/" << MA.date.getDay() << endl;
	return os;
}
MovieActor::MovieActor(const char* n, Character c, Date d)
{
	name = n;
	character = c;
	date = d;
}
MovieActor::MovieActor(const MovieActor & MA)
{
	name = MA.name;
	character = MA.character;
	date = MA.date;
}

MovieActor::~MovieActor()
{
}
#endif // !_MA_H_

