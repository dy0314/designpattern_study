//
//  main.cpp
//  VisitorPattern
//
//  Created by daeyong Lee on 2020/01/05.
//  Copyright © 2020 daeyong Lee. All rights reserved.
//

#include <iostream>

using namespace std;


class DoubleElement;
class IntElement;

class Visitor {
public:
    virtual ~Visitor(){};
    virtual void visit(DoubleElement* doubleElement) = 0;
    virtual void visit(IntElement* intElement) = 0;
};

class Element {
public:
    virtual ~Element(){};
    virtual void accept(Visitor* visitor) = 0;
};

class DoubleElement : public Element {
public:
    DoubleElement(double a, double b) : a(a), b(b) {}
    ~DoubleElement() {
        
    }
    virtual void accept(Visitor* visitor) override {
        visitor->visit(this);
    }
    double getA() {
        return a;
    }
    double getB() {
        return b;
    }
private:
    double a, b;
};

class IntElement : public Element {
public:
    IntElement(int a, int b) : a(a), b(b){}
    ~IntElement() {
        
    }
    virtual void accept(Visitor* visitor) override {
        visitor->visit(this);
    }
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
private:
    int a, b;
};

class AddVisitor : public Visitor {
    virtual void visit(DoubleElement* doubleElement) override {
        double sum = doubleElement->getA() + doubleElement->getB();
        cout<<"AddVisitor double element's result : " << sum <<endl;
    }
    virtual void visit(IntElement* intElement) override {
        int sum = intElement->getA() + intElement->getB();
        cout<<"AddVisitor int element's result : " << sum <<endl;
    }
};

class MulVisitor : public Visitor {
    virtual void visit(DoubleElement* doubleElement) override {
        double mul = doubleElement->getA() * doubleElement->getB();
        cout<<"MulVisitor double element's result : " << mul <<endl;
    }
    virtual void visit(IntElement* intElement) override {
        int mul = intElement->getA() * intElement->getB();
        cout<<"MulVisitor int element's result : " << mul <<endl;
    }
};

int main(int argc, const char * argv[]) {
    DoubleElement* doubleElement = new DoubleElement(3.2,2.3);
    IntElement* intElement = new IntElement(1,2);
    
    AddVisitor* addVisitor = new AddVisitor();
    MulVisitor* mulVisitor = new MulVisitor();
    
    doubleElement->accept(addVisitor);
    intElement->accept(addVisitor);
    
    doubleElement->accept(mulVisitor);
    intElement->accept(mulVisitor);
    
    delete doubleElement;
    delete intElement;
    delete addVisitor;
    delete mulVisitor;
    
    return 0;
}
