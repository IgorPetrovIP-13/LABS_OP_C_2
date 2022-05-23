#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
private:
	string name;
	string release_date;
	string expiration_date;
public:
	Product(string name="No name", string release_date="00-00-0000", string expiration_date ="00-00-0000");
	string get_name();
	string get_rel_date();
	string get_exp_date();
};

int number_of_products();
Product* create_arr(int);
void display_all_products(Product*, int);
void display_outdated_products(Product*, int, string);
vector<string> split(string, char sep = ' ');