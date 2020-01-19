//
//  main.cpp
//  Observer Pattern
//
//  Created by daeyong Lee on 24/03/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class TimeObserver {
public:
    virtual ~TimeObserver(){};
    virtual void Update(double time) = 0;
};

class DigitalTimeObserver : public TimeObserver {
public:
    virtual void Update(double time) {
        cout<<"Update digital time"<<endl;
    }
};

class AnalogTimeObserver : public TimeObserver {
public:
    virtual void Update(double time) {
        cout<<"Update analog time"<<endl;
    }
};

class ClockTimer {
    
public:
    void RegisterObserver(TimeObserver* observer) {
        observerList.push_back(observer);
    }
    
    void Detach(TimeObserver* observer){
        
    }
    void Tick() {
        cout<<"time is ticking"<<endl;
        NotifyObservers();
    }
private:
    vector<TimeObserver *> observerList;
    
    void NotifyObservers() {
        double currentTime = 0;
        for(int i = 0; i < observerList.size(); i++) {
            TimeObserver* observer = observerList[i];
            observer->Update(currentTime);
        }
    }
};


int main(int argc, const char * argv[]) {
    AnalogTimeObserver* analogTimeObserver = new AnalogTimeObserver();
    DigitalTimeObserver* digitalTimeObserver = new DigitalTimeObserver();
    
    ClockTimer* timer = new ClockTimer();
    timer->RegisterObserver(analogTimeObserver);
    timer->RegisterObserver(digitalTimeObserver);
    
    timer->Tick();

    return 0;
}
