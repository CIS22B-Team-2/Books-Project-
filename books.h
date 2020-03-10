#include "date.h"
#include <string>

using namespace std;

class Book
{
private: //member variables
	Date dateAdded;
	string title;
	string author;
	string publisher;
	string ISBN;
	int quantity;
	double wholesale;
	double retail;
	double MARKUP = 1;

public: //member functions
	//Setters
	Book();
	void setTitle(string s);
	void setAuthor(string a);
	void setISBN(string isbn);
	void setPublisher(string p);
	void setWholesale(double whole);
	void setRetail(double ret);
	void setDate(int month, int day, int year);
	void setDate(string date);
	void setQuantity(int q);

	//Getters
	string getTitle();
	string getAuthor();
	string getISBN();
	string getPublisher();
	double getWholesale();
	double getRetail();
	void getDate();
	int getQuantity();
	void setDate(const Date &d);
};
