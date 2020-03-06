#pragma once
#include <string>
#include <iostream>


// Books object
class Book
{
private:
	int ISBN;
	std::string title; 
	std::string publisher;
	int year; 
	int month;
	int day; 
	int quantity; 
	double wholesale; 
	double retail; 
	std::string author; 

public: 
	// Constructors
	Book(); 
	Book(int i, std::string t, std::string p, int y, int m, int d, int q, double w, double r, std::string a); // all params constructor

	// getters
	int getISBN();
	std::string getTitle();
	std::string getPublisher();
	int getYear();
	int getMonth();
	int getDay();
	int getQuantity();
	double getWholesale();
	double getRetail();
	std::string getAuthor();

	// setters 
	void setISBN(int i);
	void setTitle(std::string t);
	void setPublisher(std::string p);
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	void setQuantity(int q);
	void setWholesale(double w);
	void setRetail(double r);
	void setAuthor(std::string a);
};
