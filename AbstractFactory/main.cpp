#include<iostream>

using namespace std;

class Popup {
public:
    virtual void showPopup() = 0;
};

class Scroll {
public:
    virtual void showScroll() = 0;
};

class MacPopup : public Popup {
public:
    virtual void showPopup() {
        cout<<"This is Mac Popup"<<endl;
    }
};

class WinPopup : public Popup {
public:
    virtual void showPopup() {
        cout<<"This is Win Popup"<<endl;
    }
};

class MacScroll : public Scroll {
public:
    virtual void showScroll() {
        cout<<"This is Mac Scroll"<<endl;
    }
};

class WinScroll : public Scroll {
public:
    virtual void showScroll() {
        cout<<"This is Win Scroll"<<endl;
    }
};

class GUIFactory {
public:
    virtual Popup * makePopup() = 0;
    virtual Scroll * makeScroll() = 0;         
};

class MacGUIFactory : public GUIFactory {
public:
    virtual Popup * makePopup() {
        return new MacPopup();
    }
    virtual Scroll * makeScroll() {
        return new MacScroll();
    }
};

class WinGUIFactory : public GUIFactory {
public:
    virtual Popup * makePopup() {
        return new WinPopup();
    }
    virtual Scroll * makeScroll() {
        return new WinScroll();
    }
};

class FactoryInstance {
public:
    static GUIFactory* getGuiFacByOS() {
        int currentOS = getCurrentOS(); //현재 OS가 무엇인지 알아올 수 있는 시스템 API가 있다고 가정합시다.
        switch(currentOS) {
            case MAC:
                return new MacGUIFactory();
            case WIN:
                return new WinGUIFactory();
            default:
                assert("error");
        }
    }
};

int main(void) {
    GUIFactory * factory = FactoryInstance.getGuiFacByOS();
    
    Scroll = factory->makeScroll();
    Popup = factory->makePopup();

    return 0;
}