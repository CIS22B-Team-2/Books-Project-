#include "reportingModule.h"
ReportingModule::ReportingModule(InventoryModule *inv) : Module()
{
	inventory = inv;
}
void ReportingModule::driver()
{
	int choice;
	do
	{
		choice = displayRepenu();
		switch (choice)
		{
		case 1:{
				   inventory->sortBytitle();
				   inventory->displayBooks();
		}
			break;
		case 2:{
				   inventory->sortByquantity();
				   inventory->displayBooks();
		}
			break;
		case 3:{
				   inventory->sortByRetailPrice();
				   inventory->displayBooks();
		}
			break;
		case 4:{
				   cout << "This option is currently unavailable because sortByAge has not yet been completed.\n\n";
				   //inventory->sortByAge();
				   //inventory->displayBooks();
		}
			break;
		case 5:
			cout << "This option is currently unavailable because totalInventoryWholesale is incomplete.\n\n";
			break;
		case 6:
			cout << "This option is currently unavailable because totalInventoryRetail is incomplete.\n\n";
			break;
		default:
			cout << "Invalid choice. Please try again:";
		}

	} while (choice != 7);
}
int ReportingModule::displayRepenu()
{
	int entry;
	cout << "\n\n\n\nReporting Module Menu:\n";
	cout << "1) Listing By Title\n";
	cout << "2) Listing By Quantity\n";
	cout << "3) Listing By Cost\n";
	cout << "4) Listing By Age\n";
	cout << "5) Total Inventory Wholesale Value\n";
	cout << "6) Total Inventory Retail Value\n";
	cout << "7) Return to Main Menu\n\n";
	cout << "Enter your choice: ";
	cin >> entry;
	return entry;
}	ReportingModule::ReportingModule(InventoryModule *inv) : Module()
{
	inventory = inv;
}
void ReportingModule::driver()
{
	int choice;
	do
	{
		choice = displayRepenu();
		switch (choice)
		{
		case 1:{
				   inventory->sortBytitle();
				   inventory->displayBooks();
		}
			break;
		case 2:{
				   inventory->sortByquantity();
				   inventory->displayBooks();
		}
			break;
		case 3:{
				   inventory->sortByRetailPrice();
				   inventory->displayBooks();
		}
			break;
		case 4:{
				   cout << "This option is currently unavailable because sortByAge has not yet been completed.\n\n";
				   //inventory->sortByAge();
				   //inventory->displayBooks();
		}
			break;
		case 5:
			cout << "This option is currently unavailable because totalInventoryWholesale is incomplete.\n\n";
			break;
		case 6:
			cout << "This option is currently unavailable because totalInventoryRetail is incomplete.\n\n";
			break;
		default:
			cout << "Invalid choice. Please try again:";
		}

	} while (choice != 7);
}
int ReportingModule::displayRepenu()
{
	int entry;
	cout << "\n\n\n\nReporting Module Menu:\n";
	cout << "1) Listing By Title\n";
	cout << "2) Listing By Quantity\n";
	cout << "3) Listing By Cost\n";
	cout << "4) Listing By Age\n";
	cout << "5) Total Inventory Wholesale Value\n";
	cout << "6) Total Inventory Retail Value\n";
	cout << "7) Return to Main Menu\n\n";
	cout << "Enter your choice: ";
	cin >> entry;
	return entry;
}
