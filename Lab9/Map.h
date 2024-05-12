#pragma once
#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <tuple>

template<class key_type, class value_type>
struct Object {
	key_type key;
	value_type value;
	int index;

	Object() {}
	Object(key_type key, value_type value, int index) : key(key), value(value), index(index) {}
};


template<class key_type, class value_type>
class Map {
	Object<key_type, value_type>* objects;
	int number_of_objects;
public:
	Map() {
		objects = new Object<key_type, value_type>[50];
		number_of_objects = 0;
	}
	value_type& operator[](const key_type param_key) {
		for (int i = 0; i < number_of_objects; ++i)
			if (objects[i].key == param_key)
				return objects[i].value;
		//objects[number_of_objects] = new Object<key_type, value_type>;
		objects[number_of_objects].index = number_of_objects;
		objects[number_of_objects].key = param_key;
		number_of_objects++;
		return objects[number_of_objects - 1].value;
	}
	void Set(const key_type param_key, const value_type param_value) {
		for (int i = 0; i < number_of_objects; ++i)
			if (objects[i].key == param_key)
				objects[i].value = param_value;
	}
	bool Get(const key_type& param_key, value_type& param_value) const {
		for (int i = 0; i < number_of_objects; ++i)
			if (objects[i].key == param_key) {
				param_value = objects[i].value;
				return true;
			}
		return false;
	}
	int Count() const {
		return number_of_objects;
	}
	void Clear() {
		for (int i = 0; i < number_of_objects; ++i) {
			&objects[i].key = nullptr;
			&objects[i].value = nullptr;
			objects[i].index = 0;
		}
	}
	bool Delete(const key_type& key) {
		for (int i = 0; i < number_of_objects; ++i)
			if (objects[i].key == key) {
				&objects[i].key = nullptr;
				&objects[i].value = nullptr;
				objects[i].index = 0;
			}
	}
	bool Includes(const Map<key_type, value_type>& map) {
		for (auto [key, value, index] : map)
		{
			bool found = false;
			for (int i = 0; i < number_of_objects; ++i)
				if (objects[i].key == key)
				{
					found = true;
					break;
				}
			if (found == false)
				return false;
		}
		return true;
	}
	Object<key_type, value_type>* begin() {
		return objects;
	}
	Object<key_type, value_type>* end() {
		return &objects[number_of_objects];
	}
	~Map() {
		delete[] objects;
	}
};


#endif // !MAP_h
