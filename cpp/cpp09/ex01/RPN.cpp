#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : stack(other.stack) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		stack = other.stack;
	}
	return (*this);
}

RPN::~RPN() {}

bool RPN::is_operator(std::string c)
{
	if (c == "+" || c == "-" || c == "*" || c == "/")
		return (true);
	return (false);
}

bool RPN::run_operator(std::string c)
{
	int top;
	int bottom;
	if (stack.size() > 1)
	{
		top = stack.top();
		stack.pop();
		bottom = stack.top();
		stack.pop();
		if (c == "+")
			stack.push(bottom + top);
		else if (c == "-")
			stack.push(bottom - top);
		else if (c == "*")
			stack.push(bottom * top);
		else
		{
			if (top == 0)
				return (false);
			stack.push(bottom / top);
		}
		return (true);
	}
	return (false);
}

bool RPN::is_stack(std::string data)
{
	if (data.size() > 1)
		return (false);
	if (!std::isdigit(*data.c_str()))
		return (false);
	return (true);
}

bool RPN::eval(std::string av)
{
	int num;
	std::istringstream iss(av);
	std::string token;

	while (iss >> token)
	{
		if (is_operator(token))
		{
			if (!run_operator(token))
			{
				std::cerr << "Error: Not enough operands for operation or Division by 0." << std::endl;
				return (false);
			}
		}
		else if (is_stack(token))
		{
			num = token[0] - '0';
			stack.push(num);
		}
		else
		{
			std::cerr <<  "Error: Invalid token" << std::endl;
			return (false);
		}
	}
	if (stack.size() > 1)
	{
		std::cerr <<  "Error: Invalid expression format." << std::endl;
		return (false);
	}
	std::cout	<< stack.top() << std::endl;
	return (true);
}