#include <iostream>
#include "Interpreter.h"
#include <string>
#include <fstream>


int main(int argc, char* argv[])
{
    int counter;
    
    //printf("Program Name Is: %s", argv[0]);
    //if (argc == 1)
    //    printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
    //if (argc >= 2)
    //{
    //    printf("\nNumber Of Arguments Passed: %d", argc);
    //    printf("\n----Following Are The Command Line Arguments Passed----");
    //    for (counter = 0; counter < argc; counter++)
    //        printf("\nargv[%d]: %s", counter, argv[counter]);
    //}
    //return 0;
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

//    std::cin.get();

}

