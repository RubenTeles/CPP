/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/02/21 23:47:00 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    testGrade(Bureaucrat *bure, AForm *form)
{
    try {
            std::cout << *bure << std::endl;
            std::cout << *form << std::endl << std::endl;

            form->beSigned(bure);
            form->execute(*bure);

            std::cout << std::endl << std::endl;
        
    } catch (const AForm::GradeTooHighException& e) {
        
        std::cout << "Erro: " << e.what() << std::endl << std::endl;
    
    } catch (const AForm::GradeTooLowException& e) {
    
        std::cout << "Erro: " << e.what() << std::endl << std::endl;
    } catch (const AForm::GradeIsNotSignedException& e) {
    
        std::cout << "Erro: " << e.what() << std::endl << std::endl;
    }
}

void    testCopy(AForm *form1, AForm *form2)
{
    std::cout << *form1 << " for " << *form2 << std::endl;
    
    form1 = form2;

    std::cout << std::endl << "Result: " << *form1 << std::endl << std::endl;
}

int main()
{
    Bureaucrat  camila("Camila", 1);
    Bureaucrat  albert("Albert", 150);
    AForm       *shrubbery = new ShrubberyCreationForm();
    AForm       *robot = new RobotomyRequestForm();
    AForm       *presidential = new PresidentialPardonForm();

    std::cout << std::endl << "---Test Assined---" << std::endl << std::endl;

    testGrade(&albert, shrubbery);
    testGrade(&albert, robot);
    testGrade(&albert, presidential);
    testGrade(&camila, shrubbery);
    testGrade(&camila, robot);
    testGrade(&camila, presidential);
    
    std::cout << std::endl << "---Test Copy---" << std::endl << std::endl;
    
    testCopy(shrubbery, robot);

    delete shrubbery;
    delete robot;
    delete presidential;
    
    return 0;
}
