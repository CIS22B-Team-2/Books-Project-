#include "CashierModule.h"

CashierModule::CashierModule(InventoryModule *inv) : Module()
{
	inventory = inv;
}
bool CashierModule::displayBookPricing(int index, double &purchasetotal)
{
	char choice;
	double purchasetotal;
	cout << "The book you chose is: " << "/t" << displayBookPricing << endl;
	cout << "How many copies would you like to purchase?" << endl;
	cin >> bookPurchaseNum;
	purchasetotal = bookPRICE*bookPurchaseNum*tax;
	cout << setprecision (2) << fixed << "Total: " << "/t" << purchasetotal << endl;
	cout << "Press Y to continue transaction, press any other key to cancel." << endl;
	if(choice == 'Y')
		return true;
	else return false;
}//<- FORMATTING
void CashierModule::transaction(double purchasetotal)
{
	double customercash;
	cout << "Please enter the amount of funds you will be paying with: ";
	cin >> customer cash;
	cout << "\nYour change will be " << customercash - purchasetotal << ".\n";
}
void CashierModule::updateInventory()
{} // to do 
void CashierModule::driver()
{
	char choice;
	do
	{
		string entry;
		int index;
		bool compltransact;
		double purchasetotal = 0;
		do{
		cout << "Enter the title of the book you wish to purchase: ";
		getline(cin, entry);
		index = (inventory->searchByTitle(entry));//(in database)
		if (index != -1){
			compltransact = displayBookPricing(index, purchasetotal); //use everywhere! <- complete transaction is used to cout total pricing and give back change.
			if (compltransact){
				transaction(double purchasetotal);
				updateInventory();
			}
		}
		else cout << "Book not found. ";
		}while (index == -1);
		cout << "\n\nDo you wish to checkout another book? y/n: ";
		cin >> choice;
		cin.get();
	} while (choice == 'y');
}
