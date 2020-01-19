//
//  main.cpp
//  FactoryMethod
//
//  Created by daeyong Lee on 13/01/2019.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
#include "BaseFileFactory.h"
#include "DocFileFactory.h"
#include "HwpFileFactory.h"

#include "HwpFile.h"
#include "BaseFile.h"

int main(int argc, const char * argv[]) {
    
    BaseFileFactory* factory = new DocFileFactory();
    BaseFile* file = factory->CreateFile();
    file->Use();
    
    delete factory;
    delete file;
    
    factory = new HwpFileFactory();
    file = factory->CreateFile();
    file->Use();
    
    return 0;
}
