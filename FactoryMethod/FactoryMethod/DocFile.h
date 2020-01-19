//
//  DocFile.h
//  FactoryMethod
//
//  Created by daeyong Lee on 06/02/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#ifndef DocFile_h
#define DocFile_h
#include "BaseFile.h"
using namespace std;

class DocFile : public BaseFile  {
public:
    virtual void Use() {
        cout<<"Use DocFile"<<endl;
    }
};

#endif /* DocFile_h */
