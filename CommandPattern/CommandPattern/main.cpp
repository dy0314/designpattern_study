//
//  main.cpp
//  CommandPattern
//
//  Created by daeyong Lee on 2019/12/22.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Command { //Command Interface
public:
    virtual void excute() = 0;
    virtual ~Command() {}
};

class IotTV { //Receiver
public:
    void turnOn() {
        cout<<"Turn on Iot TV"<<endl;
    }
    void turnOff() {
        cout<<"Turn off Iot TV"<<endl;
    }
};

class IotTVOnCommand : public Command {
public:
    IotTVOnCommand(IotTV* iotTV) {
        this->iotTV = iotTV;
    }
    void excute() override {
        iotTV->turnOn();
    }
    
private:
    IotTV* iotTV;
};

class IotTVOffCommand : public Command {
public:
    IotTVOffCommand(IotTV* iotTV) {
        this->iotTV = iotTV;
    }
    void excute() override {
        iotTV->turnOff();
    }
    
private:
    IotTV* iotTV;
};

class IotInvoker {
public:
    void setCommand(Command* command) {
        this->command = command;
    }
    void runCommand() {
        if(command)
            command->excute();
    }

private:
    Command* command;
};


int main(int argc, const char * argv[]) {
    IotTV* iotTV = new IotTV();
    
    IotTVOnCommand* iotTVOnCommand = new IotTVOnCommand(iotTV);
    IotTVOffCommand* iotTVOffCommand = new IotTVOffCommand(iotTV);
    
    IotInvoker* iotInvoker = new IotInvoker();
    iotInvoker->setCommand(iotTVOnCommand);
    iotInvoker->runCommand();
    
    iotInvoker->setCommand(iotTVOffCommand);
    iotInvoker->runCommand();
    
    delete iotInvoker;
    delete iotTVOffCommand;
    delete iotTVOnCommand;
    delete iotTV;
    return 0;
}
