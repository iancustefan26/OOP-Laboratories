#pragma once

#ifndef VISITOR_H
#define VISITOR_H
#include "iostream"
#include "Product.h"

using namespace std;

class Book;
class Pen;

class Visitor {
public:
    void Visit(Book* param) {

    }
    void Visit(Pen* param) {

    }
};

class PriceVisitor : public Visitor {
public:
    void Visit(Book* param) {
        cout << "Pretul cartii este :" << param->GetPrice() << " lei\n";
    }
    void Visit(Pen* param) {
        cout << "Pretul pixului este :" << param->GetPrice() << " lei\n";
    }
};

class DetailsVisitor : public Visitor {
public:
    void Visit(Book* param) {
        cout << "Numarul de pagini al cartii este : " << param->GetNrPages() << "\n";
    }
    void Visit(Pen* param) {
        cout << "Culoarea pixului este : " << param->GetColor() << "\n";
    }
};

#endif