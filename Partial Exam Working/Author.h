#pragma once
#include <iostream>
#include <string>

using namespace std;


class Author {
    string surname;
    string firstname;
public:
    Author() {
        surname = "";
        firstname = "";
    }
    Author(string first, string sur) : firstname(first), surname(sur) {};
    string GetSurname() const {
        return surname;
    }
    string GetFirstname() const {
        return firstname;
    }

};