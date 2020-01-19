//
//  main.cpp
//  SigletonPattern
//
//  Created by daeyong Lee on 28/09/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
using namespace std;

class NetworkManager {
public:
    static NetworkManager* Instance() {
        static NetworkManager networkManager;
        return &networkManager;
    }
    void connect() {
        cout<<"connect..."<<endl;
    }
    void disconnect() {
        cout<<"disconnect..."<<endl;
    }
    
private:
    NetworkManager(){}
};

int main(int argc, const char * argv[]) {
    NetworkManager* networkManager = NetworkManager::Instance();
    networkManager->connect();
    networkManager->disconnect();
    return 0;
}
