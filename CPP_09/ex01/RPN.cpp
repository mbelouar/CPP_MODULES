#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN & src): _stack(src._stack) {
	*this = src;
}

RPN &RPN::operator=(const RPN & src) {
	if (this == &src)
		return (*this);
	this->_stack = src._stack;
	return (*this);
}

RPN::~RPN() {}

bool RPN::isOperator(char token) {
    return token == '+' || token == '-' || token == '*' || token == '/';
}

int RPN::performOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::invalid_argument("Error: Division by zero");
            return a / b;
        default:
            throw std::invalid_argument("Error: Invalid operator");
    }
}

int RPN::calculate(const std::string& expression) {
    int i = 0;

    while (expression[i]) {
        if ((i == 0 && !isdigit(expression[i])) ||
            (isdigit(expression[i]) && expression[i + 1] != ' ' && expression[i + 1] != '\0') ||
            (isOperator(expression[i]) && expression[i + 1] != ' ' && expression[i + 1] != '\0')) 
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }

        if (isdigit(expression[i])) {
            this->_stack.push(expression[i] - '0');
        } else if (isOperator(expression[i]) && this->_stack.size() >= 2) {
            int second = this->_stack.top();
            this->_stack.pop();
            int first = this->_stack.top();
            this->_stack.pop();

            int result = performOperation(first, second, expression[i]);
            this->_stack.push(result);
        } else if (isOperator(expression[i]) && this->_stack.size() < 2) {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        i++;
    }

    if (this->_stack.size() == 1) {
        return this->_stack.top();
    } else {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
}
