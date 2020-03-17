#include "books.h"

// Constructors
Book::Book() // default constructor 
{
	ISBN = "0000000000";
	title = "Default Book"; 
	publisher = "Default Publisher";
	int year = 0;
	int month = 0; 
	int day = 0;
	int quantity = 1; 
	double wholesale = 0; 
	double retail = 0; 
	author = "Default Author";
}

Book::Book(int i, std::string t, std::string p, int y, int m, int d, int q, double w, double r, std::string a) // all params constructor
{
	this->ISBN = i; 
	this->title = t; 
	this->publisher = p;
	this->year = y;
	this->month = m; 
	this->day = d; 
	this->quantity = q; 
	this->wholesale = w;
	this->retail = r; 
	this->author = a; 
}

// getters
std::string Book::getISBN() { return ISBN; }
std::string Book::getTitle() { return title; }
std::string Book::getPublisher() { return publisher; }
int Book::getYear() { return year; }
int Book::getMonth() { return month; }
int Book::getDay() { return day; }
int Book::getQuantity() { return quantity; }
double Book::getWholesale() { return wholesale; }
double Book::getRetail() { return retail; }
std::string Book::getAuthor() { return author; }

// setters 
void Book::setISBN(std::string i) { ISBN = i; }
void Book::setTitle(std::string t) { title = t; }
void Book::setPublisher(std::string p) { publisher = p;  }
void Book::setYear(int y) { year = y; }
void Book::setMonth(int m) { month = m; }
void Book::setDay(int d) { day = d; }
void Book::setQuantity(int q) { quantity = q;  }
void Book::setWholesale(double w) { wholesale = w; }
void Book::setRetail(double r) { retail = r;  }
void Book::setAuthor(std::string a) { author = a;  }

// functions
void Book::displayABook()
{
	std::cout << "Entering Display A Book function....\n";
	std::cout << "\nTitle: " << this->getTitle()
		<< "\nAuthor: " << this->getAuthor()
		<< "\nISBN: " << this->getISBN()
		<< "\nWholesale Cost: " << this->getWholesale()
		<< "\nRetail Cost: " << this->getRetail()
		<< "\nDate Added to Inventory: " << this->getYear() << "/" << this->getMonth() << "/" << this->getDay(); 
	std::cout << "\nQuantity: " << this->getQuantity();
}
