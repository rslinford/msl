#pragma once
#include "ExpressionManagerInterface.h"
#include <string>
using namespace std;

class ExpressionManager : public ExpressionManagerInterface
{
private:

public:
	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);
};
