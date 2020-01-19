//
//  main.cpp
//  FlyweightPattern
//
//  Created by daeyong Lee on 2019/11/09.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Contents {
public:
    virtual void play() = 0;
};

class Movie : public Contents {
public:
    Movie(string title) {
        this->title = title;
        cout<<"Load "<<title<<endl;
    }
    virtual void play() override final {
        cout<<"Play:" <<title<<endl;
    }
private:
    string title;
};

class ContentsFactory {
public:
    Contents* getContents(string key) {
        if(contentsList.find(key) == contentsList.end()) {
            contentsList[key] = new Movie(key);
        } else {
            cout<<"reuese"<<endl;
        }
        
        return contentsList[key];
    }
private:
    map<string, Contents*> contentsList;
};

int main(int argc, const char * argv[]) {
    ContentsFactory* contentsFactory = new ContentsFactory();
    
    Contents* movie = contentsFactory->getContents("Big short");
    movie->play();
    
    Contents* movie2 = contentsFactory->getContents("Big short");
    movie2->play();
    
    return 0;
}
