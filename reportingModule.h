#include "database.h"
#include "module.h"

using namespace std;

class ReportingModule : public Module
{
protected:
	InventoryModule *inventory;
public:
	ReportingModule(InventoryModule *inv);
	void driver();
	int displayRepenu();
};
