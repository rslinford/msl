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
    static bool isOpener(const string& s);
    static bool isCloser(const string& s);
    static int lookUpPrecedence(const string& o);
    static bool compareOps(const string& o1, const string& o2);
    static string stackToString(const stack<string>& os);
    static int stringToInt(string s);
    static string stackToString(const stack<int>& os);
        
public:
	ExpressionManager() {}
	virtual ~ExpressionManager() {}

	virtual bool isBalanced(string expression);
	virtual string postfixToInfix(string postfixExpression);
	virtual string infixToPostfix(string infixExpression);
	virtual string postfixEvaluate(string postfixExpression);
};
