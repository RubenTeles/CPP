/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 17:39:58 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void    testInit(int grade)
{
    try {
        
        Bureaucrat  bur("Bur", grade);
        
    } catch (const Bureaucrat::GradeTooHighException& e) {
        
        std::cout << "Erro: " << e.what() << std::endl << std::endl;
    
    } catch (const Bureaucrat::GradeTooLowException& e) {
    
        std::cout << "Erro: " << e.what() << std::endl << std::endl;
    }
}

void    testGrade(Bureaucrat *bure, std::string test)
{
    try {
        
        if (test == "Increment")
        {
            std::cout << bure->getName() << " increment Grade for: " << bure->getGrade() - 1 << std::endl;
            bure->incrementGrade();
        }
        else if (test == "Decrement")
        {
            std::cout << bure->getName() << "Decrement Grade for: " << bure->getGrade() + 1 << std::endl;
            bure->decrementGrade();
        }

        std::cout << *bure << std::endl << std::endl;
        
    } catch (const Bureaucrat::GradeTooHighException& e) {
        
        std::cout << "Erro: " << e.what() << std::endl << std::endl;
    
    } catch (const Bureaucrat::GradeTooLowException& e) {
    
        std::cout << "Erro: " << e.what() << std::endl << std::endl;
    }
}

void    testCopy(Bureaucrat *bure1, Bureaucrat *bure2)
{
    std::cout << *bure1 << " for " << *bure2 << std::endl;
    
    bure1 = bure2;

    std::cout << std::endl << "Result: " << *bure1 << std::endl << std::endl;
}

int main()
{
    Bureaucrat  camila("Camila", 1);
    Bureaucrat  albert("Albert", 150);

    std::cout << std::endl << "---Test Init---" << std::endl << std::endl;

    testInit(0);
    testInit(151);
    testInit(1);

    std::cout << std::endl << "---Test Increment/Decrement---" << std::endl << std::endl;

    testGrade(&camila, "Increment");
    testGrade(&camila, "Decrement");
    testGrade(&albert, "Decrement");
    testGrade(&albert, "Increment");
    
    std::cout << std::endl << "---Test Copy---" << std::endl << std::endl;
    
    testCopy(&albert, &camila);
    
    return 0;
}
