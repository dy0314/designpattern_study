//
//  main.cpp
//  ProxyPattern
//
//  Created by daeyong Lee on 2019/12/08.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Image {
public:
    virtual void renderImage() = 0;
    virtual ~Image();
};

class RealImage : public Image {
public:
    RealImage(const string filePath) {
        cout<<"Load Image:"<<filePath<<endl;
    }
    void renderImage() override final {
        cout<<"Render real image"<<endl;
    }
};

class ProxyImage : public Image {
public:
    ProxyImage(string filePath):realImage(nullptr) {
        this->filePath = filePath;
    }
    ~ProxyImage() override {
        if(realImage != nullptr)
            delete realImage;
    }
    void renderImage() override final {
        if(realImage == nullptr) {
            realImage = new RealImage(filePath);
        }
        realImage->renderImage();
    }
    
private:
    Image* realImage;
    string filePath;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ProxyImage* proxyImage = new ProxyImage("/web/image/test.png");
    proxyImage->renderImage();
    
    delete proxyImage;
    return 0;
}
