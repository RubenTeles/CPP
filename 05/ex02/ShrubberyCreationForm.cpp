/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:42 by rteles            #+#    #+#             */
/*   Updated: 2023/02/23 12:25:39 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = "";
    std::cout << "ShrubberyCreationForm Constructor!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 72, 45)
{
    this->target = target;
    std::cout << "ShrubberyCreationForm Constructor!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src): AForm(src)
{
    std::cout << "ShrubberyCreationForm Clonned!" << std::endl;
    
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor!" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);

    return *this;
}

const char* ShrubberyCreationForm::FailToOpenException::what() const throw()
{
    return ("Error Opening File.");
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ifstream	readFile;
    std::ofstream	writeFile;
	std::string 	text;
	std::string		line;
    int             random = -1;
    int             index = 0;

    executor.executeForm(*this);
    
    std::srand(time(NULL));
    while (random <= 0 || random > 12)
        random = (1 + (std::rand() % 12));
    
    readFile.open("tree.ascii");
	
    if (readFile.fail())
        throw FailToOpenException();
        
    if (readFile.is_open())
	{
		while (getline(readFile, line))
		{
            if (line.length() == 0)
                index++;
            if (index == random)
    			text += line + "\n";
		}
		readFile.close();
	}

    writeFile.open((this->target + std::string("_shrubbery.42")).c_str());
	
	if (writeFile.fail())
        throw FailToOpenException();
	
	if (writeFile.is_open())
	{
		writeFile << text;

		writeFile.close();
	}

    std::cout << "Created: " << this->target << "_shrubbery.42" << std::endl;
}
