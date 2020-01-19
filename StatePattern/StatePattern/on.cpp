//
//  on.cpp
//  StatePattern
//
//  Created by daeyong Lee on 2020/01/01.
//  Copyright © 2020 daeyong Lee. All rights reserved.
//

#include <stdio.h>
#include "on.h"
#include "lightcontext.h"
#include "off.h"

using namespace std;

void OnState::OnPushedHandle(LightContext* lightContext) {
    cout<<"Already On"<<endl;
}
    
void OnState::OffPushedHandle(LightContext* lightContext) {
    cout<<"Turn Off the light"<<endl;
    lightContext->chageState(OffState::getInstance());
}
