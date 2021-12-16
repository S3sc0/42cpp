#include "Bureaucrat.hpp"

/*
	Orthodox Canonical Form
*/

Bureaucrat::Bureaucrat( const std::string& Name, const int Grade ) : name(Name), grade(Grade)
{
	// std::cout << name << " Bureaucrat Constructor Has Been Called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& copyObj ) : grade(copyObj.getGrade())
{
	*this = copyObj;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& rop )
{
	if (this == &rop)
		return (*this);
	return (*this);	
}

Bureaucrat::~Bureaucrat( void )
{
	// std::cout << name << " Bureaucrat Destructor Has Been Called" << std::endl;
}

/*
	Accessors
*/

std::string	Bureaucrat::getName( void ) const
{
	return (name);
}

int			Bureaucrat::getGrade( void ) const
{
	return (grade);
}

/*
	Required Functions
*/

void		Bureaucrat::increament( void )
{
	int		tmpGrade;

	tmpGrade = getGrade();
	tmpGrade--;
	if (tmpGrade < 1)
		throw GradeTooHighException();
}

void		Bureaucrat::decreament( void )
{
	int		tmpGrade;

	tmpGrade = getGrade();
	tmpGrade++;
	if (tmpGrade > 150)
		throw GradeTooLowException();
}

/*
	Nested Classes' Function Implementation
*/

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade Too Hight!");
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade Too Low!");
}

/*
	Operator Overloading
*/

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& obj )
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}