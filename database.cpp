#include "database.h"

Database::Database() : Module()
{
	numBooks = 0;
	FileToArray();
	sortBytitle();
}
Database::~Database()
{
	ArrayToFile();
}
void Database::driver()
{
	int choice1, choice2, index;
	string searchValue;
	char findAnother;
	do
	{
		choice1 = displayInvenu();
		if (choice1 == 1)
		{
			do
			{
				std::cout << "Do you want to look up the book by 1)Title or 2)ISBN? Enter your choice: ";
				std::cin >> choice2;
				std::cin.get();
				if (choice2 == 1)
				{
					do
					{
						std::cout << "Please enter the book title: ";
						getline(std::cin, searchValue);
						index = searchByTitle(searchValue);
						if (index != -1)
							displayABook(index);
						else
							std::cout << "Book not found. Please search again.\n";
					} while (index == -1);
				}
				else if (choice2 == 2)
				{
					do
					{
						std::cout << "Please enter the book ISBN: ";
						std::cin >> searchValue;
						sortByISBN();
						index = searchByISBN(searchValue); //<- enter isbn and search by author? WRONG!
						if (index != -1)
							displayABook(index);
						else
							std::cout << "Book not found. Please search again.\n";
					} while (index == -1);
				}
				else
				{
					std::cout << "Invalid entry. Please try again. Press enter.\n";
				}

				std::cout << "\n\nDo you wish to look up another book? y/n: ";
				std::cin >> findAnother;
			} while ((choice2 != 1 && choice2 != 2) || findAnother == 'y');
		}
		if (choice1 == 2)
			editBook();
		if (choice1 == 3)
			addBook();
		if (choice1 == 4)
			deleteBook();
	} while (choice1 != 5);
	std::cout << "\n\nLeaving Inventory Menu and returning to Main Menu...";
}
int Database::displayInvenu()
{
	int entry;
	std::cout << "\n\n\n\nInventory Database Menu:\n";
	std::cout << "1) Look up a book\n";
	std::cout << "2) Edit a book\n";
	std::cout << "3) Add a book\n";
	std::cout << "4) Delete a book\n";
	std::cout << "5) Return to Main Menu\n";
	std::cout << "Enter your choice: ";
	std::cin >> entry;
	return entry;
}
void Database::FileToArray()
{
	fstream bookList;
	string inputFileName;
	//need to skip the first line before readings(headings)
	int number = 0;
	do
	{
		std::cout << "Please enter the path to the input text file: ";
		std::cin >> inputFileName;
		bookList.open(inputFileName);
		if (bookList)
		{
			std::cout << "File opened successfully!\n";
			string title, author, publisher, ISBN;
			int quantity;
			double wholesale = 0.0, retail = 12.3456;
			Date date;
			for (int i = 0; i < arrsize && getline(bookList, title, '\t'); i++)
			{
				std::cout << "\nWe are reading eight values from the file!!\n"; //these read from file functions are creating issues!
				getline(bookList, author, '\t');
				getline(bookList, ISBN, '\t');
				bookList >> wholesale;
				bookList >> retail;
				bookList.ignore();
				bookList >> date;
				bookList >> quantity;
				bookList.ignore();

				inventory[i].setTitle(title);
				inventory[i].setAuthor(author);
				inventory[i].setISBN(ISBN);
				inventory[i].setWholesale(wholesale);
				inventory[i].setRetail(retail);
				inventory[i].setDate(date);
				inventory[i].setQuantity(quantity);
				numBooks++;
			} //OR: Until you hit '\t', read in a value(including spaces). Every eight set values will be one Book.
			//Then the next eight are the next book.
			std::cout << "\nWe have completed file read! Here is what is in the array: \n";
			displayBooks();
			number = 1;
			sortBytitle();
			displayBooks();
		}
		else
			std::cout << "\n\nFile Open Error! Please ensure the file is accessible, then try again.\n";
	} while (!number); //BY the time the if statement is complete, !bookList has turned to true. So, this repeats over and over again!
}
void Database::ArrayToFile()
{
	fstream UpdatedBookList;
	std::cout << "What file would you like to save your book list into?";
	string fileName;
	std::cin >> fileName;
	UpdatedBookList.open(fileName);
	for (int i = 0; i < 100; i++)
	{
		string title, author, publisher, ISBN;
		int quantity;
		double wholesale, retail;

		title = inventory[i].getTitle();
		author = inventory[i].getAuthor();
		ISBN = inventory[i].getISBN();
		quantity = inventory[i].getQuantity();
		wholesale = inventory[i].getWholesale();
		retail = inventory[i].getRetail();

		UpdatedBookList << title << "\t";
		UpdatedBookList << author << "\t";
		UpdatedBookList << ISBN << "\t";
		UpdatedBookList << wholesale << "\t";
		UpdatedBookList << retail << "\t";
		UpdatedBookList << quantity << "\t";
	}
}
void Database::sortBytitle()
{
	int startScan, minIndex;
	Book minBook;
	for (startScan = 0; startScan < (numBooks - 1); startScan++)
	{
		minIndex = startScan;
		minBook = inventory[startScan];
		for (int index = startScan + 1; index < numBooks; index++)
		{
			if (inventory[index].getTitle() < minBook.getTitle())
			{
				minBook = inventory[index];
				minIndex = index;
			}
		}
		inventory[minIndex] = (inventory[startScan]);
		inventory[startScan] = (minBook);
	}
}
void InventoryModule::sortByquantity()
{
	int startScan, minIndex;
	Book minBook;
	for (startScan = 0; startScan < (numBooks - 1); startScan++)
	{
		minIndex = startScan;
		minBook = inventory[startScan];
		for (int index = startScan + 1; index < numBooks; index++)
		{
			if (inventory[index].getQuantity() < minBook.getQuantity())
			{
				minBook = inventory[index];
				minIndex = index;
			}
		}
		inventory[minIndex] = (inventory[startScan]);
		inventory[startScan] = minBook;
	}
}
void InventoryModule::sortByRetailPrice()
{
	int startScan, minIndex;
	Book minBook;
	for (startScan = 0; startScan < (numBooks - 1); startScan++)
	{
		minIndex = startScan;
		minBook = inventory[startScan];
		for (int index = startScan + 1; index < numBooks; index++)
		{
			if (inventory[index].getRetail() < minBook.getRetail())
			{
				minBook = inventory[index];
				minIndex = index;
			}
		}
		inventory[minIndex] = (inventory[startScan]);
		inventory[startScan] = (minBook);
	}
}
void InventoryModule::sortByWholesalePrice()
{
	int startScan, minIndex;
	Book minBook;
	for (startScan = 0; startScan < (numBooks - 1); startScan++)
	{
		minIndex = startScan;
		minBook = inventory[startScan];
		for (int index = startScan + 1; index < numBooks; index++)
		{
			if (inventory[index].getWholesale() < minBook.getWholesale())
			{
				minBook = inventory[index];
				minIndex = index;
			}
		}
		inventory[minIndex] = (inventory[startScan]);
		inventory[startScan] = (minBook);
	}
}
void InventoryModule::sortByAuthor()
{
	int startScan, minIndex;
	Book minBook;
	for (startScan = 0; startScan < (numBooks - 1); startScan++)
	{
		minIndex = startScan;
		minBook = inventory[startScan];
		for (int index = startScan + 1; index < numBooks; index++)
		{
			if (inventory[index].getAuthor() < minBook.getAuthor())
			{
				minBook = inventory[index];
				minIndex = index;
			}
		}
		inventory[minIndex] = (inventory[startScan]);
		inventory[startScan] = (minBook);
	}
}
void InventoryModule::sortByISBN()
{
	int startScan, minIndex;
	Book minBook;
	for (startScan = 0; startScan < (numBooks - 1); startScan++)
	{
		minIndex = startScan;
		minBook = inventory[startScan];
		for (int index = startScan + 1; index < numBooks; index++)
		{
			if (inventory[index].getISBN() < minBook.getISBN())
			{
				minBook = inventory[index];
				minIndex = index;
			}
		}
		inventory[minIndex] = (inventory[startScan]);
		inventory[startScan] = (minBook);
	}
}
int InventoryModule::searchByTitle(string title)
{
	int first = 0, last = numBooks - 1, middle, position = -1;
	bool found = false;
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (inventory[middle].getTitle() == title)
		{
			found = true;
			position = middle;
		}
		else if (inventory[middle].getTitle() > title)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}

int InventoryModule::searchByISBN(string isbn)
{
	int first = 0, last = numBooks - 1, middle, position = -1;
	bool found = false;
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (inventory[middle].getISBN() == isbn)
		{
			found = true;
			position = middle;
		}
		else if (inventory[middle].getISBN() > isbn)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}

void Database::addBook()
{

	string Title;
	string Author;
	string Publisher;
	double RetailPrice;
	double wholeSalePrice;
	std::cout << "Please enter the details of the Book you want to add\n";
	std::cout << "Enter Title\n";
	std::cin >> Title;
	int result = binarySearchbyName(bookObject, size, Title);
	if (result != -1)
	{
		bookObject[result].incrementQuantity();
	}
	else
	{
		size = size + 1;
		bookObject[size].setTitle(Title);

		std::cout << "Enter Author";
		std::cin >> Author;
		std::cout << "\n";
		bookObject[size].setAuthor(Author);
		std::cout << "Enter Publisher";
		std::cin >> Publisher;
		std::cout << "\n";
		bookObject[size].setPublisher(Publisher);
		std::cout << "Retail price";
		std::cin >> RetailPrice;
		std::cout << "\n";
		bookObject[size].setRetailPrice(RetailPrice);
		std::cout << "whole sale price";
		std::cin >> wholeSalePrice;
		std::cout << "\n";
		bookObject[size].setWholesale(wholeSalePrice);
		bookObject[size].setQuantity(1);
	}
}

void Database::deleteBook()
{

	string BookTitle;
	std::cout << "what book do you want Delete";
	std::cin >> BookTitle;
	int result = binarySearchbyName(bookObject, size, BookTitle);
	if (result != -1)
	{
		for (int i = result; i < size - 1; i++)
		{
			bookObject[i] = bookObject[i + 1]; //Moves the entire list up by one.
		}
		size = size - 1;
	}
	else
	{
		std::cout << "Book not found\n";
	}
}

void Database::editBook()
{
	string BookTitle;
	std::cout << "what book do you want edit: Enter Title ";
	std::cin >> BookTitle;
	int result = binarySearchbyName(bookObject, size, BookTitle);
	if (result != -1)
	{
		string res = "";
		int entry;
		//int entry;
		std::cout << "\nPlease select entry to be edited\t";
		std::cout << "1:Title\n 2:Author\n 3:Publisher\n:4:Quantity \n 5:Retail price\n 6:whole sale\n ";
		std::cin >> entry;
		switch (entry)
		{
		case 1:
			std::cout << "Enter Title";
			std::cin >> res;
			bookObject[result].setTitle(res);
			break;
		case 2:
			std::cout << "Enter author ";
			std::cin >> res;
			bookObject[result].setAuthor(res);
			break;
		case 3:
			std::cout << "Enter publisher";
			std::cin >> res;
			bookObject[result].setPublisher(res);
			break;

		case 4:
			std::cout << "Quantity";
			int value;
			std::cin >> value;
			bookObject[result].setQuantity(value);
			break;

		case 5:

			std::cout << "Retail price";
			double value2;
			std::cin >> value2;
			bookObject[result].setRetailPrice(value2);
			break;
		case 6:

			std::cout << "whole sale";
			double value3;
			std::cin >> value3;
			bookObject[result].setWholesale(value3);
			break;
		default:
			std::cout << "Invalid menu choice. Please try again: ";
		}
	}
	else
	{
		std::cout << "Book not found\n";
	}
}
void Database::displayABook(int index)
{
	std::cout << "Entering Display A Book function....\n";
	std::cout << "\nTitle: " << inventory[index].getTitle()
		 << "\nAuthor: " << inventory[index].getAuthor()
		 << "\nISBN: " << inventory[index].getISBN()
		 << "\nWholesale Cost: " << inventory[index].getWholesale()
		 << "\nRetail Cost: " << inventory[index].getRetail()
		 << "\nDate Added to Inventory: ";
	inventory[index].getDate();
	std::cout << "\nQuantity: " << inventory[index].getQuantity();
}
void Database::displayBooks()

{
	std::cout << "\n\nEntering Display Book function....\n";
	std::cout << "Title" << setw(20) << "author" << setw(20) << "publisher" << setw(20) << "ISBN" << setw(20)
		 << "WholesaleCost" << setw(20) << "RetailCost" << setw(20) << "date" << setw(20) << "quantity" endl;
	for (int i = 1; i <= size; i++)
	{
		std::cout << bookObject[i].getbookName() << setw(20) << bookObject[i].getbookAuhtor() << setw(20) << bookObject[i].getISBN() << setw(20) << bookObject[i].getWholesale() << endl;
		//for (int i = 0; i < numBooks; i++)
		//{
		///std::cout << "\nTitle: " << inventory[i].getTitle()
		//<< "\nAuthor: " << inventory[i].getAuthor()
		//<< "\nISBN: " << inventory[i].getISBN()
		//<< "\nWholesale Cost: " << inventory[i].getWholesale()
		//<< "\nRetail Cost: " << inventory[i].getRetail()
		//<< "\nDate Added to Inventory: ";
		inventory[i].getDate();
		std::cout << "\nQuantity: " << inventory[i].getQuantity();
		std::cout << "\n\n\n\n";
	}
}
