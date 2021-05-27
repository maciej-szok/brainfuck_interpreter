#include <iostream>
#include "Interpreter.h"
#include <string>
#include <fstream>


int main(int argc, char* argv[])
{
    
    std::string command = "";

    std::string line;
    std::ifstream myfile(argv[1]);
    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            //std::cout << line << '\n';
            command += line;
        }
        myfile.close();
    }
    else {
        std::cout << "Couldn't open the file.";
        return 1;
    }
    
    //this is hello world
    //std::string command = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
    Interpreter in;
    in.setProgramm(command);

    in.interpret();

}

