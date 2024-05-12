#include "Header.h"

int main()
{
	bool check = false;
	while (!check)
	{
		check = login("credentials.csv");
	}
	int choice=1;
	Inventory inventory;
	inventory.load_inventory("Inventory.csv");
	
	do
	{
		display();
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			break;
			
		case 1:

		default:
			break;
		}
	} while (choice !=0);
}

