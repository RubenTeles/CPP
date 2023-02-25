/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/02/23 12:08:45 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf;

    try {
            std::cout << std::endl << "--- Test ---" << std::endl << std::endl;
    
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
            std::cout << "1. " << rrf->getName() << std::endl;
            delete rrf;
            std::cout  << std::endl;
            
            rrf = someRandomIntern.makeForm("shrubbery creation", "Fruit");
            std::cout << "2. " << rrf->getName() << std::endl;
            delete rrf;
            std::cout  << std::endl;
        
            rrf = someRandomIntern.makeForm("presidential pardon", "House");
            std::cout << "3. " << rrf->getName() << std::endl;
            delete rrf;
            std::cout  << std::endl;
        
            rrf = someRandomIntern.makeForm("food request", "Ameijoa");
        
    }  catch(const std::exception& e) {
        
        std::cout << "Erro: " << e.what() << std::endl << std::endl;
    
    }
    
    return 0;
}
