#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat {
	private:
		std::string const _name;
		unsigned int _grade;

	public:
	//Constructors; destructor; operator assignment;
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	
	//getters and setters
	std::string get_name() const;
	int get_grade() const;
	
	//functions
	void incrementGrade();
	void decrementGrade();

	//error treatment
	class GradeTooHighException : public std::exception {
		public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif