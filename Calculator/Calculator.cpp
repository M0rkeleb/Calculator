// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

typedef int(*arithmeticFcn)(int, int);

struct arithmeticStruct
{
	char arithFcnShort;
	arithmeticFcn arithFcnName;
};

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}

static const int g_numFunctions = 4;
static const arithmeticStruct arithmeticArray[] = { { '+',add },
													{'-',subtract},
													{'*',multiply},
													{'/',divide} };

arithmeticFcn getArithmeticFunction(char oper)
{
	for (int i = 0; i < g_numFunctions; i++)
	{
		if (oper == arithmeticArray[i].arithFcnShort) return arithmeticArray[i].arithFcnName;
	}
}

int main()
{
	int a, b;
	char oper;
	std::cout << "Enter an integer, an operator (+,-,*,/), and another integer, and I will tell you the result." << std::endl;
	std::cin >> a;
	std::cin >> oper;
	std::cin >> b;
	if (oper != '+' && oper != '-' && oper != '*' && oper != '/')
	{
		std::cout << "Bad operator. You fail!" << std::endl;
		return 0;
	}
	if (oper == '/' && b == 0)
	{
		std::cout << "Cannot divide by 0. You fail!" << std::endl;
		return 0;
	}
	std::cout << "Input looks good, will calculate now." << std::endl;
	arithmeticFcn calcOper = getArithmeticFunction(oper);
	std::cout << calcOper(a, b) << std::endl;
    return 0;
}

