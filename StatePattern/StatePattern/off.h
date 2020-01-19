//
//  off.h
//  StatePattern
//
//  Created by daeyong Lee on 2020/01/01.
//  Copyright © 2020 daeyong Lee. All rights reserved.
//

#ifndef off_h
#define off_h
#include <iostream>
#include "state.h"

using namespace std;
class LightContext;

class OffState : public State {
public:
    static State* getInstance() {
        static OffState offState;
        return &offState;
    }
    virtual void OnPushedHandle(LightContext* lightContext) override;
    virtual void OffPushedHandle(LightContext* lightContext) override;
};


#endif /* off_h */
