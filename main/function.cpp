#include "Header.h"

Item::Item()
{
	name = "Some Item";
	price = 0.0;
	quantity = 0;
	id = 0;
}

Item::~Item() {}

Item::Item(std::string _name, int _quantity, double _price, int _id) :name(_name), quantity(_quantity), price(_price),id(_id) {}

void Item::set_name(std::string _name)
{
	name = _name;
}

void Item::set_quantity(int _quantity)
{
	quantity = _quantity;
}

void Item::set_price(double _price)
{
	price = _price;
}

std::string Item::get_name() { return name; }
double Item::get_price() const { return price; }
int Item::get_quantity() const { return quantity; }
int Item::get_id() const { return id; }


Warehouse::Warehouse()
{
	name = "Some warehouse";
	address = "Somewhere";
	region = "Some region";
	id = 0;
}
Warehouse::~Warehouse() {}
Warehouse::Warehouse(std::string _name, std::string _address, std::string _region,int _id) :name(_name), address(_address), region(_region),id(_id) {}
void Warehouse::add_item(Item item)
{
	bool check = false;
	for (auto& i : Warehouse::Items)
	{
		if (i.get_id() == item.get_id())
		{
			throw std::invalid_argument("Item already exists!\n");
			check = true;
			break;
		}
	}
	if (!check)
	{
		Items.push_back(item);
		std::cout << "Item added successfully\n";
	}
}

void Warehouse::remove_item(int _id)
{
	bool check = false;
	for (auto i = Items.begin(); i != Items.end(); i++)
	{
		if (i->get_id() == _id)
		{
			Items.erase(i);
			check = true;
			std::cout << "Item removed successfully\n";
			break;
		}
	}
	if (!check) throw std::invalid_argument("Item not found!");
}

void Warehouse::update_item(std::string _name, int _quantity, double _price, int _id)
{
	bool check = false;
	for (auto i = Items.begin(); i != Items.end(); i++)
	{
		if (i->get_id() == _id)
		{
			check = true;
			i->set_name(_name);
			i->set_quantity(_quantity);
			i->set_price(_price);
			std::cout << "Item updated successfully!\n";
			break;
		}
	}
	if (!check) throw std::invalid_argument("Item not found!");
}

int Warehouse::get_id() const { return id; }
void Warehouse::set_name(std::string _name)
{
	name = _name;
}
void Warehouse::set_address(std::string _address)
{
	address = _address;
}
void Warehouse::set_region(std::string _region)
{
	region = _region;
}
std::string Warehouse::get_name() { return name; }
std::string Warehouse::get_address() { return address; }
std::string Warehouse::get_region() { return region; }

void Warehouse::find_item(int _id)
{
	bool check = false;
	for (auto i = Warehouse::Items.begin(); i != Warehouse::Items.end(); i++)
	{
		if (i->get_id() == _id)
		{
			check = true;
			std::cout << "\nMane: " << i->get_name();
			std::cout << "\nQuantity: " << i->get_quantity();
			std::cout << "\nPrice: " << i->get_price();
		}
	}
	if (!check) throw std::invalid_argument("Item not found!");
}

void Warehouse::view_all_item()
{
	for (auto i = Items.begin(); i != Items.end(); i++)
	{
		std::cout << "\nID: " << i->get_id();
		std::cout << "\nMane: " << i->get_name();
		std::cout << "\nQuantity: " << i->get_quantity();
		std::cout << "\nPrice: " << i->get_price();
	}
}



Inventory::Inventory() {};
Inventory::~Inventory() {};

void Inventory::add_warehouse(Warehouse warehouse)
{
	bool check = false;
	for (auto& i : Inventory::Warehouses)
	{
		if (i.get_id() == warehouse.get_id())
		{
			throw std::invalid_argument("Warehouse already exists!\n");
			check = true;
			break;
		}
	}
	if (!check)
	{
		Warehouses.push_back(warehouse);
		std::cout << "Warehouse added successfully\n";
	}
}

void Inventory::remove_warehouse(int _id)
{
	bool check = false;
	for (auto i = Warehouses.begin(); i != Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			Warehouses.erase(i);
			check = true;
			std::cout << "Warehouse removed successfully\n";
			break;
		}
	}
	if (!check) throw std::invalid_argument("Warehouse not found!");
}

void Inventory::update_warehouse(int _id, std::string _name, std::string _address, std::string _region)
{
	bool check = false;
	for (auto i = Warehouses.begin(); i != Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			check = true;
			i->set_name(_name);
			i->set_address(_address);
			i->set_region(_region);
			std::cout << "Warehouse updated successfully\n";
			break;
		}
	}	
	if (!check) throw std::invalid_argument("Warehouse not found!");
}

void Inventory::find_warehouse_location(int _id)
{
	bool check = false;
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			check = true;
			std::cout << "\nMane: " << i->get_name();
			std::cout << "\nAddress: " << i->get_address();
			std::cout << "\nRegion: " << i->get_region();
		}
	}
	if (!check) throw std::invalid_argument("Warehouse not found!");
}


void display()
{
	std::cout << "1.View all" << std::endl;
	std::cout << "2.Search\n";
	std::cout << "3.Add\n";
	std::cout << "4.Delete\n";
	std::cout << "5.Update\n";
	std::cout << "0.Exit\n";
	std::cout << "\nYour choice: ";
}

bool login(std::string filename)
{
	std::fstream file;
	std::string usr_username, usr_password;
	std::cout << "\t\t\t-----------------Warehouse management system-------------------";
	std::cout << "\n\nPlease enter your credentials: ";
	std::cout << "\n\nUsername: ";
	std::cin >> usr_username;
	std::cout << "\nPassword: ";
	std::cin >> usr_password;
	file.open(filename);
	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			std::stringstream ss(line);
			std::string username, password;
			std::getline(ss, username, ',');
			std::getline(ss, password, ',');
			if ((username == usr_username) && (password == usr_password)) return true;
		}
		std::cerr << "Username or password incorrect!\n\n";
		_getch();
		system("cls");
		return false;
	}
	else throw std::invalid_argument("file not found!");
}

void Inventory::load_inventory(std::string filename)
{
	std::fstream file;
	file.open(filename,std::ios::in|std::ios::out);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file,line))
		{
			std::stringstream ss(line);
			std::string idstr, address, name, region;
			std::getline(ss, name, ',');
			std::getline(ss, address, ',');
			std::getline(ss, region, ',');
			std::getline(ss, idstr, ',');
			int id = std::stoi(idstr);
			Warehouse w(name, address, region, id);
			Inventory::Warehouses.push_back(w);
		}
		file.close();
	}
	else  throw std::invalid_argument("file not found!");
	for(auto w = Inventory::Warehouses.begin();w!=Inventory::Warehouses.end();w++)
	{
		w->load_warehouse(w->get_name()+".csv");
	}
}

void Inventory::view_all_warehouse()
{
	for (auto i = Warehouses.begin(); i != Warehouses.end(); i++)
	{
		std::cout << "\nID: " << i->get_id();
		std::cout << "\nMane: " << i->get_name();
		std::cout << "\Address: " << i->get_address();
		std::cout << "\Region: " << i->get_region();
	}
}
void Warehouse::load_warehouse(std::string filename)
{
	std::fstream file;
	file.open(filename, std::ios::in | std::ios::out);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			std::string idstr, name, quantitystr, pricestr;
			std::getline(ss, name, ',');
			std::getline(ss, quantitystr, ',');
			std::getline(ss, pricestr, ',');
			std::getline(ss, idstr, ',');

			int id = std::stoi(idstr);
			int quantity = std::stoi(quantitystr);
			double price = std::stod(pricestr);
			Item i(name, quantity, price, id);
			Warehouse::Items.push_back(i);
		}
		file.close();
	}
	else throw std::invalid_argument("file not found!");
}
