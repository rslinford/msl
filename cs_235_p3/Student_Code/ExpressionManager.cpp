#pragma once
#include "ExpressionManager.h"
#include <string>
#include <stack>
#include <iostream>
#include <sstream>
using namespace std;

/* TEST CASES TO WATCH FOR
1. any other chars in the expressions other than numbers, ({[]}), "/+-*%" are bad -> reject and inform the user
2. strings for numbers like "a2" for a number
3. Not spaces in between every char in the expressions like 2 *( 2 + 5 -3)*()
4. In infix two operators together
5. In postfix expressions in the wrong places
6. Handle divide by zero attempts
*/


bool ExpressionManager::isNumber(const string& s)
{
	if (s.empty() || (s[0] < '0' || s[0] > '9') && ((s.size() < 2) || (s[0] != '-' || s[0] != '+'))) {
		return false;
	}

	if (s.size() == 1) {
		return true;
	}

	for (int i = 1; i < s.size(); i++) {
		if (s[i] < '0' || s[i] > '9') {
			return false;
		}
	}

	return true;
}

// True if one of +, -, *, /, and %
bool ExpressionManager::isOperator(const string& s)
{
	// Assume all operators are a single char.
	if (s.size() != 1) {
		return false;
	}

	char c = s[0];

	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

// True if one of {, }, (, ), [, and ] 
bool ExpressionManager::isMatchyMigrainSymbol(const string& s)
{
	// Assume all migrain inducing symbols are a single char.
	if (s.size() != 1) {
		return false;
	}

	char c = s[0];

	return c == '{' || c == '}' || c == '(' || c == ')' || c == '[' || c == ']';
}


bool ExpressionManager::ratio(const string& expression)// numbers (operands) to operators
{
	stack<string> numbers;
	stack<char> operators;
	stack<char> matchyMigrainSymbols;

	string s;
	stringstream ss(expression);
	while (getline(ss, s, ' '))
		//for (int i = 0; i < expression.size(); i++)
	{
		if (isNumber(s))
		{
			numbers.push(s);
		}
		else if (isOperator(s))
		{
			operators.push(s[0]);
		}
		else if (isMatchyMigrainSymbol(s))
		{
			matchyMigrainSymbols.push(s[0]);
		}
		else {
			// TODO: error, bad character in expression
		}
	}

	if (operators.size() + 1 != numbers.size())
	{
		return false;
	}

	return true;
}

/*   DONT FOCUS ON THIS YET
int presidence()
{
return 0;
}
*/

bool ExpressionManager::brackets(const string& expression)
{
	stack<string> braketThings;
	string s;
	stringstream ss(expression);
	while (getline(ss, s, ' '))
	{
		if (s.empty())
		{
			return false;
		}
		else if (s == "{" || s == "(" || s == "[")
		{
			braketThings.push(s);
		}
		else if (s == "}" || s == ")" || s == "]")
		{
			if (braketThings.empty())
			{
				return false;
			}
			else if (s == "}" && braketThings.top() != "{")
			{
				return false;
			}
			else if (s == "]" && braketThings.top() != "[")
			{
				return false;
			}
			else if (s == ")" && braketThings.top() != "(")
			{
				return false;
			}
			else
			{
				braketThings.pop();
			}
		}
	}
	if (braketThings.empty())
	{
		return true;
	}
	return false;
}


bool ExpressionManager::isBalanced(string expression)
{
	return brackets(expression);
}



/**
* Converts a postfix expression into an infix expression
* and returns the infix expression.
*
* - The given postfix expression will have a space between every number or operator.
* - The returned infix expression must have a space between every number or operator.
* - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
* - Check lab requirements for what will be considered invalid.
*
* return the string "invalid" if postfixExpression is not a valid postfix expression.
* otherwise, return the correct infix expression as a string.
*/
string ExpressionManager::postfixToInfix(string postfixExpression)
{
	// Example input
	//
	//    5 1 2 + 4 × + 3 −

	stack<string> conversion;
	string s;
	string infix;
	stringstream ss(postfixExpression);
	while (getline(ss, s, ' '))
	{
	    if(!isNumber(s) && !isOperator(s)) //bad character
        {
    	    return "invalid";        
        }
        else if(isNumber(s))
        {
            conversion.push(s);
        }
        else if (isOperator(s))
        {
            if(conversion.size() < 2)
            {
                return "invalid";
            }
            string rh = conversion.top();
            conversion.pop();
            string lh = conversion.top();
            conversion.pop();
         
            if(s == "+")
            {
               conversion.push("( " + lh + " + " + rh + " )");
            }
            else if(s == "-")
            {
               conversion.push("( " + lh + " - " + rh + " )");
            }
            else if (s == "*")
            {
               conversion.push("( " + lh + " * " + rh + " )");
            }
            else if (s == "/")
            {
                conversion.push("( " + lh + " / " + rh + " )");
            }
            else if (s == "%")
            {
                conversion.push("( " + lh + " % " + rh + " )");
            }
        }
	}
	
	if (conversion.empty()) {
		return "invalid";
	}
	
	infix = conversion.top();
	conversion.pop();
	
	if(conversion.size()>0)
	{
	    return "invalid";
	}
	return infix;
}

int ExpressionManager::lookUpPrecedence(const string& o) {
	if (o == "*" || o == "/" || o == "%") {
		return 3;
	}
	
	if (o == "+" || o == "-") {
		return 2;
	}
	
	if (isCloser(o)) {
		return -1;
	}
	
	if (isOpener(o)) {
		return -2;
	}
	
	return -100;
}

bool ExpressionManager::compareOps(const string& o1, const string& o2) {
	int p1 = lookUpPrecedence(o1);
	int p2 = lookUpPrecedence(o2);
	
	return p1 <= p2;
}

bool ExpressionManager::isOpener(const string& s) {
	return s == "(" || s == "{" || s == "[";
}

bool ExpressionManager::isCloser(const string& s) {
	return s == ")" || s == "}" || s == "]";
}

string ExpressionManager::stackToString(const stack<string>& os) {
	stack<string> dump = os;
	string s;
	while (!dump.empty()) {
		s += dump.top();
		dump.pop();
	}
	return s;
}

string ExpressionManager::stackToString(const stack<int>& os) {
	stack<int> dump = os;
	string s;
	while (!dump.empty()) {
		stringstream x;
		x << dump.top();
		string y;
		x >> y;
		s = s + " " + y;
		dump.pop();
	}
	return s;
}

/*
* Converts an infix expression into a postfix expression
* and returns the postfix expression
*
* - The given infix expression will have a space between every number or operator.
* - The returned postfix expression must have a space between every number or operator.
* - Check lab requirements for what will be considered invalid.
*
* return the string "invalid" if infixExpression is not a valid infix expression.
* otherwise, return the correct postfix expression as a string.
*/
string ExpressionManager::infixToPostfix(string infixExpression)
{
	//  Example input
	//  40 * ( 2 + 4 - ( 2 + 2 ) ) - 4 / 5 / 6
	//
	//  ( 40 * ( 2 + 4 - ( 2 + 2 ) ) ) - ( ( 4 / 5 ) / 6 )
	//
	//  Expected result
    //  40 2 4 + 2 2 + - * 4 5 / 6 / -
    
 //   cout << endl << "Infix to Postfix. Starting infix:" << endl;
  //  cout << "   '" << infixExpression << "'" << endl;

	if(!ratio(infixExpression))
	{
//		cout << "congrats you are ratio" << endl;
		return "invalid";
	}
	if(!brackets(infixExpression))
	{
	//	cout << "congrats you are brackets()" << endl;
		return "invalid";
	}
    stack<string> conversion;
	string s;
	string postfix = "";
	stringstream ss(infixExpression);
	while (getline(ss, s, ' '))
	{
	//	cout << endl << "Token '" << s << "'   Postfix '" << postfix << "'   Stack '" << stackToString(conversion) << "'" << endl;
		if(isNumber(s))
		{
			postfix = postfix + " " + s;
			continue;
		}
		
		if(isOpener(s))		
		{
			conversion.push(s);
			continue;
		}
		
		if(isOperator(s))
		{
			while ( (!conversion.empty()) && compareOps(s, conversion.top()) ) {
				postfix = postfix + " " + conversion.top();
				conversion.pop();
			}
			
    		conversion.push(s);
		}

		if(isCloser(s)) 
		{
			while ( (!conversion.empty()) && (!isOpener(conversion.top())) ) {
				postfix = postfix + " " + conversion.top();
				conversion.pop();
			}
			if( conversion.empty() || !isOpener(conversion.top()) )
			{
				return "invalid";
			}
			conversion.pop();
		}
	}
	
	while (!conversion.empty()) {
		postfix += " " + conversion.top();
		conversion.pop();
	}
	
	// trim leading space(s)
	postfix.erase(0, postfix.find_first_not_of(' '));
//	cout << endl << "Returning postfix expression '" << postfix << "'" << endl;

	return postfix;
}

int ExpressionManager::stringToInt(string s) {
	int i = 0;
	stringstream ss;
	ss.str("");
	ss.str(s);
	ss >> i;
	
	return i;
}

/*
* Evaluates a postfix expression returns the result as a string
*
* - The given postfix expression will have a space between every number or operator.
* - Check lab requirements for what will be considered invalid.
*
* return the string "invalid" if postfixExpression is not a valid postfix Expression
* otherwise, return the correct evaluation as a string
*/
string ExpressionManager::postfixEvaluate(string postfixExpression)
{
 //   cout << endl << "Postfix Eval. Expression:" << endl;
 //   cout << "   '" << postfixExpression << "'" << endl;
    
	// Example input
	//
	//   40 2 4 + 1 1 + - * 4 2 / 1 / - 7 %
	//
	//   2 4 + 1 1 + - * 4 2 / 1 / - 7 %       40
	//
	//   4 + 1 1 + - * 4 2 / 1 / - 7 %       2 40
	//
	//   + 1 1 + - * 4 2 / 1 / - 7 %       4 2 40
	//
	//   1 1 + - * 4 2 / 1 / - 7 %           6 40
	//
	//   1 + - * 4 2 / 1 / - 7 %           1 6 40
	//
	//   + - * 4 2 / 1 / - 7 %           1 1 6 40
	//
	//   - * 4 2 / 1 / - 7 %               2 6 40
	//
	//   * 4 2 / 1 / - 7 %                   8 40
	//
	//   4 2 / 1 / - 7 %                      320
	//
	//   2 / 1 / - 7 %                      4 320
	//
	//   / 1 / - 7 %                      2 4 320
	//
	//   1 / - 7 %                          2 320
	//
	//   / - 7 %                          1 2 320
	//
	//   - 7 %                              2 320
	//
	//   7 %                                  318
	//
	//   %                                  7 318
	//
	//   %                                  7 318
	//
	//                                          3

    stack<int> numbers;
	string s;
	stringstream ss(postfixExpression);
	while (getline(ss, s, ' '))
	{
		if(isMatchyMigrainSymbol(s))
		{
			return "invalid";
		}
	//	cout << endl << "Token '" << s << "'   Stack '" << stackToString(numbers) << "'" << endl;
		
		if (s.empty())
		{
			return "invalid";
		}

		if(isNumber(s))
		{
			numbers.push(stringToInt(s));
			continue;
		}
		
		if(isOperator(s))
		{
			if(numbers.size()<2)
			{
				return "invalid";
			}
			
			int rh = numbers.top();
			numbers.pop();
			int lh = numbers.top();
			numbers.pop();
			
			if(s == "+")
            {
                numbers.push(lh + rh); 
            }
            else if(s == "-")
            {
                numbers.push(lh - rh); 
            }
            else if (s == "*")
            {
                numbers.push(lh * rh); 
            }
            else if (s == "/")
            {
            	if(rh == 0)
            	{
            		return "invalid";
            	}
                numbers.push(lh / rh); 
            }
            else if (s == "%")
            {
            	if(rh == 0)
            	{
            		return "invalid";
            	}
                numbers.push(lh % rh); 
            }
		}
	}
	
	
	if(numbers.empty())
	{
		return "invalid";
	}
	
	int total = numbers.top();
	numbers.pop();
	
	if(numbers.size()>0)
	{
	    return "invalid";
	}
	
	cout << "Returning total: " << total << endl;
   		stringstream x;
		x << total;
		string y;
		x >> y;
	return y;
}
