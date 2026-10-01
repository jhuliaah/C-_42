#include "RPN.hpp"

//==========================================//
//				CONSTRUCTORS				//
//==========================================//

// Default constructor: starts with an empty stack.
RPN::RPN() {}

// Copy constructor: copies the stack.
RPN::RPN(const RPN &other) : _stack(other._stack) {}

// Assignment operator: copies the stack from another object.
RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}

// Destructor: nothing to free, the stack cleans itself up.
RPN::~RPN() {}

//==========================================//
//				FUNCTIONS					//
//==========================================//

// Returns true if the char is one of the 4 accepted operators.
static bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Pops the two numbers on top of the stack, applies the operator and pushes
// the result back. The first number popped is the RIGHT operand
// ("8 2 -" means 8 - 2). Throws if there are less than 2 numbers on the
// stack or on a division by zero.
void RPN::applyOperator(char op) {
	if (_stack.size() < 2)
		throw ErrorException();

	long right = _stack.top();
	_stack.pop();
	long left = _stack.top();
	_stack.pop();

	switch (op) {
		case '+':
			_stack.push(left + right);
			break;
		case '-':
			_stack.push(left - right);
			break;
		case '*':
			_stack.push(left * right);
			break;
		case '/':
			if (right == 0)
				throw ErrorException();
			_stack.push(left / right);
			break;
	}
}

// Reads the expression token by token (tokens are separated by spaces):
// - a digit (0-9) is pushed on the stack
// - an operator takes the 2 numbers on top and pushes the result
// At the end exactly one number must be left: that's the result.
// Anything else (other chars, numbers >= 10, missing operands, too many
// numbers left) throws ErrorException.
long RPN::calculate(const std::string &expression) {
	while (!_stack.empty())
		_stack.pop();

	for (std::size_t i = 0; i < expression.size(); i++) {
		char c = expression[i];

		if (c == ' ')
			continue;
		// every token must be a single char, so the next one has to be a
		// space or the end of the string (this also rejects "12", "1+"...)
		if (i + 1 < expression.size() && expression[i + 1] != ' ')
			throw ErrorException();

		if (isdigit(static_cast<unsigned char>(c)))
			_stack.push(c - '0');
		else if (isOperator(c))
			applyOperator(c);
		else
			throw ErrorException();
	}

	if (_stack.size() != 1)
		throw ErrorException();
	return _stack.top();
}
