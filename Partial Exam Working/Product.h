#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H
#include "Author.h"
#include <vector>

using namespace std;

class Visitor;


class Product {
public:
    void Accept(Visitor* param) {

    }
};

class Book : public Product {
    int nrPages;
    int price;
    vector<Author*> authors;
public:
    Book() {
        nrPages = 0;
        price = 0;
    }
    Book(int price, int pages) : price(price), nrPages(pages) {
        authors.reserve(50);
    };
    void Accept(Visitor* param) {
        param->Visit(this);
    }
    void AddAuthor(Author* param) {
        authors.push_back(param);
    }
    int GetNrPages() const {
        return nrPages;
    }
    int GetPrice() const {
        return price;
    }
};

class Pen : public Product {
    string color;
    int price;
public:
    Pen() {
        color = "";
        price = 0;
    }
    Pen(int price, string color) : price(price), color(color) {};
    void Accept(Visitor* param) {
        param->Visit(this);
    }
    string GetColor() const {
        return color;
    }
    int GetPrice() const {
        return price;
    }
};

#endif