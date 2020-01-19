//
//  main.cpp
//  FacadePattern
//
//  Created by daeyong Lee on 2019/10/27.
//  Copyright © 2019 daeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Parser {
public:
    Parser(string sourceCode) {
        cout<<"Parsing sourcecode"<<endl;
    }
};

class AssemblyGenerator {
public:
    AssemblyGenerator(string parsedCode) {
        cout<<"Assembly generated"<<endl;
    }
};

class Compiler { //Facade
public:
    Compiler(string sourceCode) {
        Parser codeParser(sourceCode);
        AssemblyGenerator assemblyGenerartor(sourceCode);
    }
};


int main(int argc, const char * argv[]) {
    string code ="blahblah";
    Compiler* compiler = new Compiler(code);
    
    return 0;
}
