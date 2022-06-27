#include "tree.h"
#include "func.h"

int main() {
	string s;
	cout << "Enter expression separating operations with parentheses:\n";
	getline(cin, s);
	vector <string> expression = split(s);
	ExpressionTree Tree(expression);
	cout << "\nFixed expression:\n"; fixed_expression(expression);
	cout << "\Tree from infix expression:\n";
	Tree.print();
	Tree.modify();
	cout << "\nModified tree:\n\n";
	Tree.print();
	Tree.free_memory();
}