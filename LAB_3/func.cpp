# include "func.h"

int number_of_products(){
	int size = 0;
	do {
		cout << "Number of products: "; cin >> size;
		cout << std::endl;
	} while (size <= 0);
	return size;
}

Product::Product(string name, string release_date, string expiration_date) {
	this->name = name;
	this->release_date = release_date;
	this->expiration_date = expiration_date;
}

string Product::get_name() {
	return name;
}
string Product::get_rel_date() {
	return release_date;
}
string Product::get_exp_date() {
	return expiration_date;
}

Product* create_arr(int size) {
	Product* arr = new Product[size];
	for (size_t i = 0; i < size; i++) {
		string name, r_date, e_date;
		cout << i + 1 << ". Product:\n";
		cout << "Product name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Release date in format DD-MM-YYYY: "; cin >> r_date;
		cout << "Expiration date in format DD-MM-YYYY: "; cin >> e_date;
		cout << endl;
		Product product(name, r_date, e_date);
		arr[i] = product;
	}
	return arr;
}

void display_all_products(Product* arr, int size) {
	for (size_t i = 0; i < size; i++)
		cout << i + 1 << ". Product| " << "name: " << arr[i].get_name() << ", release date: " << arr[i].get_rel_date() << ", expiration date: " << arr[i].get_exp_date() << endl;
	cout << endl;
}

void display_outdated_products(Product* arr, int size, string c_date) {
	vector<string> current_v = split(c_date, '-');
	int current_d = stoi(current_v[0]), current_m = stoi(current_v[1]), current_y = stoi(current_v[2]);
	int prod_d, prod_m, prod_y, delta_year, delta_month, delta_day;
	vector<string> prod_v;
	for (size_t i = 0; i < size; i++)
	{
		prod_v = split(arr[i].get_exp_date(), '-');
		prod_d = stoi(prod_v[0]);
		prod_m = stoi(prod_v[1]);
		prod_y = stoi(prod_v[2]);
		delta_year = current_y - prod_y;
		delta_month = current_m - prod_m;
		delta_day = current_d - prod_d;
		if (delta_year > 0 or delta_month > 0 or delta_day > 0) {
			cout << "Name: " << arr[i].get_name() << ", release date: " << arr[i].get_rel_date() << ", expiration date: " << arr[i].get_exp_date() << endl;
		}
	}

}


vector<string> split(string line, char sep) {
	vector<string> res;
	string slice = "";
	line += sep;
	for (int i = 0; i < int(line.length()); i++) {
		if (line[i] == sep) {
			if (slice.length() > 0) res.push_back(slice);
			slice = "";
		}
		else slice += line[i];
	}
	return res;
}