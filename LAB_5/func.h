#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TQuadrangle {
protected:
	vector <int> point1, point2, point3, point4;
public:
	explicit TQuadrangle(vector <vector <int>>);
	virtual double get_p() = 0;
	virtual double get_s() = 0;
};

class Parallelogram : public TQuadrangle {
public:
	explicit Parallelogram(vector <vector <int>> points) : TQuadrangle(points) {};
	double get_p() override;
	double get_s() override;
};

class Rectangle : public Parallelogram {
public:
	explicit Rectangle(vector <vector <int>> points) : Parallelogram(points) {};
	double get_s() override;
};

class Square : public Rectangle {
public:
	explicit Square(vector <vector <int>> points) : Rectangle(points) {};
	double get_p() override;
	double get_s() override;
};

int make_choice();
vector <vector <int>> enter_points();
double side_distance(vector<int>, vector<int>);
vector <int> split(string, char sep=' ');