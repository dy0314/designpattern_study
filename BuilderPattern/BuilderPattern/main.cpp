//
//  main.cpp
//  BuilderPattern
//
//  Created by daeyong Lee on 24/08/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Computer {
public:
    Computer() {
        //set default
        this->cpu = "i5";
        this->ram = 8;
        this->ssd = 128;
    }
    void setCPU(string cpu) {
        this->cpu = cpu;
    }
    void setRAM(int ramgb) {
        this->ram = ramgb;
    }
    void setSSD(int ssdgb) {
        this->ssd = ssdgb;
    }
    void showSpec() {
        cout<<"cpu:"<<cpu<<" ram:"<<ram<<" ssd:"<<ssd<<endl;
    }
private:
    string cpu;
    int ram;
    int ssd;
};


class ComputerBuilder { //abstract builder
public:
    virtual void setCPU() = 0;
    virtual void setRAM() = 0;
    virtual void setSSD() = 0;
    virtual Computer* getComputer() = 0;
};

class MacBuilder : public ComputerBuilder {
public:
    MacBuilder() {
        computer = new Computer();
    }
    virtual void setCPU() {
        computer->setCPU("i7");
    }
    virtual void setRAM() {
        computer->setRAM(16);
    }
    virtual void setSSD() {
        computer->setSSD(256);
    }
    
    virtual Computer* getComputer() {
        return computer;
    }
    
private:
    Computer* computer;
};

class ComputerDirector {
public:
    void setComputerBuilder(ComputerBuilder* computerBuilder) {
        this->computerBuilder = computerBuilder;
    }
    Computer* makeComputer() {
        computerBuilder->setCPU();
        computerBuilder->setRAM();
        computerBuilder->setSSD();
        
        return computerBuilder->getComputer();
    }
    
private:
    ComputerBuilder* computerBuilder;
};

int main(int argc, const char * argv[]) {
    ComputerDirector* computerDirector = new ComputerDirector();
    MacBuilder* macbuilder = new MacBuilder();
    
    computerDirector->setComputerBuilder(macbuilder);
    Computer* myCompuer = computerDirector->makeComputer();
    myCompuer->showSpec();
    
    
    return 0;
}
