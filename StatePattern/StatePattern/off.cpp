//
//  off.cpp
//  StatePattern
//
//  Created by daeyong Lee on 2020/01/01.
//  Copyright © 2020 daeyong Lee. All rights reserved.
//

#include <stdio.h>
#include "off.h"
#include "lightcontext.h"
#include "on.h"

using namespace std;
void OffState::OnPushedHandle(LightContext* lightContext) {
    cout<<"Turn On the light"<<endl;
    lightContext->chageState(OnState::getInstance());
}

void OffState::OffPushedHandle(LightContext* lightContext) {
    cout<<"Already Off"<<endl;
}
