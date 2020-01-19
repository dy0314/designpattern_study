//
//  main.cpp
//  MediatorPattern
//
//  Created by daeyong Lee on 2019/12/29.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
#include <list>
#include <string>

using namespace std;
class Colleague;

class Meditator {
public:
    virtual ~Meditator() {}
    void addColleague(Colleague* collegue) {
        this->collegues.push_back(collegue);
    }
    virtual void mediate(string message) = 0;
    
protected:
    list<Colleague*> collegues;
};

class Colleague {
public:
    virtual ~Colleague() {}
    void setMeditator(Meditator* meditator) {
        this->meditator = meditator;
        this->meditator->addColleague(this);
    }
    void sendMessage(string message) {
        cout<<"Colleague:"<<this<<" Send message"<<endl;
        meditator->mediate(message);
    }
    virtual void handleMessage(string message) = 0;
    
private:
    Meditator* meditator;
};

class ChatColleague : public Colleague {
public:
    virtual void handleMessage(string message) override {
        cout<<message<<endl;
    }
};

class ChatMediator : public Meditator {
public:
    virtual void mediate(string message) override {
        list<Colleague*>::iterator iter;
        for(iter = collegues.begin(); iter!=collegues.end(); ++iter)
        {
            (*iter)->handleMessage(message);
        }
    }
};

int main(int argc, const char * argv[]) {
    Meditator* chatMediator = new ChatMediator();
    
    Colleague* colleague1 = new ChatColleague();
    Colleague* colleague2 = new ChatColleague();
    Colleague* colleague3 = new ChatColleague();
    
    colleague1->setMeditator(chatMediator);
    colleague2->setMeditator(chatMediator);
    colleague3->setMeditator(chatMediator);
    
    colleague1->sendMessage("hi_1");
    colleague2->sendMessage("hi_2");
    colleague3->sendMessage("hi_3");
    
    delete colleague1;
    delete colleague2;
    delete colleague3;
    delete chatMediator;
    
    return 0;
}
