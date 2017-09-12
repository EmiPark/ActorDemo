#pragma once
#ifndef _DATE_H_
#define _DATE_H_

class Date
{
public:
	Date::Date() {};
	Date(int y, int m, int d);
	int getYear() const
	{
		return year;
	}
	int getMonth() const
	{
		return month;
	}
	int getDay() const
	{
		return day;
	}
	void setYear(int y)
	{
		year = y;
	}
	void setMonth(int m)
	{
		month = m;
	}
	void setDay(int d)
	{
		day = d;
	}
private:
	int year;
	int month;
	int day;
};

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
bool operator ==(const Date& d1, const Date& d2)
{
	return (d1.getYear() == d2.getYear()) && (d1.getMonth() == d2.getMonth()) && (d1.getDay() == d2.getDay());
}
#endif // !_DATE_H_

 