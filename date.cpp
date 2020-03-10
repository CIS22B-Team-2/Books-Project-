#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int dy, int mon, int yr)
{
	day = dy;
	month = mon;
	year = yr;
}
void Date::setDate(int dy, int mon, int yr)
{
	day = dy;
	month = mon;
	year = yr;
}
void Date::setDate(std::string stringformat)
{
	stringstream stream;
	stream << stringformat;
	stream >> *this;

}

bool Date::operator > (const Date &dateobj)
{
	bool status;
	if (year < dateobj.year)
		status = true;
	else if (year > dateobj.year)
		status = false;
	else if (year == dateobj.year)
	{
		if (month < dateobj.month)
			status = true;
		else if (month > dateobj.month)
			status = false;
		else if (month == dateobj.month)
		{
			if (day < dateobj.day)
				status = true;
			else if (day >= dateobj.day)
				status = false;
		}
	}
	return status;
}

bool Date::operator ==(const Date &dateobj)
{
	bool status;
	if (year == dateobj.year && month == dateobj.month && day == dateobj.day)
		status = true;
	else
		status = false;
	return status;
}

bool Date::operator <(const Date &dateobj)
{
	bool status;
	if (year > dateobj.year)
		status = true;
	else if (year < dateobj.year)
		status = false;
	else if (year == dateobj.year)
	{
		if (month > dateobj.month)
			status = true;
		else if (month < dateobj.month)
			status = false;
		else if (month == dateobj.month)
		{
			if (day > dateobj.day)
				status = true;
			else if (day <= dateobj.day)
				status = false;
		}
	}
	return status;
}

ostream &operator <<(ostream &stra, const Date &dateobj)
{
	stra << dateobj.month << '/' << dateobj.day << '/' << dateobj.year;

	return stra;
}

istream &operator >>(istream &strm, Date &date) {
	int month, day, year;
	strm >> month;
	strm.ignore();
	strm >> day;
	strm.ignore();
	strm >> year;
	strm.ignore();

	date.setDate(day, month, year);
	return strm;
}
