#include "database.h"
#include "cashierModule.h"
#include "reportingModule.h"
#include "Module.h"
#include "books.h"
#include "date.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

/*
Main To- Do:
1)Calls inventory, reporting, or cashier, depending on what the user wants
*/

int main()
{
	cout << "Welcome to the Serendipity Bookstore online user interface!";
	InventoryModule inventory;
	CashierModule cashier(&inventory);
	ReportingModule reporter(&inventory);

	Module *invenptr = &inventory;
	Module *cashptr = &cashier;
	Module *repointer = &reporter;


	int entry;
	do
	{
		cin.clear();
		cout << "\n\nPlease select a module:\n\n1)Cashier Module\n2)Inventory/Database Module\n3)Reporting Module\n4)Exit\nEnter"
			<< " your choice: 1/2/3/4	";
		cin >> entry; //entry can only hold integers. Inputting a non integer will crash the program. EXCEPTION HANDLING!!
		cin.get();
		if (entry != 4)
		{
			switch (entry)
			{
			case 1: cashptr->driver();
				break;
			case 2: invenptr->driver();
				break;
			case 3: repointer->driver();
				break;
			default: cout << "Invalid menu choice. Please try again: ";
			}
		}
	} while (entry != 4);

	cout << "\n\n\n\t\tThank you for using our system! Good-bye!";

	cin.get();
	cin.get();
	system("pause");
	return 0;
}