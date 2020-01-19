//
//  main.cpp
//  Compiste_Pattern
//
//  Created by daeyong Lee on 21/04/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Component {
public:
    Component(string componentName) {
        this->componentName = componentName;
    }
    virtual ~Component(){ }
    
    virtual void ShowName() const = 0; //operation
    
protected:
    string componentName;
};

class Folder : public Component {
public:
    Folder(string folderName)
    : Component(folderName)
    { }
    
    virtual void ShowName() const {
        cout << this->componentName <<" child list" << endl;
        
        for (vector<Component*>::const_iterator it = children.begin();
             it != children.end(); ++it)
        {
            (*it)->ShowName();
        }
    }
    
    void addFile(Component* component) {
        children.push_back(component);
    }
    
private:
    vector<Component*> children;
};

class File : public Component {
public:
    File(string fileName)
    : Component(fileName)
    { }
    
    virtual void ShowName() const {
        cout<< this->componentName <<endl;
    }
};

int main(int argc, const char * argv[]) {
    Folder* root = new Folder("root");
    root->addFile(new File("config.txt"));
    
    Folder* usr =new Folder("usr");
    root->addFile(usr);
    usr->addFile(new File("guest1"));
    usr->addFile(new File("guest2"));
    
    
    root->ShowName();
    return 0;
}
