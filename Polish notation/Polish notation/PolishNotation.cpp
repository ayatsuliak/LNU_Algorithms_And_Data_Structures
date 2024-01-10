#include<iostream>
#include <stack>
#include<cmath>
#include<string>
#include <iomanip>

#define tg(x) (sin(x)/cos(x))

using namespace std;

int IsOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
	{
		return 2;      
	}
	if (ch == 's' || ch == 'c' || ch == 't')
	{
		return 1;       
	}
	return 0;                
}

int Priority(char ch)
{
	if (ch == '(' || ch == ')' || ch == '#')
	{
		return 0;
	}
	if (ch == '+' || ch == '-')
	{
		return 1;
	}
	if (ch == '*' || ch == '/')
	{
		return 2;
	}
	if (ch == '^')
	{
		return 3;
	}
}

string ToPostfix(string exp)
{
	string result = "";
	stack<char> stack;
	stack.push('#');
	for (size_t i = 0; i <= exp.length(); i++)
	{
		
		if (isdigit(exp[i]))
		{
			result += exp[i];
			continue;
		}

		switch (exp[i])
		{
		case '(':
		{
			stack.push(exp[i]);
			continue;
		}
		case ')':
		{
			while (stack.top() != '(')
			{
				result += stack.top();
				stack.pop();
			}
			stack.pop();
			continue;
		}
		case '\0':
		{
			while (stack.top() != '#')
			{
				result += stack.top();
				stack.pop();
			}
			break;
		}
		}

		if (IsOperator(exp[i]) == 2 || IsOperator(exp[i]) == 1)
		{
			while (Priority(exp[i]) <= Priority(stack.top()))
			{
				result += stack.top();
				stack.pop();
			}
			stack.push(exp[i]);
			continue;
		}
	}
	return result;
}

double ReversePolishNotation(string exp)
{
	stack<double> stack;

	double value;

	for (size_t i = 0; i < exp.size(); i++)
	{
		if (isdigit(exp[i]))  //перевіряємо чи є в стрінгу цифра
		{
			stack.push(exp[i] - 48);  //-48 пов'язане з тим, щоб код символу перетворити в цифру
		}
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			double a;
			double b;
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();

			switch (exp[i])
			{
			case '+': value = a + b;
				break;
			case '-': value = b - a;
				break;
			case '*': value = a * b;
				break;
			case '/': value = b / a;
				break;
			}

			stack.push(value);
		}
		if (exp[i] == 's' || exp[i] == 'c' || exp[i] == 't')
		{
			double a;
			a = stack.top();
			stack.pop();

			switch (exp[i])
			{
			case 's': value = sin(a);
				break;
			case 'c': value = cos(a);
				break;
			case 't': value = tg(a);
				break;
			}
			stack.push(value);
		}
	}
	return stack.top();
}

int main()
{
	//(1+2)*4+3
	//3*(4+5)-(6-2)*4
	//7+s(5)
	//2+c(5)
	//3+t(5)


	string str;
	cout << "Write your example: ";
	cin >> str;

	cout << endl;

	string str2 = ToPostfix(str);
	cout<<"Reverse Polish notation: " << str2 << endl;

	cout << endl;

	cout << "Answer: " << ReversePolishNotation(str2) << endl;
	

	return 0;
}

