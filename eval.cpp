#include "Map.h"
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int evaluate(string infix, const Map& values, string& postfix, int& result)
{
	if (infix == "")
		return 1;
	postfix = "";
	stack<char> op;
	stack<int> opand;
	int let = 0;
	int paren = 0;
	for (unsigned int i = 0; i < infix.size(); i++)	
	{
		if (infix[i] == ' ')
			continue;
		if (let == 0)
		{
			if (islower(infix[i]))
			{
				postfix += infix[i];
				let++;
				continue;
			}
			else if (infix[i] == '(')
			{
				op.push('(');
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
				while (!op.empty() && op.top() != '(')
				{
					postfix += op.top();
					op.pop();
				}
				op.push(infix[i]);
				let--;
				break;
			case '/':
			case '*':
				while (!op.empty() && op.top() != '(' && op.top() != '+' && op.top() != '-')
				{
					postfix += op.top();
					op.pop();
				}
				op.push(infix[i]);
				let--;
				break;
			case ')':
				while (!op.empty() && op.top() != '(')
				{
					postfix += op.top();
					op.pop();
				}
				if (!op.empty())
					op.pop();
				paren--;
				break;
			default:
				return 1;
			}
	}
	while (!op.empty())
	{
		postfix += op.top();
		op.pop();
	}
	if (let != 1 || paren != 0)
		return 1;
	for (unsigned int x = 0; x < postfix.size(); x++)
	{
		if (islower(postfix[x]))
		{
			int temp;
			if (!values.contains(postfix[x]))
				return 2;
			values.get(postfix[x], temp);
			opand.push(temp);
		}
		else
		{
			int two = opand.top();
			opand.pop();
			int one = opand.top();
			opand.pop();
			switch (postfix[x])
			{
			case '+':
				opand.push(one + two);
				break;
			case '-':
				opand.push(one - two);
				break;
			case '*':
				opand.push(one * two);
				break;
			case '/':
				if (two == 0)
					return 3;
				opand.push(one / two);
				break;
			}
		}
	}
	result = opand.top();
	return 0;
}
