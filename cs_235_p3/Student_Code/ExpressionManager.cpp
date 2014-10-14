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


/*
* Checks whether an expression is balanced on its parentheses
*
* - The given expression will have a space between every number or operator
*
* @return true if expression is balanced
* @return false otherwise
*/

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
	//  Expected result
    //  40 2 4 + 2 2 + - * 4 5 / 6 / -

	if(!ratio(infixExpression))
	{
		cout << "congrats you are ratio" << endl;
		return "invalid";
	}
	if(!brackets(infixExpression))
	{
		cout << "congrats you are brackets()" << endl;
		return "invalid";
	}
    stack<string> conversion;
	string s;
	string l1;
	string l2;
	string lh;
	string opp;
	string postfix;
	stringstream ss(infixExpression);
	while (getline(ss, s, ' '))
	{
	    if(!isNumber(s) && !isOperator(s) && !isMatchyMigrainSymbol(s)) //bad character
        {
        	cout << "congrats you are !num or !opp or !brace" << endl;
    	    return "invalid";        
        }
        else if(isNumber(s))
        {
        	if(conversion.empty())
        	{
        		conversion.push(s);
        	}
        	else if(isOperator(conversion.top()))
        	{
            	opp = conversion.top();
            	conversion.pop();
            	lh = conversion.top();
            	conversion.pop();	
            	conversion.push(lh + " " + s + " " + opp);
        	}
        }
        else if (isOperator(s))
        {
        	conversion.push(s);
        }
        else if(s == "(" || s == "{" || s == "[")
        {
        	conversion.push(s);
        }
        else if(s == ")" || s == "}" || s == "]")
        {
        	l1 = conversion.top();
        	conversion.pop();
        	if(l1 == "(" || l1 == "{" || l1 == "[")
			{
				
			}
       		l2 = conversion.top();
       		conversion.pop();
       		cout << "npos is our problem" << endl;
			if(l2.find(' ') == -1)
			{
				return false;
			}
			cout << "npos is not our problem" << endl;
			
        }
	}
	
	if (conversion.empty()) 
	{
		cout << "congrats you are empty" << endl;
		return "invalid";
	}
	
	postfix = conversion.top();
	conversion.pop();
	
	if(conversion.size()>0)
	{
		cout << "congrats you are greater than 0 postfix: " << postfix << " top thing: " << conversion.top() << endl;
		cout << "Dumping stack:" << endl;
		while (!conversion.empty()) {
			cout << "  '" << conversion.top() << "'" << endl;
			conversion.pop();
		}
	    return "invalid";
	}
	return postfix;
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
    
    /*
                if(s == "+")
            {
                int sum = first + last; // conversion from string to int needed
                conversion.push(sum); // conversion from int to string needed
            }
            else if(s == "-")
            {
                int sub = first - last; // conversion from string to int needed
                conversion.push(sub); // conversion from int to string needed
            }
            else if (s == "*")
            {
                int times = first * last; // conversion from string to int needed
                conversion.push(times); // conversion from int to string needed
            }
            else if (s == "/")
            {
                int divide = first / last; // conversion from string to int needed
                conversion.push(divide); // conversion from int to string needed
            }
            else if (s == "%")
            {
                int mod = first % last; // conversion from string to int needed
                conversion.push(mod); // conversion from int to string needed
            }
    */
    
	return "invalid";
}
