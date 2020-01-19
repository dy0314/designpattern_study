//
//  state.h
//  StatePattern
//
//  Created by daeyong Lee on 2020/01/01.
//  Copyright © 2020 daeyong Lee. All rights reserved.
//

#ifndef state_h
#define state_h
class LightContext;

class State {
public:
    virtual ~State(){}
    virtual void OnPushedHandle(LightContext* lightContext) = 0;
    virtual void OffPushedHandle(LightContext* lightContext) = 0;
};

#endif /* state_h */
