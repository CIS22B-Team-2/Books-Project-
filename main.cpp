#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "books.h"
#include "database.h"
#include "Cashier.h"


using namespace std;

// Function prototypes 
void printMenu();
void printCashierMenu();
void getChoice(string &choice);

int main()
{
    // Array to hold all books
    Book bookList[100]; 
    string choice;
    bool flag = true;

    // Open textfile full of books for reading
    ifstream inFile;
    inFile.open("books.txt");

    // Temp variables to read from file into array of books 
    string copyISBN;
    string copyTitle;
    string copyPublisher;
    string copyYear;
    string copyMonth;
    string copyDay;
    string copyQuantity;
    string copyWholesale;
    string copyRetail;
    string copyAuthor;

    // Reading in all 50 books from textfile 
    int i = 0;
    while (inFile.good())
    {
        getline(inFile, copyISBN);
        getline(inFile, copyTitle); 
        getline(inFile, copyPublisher);
        getline(inFile, copyYear);
        getline(inFile, copyMonth);
        getline(inFile, copyDay);
        getline(inFile, copyQuantity);
        getline(inFile, copyWholesale);
        getline(inFile, copyRetail);
        getline(inFile, copyAuthor);
        bookList[i].setISBN(copyISBN);
        bookList[i].setTitle(copyTitle);
        bookList[i].setPublisher(copyPublisher);
        bookList[i].setYear(stoi(copyYear));
        bookList[i].setMonth(stoi(copyMonth));
        bookList[i].setDay(stoi(copyDay));
        bookList[i].setQuantity(stoi(copyQuantity));
        bookList[i].setWholesale(stod(copyWholesale));
        bookList[i].setRetail(stod(copyRetail));
        bookList[i].setAuthor(copyAuthor);
        i++;
    }

    /*int n = 0;
    while (n < i)
    {
        cout << "ISBN: " << bookList[n].getISBN() << endl
            << "Title: " << bookList[n].getTitle() << endl
            << "Publisher: " << bookList[n].getPublisher() << endl
            << "Year: " << bookList[n].getYear() << endl
            << "Month: " << bookList[n].getMonth() << endl
            << "Day: " << bookList[n].getDay() << endl
            << "Quantity: " << bookList[n].getQuantity() << endl
            << "Wholesale: " << bookLis t[n].getWholesale() << endl
            << "Retail: " << bookList[n].getRetail() << endl
            << "Author: " << bookList[n].getAuthor() << endl;
        n++;
    }*/

    std::string search;
    std::string purchaseQuantity;
    const int max = 50;
    Cashier book[max];
    Cashier purchaseList[max];
  
    do 
    {    
        printMenu();
        getChoice(choice);
        system("cls");
        if (choice == "1")
        {
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
                switch (stoi(choice))
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
        }
        if (choice == "2")
        {
            cout << "You are now using inventory database module. What would you like to do?" << endl; 
        }

        if (choice == "3")
        {
            /*bool flag3 = true; 
            do
            {








            } while (flag3 == true);*/
        }
        
        if (choice == "4")
        {
            cout << "Thank you using the Book Store Program!" << endl;
            return 0; 
        }
    } while (flag);

    return 0;
}

void printMenu()
{
    cout << internal << "Welcome to Ne Danza Book Store!" << endl;
    cout << "Please select what you wish to do" << endl;
    cout << "1. Cashier Module " << endl;
    cout << "2. Inventory Database Module " << endl;
    cout << "3. Report Module " << endl;
    cout << "4. Exit " << endl;
}

void printCashierMenu()
{
    cout << "Please enter the ISBN of the book you are purchasing, with a space followed by the quantity of that book." << endl;
    cout << "For example, if the ISBN is 9781305616691 and you are purchasing 3 of the same copies, enter: " << endl;
    cout << "9781305616691 3" << endl;
}


void getChoice(string &choice)
{
    bool flag = true; 
    do
    {
        getline(cin, choice);
        if (choice == "1" || choice == "2" || choice == "3" || choice == "4")
            flag = false;
        else
            cout << "Please enter a valid chocie" << endl; 
    } while (flag);
}





// Functions - Stephen
//The function below sorts the books by quantity;
// Largest quantity first;
void sortBooksQuantity(Book arr[], int size) {
  //sort the books by 
  int minIndex;
  int minValue;
  
  for (int start = 0; start < (size - 1); start++) {
    minIndex = start;
    minValue = arr[start].getQuantity();
    for (int index = start + 1; index < size; index++) {
      if(arr[index].getQuantity() > minValue) {
        minValue = arr[index].getQuantity();
        minIndex = index;
      }
    }
    swap(arr[minIndex], arr[start]);
  }

  cout << "AFTER: " << endl;
  listBooks(arr);

};
