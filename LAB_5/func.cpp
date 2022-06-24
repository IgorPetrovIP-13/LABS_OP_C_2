#include "func.h"

int make_choice() {
	int choice;
	cout << "Enter 1 for parallelogram, 2 for rectangle or 3 for square: "; cin >> choice;
	while (choice != 1 and choice != 2 and choice != 3) {
		cout << "Incorrect input. Enter 1 for parallelogram, 2 for rectangle or 3 for square: "; cin >> choice;
	}
	return choice;
}

vector <vector <int>> enter_points() {
	vector <vector <int>> final_vec;
	string temp;
	cin.ignore();
	for (size_t i = 0; i < 4; i++)
	{
		cout << "Point " << i + 1 << " in format x y: ";
		getline(cin, temp);
		final_vec.push_back(split(temp));
	}
	return final_vec;
}

vector<int> split(string line, char sep) {
	vector<int> res;
	string slice = "";
	line += sep;
	for (int i = 0; i < int(line.length()); i++) {
		if (line[i] == sep) {
			if (slice.length() > 0) res.push_back(stoi(slice));
			slice = "";
		}
		else slice += line[i];
	}
	return res;
}