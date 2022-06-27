#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
private:
	string value;
public:
	Node* left,* right;
	Node();
	Node(string key);

	void set_value(string key);
	string get_value();
};

class ExpressionTree
{
private:
	Node* createTree(vector<string>, int&);
	void print(Node*, int);
	void modify(Node*);
	void create_final(Node*);
	int check_formula(Node*);
	void free_memory(Node*);
	bool is_leaf(Node*);
public:
	Node* Root;
	ExpressionTree(vector<string>);
	void print();
	void modify();
	void free_memory();
};