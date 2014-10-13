#pragma once
#include "ExpressionManager.h"
#include <string>
#include <stack>
using namespace std;

/* TEST CASES TO WATCH FOR
1. any other chars in the expressions other than numbers, ({[]}), "/+-*%" are bad -> reject and inform the user
2. strings for numbers like "a2" for a number
3. Not spaces in between every char in the expressions like 2 *( 2 + 5 -3)*()
4. In infix two operators together
5. In postfix expressions in the wrong places
6. Handle divide by zero attempts
*/

/*   DONT FOCUS ON THIS YET
int isNumber(string expression) //is it a number
{
	//for ()
	
	return 0;
}

bool operators(string expression)// operators are correct
{
	for (int i = 0; i < expression.size(); i++)
	{

	}
	return false;
}
*/

bool ratio(string expression)// numbers to operands
{
	stack<int> numbers;
	stack<char> operand; 
	for (int i = 0; i < expression.size(); i++)
	{
		if (isNumber(expression[i]) == -1)
		{
			return false;
		}
		else
		{
            numbers.push(expression[i]);//expression[i] needs to be replaced with a int type piece of info
		}
		if (operators(expression[i] == true))
		{
		    operand.push(expression[i]);
		}
		
	}
	if(operand.size() + != numbers.size())
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

bool brackets()
{
	return false;
}
*/

/*
* Checks whether an expression is balanced on its parentheses
*
* - The given expression will have a space between every number or operator
*
* @return true if expression is balanced
* @return false otherwise
*/

bool isBalanced(string expression)
{
	string parenOpen = "[{(";
	string parenClose = "]})";
	string checker = "";
	stack<char> parenCheck;	
	if (expression == "")
	{
		cout << "Empty expression string" << endl;
		return false;
	}
	for (int i = 0; i < expression.size(); i++)
	{
		for (int j = 0; i < parenOpen.size(); j++)
		{
			if (expression[i] == parenOpen[j])
			{
				parenCheck.push(expression[i]);
			}
			else if (expression[i] == parenClose[j])
			{
				if (parenCheck.top() == NULL)
				{
					cout << "Uneven braces!" << endl;
					return false;
				}
				//do I need to check for specific braces () [] {}?
				//checker = parenCheck.top(); //get the top data person
				else
				{
					parenCheck.pop();
				}
		
			}
		}
		if ()
	}
	return false;
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
string postfixToInfix(string postfixExpression)
{

	return "";
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
string infixToPostfix(string infixExpression)
{
	return "";
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
string postfixEvaluate(string postfixExpression)
{
	return "";
}
