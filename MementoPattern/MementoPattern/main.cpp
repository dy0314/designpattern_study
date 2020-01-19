//
//  main.cpp
//  MementoPattern
//
//  Created by daeyong Lee on 2019/12/30.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;


class InputMemento {
public:
    InputMemento(string& input) {
        this->input = input;
    }
    string getState() {
        return this->input;
    }
private:
    string input;
};

class InputOriginator {
public:
    void setCurrentInput(string input) {
        this->currentInput = input;
    }
    InputMemento* saveCurrentInputToMemento() {
        cout<<"Save Current Input to Memento :"<<currentInput<<endl;
        return new InputMemento(currentInput);
    }
    void restoreFromInputMemento(InputMemento* inputMemento) {
        this->currentInput = inputMemento->getState();
        delete inputMemento;
    }
    string getCurrentInput() {
        return currentInput;
    }
    
private:
    string currentInput;
};

class InputCareTaker {
public:
    void saveMemento(InputMemento* inputMemento) {
        inputMementos.push(inputMemento->getState());
    }
    InputMemento* popSavedMemento() {
        InputMemento* ret = new InputMemento(inputMementos.top());
        inputMementos.pop();
        return ret;
    }
private:
    stack<string> inputMementos;
};

int main(int argc, const char * argv[]) {
    InputCareTaker* inputCareTaker = new InputCareTaker();
    InputOriginator* inputOriginator = new InputOriginator();
    
    inputOriginator->setCurrentInput("abc");
    inputCareTaker->saveMemento(inputOriginator->saveCurrentInputToMemento());
    //input abc를 저장
    inputOriginator->setCurrentInput("def");
    inputCareTaker->saveMemento(inputOriginator->saveCurrentInputToMemento());
    //input def를 저장
    inputOriginator->setCurrentInput("ghi");
    
    inputOriginator->restoreFromInputMemento(inputCareTaker->popSavedMemento());
    cout<<"Restore input : "<<inputOriginator->getCurrentInput()<<endl;
    
    inputOriginator->restoreFromInputMemento(inputCareTaker->popSavedMemento());
    cout<<"Restore input : "<<inputOriginator->getCurrentInput()<<endl;
    
    delete inputCareTaker;
    delete inputOriginator;
    
    return 0;
}
