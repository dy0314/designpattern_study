//
//  main.cpp
//  AdapterPattern
//
//  Created by daeyong Lee on 03/03/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>

using namespace std;

class NetWorkController {
public:
    virtual void Activate() = 0;
    virtual void Deactivate() = 0;
};

class BluetoothFW {
public:
    static void ActivateBT() {
        cout<<"BT Activated"<<endl;
    }
    static void DeactivateBT() {
        cout<<"BT Deactivated"<<endl;
    }
};

class WIFIFW {
public:
    static void ActivateWIFI() {
        cout<<"WIFI Activated"<<endl;
    }
    static void DeactivateWIFI() {
        cout<<"WIFI Deactivated"<<endl;
    }
};

class BluetoothController : public NetWorkController {
public:
    virtual void Activate() {
        cout<<"Save Log Activate BT"<<endl;
        BluetoothFW::ActivateBT();
    }
    virtual void Deactivate() {
        cout<<"Save Log Deactivate BT"<<endl;
        BluetoothFW::DeactivateBT();
    }
};

class WIFIController : public NetWorkController {
public:
    virtual void Activate() {
        cout<<"Save Log Activate WIFI"<<endl;
        WIFIFW::ActivateWIFI();
    }
    virtual void Deactivate() {
        cout<<"Save Log Deactivate WIFI"<<endl;
        WIFIFW::DeactivateWIFI();
    }
};



int main(int argc, const char * argv[]) {
    
    NetWorkController * controller = new BluetoothController();
    controller->Activate();
    controller->Deactivate();
    
    delete controller;
    
    controller = new WIFIController();
    controller->Activate();
    controller->Deactivate();
    
    return 0;
}
