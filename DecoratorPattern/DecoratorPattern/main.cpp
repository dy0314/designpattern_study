//
//  main.cpp
//  DecoratorPattern
//
//  Created by daeyong Lee on 21/07/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>

using namespace std;

class WidgetComponent {
public:
    virtual void Draw() = 0;
};

class CalendarWidget: public WidgetComponent {
public:
    virtual void Draw() {
        cout<<"Draw Window"<<endl;
    }
};

class Decorator: public WidgetComponent {
public:
    Decorator(WidgetComponent* comp): component(comp){};
    
    virtual void Draw() {
        component->Draw();
    }
    
private:
    WidgetComponent* component;
};

class BorderDecorator: public Decorator {
public:
    BorderDecorator(WidgetComponent* comp)
    :Decorator(comp){}
    
    virtual void Draw() {
        Decorator::Draw();
        DrawBoarder();
    }
    
private:
    void DrawBoarder() {
        cout<<"Draw Boarder"<<endl;
    }
};


class ScrollDecorator: public Decorator {
public:
    ScrollDecorator(WidgetComponent* comp)
    :Decorator(comp){}
    
    virtual void Draw() {
        Decorator::Draw();
        DrawScroll();
    }
    
private:
    void DrawScroll() {
        cout<<"Draw Scroll"<<endl;
    }
};

int main(int argc, const char * argv[]) {
    WidgetComponent* widget = new CalendarWidget();
    widget = new BorderDecorator(widget);
    widget = new ScrollDecorator(widget);
    
    widget->Draw();
    
    return 0;
}
