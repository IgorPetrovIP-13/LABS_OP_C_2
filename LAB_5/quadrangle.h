#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point() = default;
	Point(vector<int> vec);
	int get_x() { return x; };
	int get_y() { return y; };
};

class TQuadrangle {
protected:
	Point point1, point2, point3, point4;
	vector <int> vec1, vec2, vec3, vec4;
public:
	TQuadrangle(vector <vector <int>>);
	virtual double get_p() = 0;
	virtual double get_s() = 0;
	virtual bool check_quadrangle() = 0;
};

class Parallelogram : public TQuadrangle {
public:
	Parallelogram(vector <vector <int>> points) : TQuadrangle(points) {};
	double get_p() override;
	double get_s() override;
	bool check_quadrangle() override;
};

class Rectangle : public Parallelogram {
public:
	Rectangle(vector <vector <int>> points) : Parallelogram(points) {};
	double get_s() override;
	bool check_quadrangle() override;
};

class Square : public Rectangle {
public:
	Square(vector <vector <int>> points) : Rectangle(points) {};
	double get_p() override;
	double get_s() override;
	bool check_quadrangle() override;
};

double side_distance(Point, Point);