#include "Interpreter.h"
#include <iostream>
#include <algorithm> 


Interpreter::Interpreter()
{
	memoryPointer = 0;
	instructionPointer = 0;
	running = true;
	memory.push_back(0);
	//memory.resize(1);
	//std::fill(memory.begin(), memory.end(), 0);
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
	memory[memoryPointer]--;
	if (memory[memoryPointer] < 0) {
		memory[memoryPointer] = 255;
	}
}

char Interpreter::getCurrentCommand()
{
	if (instructionSet.length() == 0) {
		running = false;
		return '\0';
	}
	return instructionSet[instructionPointer];
}



void Interpreter::updateInstructionPointer()
{
	char currentCommand = this->getCurrentCommand();
	if (currentCommand != '[' && currentCommand != ']') {
		instructionPointer++;
	}
	else {
		//when entountering left parentheses i push its index to stack
		//when entountering the right one, if current memory is != 0
		//i peek the stack and go to that adress
		//when current memory is == 0 when i pop from stack
		if (currentCommand == '[') {
			instructionPointer++;
			parenthesesStack.push(instructionPointer);
			
		}else if (currentCommand == ']') {
			if (memory[memoryPointer] != 0) {
				instructionPointer = parenthesesStack.top();
			}
			else {
				parenthesesStack.pop();
				instructionPointer++;
			}
		}

	}
}


void Interpreter::setProgramm(std::string programm)
{
	this->instructionSet = programm;
}

void Interpreter::interpret()
{
	
	while (running) {
		char currentCommand = this->getCurrentCommand();

		if (currentCommand == '\0') running = false;
		
		if (currentCommand == '.') this->output();

		if (currentCommand == '>') this->incrementMemoryPointer();

		if (currentCommand == '<') this->decrementMemoryPointer();

		if (currentCommand == '+') this->incrementMemory();

		if (currentCommand == '-') this->decrementMemory();
		
		//if (currentCommand == '[') this->decrementMemory();
		//
		//if (currentCommand == ']') this->decrementMemory();

		this->updateInstructionPointer();
	}
}
