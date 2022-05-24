#include "func.h"

int main() {
	int n1;
	string n2;
	cout << "Enter N1 in decimal format: "; cin >> n1;
	cout << "Enter N2 in hex format: "; cin >> n2;
	Numeral_16 N1(n1), N2(n2), N3;
	cout << "N1 in hex format: " << N1.get_num_16() << endl;
	cout << "N2 in hex format: " << N2.get_num_16() << endl;
	cout << "Incremented N1: " << (++N1).get_num_16() << endl;
	string num_to_add;
	string mode = choose_mode();
	cout << "Enter a number in hex format to increase N2: "; cin >> num_to_add;
	if (mode == "h") N2 += num_to_add;
	else N2 += stoi(num_to_add);
	cout << "Increased N2: " << N2.get_num_16() << "\n";
	N3 = N1 + N2;
	cout << "N3 in hex format(sum of N1 & N2): " << N3.get_num_16() << endl;
	cout << "N3 in bin format(using long method): " << N3.bin_long() << endl;
	cout << "N3 in bin format(using short method): " << N3.bin_short() << endl;
}