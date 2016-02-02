#include "Map.h"
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cassert>
using namespace std;

int evaluate(string infix, const Map& values, string& postfix, int& result)
{
	int let = 0;
	int paren = 0;
	for (int i = 0; i < infix.size(); i++)	// Evaluates an integer arithmetic expression
	{
		if (infix[i] == ' ')                
			continue;
		if (let == 0)
		{
			if (islower(infix[i]))
			{
				let++;
				continue;
			}
			else if (infix[i] == '(')
			{
				paren++;
				continue;
			}
			else
				return 1;
		}
		else if (let == 1)
			switch (infix[i])
			{
			case '+':
			case '-':
			case '/':
			case '*':
				let--;
				break;
			case ')':
				paren--;
				break;
			default:
				return 1;
			}
	}
	if (let == 1 && paren == 0)     //if syntactically valid
	{

	}
// Precondition: infix is an infix integer arithmetic
//   expression consisting of single lower case letter operands,
//   parentheses, and the operators +, -, *, /, with embedded blanks
//   allowed for readability. 
// Postcondition: If infix is a syntactically valid infix integer
//   expression whose only operands are single lower case letters
//   (whether or not they appear in the values map), then postfix is
//   set to the postfix form of the expression; otherwise postfix may
//   or may not be changed, result is unchanged, and the function
//   returns 1.  If infix is syntactically valid but contains at
//   least one lower case letter operand that does not appear in the
//   values map, then result is unchanged and the function returns 2.
//   If infix is syntactically valid and all its lower case operand
//   letters appear in the values map, then if evaluating the
//   expression (using for each letter in the expression the value in
//   the map that corresponds to it) attempts to divide by zero, then
//   result is unchanged and the function returns 3; otherwise,
//   result is set to the value of the expression and the function
//   returns 0.
}
