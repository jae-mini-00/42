#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
	private :
		std::stack<int> stack;

		bool is_operator(std::string c);
		bool run_operator(std::string c);
		bool is_stack(std::string data);
	public :
 		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		bool eval(std::string av);
};

#endif