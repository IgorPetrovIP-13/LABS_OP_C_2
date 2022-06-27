#include "tree.h"
#include "func.h"

Node::Node()
{
	this->value = "";
	left = NULL;
	right = NULL;
}

Node::Node(string key)
{
	this->value = key;
	left = NULL;
	right = NULL;
}

void Node::set_value(string key)
{
	this->value = key;
}
string Node::get_value()
{
	return value;
}

ExpressionTree::ExpressionTree(vector<string> symbs)
{
	int index = 0;
	Root = createTree(symbs, index);
}

Node* ExpressionTree::createTree(vector<string> symbs, int& index)
{
	Node* node = new Node();
	while (index < symbs.size()) {
		if (symbs[index] == ")") {
			return node;
		}
		if (symbs[index] == "(") {
			node->left = createTree(symbs, ++index);
			index++;
		}
		if (isdigit(symbs[index][0])) {
			node->set_value(symbs[index]);
			return node;
		}
		if (is_operator(symbs[index])) {
			node->set_value(symbs[index]);
			node->right = createTree(symbs, ++index);
			index++;
		}
	}
	return node;
}

void ExpressionTree::print(Node* node, int space)
{
	if (node != NULL) {
		print(node->right, space + 1);
		for (int i = 0; i < space; i++) {
			cout << "\t";
		}
		cout << "  " << node->get_value() << "\n";
		print(node->left, space + 1);
	}
}

void ExpressionTree::print()
{
	print(Root, 0);
}

void ExpressionTree::modify() {
	modify(Root);
}

void ExpressionTree::modify(Node* node) {
	if (node == NULL) {
		return;
	}
	create_final(node);
	modify(node->left);
	modify(node->right);
}

void ExpressionTree::create_final(Node* node) {
	if (check_formula(node) == 1) {
		string mult = node->right->get_value(), plus = node->left->right->get_value();
		node->set_value(node->left->get_value());
		node->left->set_value("*");
		node->right->set_value("*");
		node->left->right->set_value(mult);
		node->right->left = new Node;
		node->right->left->set_value(plus);
		node->right->right = new Node;
		node->right->right->set_value(mult);
	}
	else if (check_formula(node) == 2){
		string mult = node->left->get_value(), plus = node->right->right->get_value();
		node->set_value(node->right->get_value());
		node->right->set_value("*");
		node->left->set_value("*");
		node->right->right->set_value(mult);
		node->left->left = new Node;
		node->left->left->set_value(plus);
		node->left->right = new Node;
		node->left->right->set_value(mult);
	}
}

int ExpressionTree::check_formula(Node* node) {
	if (node->get_value() == "*" && is_leaf(node->right) && (node->left->get_value() == "+" || node->left->get_value() == "-") && is_leaf(node->left->left) && is_leaf(node->left->right)) {
		return 1;
	}
	else if (node->get_value() == "*" && is_leaf(node->left) && (node->right->get_value() == "+" || node->right->get_value() == "-") && is_leaf(node->right->right) && is_leaf(node->right->left)) {
		return 2;
	}
	return -1;
}

bool ExpressionTree::is_leaf(Node* node) {
	return(isdigit(node->get_value()[0]));
}

void ExpressionTree::free_memory(Node* node)
{
	if (node->left == NULL && node->right == NULL) {
		delete(node);
		return;
	}
	if (node->left != NULL) {
		free_memory(node->left);
	}
	if (node->right != NULL) {
		free_memory(node->right);
	}
}

void ExpressionTree::free_memory()
{
	free_memory(Root);
}