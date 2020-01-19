//
//  main.cpp
//  StatePattern
//
//  Created by daeyong Lee on 2020/01/01.
//  Copyright © 2020 daeyong Lee. All rights reserved.
//

#include <iostream>
#include "state.h"
#include "off.h"
#include "on.h"
#include "lightcontext.h"

using namespace std;

int main(int argc, const char * argv[]) {
    LightContext* light = new LightContext();
    light->onPushedRequest();
    light->onPushedRequest();
    
    light->offPushedRequest();
    light->offPushedRequest();
    
    return 0;
}
