//Program that takes the postfix notation of representing 
//arithmetic expressions. And prints out the result

#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>

#define STR_MAX_LEN 5001

using namespace std;

bool is_operator(char c) {
	return c == 'M' || c == 'm';
}

//Function that returns the priority of operators.
int priority(char c) {
	if(c == 'm')
		return 1;
	else if(c == 'M')
		return 2;
	else
		throw "Invalid operator";
}

//Function that applays the operators from the operators stack
//on to the values from the values stack and stores them back
//in the values stack.
void use_operator(stack<char> &operators, stack<int> &values) {
	char op = operators.top();
	operators.pop();

	int op2 = values.top(); values.pop();
	int op1 = values.top(); values.pop();
	
	int num;
	if(op == 'M')
		num = (op1 > op2) ? op1 : op2;
	if(op == 'm')
		num = (op1 < op2) ? op1 : op2;

	values.push(num);
}

int exp_value(const string &exp) {
	stack<int> values;
	stack<char> operators;

	for (char c : exp) {
		if (isdigit(c))
			values.push(c - '0');
		else if (c == '(')
			operators.push('(');
		else if (c == ')') {
			while (operators.top() != '(') {
				use_operator(operators, values);
			}
			//Its important to remove the "(" from
			//the operators stack.
			operators.pop();
		}
		else if (is_operator(c)) {
			while (!operators.empty() && is_operator(operators.top()) &&
			priority(operators.top()) >= priority(c))
				use_operator(operators, values);
			
			operators.push(c);
		}
	}

	while (!operators.empty())
		use_operator(operators, values);

	return values.top();
}

int main() {

	char exp[STR_MAX_LEN];
	cin >> exp;

	int value = exp_value(exp);
	cout << value << endl;

	return 0;
}