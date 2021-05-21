#pragma once
#include <string>
#include <vector>

class Interpreter {
private:
	std::vector<int> memory;
	int memoryPointer;

	void output();
	void incrementMemoryPointer();
	void decrementMemoryPointer();
	void incrementMemory();
	void decrementMemory();
public:
	
	Interpreter();


	void interpret(std::string command);

};