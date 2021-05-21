#pragma once
#include <string>
#include <vector>
#include <stack>

class Interpreter {
private:
	std::vector<int> memory;
	std::stack<int> parenthesesStack;
	int memoryPointer;
	bool running;

	std::string instructionSet;
	size_t instructionPointer;

	void output();
	void incrementMemoryPointer();
	void decrementMemoryPointer();
	void incrementMemory();
	void decrementMemory();
	void getInput();

	bool isValidInstruction(const char instuction);

	char getCurrentCommand();
	void updateInstructionPointer();

public:	
	Interpreter();

	void setProgramm(std::string command);
	void interpret();

};