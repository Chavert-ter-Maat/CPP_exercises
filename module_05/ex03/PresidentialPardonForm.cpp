/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/01 15:55:48 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/12 15:16:39 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************** Orthodox Canonical **************************** */
PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", PRESIDENT_SIGN, PRESIDENT_EXEC),
	 _target("Default"){
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}
	
PresidentialPardonForm::PresidentialPardonForm(const std::string name) : AForm(name, 
	PRESIDENT_SIGN, PRESIDENT_EXEC), _target(name){
	std::cout << "PresidentialPardonForm constructor is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) 
	: AForm(obj.getNameForm(), PRESIDENT_SIGN, PRESIDENT_EXEC){
	std::cout << "PresidentialPardonForm copy constructor is called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj){
	if (this != &obj){
		this->_target = obj._target;
	}
	std::cout<< "PresidentialPardonForm assignment overload is called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm deconstructor called" << std::endl;
}

/* *************************** Member functions ***************************** */



bool	PresidentialPardonForm::execute(Bureaucrat const& executor) const{
	try{
		canBeSigned(executor);
		if(executor.getGrade() > PRESIDENT_EXEC)
			throw GradeTooLowException();
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
		return (false);
	}
	return (true);
 }