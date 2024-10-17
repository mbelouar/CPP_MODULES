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

std::stack<int> RPN::getStack() const {
    return this->_stack;
}

bool RPN::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::performOperation(int a, int b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::invalid_argument("Error: Division by zero");
        return a / b;
    }
    throw std::invalid_argument("Error: Invalid operator");
}

int RPN::calculate(const std::string& expression) {
    int i = 0;

    // Iterate through each character in the expression
    while (expression[i]) {
        // Check for errors: non-digit as the first character, incorrect spacing, or invalid operator usage
        if ((i == 0 && !isdigit(expression[i])) ||
            (isdigit(expression[i]) && expression[i + 1] != ' ' && expression[i + 1] != '\0') ||
            (isOperator(std::string(1, expression[i])) && expression[i + 1] != ' ' && expression[i + 1] != '\0')) 
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }

        // If the character is a digit, push it onto the stack
        if (isdigit(expression[i])) {
            this->_stack.push(expression[i] - '0');
        } 
        // If it's an operator, ensure there are at least two operands on the stack
        else if (isOperator(std::string(1, expression[i])) && this->_stack.size() >= 2) {
            int second = this->_stack.top();
            this->_stack.pop();
            int first = this->_stack.top();
            this->_stack.pop();

            // Use performOperation to calculate the result
            int result = performOperation(first, second, std::string(1, expression[i]));
            this->_stack.push(result);
        } 
        // Handle errors for insufficient operands when an operator is encountered
        else if (isOperator(std::string(1, expression[i])) && this->_stack.size() < 2) {
            std::cerr << "Error" << std::endl;
            exit(1);
        }

        // Move to the next character
        i++;
    }

    // If the stack size is exactly 1, output the result; otherwise, output an error
    if (this->_stack.size() == 1) {
        return this->_stack.top();
    } else {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
}
