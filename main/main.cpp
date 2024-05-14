#include "Header.h"

int main()
{
	std::fstream file;
	int usr_choice;
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
			system("cls");
			inventory.view_all_warehouse();
			std::cout << "\nPress enter to continue...\n";
			_getch();
			break;
		case 2:
			break;
		case 3:
			system("cls");
			std::cout << "Press [1] to add an item, press [2] to add a warehouse...\n";
			std::cin >> usr_choice;
			if (usr_choice == 1)
			{
				int usr_id;
				std::cout << "\nEnter the id of the warehouse: ";
				std::cin >> usr_id;
				std::cin.ignore();
				if (!inventory.check_and_add_item(usr_id)) std::cout << "a"; //throw error warehouse not found
				else std::cout << "\nItem added successfully";
			}
			else if (usr_choice == 2)
			{
				int id;
				std::string name,address,region;
				std::cin.ignore();
				std::cout << "Enter name: "; 
				std::getline(std::cin, name);
				
				std::cout << "\nEnter address: "; std::getline(std::cin, address);
				std::cout << "\nEnter region: "; std::getline(std::cin, region);
				std::cout << "\nEnter id: "; std::cin >> id; 
				if (!inventory.check_warehouse(id)) 
				{
					//throw error
					std::cout << "a";
					_getch();
					break;
				}
				Warehouse w(name, address, region, id);
				inventory.add_warehouse(w);
				file.open(name + ".csv", std::ios::in | std::ios::out | std::ios::app);
				file.close();
			}
			else
			{
				//throw exception invalid argument;
				std::cout << "a";
				fflush(stdin);
				_getch();
			}
			inventory.save_inventory("Inventory.csv");
			break;
		case 4:
			system("cls");
			std::cout << "Press [1] to delete an item, press [2] to delete a warehouse...\n";
			std::cin >> usr_choice;
			if (usr_choice == 1)
			{
				int usr_id;
				std::cout << "\nEnter the id of the warehouse: ";
				std::cin >> usr_id;
				std::cin.ignore();
				if (!inventory.check_and_delete_item(usr_id)) std::cout << "a"; //throw error warehouse not found
				else std::cout << "\nItem deleted successfully";
			}
			else if (usr_choice == 2)
			{
				int id;
				std::cout << "\nEnter the id of the warehouse you want to delete: ";
				std::cin >> id;
				inventory.remove_warehouse(id);

			}
			else
			{
				//throw exception invalid argument;
				std::cout << "a";
				fflush(stdin);
				_getch();
			}
			inventory.save_inventory("Inventory.csv");
			break;
		case 5:
			system("cls");
			std::cout << "Press [1] to update an item, press [2] to update a warehouse...\n";
			std::cin >> usr_choice;
			if (usr_choice == 1)
			{
				int usr_id;
				std::cout << "\nEnter the id of the warehouse: ";
				std::cin >> usr_id;
				std::cin.ignore();
				if (!inventory.check_and_update_item(usr_id))
				{
					//throw error
					std::cout << "a";
					fflush(stdin);
					_getch();
				}
			}
			else if (usr_choice == 2)
			{
				std::cin.ignore();
				int id;
				std::string wname, waddress, wregion;
				std::cout << "\nEnter the id of the warehouse you want to update: ";
				std::cin >> id; std::cin.ignore();
				std::cout << "Warehouse new address: ";
				std::getline(std::cin, waddress);
				std::cout << "Warehouse new region: ";
				std::getline(std::cin, wregion);
				inventory.update_warehouse(id, wname, waddress, wregion);
			}
			else
			{
				//throw exception invalid argument;
				std::cout << "a";
				fflush(stdin);
				_getch();
			}
			inventory.save_inventory("Inventory.csv");
			break;

		default:
			break;
		}
	} while (choice !=0);
}

