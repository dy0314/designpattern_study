//
//  main.cpp
//  BridgePattern
//
//  Created by daeyong Lee on 13/10/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
using namespace std;

class DisplayImpl { //Implementor
public:
    virtual void showDisplay() = 0;
    virtual void setHeight() = 0;
    virtual void setWidth() = 0;
};

class Tablet9DisplayImpl : public DisplayImpl { //ConcreteImplementor
public:
    virtual void showDisplay() override final {
        cout<<"show 9 Inches tablet"<<endl;
    }
    virtual void setHeight() override final {
        cout<<"set for 9 Inches tablet height"<<endl;
    }
    virtual void setWidth() override final {
        cout<<"set for 9 Inches tablet weight"<<endl;
    }
};

class Tablet11DisplayImpl : public DisplayImpl { //ConcreteImplementor
public:
    virtual void showDisplay() override final {
        cout<<"show 11 Inches tablet"<<endl;
    }
    virtual void setHeight() override final {
        cout<<"set for 11 Inches tablet height"<<endl;
    }
    virtual void setWidth() override final {
        cout<<"set for 11 Inches tablet weight"<<endl;
    }
};

class Tablet13DisplayImpl : public DisplayImpl { //ConcreteImplementor
public:
    virtual void showDisplay() override final {
        cout<<"show 13 Inches tablet"<<endl;
    }
    virtual void setHeight() override final {
        cout<<"set for 13 Inches tablet height"<<endl;
    }
    virtual void setWidth() override final {
        cout<<"set for 13 Inches tablet weight"<<endl;
    }
};


class TabletDisplay { //Abstraction
public:
    TabletDisplay(DisplayImpl* displayImpl) {
        this->displayImpl = displayImpl;
    }
    void setTabletDisplayImpl(DisplayImpl* displayImpl) {
        this->displayImpl = displayImpl;
    }
    void show() {
        displayImpl->showDisplay();
    }
    void setWidth() {
        displayImpl->setWidth();
    }
    void setHeight() {
        displayImpl->setHeight();
    }
    
private:
    DisplayImpl* displayImpl;
};

class GalaxyTabDisplay : public TabletDisplay { //ConcreteAbstraction
public:
    GalaxyTabDisplay(DisplayImpl* displayImpl) : TabletDisplay(displayImpl){
        
    }
    void showMyDisplay() {
        setWidth();
        setHeight();
        show();
    }
};

class A {
public:
    virtual void doSomething(int a) {
        cout<<"A do"<<endl;
    }
};

class B : public A{
public:
    virtual void doSomething(float b) { //compile ok
        cout<<"B do"<<endl;
    }
};

class GrandParent {
public:
    virtual void useMail() {
        cout<<"send mail"<<endl;
    }
    virtual void useMessanger() {
        cout<<"use text message"<<endl;
    }
};

class Parent : GrandParent{
public:
    virtual void useMail() override final{
        cout<<"send e-mail"<<endl;
    }
    virtual void useMessanger() override {
        cout<<"use kakao talk"<<endl;
    }
};

class Child : Parent {
public:
    virtual void useMail() override { //Declaration of 'useMail' overrides a 'final' function
        
    }
    virtual void useMessanger() override {
        cout<<"use facebook messanger"<<endl;
    }
};

int main(int argc, const char * argv[]) {
    GalaxyTabDisplay* myTablet = new GalaxyTabDisplay(new Tablet9DisplayImpl());
    myTablet->showMyDisplay();
    
    myTablet->setTabletDisplayImpl(new Tablet11DisplayImpl());
    myTablet->showMyDisplay();
    
    myTablet->setTabletDisplayImpl(new Tablet13DisplayImpl());
    myTablet->showMyDisplay();

    return 0;
}
