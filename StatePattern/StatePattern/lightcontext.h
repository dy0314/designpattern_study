//
//  lightcontext.h
//  StatePattern
//
//  Created by daeyong Lee on 2020/01/01.
//  Copyright © 2020 daeyong Lee. All rights reserved.
//

#ifndef lightcontext_h
#define lightcontext_h

#include <iostream>
class State;

using namespace std;

class LightContext {
public:
    LightContext();
    void chageState(State* newState);
    void onPushedRequest();
    void offPushedRequest();
private:
    State* currentState;
};

#endif /* lightcontext_h */
