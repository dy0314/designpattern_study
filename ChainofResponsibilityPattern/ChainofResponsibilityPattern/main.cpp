//
//  main.cpp
//  ChainofResponsibilityPattern
//
//  Created by daeyong Lee on 2019/12/15.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class AuthRequest {
public:
    AuthRequest(string id, string token) : id(id), token(token)
    {}
    virtual ~AuthRequest() {}
    string getId() {return id;}
    string getToken() {return token;}
private:
    string id;
    string token;
};

class AuthHandler {
public:
    void setNextAuthHandler(AuthHandler* authHandler) {
        this->nextAuthHandler = authHandler;
    }
    
    virtual bool handleRequest(AuthRequest* authRequest) = 0;
protected:
    AuthHandler* nextAuthHandler;
};

class IDAuthHandler : public AuthHandler {
public:
    virtual bool handleRequest(AuthRequest* authRequest) override {
        if(checkIDAuth(authRequest->getId())) {
            cout<<"ID authentication succeed"<<endl;
            if(nextAuthHandler != nullptr)
                return nextAuthHandler->handleRequest(authRequest);
            else
                return true;
        }
        else
            return false;
    }
private:
    bool checkIDAuth(string id) {
        return true;
    }
};

class TokenAuthHandler : public AuthHandler {
public:
    virtual bool handleRequest(AuthRequest* authRequest) override {
        if(checkTokenAuth(authRequest->getToken())) {
            cout<<"Token authentication succeed"<<endl;
            if(nextAuthHandler != nullptr)
                return nextAuthHandler->handleRequest(authRequest);
            else
                return true;
        }
        else
            return false;
    }
private:
    bool checkTokenAuth(string id) {
        return true;
    }

};

int main(int argc, const char * argv[]) {
    AuthRequest* authRequest = new AuthRequest("testID", "testToken");
    
    IDAuthHandler* idAuthHandler = new IDAuthHandler();
    TokenAuthHandler* tokenAuthHandler = new TokenAuthHandler();
    
    idAuthHandler->setNextAuthHandler(tokenAuthHandler);
    idAuthHandler->handleRequest(authRequest);
    
    delete authRequest;
    delete tokenAuthHandler;
    delete idAuthHandler;
    
    return 0;
}


