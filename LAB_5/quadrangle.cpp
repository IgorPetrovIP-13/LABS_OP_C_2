#include "quadrangle.h"

TQuadrangle::TQuadrangle(vector<vector <int>> points) {
	point1 = Point(points[0]);
	point2 = Point(points[1]);
	point3 = Point(points[2]);
	point4 = Point(points[3]);

	vec1 = { point2.get_x() - point1.get_x(), point2.get_y() - point1.get_y() };
	vec2 = { point3.get_x() - point2.get_x(), point3.get_y() - point2.get_y() };
	vec3 = { point3.get_x() - point4.get_x(), point3.get_y() - point4.get_y() };
	vec4 = { point4.get_x() - point1.get_x(), point4.get_y() - point1.get_y() };
}

Point::Point(vector<int> vec) {
	x = vec[0];
	y = vec[1];
}

double Parallelogram::get_p() {
	return (side_distance(point1, point2) + side_distance(point2, point3)) * 2;
}

double Parallelogram::get_s() {
	return abs(vec1[0] * vec4[1] - vec1[1] * vec4[0]);
}

bool Parallelogram::check_quadrangle() {
	int t1, t2, t3, t4;
	t1 = vec1[0] * vec2[1] - vec1[1] * vec2[0];
	t2 = vec2[0] * vec3[1] - vec2[1] * vec3[0];
	t3 = vec3[0] * vec4[1] - vec3[1] * vec4[0];
	t4 = vec4[0] * vec1[1] - vec4[1] * vec1[0];

	if (vec1 == vec3 and vec2 == vec4 and t1 * t2 * t3 * t4 > 0) {
		return true;
	}
	return false;
}

double Rectangle::get_s() {
	return side_distance(point1, point2) * side_distance(point2, point3);
}

bool Rectangle::check_quadrangle() {
	int scal1, scal2;
	scal1 = vec1[0] * vec2[0] + vec1[1] * vec2[1];
	scal2 = vec1[0] * vec4[0] + vec1[1] * vec4[1];

	if (vec1 == vec3 and vec2 == vec4 and scal1 == 0 and scal2 == 0) {
		return true;
	}
	return false;
}

double Square::get_p() {
	return side_distance(point1, point2) * 4;
}

double Square::get_s() {
	return pow(side_distance(point1, point2), 2);
}

bool Square::check_quadrangle() {
	int scal1, scal2;
	scal1 = vec1[0] * vec2[0] + vec1[1] * vec2[1];
	scal2 = vec1[0] * vec4[0] + vec1[1] * vec4[1];

	int side1, side2, side3, side4;
	side1 = side_distance(point1, point2);
	side2 = side_distance(point2, point3);
	side3 = side_distance(point4, point3);
	side4 = side_distance(point1, point4);

	if (vec1 == vec3 and vec2 == vec4 and side1 == side2 and side2 == side3 and side2 == side4 and scal1 == 0 and scal2 == 0) {
		return true;
	}
	return false;
}

double side_distance(Point first_point, Point second_point) {
	return sqrt(pow((second_point.get_x() - first_point.get_x()), 2) + pow((second_point.get_y() - first_point.get_y()), 2));
}