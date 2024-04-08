#include <iostream>
#include "Tree.h"

int main() {
	Tree<int> myTree;

	myTree.add_node(nullptr, 1);
	myTree.add_node(&myTree.get_node(nullptr)->childrens[0], 2);
	//myTree.sort(myTree.get_node(nullptr), nullptr);
	std::cout << myTree.count(myTree.get_node(nullptr));
	

	return 0;
}