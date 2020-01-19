//
//  main.cpp
//  strategy_pattern
//
//  Created by daeyong Lee on 07/07/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>

using namespace std;

class Scheduler {
public:
    virtual void doSchedule() = 0;
    
};

class FIFO : public Scheduler {
public:
    virtual void doSchedule() {
        cout<<"FIFO Scheduler"<<endl;
    }
};

class RR : public Scheduler {
public:
    virtual void doSchedule() {
        cout<<"RR Scheduler"<<endl;
    }
};

class SRT : public Scheduler {
public:
    virtual void doSchedule() {
        cout<<"SRT Scheduler"<<endl;
    }
};

class System {
public:
    void setScheduler(Scheduler* scheduler) {
        myScheduler = scheduler;
    }
    void doSchedule() {
        myScheduler->doSchedule();
    }

private:
    Scheduler* myScheduler;
};

int main(int argc, const char * argv[]) {
    
    System* mySystem = new System();
    Scheduler* myScheduler = new FIFO();
    
    mySystem->setScheduler(myScheduler);
    mySystem->doSchedule();
    
    delete myScheduler;
    
    myScheduler = new RR();
    mySystem->setScheduler(myScheduler);
    mySystem->doSchedule();
    
    return 0;
}
