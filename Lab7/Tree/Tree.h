#pragma once
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <algorithm>

template <class T>
struct Node {
	T value = 0;
	Node<T>* childrens = nullptr;
	int number_of_childrens = 0;

	Node(T value) {
		this->value = value;
	}
	Node() {}
	void operator=(Node<T>* a) {
		*this = a;
	}
};
template <class T>
class Tree {
private:
	Node<T>* root;
	static bool default_compare(Node<T>& a, Node<T>& b) {
		return a.value < b.value;
	}
public:
	Tree() {
		root = new Node<T>();
	}
	void add_node(Node<T>* node, T value) {
		if (node == nullptr) {
			this->root = new Node<T>();
			this->root->value = value;
			return;
		}
		node->childrens[node->number_of_childrens] = new Node<T>(value);
		node->number_of_childrens++;
		node->value = 0;
	}
	Node<T>* get_node(Node<T>* node) {
		if (node == nullptr) {
			return this -> root;
		}
		else {
			return node->childrens;
		}
	}
	Node<T>* get_node(Node<T>& node) {
		if (&node == nullptr) {
			return this -> root;
		}
		else {
			return &node.childrens;
		}
	}
	void delete_node(Node<T>* node) {
		delete[] node->childrens;
		delete node;
	}
	Node<T>* find(T to_find_value, Node<T>* temp, bool* function(T, T)) {
		while (temp != nullptr) {	
			for (int i = 0; i < temp->number_of_childrens; ++i) {
				find(to_find_value, temp[i], function);
				if (function(to_find_value, temp->value))
					return temp[i];
			}
		}
		return nullptr;
	}
	void insert(Node<T>* parent, T value) {
		parent->childrens[parent->number_of_childrens] = new Node<T>(value);
		parent->number_of_childrens++;
	}
	void sort(Node<T>* node, bool* compare(T, T)) {
		if (compare == nullptr) {
			std::sort(node->childrens, node->childrens + node->number_of_childrens, default_compare);
		}
		std::sort(node->childrens, node->childrens + node->number_of_childrens, compare);
	}
	int count(Node<T>* node, const bool initial = false) const {
		if (node == nullptr && initial == false)
			return count(this->root);
		else if (node->childrens != nullptr)
			return 1 + count(node->childrens + 1, true);
		else return 0;
	}
};

#endif // !TREE_H
