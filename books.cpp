#include "Book.h"

Book::Book()
	{
		retail = 0;
		dateAdded.setDate(0, 0, 0);
	}
void Book::setTitle(string s)
	{
		title = s;
	}
void Book::setAuthor(string a)
	{
		author = a;
	}
void Book::setISBN(string isbn)
	{
		ISBN = isbn;
	}
void Book::setPublisher(string p)
	{
		publisher = p;
	}
void Book::setWholesale(double whole)
	{
		wholesale = whole;
	}
void Book::setRetail(double ret)
	{
		retail = ret;
	}
void Book::setDate(int month, int day, int year)
	{
		dateAdded.setDate(day, month, year);
	}
void Book::setDate(string date)
	{
		dateAdded.setDate(date);
	}
void Book::setQuantity(int q)
	{
		quantity = q;
	}

	//Getters
string Book::getTitle()
	{
		return title;
	}
string Book::getAuthor()
	{
		return author;
	}
string Book::getISBN()
	{
		return ISBN;
	}
string Book::getPublisher()
	{
		return publisher;
	}
double Book::getWholesale()
	{
		return wholesale;
	}
double Book::getRetail()
	{
	return wholesale * MARKUP;
	}
void Book::getDate()
	{
		cout << dateAdded;//dateAdded.getDate();
	}
int Book::getQuantity()
	{
		return quantity;
	}
void Book::setDate(const Date &d) { dateAdded = d; }