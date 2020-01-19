//
//  DocFileFactory.h
//  FactoryMethod
//
//  Created by daeyong Lee on 06/02/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#ifndef DocFileFactory_h
#define DocFileFactory_h
#include <iostream>
#include "BaseFileFactory.h"
#include "DocFile.h"
using namespace std;

class DocFileFactory : public BaseFileFactory {
    
private:
    virtual void GetDataFromDB() {
        cout<<"Doc file GetDataFromDB"<<endl;
    }
    virtual BaseFile* CreateNewFile() {
        cout<<"Doc file CreateNewFile"<<endl;
        return new DocFile();
    }
    virtual void SaveLog() {
        cout<<"Doc file SaveLog"<<endl;
    }
};

#endif /* DocFileFactory_h */
