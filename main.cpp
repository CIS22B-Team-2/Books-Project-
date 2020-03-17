#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "books.h"
#include "Database.h"
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

    std::string search;
    std::string purchaseQuantity;
    const int max = 100;
    Cashier book[max];
    Cashier purchaseList[max];

    int size = 0; // Current number of titles 

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
        book[i].setISBN(copyISBN);
        book[i].setTitle(copyTitle);
        book[i].setPublisher(copyPublisher);
        book[i].setYear(stoi(copyYear));
        book[i].setMonth(stoi(copyMonth));
        book[i].setDay(stoi(copyDay));
        book[i].setQuantity(stoi(copyQuantity));
        book[i].setWholesale(stod(copyWholesale));
        book[i].setRetail(stod(copyRetail));
        book[i].setAuthor(copyAuthor);
        i++;
        size++; 
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
                            if (stoi(purchaseQuantity) <= (book[k].getQuantity()))
                            {
                                purchaseList[maxPurchase].setQuantity(stoi(purchaseQuantity));
                                maxPurchase++;
                                difference = (book[k].getQuantity()) - stoi(purchaseQuantity);
                                book[k].setQuantity(difference);
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
                            if (stoi(purchaseQuantity) <= book[k].getQuantity())
                            {
                                purchaseList[maxPurchase].setQuantity(stoi(purchaseQuantity));
                                maxPurchase++;
                                difference = book[k].getQuantity() - stoi(purchaseQuantity);
                                book[k].setQuantity(difference);
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
                std::cout << std::setw(4) << purchaseList[a].getQuantity() << std::setw(15) << purchaseList[a].getISBN() << std::setw(30) << purchaseList[a].getTitle() << std::setw(8) << std::fixed << std::setprecision(2) << purchaseList[a].getRetail() << std::setw(8) << std::setprecision(2) << purchaseList[a].Cashier::calcSubTotal() << std::endl;
                finalTotal += purchaseList[a].Cashier::calcSubTotal();
            }
            std::cout << std::endl;
            book[maxPurchase].displayTableBottom(finalTotal);
        }
        if (choice == "2")
        {
            string choice = "";
            bool flag1 = true; 
            /*string search = ""; 
            string findAnother = ""; */
            do
            {
                cout << "You are now using inventory database module. What would you like to do?" << endl;
                cout << "1. Look up a book" << endl;
                cout << "2. Add a book" << endl;
                cout << "3. Edit a book's record" << endl;
                cout << "4. Delete a book" << endl;
                cout << "5. Return to main menu" << endl;
                getline(cin, choice); // do error checking later

                // Look up a book
                if (choice == "1")
                {
                    string choice2 = "";
                    string searchValue = "";
                    int index = -1;
                    string search = "";
                    string findAnother = "";

                    do
                    {
                        std::cout << "Do you want to look up the book by 1)Title or 2)ISBN? Enter your choice: ";
                        getline(cin, choice2); // INPUT VALIDAITION
                        if (choice2 == "1")
                        {
                            do
                            {
                                cout << "Please enter the book title: ";
                                getline(cin, searchValue);
                                for (int i = 0; i < size; i++)
                                {
                                    if (book[i].getTitle() == searchValue)
                                    {
                                        index = i;
                                    }
                                }
                                if (index != -1)
                                    book[index].displayABook();
                                else
                                    cout << "Book not found. Please search again.\n";
                            } while (index == -1);
                        }
                        else if (choice2 == "2")
                        {
                            do
                            {
                                cout << "Please enter the book ISBN: ";
                                getline(cin, searchValue);
                                for (int i = 0; i < size; i++)
                                {
                                    if (book[i].getISBN() == searchValue)
                                    {
                                        index = i;
                                    }
                                }
                                if (index != -1)
                                    book[index].displayABook();
                                else
                                    cout << "Book not found. Please search again.\n";
                            } while (index == -1);
                        }
                        else
                        {
                            std::cout << "Invalid entry. Please try again. Press enter.\n";
                        }
                    } while ((choice2 != "1" && choice2 != "2") || findAnother == "y" || findAnother == "Y");
                }

                // Add a book
                else if (choice == "2")
                {
                    bool flag2 = true;
                    string choice1; 
                    do
                    {
                        cout << "Please enter the details of the Book you want to add\n";
                        cout << "Enter Title\n";
                        getline(cin, copyTitle);
                        for (int i = 0; i < size; i++)
                        {
                            if (book[i].getTitle() == copyTitle)
                                flag2 = false; 
                        }
                        if (flag2 == false)
                        {
                            cout << "This book is already in the database, pleaes go to 'Edit a book's Record.'" << endl;
                        }
                        
                        else if (flag2 == true)
                        {
                            size = size + 1;
                            book[size].setTitle(copyTitle);

                            cout << "Enter the ISBN"; 
                            getline(cin, copyISBN);
                            cout << "\n";
                            book[size].setISBN(copyISBN);
                            cout << "Enter Author";
                            getline(cin, copyAuthor); 
                            cout << "\n";
                            book[size].setAuthor(copyAuthor);
                            cout << "Enter Publisher";
                            getline(cin, copyPublisher);
                            cout << "\n";
                            book[size].setPublisher(copyPublisher);
                            cout << "Retail price";
                            getline(cin, copyRetail);
                            cout << "\n";
                            book[size].setRetail(stod(copyRetail));
                            cout << "whole sale price";
                            getline(cin, copyWholesale);
                            cout << "\n";
                            book[size].setWholesale(stod(copyWholesale));
                            cout << "Enter quantity to add"; 
                            getline(cin, copyQuantity); 
                            cout << "\n"; 
                            book[size].setQuantity(stoi(copyQuantity));

                            // Set date as 3/19/2020
                            book[size].setYear(2020);
                            book[size].setMonth(3);
                            book[size].setDay(19);
                            
                            cout << "Would you like to add another book? Please enter Y or N" << endl; 
                            getline(cin, choice1); // INPUT VALIDATION
                            if (choice1 == "Y" || choice1 == "y")
                            {
                                flag2 = true;
                            }
                            else if (choice1 == "N" || choice1 == "n")
                            {
                                flag2 = false;
                            }
                        }   
                    } while (flag2 != false);
                } // DONE

                // Edit a book
                else if (choice == "3")
                {
                    string searchValue = ""; 
                    int index = -1; 

                    cout << "Please enter the title of the book you wish to edit: "; 
                    getline(cin, searchValue); // INPUT VALIDATION

                    for (int i = 0; i < size; i++)
                    {
                        if (book[i].getTitle() == searchValue)
                        {
                            index = i;
                        }
                    }

                    if (index != -1)
                    {
                        string res = "";
                        string entry;
                        bool flag3 = true; 
                        do
                        {
                            cout << "\nPlease select entry to be edited\t";
                            cout << "1:Quantity\n 2:Retail price\n 3:Wholesale Price\n";
                            getline(cin, entry); // INPUT VALIDATION
                            switch (stoi(entry))
                            {
                            case 1:
                                cout << "Enter new quantity: ";
                                getline(cin, res);
                                book[index].setQuantity(stoi(res));
                                cout << "Quantity has been updated!" << endl; 
                                flag3 = false; 
                                break;
                            case 2:
                                cout << "Enter new retail price: ";
                                getline(cin, res);
                                book[index].setRetail(stoi(res));
                                cout << "Retail price has been updated!" << endl;
                                flag3 = false; 
                                break;
                            case 3:
                                cout << "Enter new wholesale price: ";
                                getline(cin, res);
                                book[index].setWholesale(stoi(res));
                                cout << "Wholesale price has been updated!" << endl;
                                flag3 = false; 
                                break;
                            default:
                                cout << "Invalid menu choice. Please try again: ";
                            }
                        } while (flag3 == true); 
                    }
                    else
                    {
                        std::cout << "Book not found\n";
                    }
                }


                else if (choice == "4")
                {
                        
                }

                else if (choice == "5")
                {
                    cout << "Returning to main menu." << endl; 
                    flag1 = false; 
                }
            } while (flag1); 
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
