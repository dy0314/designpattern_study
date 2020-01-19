//
//  main.cpp
//  PrototypePattern
//
//  Created by daeyong Lee on 13/09/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

class ShapePrototype {
public:
    virtual ShapePrototype* clone() = 0;
};

class Circle : public ShapePrototype {
public:
    Circle(int x, int y, int r) {
        this->x = x;
        this->y = y;
        this->r = r;
    }
    virtual ShapePrototype* clone() override final {
        return new Circle(x+1, y, r);//x축으로 1만큼 이동
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
private:
    int x;
    int y;
    int r;
};

int main(int argc, const char * argv[]) {
    ShapePrototype* circleA = new Circle(10, 20, 3);
    ShapePrototype* circleB = (Circle*)circleA->clone();
    
    printf("circleA address : %p \ncircleB address : %p\n\n", circleA, circleB);
    
    printf("A(%d, %d) B(%d, %d)\n", ((Circle*)circleA)->getX(), ((Circle*)circleA)->getY(), ((Circle*)circleB)->getX(),((Circle*)circleB)->getY());
    
    return 0;
}
