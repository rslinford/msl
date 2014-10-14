#pragma once
#include "ExpressionManagerInterface.h"
#include <string>
using namespace std;

class ExpressionManager : public ExpressionManagerInterface
{
private:
	static bool isNumber(const string& s);
	static bool isOperator(const string& s);
    static bool ratio(const string& expression);
    static bool brackets(const string& expression);
    static bool isMatchyMigrainSymbol(const string& s);
    
public:
	ExpressionManager() {}
	virtual ~ExpressionManager() {}

	virtual bool isBalanced(string expression);
	virtual string postfixToInfix(string postfixExpression);
	virtual string infixToPostfix(string infixExpression);
	virtual string postfixEvaluate(string postfixExpression);
};
