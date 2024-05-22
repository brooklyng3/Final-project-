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

std::string Item::get_name() const { return name; }
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
			_getch();
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
std::string Warehouse::get_name() const { return name; }
std::string Warehouse::get_address() const { return address; }
std::string Warehouse::get_region() const { return region; }

void Warehouse::find_item(int id) {
	bool check = false;
	for (auto i = Warehouse::Items.begin(); i != Warehouse::Items.end(); i++) {
		if (i->get_id() == id) {
			check = true;
			std::cout << "\nId :" << i->get_id();
			std::cout << "\nName: " << i->get_name();
			std::cout << "\nQuantity: " << i->get_quantity();
			std::cout << "\nPrice: " << i->get_price() << std::endl;
			return;
		}
	}
	if (!check)
	{
		std::cout << "Item not found!" << std::endl;
	}
}

void Warehouse::view_all_item()
{
	for (auto i = Items.begin(); i != Items.end(); i++)
	{
		std::cout << "\nID: " << i->get_id();
		std::cout << "\nName: " << i->get_name();
		std::cout << "\nQuantity: " << i->get_quantity();
		std::cout << "\nPrice: " << i->get_price() << std::endl << std::endl;
	}
}

void Warehouse::save_warehouse(std::string filename)
{
	std::fstream file1;
	file1.open(filename, std::ios::trunc | std::ios::out);
	for (int i = 0; i < Items.size(); i++)
	{
		Item it = Items[i];
		file1 << it.get_name() << "," << it.get_quantity() << "," << it.get_price() << "," << it.get_id() << std::endl;
	}
	file1.close();
}

bool Warehouse::check_id(int _id)
{
	bool check = true;
	for (auto& i : Warehouse::Items)
	{
		if (i.get_id() == _id)
		{
			check = false;
			return check;
		}
	}
	return check;
}

void Warehouse::sort_id_a()
{
	std::sort(Items.begin(), Items.end(), [](const Item& a, const Item& b) { return (a.get_id() < b.get_id()); });
}

void Warehouse::sort_id_d()
{
	std::sort(Items.begin(), Items.end(), [](const Item& a, const Item& b) { return (a.get_id() > b.get_id()); });
}


void Warehouse::sort_name_a()
{
	std::sort(Items.begin(), Items.end(), [](const Item& a, const  Item& b) {
		return a.get_name() < b.get_name();
		});
}

void Warehouse::sort_name_d()
{
	std::sort(Items.begin(), Items.end(), [](const Item& a, const  Item& b) {
		return a.get_name() > b.get_name();
		});
}

void Warehouse::sort_quantity_a()
{
	std::sort(Items.begin(), Items.end(), [](const Item& a, const Item& b) { return (a.get_quantity() < b.get_quantity()); });
}

void Warehouse::sort_quantity_d()
{
	std::sort(Items.begin(), Items.end(), [](const Item& a, const Item& b) { return (a.get_quantity() > b.get_quantity()); });
}

void Warehouse::sort_price_a()
{
	std::sort(Items.begin(), Items.end(), [](const Item& a, const Item& b) {return (a.get_price() < b.get_price()); });
}

void Warehouse::sort_price_d()
{
	std::sort(Items.begin(), Items.end(), [](const Item& a, const Item& b) {return (a.get_price() > b.get_price()); });
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
			std::string name = i->get_name() + ".csv";
			Warehouses.erase(i);
			check = true;
			std::cout << "Warehouse removed successfully\n";
			_getch();
			remove(name.c_str());
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

bool Inventory::check_and_add_item(int _id)
{
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			int id, quantity;
			double price;
			std::string name;
			std::cout << "Enter name: ";
			std::getline(std::cin,name);
			std::cout << "\nEnter quantity: "; std::cin >> quantity;
			std::cout << "\nEnter price: "; std::cin >> price;
			std::cout << "\nEnter id: "; std::cin >> id;
			if (i->check_id(id) == false)
			{
				//throw error unique id found
				return false;
			}
			Item item(name, quantity, price, id);
			i->add_item(item);
			return true;
		}
	}
	std::cout << "a";
	_getch();
	return false;
}

bool Inventory::check_warehouse(int _id)
{
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			return false;
		}

	}
	return true;
}

bool Inventory::check_and_delete_item(int _id)
{
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			int usr_id;
			std::cout << "Enter id of the item you want to remove...";
			std::cin >> usr_id;
			i->remove_item(usr_id);
			return true;
		}
	}
	return false;
}

bool Inventory::check_and_update_item(int _id)
{
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			int itid,itquantity;
			std::string itname;
			double itprice;
			std::cout << "Enter id of the item you want to update...";
			std::cin >> itid; std::cin.ignore();
			std::cout << "Item new name: ";
			std::getline(std::cin, itname);
			std::cout << "\nItem new quantity: ";
			std::cin >> itquantity; std::cin.ignore();
			std::cout << "\nItem new price: ";
			std::cin >> itprice;
			i->update_item(itname, itquantity, itprice, itid);
			return true;
		}
	}
	return false;
}


void display()
{
	system("cls");
	std::cout << "1.View all" << std::endl;
	std::cout << "2.Search\n";
	std::cout << "3.Add\n";
	std::cout << "4.Delete\n";
	std::cout << "5.Update\n";
	std::cout << "6.Sort\n";
	std::cout << "7.Change password\n";
	std::cout << "8.Create new account\n";
	std::cout << "9.Delete account\n";
	std::cout << "10.Log out\n";
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
			if ((username == usr_username) && (password == usr_password))
			{
				file.close();
				return true;
			}
		}
		std::cerr << "Username or password incorrect!\n\n";
		_getch();
		system("cls");
		file.close();
		return false;
	}
	else throw std::string("Credential file not found!");
}

void change_pwd(std::string filename)
{
	std::fstream file,file2;
	std::string usr_username, usr_password;
	std::cout << "\n\nPlease reenter your credentials: ";
	std::cout << "\n\nUsername: ";
	std::cin >> usr_username;
	std::cout << "\nPassword: ";
	std::cin >> usr_password;
	file.open(filename);
	if (file.is_open())
	{
		bool check = false;
		std::string line;
		while (getline(file, line))
		{
			std::stringstream ss(line);
			std::string username, password;
			std::getline(ss, username, ',');
			std::getline(ss, password, ',');
			if ((username == usr_username) && (password == usr_password))
			{
				check = true;
				file.close();
				break;
			}
		}
		if (!check)
		{
			std::cerr << "Username or password incorrect!\n\n";
			std::cout << "Returning to main menu...";
			_getch();
			system("cls");
			file.close();
			return;
		}
	}
	else
	{
		throw std::invalid_argument("file not found!");
		//them loi o day
	}
	file.open(filename);
	if (file.is_open())
	{
		bool check;
		file2.open("tmp.csv", std::ios::app|std::ios::out);
		std::string line,new_pwd;
		while (getline(file, line))
		{
			check = false;
			std::stringstream ss(line);
			std::string username, password;
			std::getline(ss, username, ',');
			std::getline(ss, password, ',');
			if ((username == usr_username))
			{
				std::cout << "New password must not contain [ ] space\n";
				std::cout << "New password: ";
				std::cin >> new_pwd;
				check = true;
			}
			if (check) file2 << username << "," << new_pwd << std::endl;
			else file2 << username << "," << password << std::endl;
		}
	}
	file.close();
	file2.close();
	std::remove("credentials.csv");
	std::rename("tmp.csv", "credentials.csv");
}

void create_new_account(std::string filename)
{
	std::fstream file;
	std::string username, password;
	std::cout << "New account's username: ";
	std::cin >> username;
	file.open(filename);
	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			std::stringstream ss(line);
			std::string usr_name, pwd;
			std::getline(ss, usr_name, ',');
			std::getline(ss, pwd, ',');
			if (username == usr_name)
			{
				std::cout << "Acount already exists!";
				std::cout << "\nPress anykey to return to main menu...";
				_getch();
				file.close();
				return;
			}
		}
		file.close();
	}
	else
	{
		//viet ma loi o day
	}
	file.open(filename, std::ios::app | std::ios::out);
	std::cout << "Password: ";
	std::cin >> password;
	file << username << "," << password << std::endl;
	file.close();
}

bool delete_account(std::string filename)
{
	std::fstream file,file2;
	int count = 0;
	std::string usr_username, usr_password;
	std::cout << "\n\nPlease reenter your credentials: ";
	std::cout << "\n\nUsername: ";
	std::cin >> usr_username;
	std::cout << "\nPassword: ";
	std::cin >> usr_password;
	file.open(filename);
	if (file.is_open())
	{
		bool check = false;
		std::string line;
		while (getline(file, line))
		{
			std::stringstream ss(line);
			std::string username, password;
			std::getline(ss, username, ',');
			std::getline(ss, password, ',');
			if ((username == usr_username) && (password == usr_password))
			{
				check = true;
				file.close();
			}
			count++;
		}
		if (!check)
		{
			std::cerr << "Username or password incorrect!\n\n";
			std::cout << "Returning to main menu...";
			_getch();
			system("cls");
			file.close();
			return true;
		}
	}
	else
	{
		throw std::invalid_argument("file not found!");
		//them loi o day
	}
	if (count < 2)
	{
		std::cout << "Cannot delete this account because there's no other account to login!";
		_getch();
		return true;
	}
	else
	{
		file.open(filename);
		if (file.is_open())
		{
			file2.open("tmp.csv", std::ios::app | std::ios::out);
			std::string line, new_pwd;
			while (getline(file, line))
			{
				std::stringstream ss(line);
				std::string username, password;
				std::getline(ss, username, ',');
				std::getline(ss, password, ',');
				if ((username != usr_username)) file2 << username << "," << password << std::endl;
			}
		}
		file.close();
		file2.close();
		std::cout << "Account deleted successfully... Press anykey to continue.";
		_getch();
		std::remove("credentials.csv");
		std::rename("tmp.csv", "credentials.csv");
		return false;
	}
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
	else  throw std::string("Could not load inventory! Inventory file not found.");
	for(auto w = Inventory::Warehouses.begin();w!=Inventory::Warehouses.end();w++)
	{
		w->load_warehouse(w->get_name()+".csv");
	}
}

void Inventory::view_all_warehouse()
{
	for (auto i = Warehouses.begin(); i != Warehouses.end(); i++)
	{
		std::cout << "\nWarehouse " << i->get_id();
		std::cout << ":\nName: " << i->get_name();
		std::cout << "\nAddress: " << i->get_address();
		std::cout << "\nRegion: " << i->get_region() << std::endl << std::endl;
		std::cout << "Items: \n";
		i->view_all_item();
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

void Inventory::save_inventory(std::string filename)
{
	std::fstream file;
	file.open(filename, std::ios::trunc|std::ios::in|std::ios::out);
	for (int i = 0; i < Warehouses.size(); i++)
	{
		Warehouse w = Warehouses[i];
		file << w.get_name() << "," << w.get_address() << "," << w.get_region() << "," << w.get_id() << std::endl;
		
	}
	
	for (auto w = Warehouses.begin(); w != Warehouses.end(); w++)
	{
		w->save_warehouse(w->get_name() + ".csv");
	}
	file.close();
}

void Inventory::sort_item_by_id_a(int _id)
{
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			i->sort_id_a();
			break;
		}
	}
}

void Inventory::sort_item_by_id_d(int _id)
{
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			i->sort_id_d();
			break;
		}
	}
}

void Inventory::sort_item_by_name_a(int _id)
{
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			i->sort_name_a();
			break;
		}
	}
}

void Inventory::sort_item_by_name_d(int _id)
{
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			i->sort_name_d();
			break;
		}
	}
}

void Inventory::sort_item_by_quantity_a(int _id)
{
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			i->sort_quantity_a();
			break;
		}
	}
}

void Inventory::sort_item_by_quantity_d(int _id)
{
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			i->sort_quantity_d();
			break;
		}
	}
}

void Inventory::sort_item_by_price_a(int _id)
{
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			i->sort_price_a();
			break;
		}
	}
}

void Inventory::sort_item_by_price_d(int _id)
{
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		if (i->get_id() == _id)
		{
			i->sort_price_d();
			break;
		}
	}
}

void Inventory::sort_warehouse_by_id_a()
{
	std::sort(Warehouses.begin(), Warehouses.end(), [](const Warehouse& a, const Warehouse& b) { return (a.get_id() < b.get_id()); });
}

void Inventory::sort_warehouse_by_id_d()
{
	std::sort(Warehouses.begin(), Warehouses.end(), [](const Warehouse& a, const Warehouse& b) { return (a.get_id() > b.get_id()); });
}

void Inventory::sort_warehouse_by_name_a()
{
	std::sort(Warehouses.begin(), Warehouses.end(), [](const Warehouse& a, const Warehouse& b) { return (a.get_name() < b.get_name()); });
}

void Inventory::sort_warehouse_by_name_d()
{
	std::sort(Warehouses.begin(), Warehouses.end(), [](const Warehouse& a, const Warehouse& b) { return (a.get_name() > b.get_name()); });
}

void Inventory::sort_warehouse_by_address_a()
{
	std::sort(Warehouses.begin(), Warehouses.end(), [](const Warehouse& a, const Warehouse& b) { return (a.get_address() < b.get_address()); });
}

void Inventory::sort_warehouse_by_address_d()
{
	std::sort(Warehouses.begin(), Warehouses.end(), [](const Warehouse& a, const Warehouse& b) { return (a.get_address() > b.get_address()); });
}

void Inventory::sort_warehouse_by_region_a()
{
	std::sort(Warehouses.begin(), Warehouses.end(), [](const Warehouse& a, const Warehouse& b) { return (a.get_region() < b.get_region()); });
}

void Inventory::sort_warehouse_by_region_d()
{
	std::sort(Warehouses.begin(), Warehouses.end(), [](const Warehouse& a, const Warehouse& b) { return (a.get_region() > b.get_region()); });
}


void Warehouse::find_item_name(std::string n) {
	bool check = false;
	for (auto i = Warehouse::Items.begin(); i != Warehouse::Items.end(); i++) 
	{
		size_t found = i->get_name().find(n);
		if (found!= std::string::npos) {
			check = true;
			std::cout << "\nId :" << i->get_id();
			std::cout << "\nName: " << i->get_name();
			std::cout << "\nQuantity: " << i->get_quantity();
			std::cout << "\nPrice: " << i->get_price() << std::endl;
		}
	}
	if (!check)
	{
		std::cout << "Item not found!" << std::endl;
	}
}
void Warehouse::find_item_quantity(int quantity) {
	bool check = false;
	for (auto i = Warehouse::Items.begin(); i != Warehouse::Items.end(); i++) {
		if (i->get_quantity() == quantity) {
			check = true;
			std::cout << "\nId :" << i->get_id();
			std::cout << "\nName: " << i->get_name();
			std::cout << "\nQuantity: " << i->get_quantity();
			std::cout << "\nPrice: " << i->get_price() << std::endl;
		}
	}
	if (!check)
	{
		std::cout << "Item not found!" << std::endl;
	}
}

void Warehouse::find_item_quantity_s(int quantity)
{
	bool check = false;
	for (auto i = Warehouse::Items.begin(); i != Warehouse::Items.end(); i++) {
		if (i->get_quantity() < quantity) {
			check = true;
			std::cout << "\nId :" << i->get_id();
			std::cout << "\nName: " << i->get_name();
			std::cout << "\nQuantity: " << i->get_quantity();
			std::cout << "\nPrice: " << i->get_price() << std::endl;
		}
	}
	if (!check)
	{
		std::cout << "Item not found!" << std::endl;
	}
}

void Warehouse::find_item_quantity_l(int quantity)
{
	bool check = false;
	for (auto i = Warehouse::Items.begin(); i != Warehouse::Items.end(); i++) {
		if (i->get_quantity() > quantity) {
			check = true;
			std::cout << "\nId :" << i->get_id();
			std::cout << "\nName: " << i->get_name();
			std::cout << "\nQuantity: " << i->get_quantity();
			std::cout << "\nPrice: " << i->get_price() << std::endl;
		}
	}
	if (!check)
	{
		std::cout << "Item not found!" << std::endl;
	}
}
void Warehouse::find_item_price(double price) {
	bool check = false;
	for (auto i = Warehouse::Items.begin(); i != Warehouse::Items.end(); i++) {
		if (i->get_price() == price) {
			check = true;
			std::cout << "\nId :" << i->get_id();
			std::cout << "\nName: " << i->get_name();
			std::cout << "\nQuantity: " << i->get_quantity();
			std::cout << "\nPrice: " << i->get_price() << std::endl;
		}
	}
	if (!check)
	{
		std::cout << "Item not found!" << std::endl;
	}
}

void Warehouse::find_item_price_s(double price) {
	bool check = false;
	for (auto i = Warehouse::Items.begin(); i != Warehouse::Items.end(); i++) {
		if (i->get_price() < price) {
			check = true;
			std::cout << "\nId :" << i->get_id();
			std::cout << "\nName: " << i->get_name();
			std::cout << "\nQuantity: " << i->get_quantity();
			std::cout << "\nPrice: " << i->get_price() << std::endl;
		}
	}
	if (!check)
	{
		std::cout << "Item not found!" << std::endl;
	}
}

void Warehouse::find_item_price_l(double price) {
	bool check = false;
	for (auto i = Warehouse::Items.begin(); i != Warehouse::Items.end(); i++) {
		if (i->get_price() > price) {
			check = true;
			std::cout << "\nId :" << i->get_id();
			std::cout << "\nName: " << i->get_name();
			std::cout << "\nQuantity: " << i->get_quantity();
			std::cout << "\nPrice: " << i->get_price() << std::endl;
		}
	}
	if (!check)
	{
		std::cout << "Item not found!" << std::endl;
	}
}
void Inventory::find_item_by_id(int id) {
	int count = 0;
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++) {
		count++;
		std::cout << "\nWarehouse " << count << " : ";
		i->find_item(id);
	}
}
void Inventory::find_item_by_name(std::string n) {
	int count = 0;
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++) {
		count++;
		std::cout << "\nWarehouse " << count << " : ";
		i->find_item_name(n);
	}
}
void Inventory::find_item_by_quantity(int quantity) {
	int count = 0;
	std::cout << "\n\nPress [1] for <, press [2] for = and press [3] for > " << quantity << ": ";
	int usr_choice;
	std::cin >> usr_choice;
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++) {
		count++;
		std::cout << "\nWarehouse " << count << " : ";
		if (usr_choice == 1)
		{
			i->find_item_quantity_s(quantity);
		}
		else if (usr_choice == 2)
		{
			i->find_item_quantity(quantity);
		}
		else if (usr_choice == 3)
		{
			i->find_item_quantity_l(quantity);
		}
		else
		{
			throw std::string("Invalid user choice!");
		}		
	}
}
void Inventory::find_item_by_price(double price) {
	int count = 0;
	std::cout << "\n\nPress [1] for <, press [2] for = and press [3] for > " << price << ": ";
	int usr_choice;
	std::cin >> usr_choice;
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++) {
		count++;
		std::cout << "\nWarehouse " << count << " : ";
		if (usr_choice == 1)
		{
			i->find_item_price_s(price);
		}
		else if (usr_choice == 2)
		{
			i->find_item_price(price);
		}
		else if (usr_choice == 3)
		{
			i->find_item_price_l(price);
		}
		else
		{
			//them loi o day
		}
	}
}
void Inventory::find_warehouse_by_id(int id) {
	bool check = false;
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++) {
		if (i->get_id() == id) {
			check = true;
			std::cout << "\nId :" << i->get_id();
			std::cout << "\nName: " << i->get_name();
			std::cout << "\nAddress: " << i->get_address();
			std::cout << "\nRegion: " << i->get_region() << std::endl;
			return;
		}
	}
	if (!check)
	{
		std::cout << "Item not found!" << std::endl;
	}
}
void Inventory::find_warehouse_by_name(std::string name) {
	bool check = false;
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++)
	{
		size_t found = i->get_name().find(name);
		if (found!=std::string::npos) {
			check = true;
			std::cout << "\nId :" << i->get_id();
			std::cout << "\nName: " << i->get_name();
			std::cout << "\nAddress: " << i->get_address();
			std::cout << "\nRegion: " << i->get_region() << std::endl;
		}
	}
	if (!check)
	{
		std::cout << "Item not found!" << std::endl;
	}
}
void Inventory::find_warehouse_by_address(std::string address) {
	bool check = false;
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++) 
	{
		size_t found = i->get_address().find(address);
		if (found != std::string::npos) {
			check = true;
			std::cout << "\nId :" << i->get_id();
			std::cout << "\nName: " << i->get_name();
			std::cout << "\nAddress: " << i->get_address();
			std::cout << "\nRegion: " << i->get_region() << std::endl;
		}
	}
	if (!check)
	{
		std::cout << "Item not found!" << std::endl;
	}
}
void Inventory::find_warehouse_by_region(std::string region) {
	bool check = false;
	for (auto i = Inventory::Warehouses.begin(); i != Inventory::Warehouses.end(); i++) 
	{
		size_t found = i->get_region().find(region);
		if (found != std::string::npos) {
			check = true;
			std::cout << "\nId :" << i->get_id();
			std::cout << "\nName: " << i->get_name();
			std::cout << "\nAddress: " << i->get_address();
			std::cout << "\nRegion: " << i->get_region() << std::endl;
		}
	}
	if (!check)
	{
		std::cout << "Item not found!" << std::endl;
	}
}

