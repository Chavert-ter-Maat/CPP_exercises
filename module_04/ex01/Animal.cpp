/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: chaverttermaat <chaverttermaat@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 09:16:35 by chavertterm   #+#    #+#                 */
/*   Updated: 2023/11/21 11:13:12 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Default Animal") {
	std::cout << "Default constructor Animal is called" << std::endl;
}

Animal::Animal(const Animal &other_class){
	std::cout << "Copy constructor Animal is called" << std::endl;
	this->_type = other_class._type;
}

Animal &Animal::operator=(const Animal& other_class){
	if (this != &other_class)
		this->_type = other_class._type;
	return *this;
}

Animal::~Animal(){
	std::cout << "Deconstructor Animal is called" << std::endl;
}

const std::string &Animal::getType() const{
	return this->_type;
}

void Animal::makeSound() const{
	std::cout << this->_type << " .........." << std::endl;
}