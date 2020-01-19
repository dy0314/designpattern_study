//
//  lightcontext.cpp
//  StatePattern
//
//  Created by daeyong Lee on 2020/01/01.
//  Copyright © 2020 daeyong Lee. All rights reserved.
//

#include <stdio.h>
#include "state.h"
#include "lightcontext.h"
#include <iostream>
#include "off.h"
using namespace std;

LightContext::LightContext() {
    currentState = OffState::getInstance();
}
void LightContext::chageState(State* newState) {
    currentState = newState;
}
void LightContext::onPushedRequest() {
    currentState->OnPushedHandle(this);
}
void LightContext::offPushedRequest() {
    currentState->OffPushedHandle(this);
}
