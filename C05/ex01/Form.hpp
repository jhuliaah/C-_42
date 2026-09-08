
#ifndef FORM_HPP
#define FORM_HPP


#include <string>
#include <iostream>

class Bureaucrat;

class Form {

    private:
    std::string const _name;
    bool _signed;
    int const _gradeToSign;
    int const _gradeToExecute;
    Form();


    public:

    //constructos, copiers and destructors
    Form(std::string const name, int gradeToSign, int gradeToExecute);
    Form &operator=(const Form &other);
    Form(const Form &other);
    ~Form();


    //setters and getters

    std::string get_name() const;
	int get_grade_to_sign() const;
    int get_grade_to_execute() const;
    bool get_form_status() const;


    // be signed function
    void beSigned(Bureaucrat &_bureaucrat);

    // Errors treatments
    class GradeTooHighException : public std::exception {
        public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
        public:
		const char *what() const throw();
	};


};

std::ostream &operator<<(std::ostream &os, const Form &obj);


#endif
