 // On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: ___강동인_______ 학번: ____21500002___


// postfix.cpp :
//
// The program evaluates a given postfix expression and produces a fully
// parenthesized infix expression. If the postfix expression may be 
// evaluated to a numeric value if it is expressed using numerically.
// For simplicity of coding, however, the postfix expression consists
// of single character operands and operators only and may have spaces.
//
// Author: idebtor@gmail.com
// 2020.04.05	Creation
// 2020.10.03	evaluation of numerical postfix expressions
//
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// change the printStack to use template once you finish part 1 in step 1.
// prints the stack contents from the bottom. 

template <typename T>
void printStack(stack<T> orig) {
    stack<T> temp;
    while (!orig.empty()) {
        temp.push(orig.top());
        orig.pop();
    }

    while (!temp.empty()) {
		cout << temp.top() << ' ';
        orig.push(temp.top());
        temp.pop();
    }
}


// returns a fully parenthesized infix expression in string after postfix evaluation.
string evaluate(string tokens) {
	stack<string> st;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);
		DPRINT(printStack(st););

		// current token is a value(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			string expression;
			expression += "(";

			string op1 = st.top();
			st.pop();

			string op2 = st.top();
			st.pop();

			expression += op2;
			expression += token;
			expression += op1;

			expression += ")";

			st.push(expression);
		}

		else {  // push the operand
			DPRINT(cout << "  push: " << token << endl;);
			// convert token(char type) to a string type and push it to the stack
			string s;
			s.push_back(token);
			st.push(s);
		}
	}

	DPRINT(cout << "token exhausted: \n";);
	DPRINT(printStack(st););
	DPRINT(cout << "stack size() should be 1.\n";);
	assert(st.size() == 1);

	string expr = st.top();

	DPRINT(cout << "<evaluate() returns " << "your expr" << endl;);
	return expr;
}

// returns true if the tokens consist of '+', '-', '*', '/', spaces, and 
// digits (0 ~ 9), false otherwise.
bool is_numeric(string tokens) {

	string numeric = "+-*/ 0123456789";

	for (char token : tokens) {
		if (numeric.find(token) == string::npos) return false;
	}

	return true;
}

// returns a numeric value after evaluating the postfix evaluation.
double evaluate_numeric(string tokens) {
	stack<double> st;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// if token is a operator, evaluate; if a digit(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			// checking the stack top() for right operand 
			// checking the stack top() for left oprand 
			// compute the expression and push the result

			double n1 = st.top();
			assert(!st.empty());
			st.pop();

			double n2 = st.top();
			assert(!st.empty());
			st.pop();

			if (token == '+') st.push(n2+n1);
			if (token == '-') st.push(n2-n1);
			if (token == '*') st.push(n2*n1);
			if (token == '/') {
				st.push(n2/n1);
				assert(n1 != 0);
			}
		}
		else { // push the operand (digit) in a value to the stack
			// convert token to a numeric data type and push it the stack
			double digit = token - '0';
			st.push(digit);
		}
	}

	DPRINT(cout << "token exhausted: check the stack, its size() should be 1.\n";);
	DPRINT(printStack(st););
	assert(st.size() == 1);

	double expr = 0;
	expr = st.top();

	DPRINT(cout << "<evaluate() returns " << expr << endl;);
	return expr;
}
