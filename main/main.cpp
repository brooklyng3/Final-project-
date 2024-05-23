#include "Header.h"

int main()
{
	bool state = true;
	bool state2 = true;
	while (state)
	{
		try
		{
			std::fstream file;
			int usr_choice;

			bool check;
		check_credential:
			system("cls");
			check = false;
			while (!check)
			{
				check = login("credentials.csv");
			}
			int choice = 1;
			Inventory inventory;
			inventory.load_inventory("Inventory.csv");
			while (state2)
			{
				try
				{
					do
					{
						display();
						std::cin >> choice;
						switch (choice)
						{
						case 0:
							exit(0);
							break;

						case 1:
							system("cls");
							inventory.view_all_warehouse();
							std::cout << "\nPress enter to continue...\n";
							_getch();
							break;
						case 2:
							int searchchoice;
							system("cls");
							std::cout << "Select : \n" << "[1] Search item\n" << "[2] Search a warehouse...\n";
							std::cout << "Enter choice : ";
							std::cin >> searchchoice;
							std::cin.ignore();
							if (searchchoice == 1)
							{
								system("cls");
								int choice_it;
								std::cout << "Select: \n" << "[1] Search with ID " << "\n[2] Search with Name" << "\n[3] Search with QUANTITY" << "\n[4] Search with PRICE \n";
								std::cout << "Enter choice : ";
								std::cin >> choice_it;
								if (choice_it == 1)
								{
									system("cls");
									int id;
									std::cout << "Enter id :  ";
									std::cin >> id;
									inventory.find_item_by_id(id);
									std::cout << "\nPress enter to continue...\n";
									_getch();
								}
								else if (choice_it == 2)
								{
									system("cls");
									std::string name;
									std::cout << "Enter name :  ";
									std::cin.ignore();
									getline(std::cin, name);
									inventory.find_item_by_name(name);
									std::cout << "\nPress enter to continue...\n";
									_getch();
								}
								else if (choice_it == 3)
								{
									system("cls");
									int quantity;
									std::cout << "Enter quantity :  ";
									std::cin >> quantity;
									inventory.find_item_by_quantity(quantity);
									std::cout << "\nPress enter to continue...\n";
									_getch();
								}
								else if (choice_it == 4)
								{
									system("cls");
									float price;
									std::cout << "Enter price :  ";
									std::cin >> price;
									inventory.find_item_by_price(price);
									std::cout << "\nPress enter to continue...\n";
									_getch();
								}
								else
								{
									throw std::string("Invalid user input!");
								}

							}
							else if (searchchoice == 2)
							{
								system("cls");
								int choice_wh;
								std::cout << "Select : " << "[1] Search with ID" << "\n[2] Search with NAME" << "\n[3] Search with ADDRESS" << "\n[4] Search with REGION\n";
								std::cout << "Enter choice : ";
								std::cin >> choice_wh;
								if (choice_wh == 1)
								{
									system("cls");
									int id_wh;
									std::cout << "Enter ID :  ";
									std::cin >> id_wh;
									inventory.find_warehouse_by_id(id_wh);
									std::cout << "\nPress enter to continue...\n";
									_getch();

								}
								else if (choice_wh == 2)
								{
									system("cls");
									std::string name_wh;
									std::cout << "Enter name :  ";
									std::cin.ignore();
									getline(std::cin, name_wh);
									inventory.find_warehouse_by_name(name_wh);
									std::cout << "\nPress enter to continue...\n";
									_getch();
								}
								else if (choice_wh == 3)
								{
									system("cls");
									std::string address_wh;
									std::cout << "Enter address :  ";
									std::cin.ignore();
									getline(std::cin, address_wh);
									inventory.find_warehouse_by_address(address_wh);
									std::cout << "\nPress enter to continue...\n";
									_getch();
								}
								else if (choice_wh == 4)
								{
									system("cls");
									std::string region_wh;
									std::cout << "Enter region :  ";
									std::cin.ignore();
									getline(std::cin, region_wh);
									inventory.find_warehouse_by_region(region_wh);
									std::cout << "\nPress enter to continue...\n";
									_getch();
								}
								else
								{
									throw std::string("Invalid user input!");
								}
							}
							else
							{
								throw std::string("Invalid user input!");
							}

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
								if (!inventory.check_and_add_item(usr_id)) std::cout << "\n\nUnable to add item...";
								else std::cout << "\nItem added successfully";
								std::cout << "\nPress anykey to continue...";
								_getch();
							}
							else if (usr_choice == 2)
							{
								int id;
								std::string name, address, region;
								std::cin.ignore();
								std::cout << "Enter name: ";
								std::getline(std::cin, name);

								std::cout << "\nEnter address: "; std::getline(std::cin, address);
								std::cout << "\nEnter region: "; std::getline(std::cin, region);
								std::cout << "\nEnter id: "; std::cin >> id;
								if (!inventory.check_warehouse(id))
								{
									throw std::string("Warehouse already exists!");
								}
								Warehouse w(name, address, region, id);
								inventory.add_warehouse(w);
								file.open(name + ".csv", std::ios::in | std::ios::out | std::ios::app);
								file.close();
							}
							else
							{
								throw std::string("Invalid user input!");
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
								if (!inventory.check_and_delete_item(usr_id)) throw std::string("Warehouse not found!");
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
								throw std::string("Invalid user choice!");
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
									throw std::string("Warehouse not found");
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
								throw std::string("Invalid user choice!");
							}
							inventory.save_inventory("Inventory.csv");
							break;
						case 6:
							system("cls");
							std::cout << "Press [1] to sort items, press [2] to sort warehouses...\n";
							std::cin >> usr_choice;
							if (usr_choice == 1)
							{
								std::cout << "Enter id of the warehouse that you want to sort items in... ";
								int wid;
								std::cin >> wid;
								if (inventory.check_warehouse(wid))
								{
									throw std::string("Warehouse not found!");
								}
								else
								{
									std::cout << "Sort items by [1]: id"
										<< "\n              [2]: name"
										<< "\n             [3]: quantity"
										<< "\n              [4]: price\n";
									std::cout << "Your choice: \n";
									int it_prop, order;
									std::cin >> it_prop;
									std::cout << "Order? Press [1] for ascending or [2] for descending...\n";
									std::cin >> order;
									if (order == 1)
									{
										if (it_prop == 1) inventory.sort_item_by_id_a(wid);
										else if (it_prop == 2) inventory.sort_item_by_name_a(wid);
										else if (it_prop == 3) inventory.sort_item_by_quantity_a(wid);
										else if (it_prop == 4) inventory.sort_item_by_price_a(wid);
										else
										{
											throw std::string("Invalid user choice!");
										}
									}
									else if (order == 2)
									{
										if (it_prop == 1) inventory.sort_item_by_id_d(wid);
										else if (it_prop == 2) inventory.sort_item_by_name_d(wid);
										else if (it_prop == 3) inventory.sort_item_by_quantity_d(wid);
										else if (it_prop == 4) inventory.sort_item_by_price_d(wid);
										else
										{
											 throw std::string("Invalid user choice!");
										}
									}
									else
									{
										throw std::string("Invalid user choice!");
									}
								}
							}
							else if (usr_choice == 2)
							{
								std::cout << "Sort warehouse by [1]: id"
									<< "\n              [2]: name"
									<< "\n             [3]: address"
									<< "\n              [4]: region\n";
								std::cout << "Your choice: \n";
								int it_prop, order;
								std::cin >> it_prop;
								std::cout << "Order? Press [1] for ascending or [2] for descending...\n";
								std::cin >> order;
								if (order == 1)
								{
									if (it_prop == 1) inventory.sort_warehouse_by_id_a();
									else if (it_prop == 2) inventory.sort_warehouse_by_name_a();
									else if (it_prop == 3) inventory.sort_warehouse_by_address_a();
									else if (it_prop == 4) inventory.sort_warehouse_by_region_a();
									else
									{
										throw std::string("Invalid user choice!");
									}
								}
								else if (order == 2)
								{
									if (it_prop == 1) inventory.sort_warehouse_by_id_d();
									else if (it_prop == 2) inventory.sort_warehouse_by_name_d();
									else if (it_prop == 3) inventory.sort_warehouse_by_address_d();
									else if (it_prop == 4) inventory.sort_warehouse_by_region_d();
									else
									{
										throw std::string("Invalid user choice!");
									}
								}
								else
								{
									throw std::string("Invalid user choice!");
								}
							}
							else
							{
								throw std::string("Invalid user choice!");
							}
							break;
						case 7:
							system("cls");
							change_pwd("credentials.csv");
							break;
						case 8:
							system("cls");
							create_new_account("credentials.csv");
							break;
						case 9:
							system("cls");
							if (!delete_account("credentials.csv")) goto check_credential;
							break;
						case 10:
							std::cout << "You are about to log out... Press anykey to continue...";
							_getch();
							goto check_credential;
							break;
						default:
							throw std::string("Invalid user choice!");
							break;
						}
					} while (choice != 0);
				}
				catch (std::string message)
				{
					if (message != "Credentials file not found!")
					{
						MessageBoxA(NULL, message.c_str(), "Error", MB_ICONERROR);
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					else
					{
						state = false;
						state2 = false;
						MessageBoxA(NULL, message.c_str(), "Error", MB_ICONERROR);
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					
				}
			}
		}
		catch (std::string message)
		{
			if ((message == "Credentials file not found!") || (message == "Could not load inventory! Inventory file not found.")) state = false;
			MessageBoxA(NULL, message.c_str(), "Error", MB_ICONERROR);
		}
	}
}

