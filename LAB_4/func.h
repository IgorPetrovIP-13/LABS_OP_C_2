#pragma once
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Numeral_16 {
private:
	string num_16;
public:
	Numeral_16() = default;
	Numeral_16(int);
	Numeral_16(const string&);
	string get_num_16();
	Numeral_16 operator ++();
	const Numeral_16 operator +(const Numeral_16&);
	const Numeral_16 operator += (const string&);
	const Numeral_16 operator += (int);
	string bin_short();
	string bin_long();
};

string choose_mode();