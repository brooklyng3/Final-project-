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
#include <algorithm>
#include <locale>
#include <Windows.h>

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
	std::string get_name() const;
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
    std::string get_name() const;
	std::string get_address() const;
	std::string get_region() const;
	void find_item(int);
	void view_all_item();
	void load_warehouse(std::string);
	void save_warehouse(std::string);
	bool check_id(int);
	void sort_id_a();
	void sort_id_d();
	void sort_name_a();
	void sort_name_d();
	void sort_quantity_a();
	void sort_quantity_d();
	void sort_price_a();
	void sort_price_d();
	void find_item_name(std::string );
	void find_item_quantity(int );
	void find_item_quantity_s(int);
	void find_item_quantity_l(int);
	void find_item_price(double);
	void find_item_price_s(double);
	void find_item_price_l(double);
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
	bool check_and_delete_item(int);
	bool check_and_update_item(int);
	void sort_item_by_id_a(int);
	void sort_item_by_id_d(int);
	void sort_item_by_name_a(int);
	void sort_item_by_name_d(int);
	void sort_item_by_quantity_a(int);
	void sort_item_by_quantity_d(int);
	void sort_item_by_price_a(int);
	void sort_item_by_price_d(int);
	void sort_warehouse_by_id_a();
	void sort_warehouse_by_id_d();
	void sort_warehouse_by_name_a();
	void sort_warehouse_by_name_d();
	void sort_warehouse_by_address_a();
	void sort_warehouse_by_address_d();
	void sort_warehouse_by_region_a();
	void sort_warehouse_by_region_d();
	void find_item_by_id(int);
	void find_item_by_name(std::string );
	void find_item_by_quantity(int );
	void find_item_by_price(double);
	void find_warehouse_by_id(int );
	void  find_warehouse_by_name(std::string );
	void find_warehouse_by_address(std::string );
	void find_warehouse_by_region(std::string );
};

void display();
bool delete_account(std::string);


bool login(std::string);

void change_pwd(std::string);
void create_new_account(std::string);




#endif