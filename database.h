#pragma once
#include "Module.h"
#include "books.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;
class Database : public Module
{
private:
	const int arrsize = 100;
	Book inventory[100];
	int numBooks;
public:
	Database();
	~Database();
	void driver();
	int displayInvenu();
	void FileToArray();
	void ArrayToFile();
	void sortBytitle();
	void sortByquantity();
	void sortByRetailPrice();
	void sortByWholesalePrice();
	void sortByAuthor();
	void sortByISBN();
	int searchByTitle(string title);
	int searchByISBN(string isbn);
	
	void addBook();
	void deleteBook();
	void editBook();
	void displayABook(int index);
	void displayBooks();
};
