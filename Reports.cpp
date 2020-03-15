#include "reports.h"
#include <iostream>
#include <iomanip>
#include "bookdata.h"

void reports()
{
	int choice = 0;

	while (choice != 7)
	{

		std::cout << "Serendipity Booksellers\n";
		std::cout << "\tReports\n\n";

		std::cout << "1. Inventory Listing\n";
		std::cout << "2. Inventory Wholesale Value\n";
		std::cout << "3. Inventory Retail Value\n";
		std::cout << "4. Listing by Quantity\n";
		std::cout << "5. Listing by Cost\n";
		std::cout << "6. Listing by Age\n";
		std::cout << "7. Return to the Main Menu\n\n";

		std::cout << "Enter Your Choice: ";
		std::cin >> choice;

		//validate input
		while (choice < 1 || choice > 7)
		{
			std::cout << "\nPlease enter a number in the range 1 - 7\n";
			std::cout << "Enter your choice: ";
			std::cin >> choice;
		}
			switch (choice)
			{
			case 1:
				repListing();
				break;
			case 2:
				repWholesale();
				break;
			case 3:
				repRetail();
				break;
			case 4:
				repQty();
				break;
			case 5:
				repCost();
				break;
			case 6:
				repAge();
				break;
			case 7:
				std::cout << "\nYou selected item 7";
				break;
			}

			std::cout << std::endl;

	}//end while choice !=7
}