#include "Interpreter.h"
#include <iostream>
#include <algorithm> 


Interpreter::Interpreter()
{
	memoryPointer = 0;
	memory.resize(1);
	std::fill(memory.begin(), memory.end(), 0);
}


void Interpreter::output()
{
	std::cout << (char)memory[memoryPointer];
}

void Interpreter::incrementMemoryPointer()
{
	memoryPointer++;
	if (memory.size() <= memoryPointer)
		memory.push_back(0);

	//TODO implement exception if not enough memory
}

void Interpreter::decrementMemoryPointer()
{
	memoryPointer--;
	//TODO implement exception if memoryPointer is smaller then 0
}

void Interpreter::incrementMemory()
{
	memory[memoryPointer]++;
	if (memory[memoryPointer] > 255) {
		memory[memoryPointer] = 0;
	}
}

void Interpreter::decrementMemory()
{
	memory[memoryPointer]++;
	if (memory[memoryPointer] < 0) {
		memory[memoryPointer] = 255;
	}
}


void Interpreter::interpret(std::string command)
{
	bool running = true;

	int commandPointer = 0;
	while (running) {
		char currentCommand = command[commandPointer];

		if (currentCommand == '\0') running = false;
		
		if (currentCommand == '.') this->output();

		if (currentCommand == '>') this->incrementMemoryPointer();

		if (currentCommand == '<') this->decrementMemoryPointer();

		if (currentCommand == '+') this->incrementMemory();

		if (currentCommand == '<') this->decrementMemory();

		commandPointer++;
	}
}
