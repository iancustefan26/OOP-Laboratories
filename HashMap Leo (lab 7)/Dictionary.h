#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "CRC.h"

template<int, class value_type>
struct Element {
	int key;
	value_type value;

	Element() {
		key = 0;
	}
};

template<class key_type, class value_type>
class Dictionary {
private:
	Element<key_type,value_type>** elements;
	int number_of_elements;
	bool reserved;
public:
	Dictionary() {
		number_of_elements = 0;
		elements = nullptr;
		reserved = false;
		elements = new Element<key_type, value_type>* [200];
	}
	~Dictionary() {
		delete[] elements;
	}
	void reserve(int size) {
		number_of_elements = size;
		elements = new Element<key_type, value_type>*[size];
	}
	void addElement(key_type newKey, value_type newValue) {
		elements[number_of_elements] = new Element<int, value_type>;
		elements[number_of_elements].key = calculateCRC32(&newkey);
		elements[number_of_elements].value = newValue;
		number_of_elements++;
	}
	void print() const {
		for (int i = 0; i < number_of_elements; ++i)
			std::cout << elements[i]->key << " : " << elements[i]->value << "\n";
	}
};


#endif // !DICTIONARY_H
