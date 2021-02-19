#pragma once
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Calculator
{
public:
	Calculator(string in);

	string ToPostfix();
	float  getResult();

private:
	string input;
	string output;

	stack<char>  operands;
	stack<float> numbers;

	void setPreor(char thisEl, int preor);
	void gotBracket(char thisEl);

	void printStack();
};