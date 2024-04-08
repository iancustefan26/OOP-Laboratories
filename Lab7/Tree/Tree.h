#pragma once
#ifndef TREE_H
#define TREE_H

template <class T>
struct Node {
	T value;
	Node<T>* childrens = nullptr;
	int number_of_childrens = 0;
};
template <class T>
class Tree {
private:
	Node<T>* root;
public:
	Tree() {
		nodes = nullptr;
	}
	void add_node(Node<T>* node) {
		if (node == nullptr) {
			this->root = new Node<T>();
			return;
		}
		node->childrens[node->number_of_childrens] = new Node<T>();
		node->value = 0;
	}
	Node<T>& get_node(Node<T>* node) {
		if (node == nullptr) {
			return this -> *root;
		}
		else {
			return node->*childrens;
		}
	}
	Node<T>& get_node(Node<T>& node) {
		if (&node == nullptr) {
			return this -> *root;
		}
		else {
			return &node.childrens;
		}
	}
	void delete_node(Node<T>* node) {
		delete[] node->childrens;
		delete node;
	}
	Node<T>* find(T to_find_value, Node<T>* temp, bool* function) {
		while (temp != nullptr) {
			for (int i = 0; i < temp->number_of_childrens; ++i) {
				find(to_find_value, temp[i], funtcion);
				if (function(to_find_value, temp->value))
					return temp[i];
			}
		}
		return nullptr;
	}

};

#endif // !TREE_H
