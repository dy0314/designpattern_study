//
//  BaseFileFactory.h
//  FactoryMethod
//
//  Created by daeyong Lee on 06/02/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#ifndef BaseFileFactory_h
#define BaseFileFactory_h
using namespace std;

class BaseFile;

class BaseFileFactory {
public:
    BaseFile* CreateFile() {//factory method
        GetDataFromDB();
        BaseFile* baseFile = CreateNewFile();
        SaveLog();
        
        return baseFile;
    }
    virtual ~BaseFileFactory() {
        
    }
private:
    virtual void GetDataFromDB() = 0;
    virtual BaseFile* CreateNewFile() = 0;
    virtual void SaveLog() = 0;
};



#endif /* BaseFileFactory_h */
