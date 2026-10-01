#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <exception>

class RPN {
	private:
		std::stack<long>	_stack;

		void	applyOperator(char op);

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		//error treatment

		class ErrorException : public std::exception {
			public:
			virtual const char* what() const throw() { return "Error"; }
		};

		//functions:

		long	calculate(const std::string &expression);
};

#endif
