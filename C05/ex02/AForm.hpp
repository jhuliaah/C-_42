
#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {

    private:
    std::string const _name;
    bool _signed;
    int const _gradeToSign;
    int const _gradeToExecute;
    AForm();

    public:

    //constructos, copiers and destructors
    AForm(std::string const name, int gradeToSign, int gradeToExecute);
    AForm &operator=(const AForm &other);
    AForm(const AForm &other);
    virtual ~AForm();

    //setters and getters
    std::string get_name() const;
    int get_grade_to_sign() const;
    int get_grade_to_execute() const;
    bool get_form_status() const;

    // be signed function
    void beSigned(Bureaucrat &_bureaucrat);

    // execute the form's action, checking signature and grade first
    void execute(Bureaucrat const &executor) const;

    // Errors treatments
    class GradeTooHighException : public std::exception {
        public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
        const char *what() const throw();
    };
    class FormNotSignedException : public std::exception {
        public:
        const char *what() const throw();
    };

    private:
    virtual void executeAction() const = 0;

};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif
