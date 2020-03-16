#pragma once
#include "Module1.h"
#include "books.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class Database : public Module
{
private:
	const int arrsize = 100;
	Book inventory[100];
	int numBooks;
public:
	Database();
	~Database();
	/*void driver();*/
	int displayInvenu();
	// void FileToArray();
	void ArrayToFile();
	void sortBytitle();
	void sortByquantity();
	void sortByRetailPrice();
	void sortByWholesalePrice();
	void sortByAuthor();
	void sortByISBN();
	int searchByTitle(std::string title);
	int searchByISBN(std::string isbn);

	///*void addBook();
	//void deleteBook();
	//void editBook();
	//void displayBooks();
	//int SearchByName(Book*, int, std::string); */
};
