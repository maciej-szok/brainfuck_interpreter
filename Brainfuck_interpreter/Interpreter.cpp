#include "Interpreter.h"
#include <iostream>
#include <algorithm> 
#include "CONFIG.h"

Interpreter::Interpreter()
{
	memoryPointer = 0;
	instructionPointer = 0;
	running = true;
	memory.push_back(0);
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

void Interpreter::getInput()
{
	int temp;
	std::cin >> temp;
	if (temp > 255) temp = 255;
	if (temp < 0) temp = 0;
	memory[memoryPointer] = temp;
}


bool Interpreter::isValidInstruction(const char instuction)
{
	if (instuction == BRAINFUCK_INCREMENT_POINTER || instuction == BRAINFUCK_DECREMENT_POINTER ||
		instuction == BRAINFUCK_INCREMENT_MEMORY || instuction == BRAINFUCK_DECREMENT_MEMORY
		|| instuction == BRAINFUCK_LEFT_PARENTHESES || instuction == BRAINFUCK_RIGHT_PARENTHESES
		|| instuction == BRAINFUCK_OUTPUT || instuction == BRAINFUCK_INPUT) return true;

	return false;
}



void Interpreter::updateInstructionPointer()
{
	char currentCommand = this->getCurrentCommand();
	if (currentCommand != BRAINFUCK_LEFT_PARENTHESES && currentCommand != BRAINFUCK_RIGHT_PARENTHESES) {
		instructionPointer++;
	}
	else {
		//when entountering left parentheses i push its index to stack
		//when entountering the right one, if current memory is != 0
		//i peek the stack and go to that adress
		//when current memory is == 0 when i pop from stack
		if (currentCommand == BRAINFUCK_LEFT_PARENTHESES) {
			instructionPointer++;
			parenthesesStack.push(instructionPointer);
			
		}else if (currentCommand == BRAINFUCK_RIGHT_PARENTHESES) {
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
		if (!this->isValidInstruction(currentCommand)) continue;
		
		if (currentCommand == BRAINFUCK_OUTPUT) this->output();
		if (currentCommand == BRAINFUCK_INPUT) this->getInput();

		if (currentCommand == BRAINFUCK_INCREMENT_POINTER) this->incrementMemoryPointer();
		if (currentCommand == BRAINFUCK_DECREMENT_POINTER) this->decrementMemoryPointer();

		if (currentCommand == BRAINFUCK_INCREMENT_MEMORY) this->incrementMemory();
		if (currentCommand == BRAINFUCK_DECREMENT_MEMORY) this->decrementMemory();

		this->updateInstructionPointer();
	}
}
