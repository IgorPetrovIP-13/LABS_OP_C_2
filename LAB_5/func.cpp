#include "func.h"

TQuadrangle::TQuadrangle(vector<vector <int>> points) {
	point1 = points[0];
	point2 = points[1];
	point3 = points[2];
	point4 = points[3];
}

double Parallelogram::get_p() {
	return (side_distance(point1, point2) + side_distance(point2, point3)) * 2;
}

double Parallelogram::get_s() {
	vector<int>vec1; 
	vec1.push_back(point2[0] - point1[0]);
	vec1.push_back(point2[1] - point1[1]);
	vector<int>vec2;
	vec2.push_back(point4[0] - point1[0]);
	vec2.push_back(point4[1] - point1[1]);
	return abs(vec1[0] * vec2[1] - vec1[1] * vec2[0]);
}

double Rectangle::get_s() {
	return side_distance(point1, point2) * side_distance(point2, point3);
}

double Square::get_p() {
	return side_distance(point1, point2) * 4;
}

double Square::get_s() {
	return pow(side_distance(point1, point2), 2);
}


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


double side_distance(vector<int> first_point, vector<int> second_point) {
	return sqrt(pow((second_point[0] - first_point[0]), 2) + pow((second_point[1] - first_point[1]), 2));
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