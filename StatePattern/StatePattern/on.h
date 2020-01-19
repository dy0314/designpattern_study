//
//  on.h
//  StatePattern
//
//  Created by daeyong Lee on 2020/01/01.
//  Copyright © 2020 daeyong Lee. All rights reserved.
//

#ifndef on_h
#define on_h
#include <iostream>
#include "state.h"
#include "lightcontext.h"
#include "off.h"

using namespace std;

class OnState : public State {
public:
    static State* getInstance() {
        static OnState onState;
        return &onState;
    }
    virtual void OnPushedHandle(LightContext* lightContext);
    virtual void OffPushedHandle(LightContext* lightContext);
};

#endif /* on_h */
