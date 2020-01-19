//
//  HwpFile.h
//  FactoryMethod
//
//  Created by daeyong Lee on 06/02/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#ifndef HwpFile_h
#define HwpFile_h
#include <iostream>

using namespace std;

class HwpFile : public BaseFile  {
public:
    virtual void Use() {
        cout<<"Use HwpFile"<<endl;
    }
};

#endif /* HwpFile_h */
