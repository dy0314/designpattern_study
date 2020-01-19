//
//  BaseFile.h
//  FactoryMethod
//
//  Created by daeyong Lee on 06/02/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#ifndef BaseFile_h
#define BaseFile_h

class BaseFile {
public:
    virtual void Use() = 0;
    virtual ~BaseFile(){}
};
#endif /* BaseFile_h */
