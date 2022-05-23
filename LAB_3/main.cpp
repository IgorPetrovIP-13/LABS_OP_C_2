# include "func.h"

int main() {
	int size = number_of_products();
	Product* arr = create_arr(size);
	cout << "\nAll products:\n\n";
	display_all_products(arr, size);
	string date;
	cout << "Enter the date in format DD-MM-YYYY: "; cin >> date;
	cout << "\nOutdated products:\n\n";
	display_outdated_products(arr, size, date);
}