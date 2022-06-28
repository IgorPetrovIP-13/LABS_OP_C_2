#include "func.h"

vector<string> split(string line) {
	vector<string> res;
	string operators = "+-*/()";
	string slice = "";
	line = "(" + line + ")";
	for (char symb : line) {
		if (symb != ' ') {
			if (operators.find(symb) != string::npos) {
				if (slice.length() > 0) {
					res.push_back(slice);
					slice = "";
				}
				res.push_back(string(1, symb));
			}
			else slice += symb;
		}
	}
	return res;
}

void fixed_expression(vector<string> vec) {
	if (vec.size() > 2){
		for (int i = 1; i < vec.size() - 1; i ++)
		{
			cout << vec[i] << ' ';
		}
		cout << "\n\n";
	}
}