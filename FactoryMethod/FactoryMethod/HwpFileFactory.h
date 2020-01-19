//
//  HwpFileFactory.h
//  FactoryMethod
//
//  Created by daeyong Lee on 06/02/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#ifndef HwpFileFactory_h
#define HwpFileFactory_h

#include <iostream>
#include "BaseFileFactory.h"
#include "HwpFile.h"

using namespace std;

class HwpFileFactory : public BaseFileFactory {
    
private:
    virtual void GetDataFromDB() {
        cout<<"Hwp file GetDataFromDB"<<endl;
    }
    virtual BaseFile* CreateNewFile() {
        cout<<"Hwp file CreateNewFile"<<endl;
        return new DocFile();
    }
    virtual void SaveLog() {
        cout<<"Hwp file SaveLog"<<endl;
    }
};
#endif /* HwpFileFactory_h */
