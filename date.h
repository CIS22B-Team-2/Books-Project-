#pragma once
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;

class Date
{
private:
	int day, month, year;
public:
	Date();
	Date(int dy, int mon, int yr);
	void setDate(int dy, int mon, int yr);
	void setDate(std::string stringformat);
	bool operator > (const Date &dateobj);
	bool operator ==(const Date &dateobj);
	bool operator <(const Date &dateobj);
	friend istream &operator >>(istream &, Date &);
	friend ostream &operator <<(ostream &, const Date &);
};

//are these necessary? Since they are also above ^^^
ostream &operator <<(ostream &stra, const Date &dateobj);
istream &operator >>(istream &strm, Date &date);
