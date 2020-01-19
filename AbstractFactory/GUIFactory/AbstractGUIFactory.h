#include<iostream>

class Popup;
class Scroll;

class AbstractGUIFactory {

public:
    virtual Popup * makePopup() = 0;
    virtual Scroll * makeScroll() = 0; 
};