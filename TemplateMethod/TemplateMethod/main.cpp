//
//  main.cpp
//  TemplateMethod
//
//  Created by daeyong Lee on 01/08/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
using namespace std;

class FileViewer {
public:
    void viewFile() { //템플릿 메소드 역할을 하는 함수
        open();
        view();
        saveLog();
        hookFunc();
        
    }
protected:
    virtual void open() = 0;
    virtual void view() = 0;
    virtual void saveLog() = 0;
    virtual void hookFunc() {} //hook 함수는 구현하지 않고 빈상태로 둔다.
};

class DocFileViewer : public FileViewer {
protected:
    virtual void open() {
        cout<<"open Doc File"<<endl;
    }
    virtual void view() {
        cout<<"View Doc File"<<endl;
    }
    virtual void saveLog() {
        cout<<"Save Doc File view log"<<endl;
    }
    virtual void hookFunc() {
        cout<<"Doc hookFunc"<<endl;
    }
};

class TextFileViewer : public FileViewer {
protected:
    virtual void open() {
        cout<<"open Text File"<<endl;
    }
    virtual void view() {
        cout<<"View Text File"<<endl;
    }
    virtual void saveLog() {
        cout<<"Save Text File view log"<<endl;
    }
};

int main(int argc, const char * argv[]) {
    FileViewer* fileViewer = new DocFileViewer();
    fileViewer->viewFile();
    
    delete fileViewer;
    cout<<""<<endl;
    
    fileViewer = new TextFileViewer();
    fileViewer->viewFile();
    
    return 0;
}
