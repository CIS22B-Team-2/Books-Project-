#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Cashier.h"

int main()
{
    std::string title, isbn, author, publisher, date, quantity, whole, retail;
    std::string search;
    std::string purchaseQuantity;
    const int max = 50;
    Cashier book[max];
    Cashier purchaseList[max];
    
    std::ifstream infile;

	infile.open("books.txt");

    int i = 0;
	while (i < max) 
	{
	    getline(infile, title, '\n');
        getline(infile, isbn, '\n');
        getline(infile, author, '\n');
        getline(infile, publisher, '\n');
        getline(infile, date, '\n');
        getline(infile, quantity, '\n');
        getline(infile, whole, '\n');
        getline(infile, retail, '\n');
        book[i].setTitle(title);
        book[i].setISBN(isbn);
        book[i].setAuthor(author);
        book[i].setPublisher(publisher);
        book[i].setDate(date);
        book[i].setQuantity(quantity);
        book[i].setWholeSale(whole);
        book[i].setRetailSale(retail);
        i++;
	}

	infile.close();
	
    
    
    
    int maxPurchase = 0;
    int difference;
    
    std::string choice;
    std::cout << "Please enter 1 to search and buy a book(s) or 0 to see bill: ";
    getline(std::cin, choice, '\n');
    while (choice.length() != 1)
    {
        std::cout << "Wrong input. Please enter 1 or 0: ";
        getline(std::cin, choice, '\n');
    }
    
    while (stoi(choice) != 0)
    {
        switch(stoi(choice))
        {
            case 1:
            {
                std::cout << "Please enter the title of the book or the ISBN number to find a book. If a book could not be found, it will ask again." << std::endl;
                getline(std::cin, search, '\n');
                for (int k = 0; k < max; k++)
                {
                    if (search == book[k].getTitle())
                    {
                        purchaseList[maxPurchase] = book[k];
                        std::cout << "Please enter a quantity of the book you would like to purchase: ";
                        getline(std::cin, purchaseQuantity, '\n');
                        for (int i = 0; i < purchaseQuantity.length(); i++)
                        {
                            if (isdigit(purchaseQuantity[i]))
                            {
                                continue;
                            }
                            else
                            {
                                std::cout << "Wrong input. Please enter a quantity of the book you would like to purchase: ";
                                getline(std::cin, purchaseQuantity, '\n');
                            }
                        }
                        if (stoi(purchaseQuantity) <= stoi(book[k].getQuantity()))
                        {
                            purchaseList[maxPurchase].setQuantity(purchaseQuantity);
                            maxPurchase++;
                            difference = stoi(book[k].getQuantity()) - stoi(purchaseQuantity);
                            book[k].setQuantity(std::to_string(difference));
                            std::cout << "Book has been added. Please enter another choice 1 or 0: ";
                            getline(std::cin, choice, '\n');
                            while (choice.length() != 1)
                            {
                                std::cout << "Wrong input. Please enter 1 or 0: ";
                                getline(std::cin, choice, '\n');
                            }
                            break;
                        }
                        else
                        {
                            std::cout << "Quantity exceeds value in stock. We only have " << book[k].getQuantity() << " left in stock." << std::endl;
                            std::cout << "Try again. Please enter another choice 1 or 0: ";
                            getline(std::cin, choice, '\n');
                            while (choice.length() != 1)
                            {
                                std::cout << "Wrong input. Please enter 1 or 0: ";
                                getline(std::cin, choice, '\n');
                            }
                            break;
                        }
                    }
                    else if (search == book[k].getISBN())
                    {
                        purchaseList[maxPurchase] = book[k];
                        std::cout << "Please enter a quantity of the book you would like to purchase: ";
                        getline(std::cin, purchaseQuantity, '\n');
                        for (int i = 0; i < purchaseQuantity.length(); i++)
                        {
                            if (isdigit(purchaseQuantity[i]))
                            {
                                continue;
                            }
                            else
                            {
                                std::cout << "Wrong input. Please enter a quantity of the book you would like to purchase: ";
                                getline(std::cin, purchaseQuantity, '\n');
                            }
                        }
                        if (stoi(purchaseQuantity) <= stoi(book[k].getQuantity()))
                        {
                            purchaseList[maxPurchase].setQuantity(purchaseQuantity);
                            maxPurchase++;
                            difference = stoi(book[k].getQuantity()) - stoi(purchaseQuantity);
                            book[k].setQuantity(std::to_string(difference));
                            std::cout << "Book has been added. Please enter another choice 1 or 0: ";
                            getline(std::cin, choice, '\n');
                            while (choice.length() != 1)
                            {
                                std::cout << "Wrong input. Please enter 1 or 0: ";
                                getline(std::cin, choice, '\n');
                            }
                            break;
                        }
                        else
                        {
                            std::cout << "Quantity exceeds value in stock. We only have " << book[k].getQuantity() << " left in stock." << std::endl;
                            std::cout << "Try again. Please enter another choice 1 or 0: ";
                            getline(std::cin, choice, '\n');
                            while (choice.length() != 1)
                            {
                                std::cout << "Wrong input. Please enter 1 or 0: ";
                                getline(std::cin, choice, '\n');
                            }
                            break;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            case 0:
            {
               break; 
            }
            default:
            {
                std::cout << "Wrong input. Please enter 1 to search and buy a book or 0 to see bill: ";
                getline(std::cin, choice, '\n');
                while (choice.length() != 1)
                {
                    std::cout << "Wrong input. Please enter 1 or 0: ";
                    getline(std::cin, choice, '\n');
                }
            }
        }
    }
    
    
    double finalTotal = 0;
    book[0].displayTableTop();
    for (int a = 0; a < maxPurchase; a++)
    {
        std::cout << std::setw(4) << purchaseList[a].getQuantity() << std::setw(15) << purchaseList[a].getISBN() << std::setw(30) << purchaseList[a].getTitle() << std::setw(8) << std::fixed << std::setprecision(2) << purchaseList[a].getRetailSale() << std::setw(8) << std::setprecision(2) << purchaseList[a].Cashier::calcSubTotal() << std::endl;
        finalTotal += purchaseList[a].Cashier::calcSubTotal();
    }
    std::cout << std::endl;
    book[maxPurchase].displayTableBottom(finalTotal);
    
    
    
    
    
    
    return 0;
}