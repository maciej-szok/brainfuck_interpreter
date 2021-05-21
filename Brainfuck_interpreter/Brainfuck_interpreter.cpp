#include <iostream>
#include "Interpreter.h"
#include <string>

int main()
{

    std::string command = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";

    Interpreter in;
    in.setProgramm(command);

    in.interpret();

}

