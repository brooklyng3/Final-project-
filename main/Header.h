#ifndef HEADER_H
#define HEADER_H

#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>
#include<conio.h>

class Item
{
private:
	std::string name;
	int quantity;
	double price;
	int id;
public:
	Item(void);
	~Item(void);
	Item(std::string, int, double,int);
	void set_name(std::string);
	void set_quantity(int);
	void set_price(double);
	std::string get_name();
	int get_quantity() const;
	double get_price() const;
	int get_id() const;
};

class Warehouse
{
private:
	std::string name, address, region;
	int id;
	std::vector<Item> Items;
public:
	Warehouse(void);
	~Warehouse(void);
	Warehouse(std::string, std::string, std::string,int);
	void add_item(Item);
	void remove_item(int);
	void update_item(std::string, int, double,int); 
	int get_id() const;
	void set_name(std::string);
	void set_address(std::string);
	void set_region(std::string);
	std::string get_name();
	std::string get_address();
	std::string get_region();
	void find_item(int);
	void view_all_item();
	void load_warehouse(std::string);
	void save_warehouse(std::string);
	bool check_id(int);
};

class Inventory
{
private:
	std::vector<Warehouse> Warehouses;
public:
	Inventory(void);
	~Inventory(void);
	void add_warehouse(Warehouse);
	void remove_warehouse(int);
	void update_warehouse(int, std::string, std::string, std::string);
	void find_warehouse_location(int);
	void load_inventory(std::string);
	void view_all_warehouse();
	void save_inventory(std::string);
	bool check_and_add_item(int);
	bool check_warehouse(int);
};

void display();

bool login(std::string);



#endif