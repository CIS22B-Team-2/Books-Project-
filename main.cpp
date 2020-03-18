#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "books.h"
#include "Cashier.h"


using namespace std;

// Function prototypes 
void printMenu();
void getChoice(string &choice);
void printLine(); 

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
  
    do 
    {    
        system("cls"); 
        printMenu();
        getChoice(choice);
        system("cls");
        // Cashier module
        if (choice == "1")
        {
            int maxPurchase = 0;
            int difference;

            string choice;
            cout << setw(25) << "" << "Welcome to the Cashier Module!" << endl; 
            printLine(); 
            cout << "Please enter 1 to search and buy a book(s) or 0 to see bill: ";
            getline(cin, choice, '\n');
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
            cout << endl;
            book[maxPurchase].displayTableBottom(finalTotal);
            cout << endl << "Press enter to return to main menu." << endl; 
            cin.get(); 
            system("cls"); 
        }

        // Inventory module
        if (choice == "2")
        {
            string choice = "";
            bool flag1 = true; 
            bool flag2 = true; 
            /*string search = ""; 
            string findAnother = ""; */
            do
            {
                system("cls"); 
                cout << setw(5) << "" << "Welcome to the Inventory Database Module! Please select an option." << endl;
                printLine(); 
                cout << "1. Look up a book" << endl;
                cout << "2. Add a book" << endl;
                cout << "3. Edit a book's record" << endl;
                cout << "4. Delete a book" << endl;
                cout << "5. Return to main menu" << endl;

                // Read in a choice
                bool flag1 = false; 
                do
                {
                    getline(cin, choice); 
                    if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5")
                    {
                        cout << "Please enter a valid option." << endl;
                        flag1 = true;
                    }
                    else
                        flag1 = false; 
                } while (flag1);

                // Look up a book
                if (choice == "1")
                {
                    string choice2 = "";
                    string searchValue = "";
                    int index = -1;
                    string search = "";

                    do
                    {
                        std::cout << "Do you want to look up the book by 1)Title or 2)ISBN? Enter your choice: ";

                        do
                        {
                            getline(cin, choice2);
                            if (choice2 != "1" && choice2 != "2")
                            {
                                cout << "Please enter a valid option." << endl;
                                flag1 = true;
                            }
                            else
                                flag1 = false;
                        } while (flag1);

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
                                {
                                    book[index].displayABook();
                                    cout << "Press enter to return to Inventory Database Module." << endl;
                                    cin.get();
                                    system("cls");
                                }
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
                                {
                                    book[index].displayABook();
                                    cout << "Press enter to return to Inventory Database Module." << endl; 
                                    cin.get(); 
                                    system("cls"); 
                                }
                                else
                                    cout << "Book not found. Please search again.\n";
                            } while (index == -1);
                        }
                        else
                        {
                            std::cout << "Invalid entry. Please press enter to try again. \n";
                        }
                    } while (choice2 != "1" && choice2 != "2");
                }

                // Add a book
                else if (choice == "2")
                {
                    bool flag2 = true;
                    string choice1; 
                    do
                    {
                        cout << "Please enter the details of the book you want to add\n";
                        cout << "Enter the title: ";
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
                            size++;
                            book[size].setTitle(copyTitle);

                            try
                            {
                                cout << "Enter the ISBN: ";
                                getline(cin, copyISBN);
                                book[size].setISBN(copyISBN);
                                cout << "Enter Author: ";
                                getline(cin, copyAuthor);
                                book[size].setAuthor(copyAuthor);
                                cout << "Enter Publisher: ";
                                getline(cin, copyPublisher);
                                book[size].setPublisher(copyPublisher);
                                cout << "Retail price: ";
                                getline(cin, copyRetail);
                                book[size].setRetail(stod(copyRetail));
                                cout << "whole sale price: ";
                                getline(cin, copyWholesale);
                                book[size].setWholesale(stod(copyWholesale));
                                cout << "Enter quantity to add: ";
                                getline(cin, copyQuantity);
                                book[size].setQuantity(stoi(copyQuantity));

                                // Set date as 3/19/2020
                                book[size].setYear(2020);
                                book[size].setMonth(3);
                                book[size].setDay(19);

                                cout << "Would you like to add another book? Please enter Y or N" << endl;
                                do
                                {
                                    getline(cin, choice1);
                                    if (choice1 != "Y" && choice1 != "y" && choice1 != "N" && choice1 != "n")
                                        cout << "Please enter a valid choice." << endl; 
                                } while (choice1 != "Y" && choice1 != "y" && choice1 != "N" && choice1 != "n"); 

                                if (choice1 == "Y" || choice1 == "y")
                                {
                                    flag2 = true;
                                    system("cls");
                                }
                                else if (choice1 == "N" || choice1 == "n")
                                {
                                    flag2 = false;
                                    cout << "Press enter to return to Inventory Database Module." << endl;
                                    cin.get();
                                    system("cls");
                                }
                            }
                            catch (...)
                            {
                                cout << "An error has occured while entering information. Press enter to return to Inventory Database Module." << endl; 
                                flag2 = false; 
                                cin.get();
                                system("cls"); 
                            }
                        }   
                    } while (flag2 != false);
                } 

                // Edit a book
                else if (choice == "3")
                {
                    string searchValue = ""; 
                    int index = -1; 

                    cout << "Please enter the title of the book you wish to edit: "; 
                    getline(cin, searchValue); 
                    cout << endl; 

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
                            system("cls"); 
                            cout << "Please select entry to be edited: " << endl; 
                            cout << "1:Quantity" << endl << "2:Retail price" << endl << "3:Wholesale Price" << endl; 

                            do
                            {
                                getline(cin, entry);
                                if (entry != "1" && entry != "2" && entry != "3")
                                {
                                    cout << "Please enter a valid option." << endl;
                                    flag1 = true;
                                }
                                else
                                    flag1 = false;
                            } while (flag1);

                            switch (stoi(entry))
                            {
                            case 1:
                                cout << "Enter new quantity: ";
                                getline(cin, res);
                                book[index].setQuantity(stoi(res));
                                cout << "Quantity has been updated!" << endl; 
                                flag3 = false; 
                                cout << "Press enturn to return to Inventory Database Menu. " << endl; 
                                cin.get(); 
                                break;
                            case 2:
                                cout << "Enter new retail price: ";
                                getline(cin, res);
                                book[index].setRetail(stoi(res));
                                cout << "Retail price has been updated!" << endl;
                                flag3 = false; 
                                cout << "Press enturn to return to Inventory Database Menu. " << endl;
                                cin.get();
                                break;
                            case 3:
                                cout << "Enter new wholesale price: ";
                                getline(cin, res);
                                book[index].setWholesale(stoi(res));
                                cout << "Wholesale price has been updated!" << endl;
                                flag3 = false; 
                                cout << "Press enturn to return to Inventory Database Menu. " << endl;
                                cin.get();
                                break;
                            }
                        } while (flag3 == true); 
                    }
                    else
                    {
                        std::cout << "Book not found\n";
                    }
                }

                // Delete a book
                else if (choice == "4")
                {
                    cout << "Enter the title of the book you wish to delete: ";
                    getline(cin, copyTitle); 
                    int result = -1; 
                    for (int i = 0; i < size; i++)
                    {
                        if (book[i].getTitle() == copyTitle)
                            result = i; 
                    }
                    if (result != -1)
                    {
                    	for (int n = result; n < size - 1; n++)
                    	{
                    		book[n] = book[n + 1]; //Moves the entire list up by one.
                    	}
                        size--; 
                        cout << "'" << copyTitle << "' has been succesfully deleted!" << endl; 
                        cout << "Press enter to return to Inventory Database Module." << endl; 
                        cin.get(); 
                    }
                    else
                    {
                    	cout << "Book not found\n";
                        cout << "Press enter to return to Inventory Database Module." << endl;
                        cin.get();
                    }
                }

                else if (choice == "5")
                {
                    cout << "Returning to main menu." << endl; 
                    cout << "Press enter to continue." << endl; 
                    cin.get(); 
                    flag2 = false; 
                }
            } while (flag2 != false); 
        } 

        // Report module
        if (choice == "3")
        {
            bool flag3 = true; 
            bool flag1 = false; 
            do
            {
                system("cls"); 
                string choice3; 
                cout << setw(12) << "" << "Entering Report Module! Please select an option. " << endl; 
                printLine(); 
                cout << "1. Inventory Listing" << endl
                    << "2. Inventory by Wholesale Price" << endl
                    << "3. Inventory by Retail Price" << endl
                    << "4. Listing by Quantity" << endl
                    << "5. Listing by Wholesale" << endl
                    << "6. Listing by Age" << endl
                    << "7. Return to Main Menu" << endl; 

                // Read in an input
                do
                {
                    getline(cin, choice3);
                    if (choice3 != "1" && choice3 != "2" && choice3 != "3" && choice3 != "4" && choice3 != "5" && choice3 != "6" && choice3 != "7")
                    {
                        cout << "Please enter a valid option." << endl;
                        flag1 = true;
                    }
                    else
                        flag1 = false;
                } while (flag1);
                
                switch (stoi(choice3))
                {
                case 1:
                {
                    int total = 0; 
                    cout << "Listing the entire inventory: " << endl; 
                    for (int i = 0; i < size; i++)
                    {
                        cout << "Title: " << setw(75) << left << book[i].getTitle()
                            << setw(15) << right << "Quantity: " << setw(5) << right << book[i].getQuantity() << endl;
                        total += book[i].getQuantity();
                    }
                    cout << setw(82) << left << "TOTAL QUANTITY OF BOOKS: " << setw(20) << right << total << endl;
                    cout << "Press enter to return to the reporting module." << endl; 
                    cin.get(); 
                    break; 
                }
                case 2:
                {
                    double total = 0;
                    cout << "Listing the entire inventory by wholesale price: " << endl;
                    for (int i = 0; i < size; i++)
                    {
                        cout << "Title: " << setw(75) << left << book[i].getTitle()
                            << setw(15) << right << "Wholesale Price: " << setw(8) << right << book[i].getWholesale() << endl;
                        total = total + (book[i].getWholesale() * book[i].getQuantity());
                    }
                    cout << fixed << setprecision(2); 
                    cout << setw(79) << left << "TOTAL WHOLESALE PRICE OF BOOKS: " << setw(20) << right << "$" << total << endl;
                    cout << "Press enter to return to the reporting module." << endl;
                    cin.get();
                    break; 
                }
                case 3:
                {
                    double total = 0;
                    cout << "Listing the entire inventory by retail price: " << endl;
                    for (int i = 0; i < size; i++)
                    {
                        cout << "Title: " << setw(75) << left << book[i].getTitle()
                            << setw(15) << right << "Retail Price: " << setw(8) << right << book[i].getRetail() << endl;
                        total = total + (book[i].getRetail() * book[i].getQuantity());
                    }
                    cout << fixed << setprecision(2);
                    cout << setw(77) << left << "TOTAL RETAIL PRICE OF BOOKS: " << setw(20) << right << "$" << total << endl;
                    cout << "Press enter to return to the reporting module." << endl;
                    cin.get();
                    break;
                }
                case 4:
                {
                    int start;
                    int maxIndex = 0;
                    Cashier maxBook; 
                    for (start = 0; start < (size - 1); start++)
                    {
                        maxIndex = start;
                        maxBook = book[start];
                        for (int index = start + 1; index < size; index++)
                        {
                            if (book[index].getQuantity() > maxBook.getQuantity())
                            {
                                maxBook = book[index];
                                maxIndex = index;
                            }
                        }
                        book[maxIndex] = (book[start]);
                        book[start] = (maxBook);
                    }
                    int total = 0;
                    cout << "Listing the entire inventory by quantity: " << endl;
                    for (int i = 0; i < size; i++)
                    {
                        cout << "Title: " << setw(75) << left << book[i].getTitle()
                            << setw(15) << right << "Quantity: " << setw(5) << right << book[i].getQuantity() << endl;
                        total += book[i].getQuantity();
                    }
                    cout << setw(82) << left << "TOTAL QUANTITY OF BOOKS: " << setw(20) << right << total << endl;
                    cout << "Press enter to return to the reporting module." << endl;
                    cin.get();
                    break;
                }
                case 5:
                {
                    int start;
                    int maxIndex = 0;
                    Cashier maxBook;
                    for (start = 0; start < (size - 1); start++)
                    {
                        maxIndex = start;
                        maxBook = book[start];
                        for (int index = start + 1; index < size; index++)
                        {
                            if (book[index].getWholesale() > maxBook.getWholesale())
                            {
                                maxBook = book[index];
                                maxIndex = index;
                            }
                        }
                        book[maxIndex] = (book[start]);
                        book[start] = (maxBook);
                    }
                    double total = 0;
                    cout << "Listing the entire inventory by wholesale price: " << endl;
                    for (int i = 0; i < size; i++)
                    {
                        cout << "Title: " << setw(75) << left << book[i].getTitle()
                            << setw(15) << right << "Wholesale Price: " << setw(8) << right << book[i].getWholesale() << endl;
                        total = total + (book[i].getWholesale() * book[i].getQuantity());
                    }
                    cout << fixed << setprecision(2);
                    cout << setw(79) << left << "TOTAL WHOLESALE PRICE OF BOOKS: " << setw(20) << right << "$" << total << endl;
                    cout << "Press enter to return to the reporting module." << endl;
                    cin.get();
                    break;
                }
                case 6:
                {
                    int start;
                    int maxIndex = 0;
                    Cashier maxBook;
                    for (start = 0; start < (size - 1); start++)
                    {
                        maxIndex = start;
                        maxBook = book[start];
                        for (int index = start + 1; index < size; index++)
                        {
                            if (book[index].getYear() * 10000 + book[index].getMonth() * 100 + book[index].getDay() <
                                maxBook.getYear() * 10000 + maxBook.getMonth() * 100 + maxBook.getDay())
                            {
                                maxBook = book[index];
                                maxIndex = index;
                            }
                        }
                        book[maxIndex] = (book[start]);
                        book[start] = (maxBook);
                    }
                    double total = 0;
                    cout << "Listing the entire inventory by date: " << endl;
                    for (int i = 0; i < size; i++)
                    {
                        cout << "Title: " << setw(75) << left << book[i].getTitle()
                            << setw(15) << right << "Date: " << setw(8) << right << book[i].getYear() << "/" 
                            << book[i].getMonth() << "/" << book[i].getDay() << endl; 
                    }
                    cout << "Press enter to return to the reporting module." << endl;
                    cin.get();
                    break; 
                }
                case 7:
                    cout << "Returning to main menu" << endl; 
                    flag3 = false; 
                    break; 
                }

            } while (flag3 == true);
        }
        
        // Exit diagram
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

void getChoice(string &choice)
{
    bool flag = true; 
    do
    {
        getline(cin, choice);
        if (choice == "1" || choice == "2" || choice == "3" || choice == "4")
            flag = false;
        else
            cout << "Please enter a valid choice" << endl; 
    } while (flag);
}

void printLine()
{
    cout << "================================================================================" << endl; 
}
