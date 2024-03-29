/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 08:56:45 by cter-maa      #+#    #+#                 */
/*   Updated: 2024/03/12 15:11:18 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ************************** Orthodox Canonical **************************** */
RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", ROBOT_SIGN, ROBOT_EXEC),
	 _target("Default"){
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}
	
RobotomyRequestForm::RobotomyRequestForm(const std::string name) : AForm(name, 
	ROBOT_SIGN, ROBOT_EXEC), _target(name){
	std::cout << "RobotomyRequestForm constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) 
	: AForm(obj.getNameForm(), ROBOT_SIGN, ROBOT_EXEC){
	std::cout << "RobotomyRequestForm copy constructor is called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj){
	if (this != &obj){
		this->_target = obj._target;
	}
	std::cout<< "RobotomyRequestForm assignment overload is called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm deconstructor called" << std::endl;
}

/* *************************** Member functions ***************************** */
bool   RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	try{
		canBeSigned(executor);
		if(executor.getGrade() > ROBOT_EXEC)
			throw GradeTooLowException();
		std::cout << this->_target << " *makes some drilling noise*." <<std::endl;
        if (rand() % 2 == 0)
            std::cout << this->_target << " has been robotomized successfully." << std::endl;
        else
            std::cout << this->_target << " failed to rabotmized." << std::endl;
	}   
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return true;
 }