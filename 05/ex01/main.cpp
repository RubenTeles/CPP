/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/02/23 11:35:35 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void    testGrade(Bureaucrat *bure, Form *form)
{
    try {
            std::cout << *bure << std::endl;
            std::cout << *form << std::endl << std::endl;
        
            form->beSigned(bure);

            std::cout << std::endl << std::endl;
        
    } catch(const std::exception& e) {
        
        std::cout << "Erro: " << e.what() << std::endl << std::endl;
    
    }
}

void    testCopy(Form *form1, Form *form2)
{
    std::cout << *form1 << " for " << *form2 << std::endl;
    
    form1 = form2;

    std::cout << std::endl << "Result: " << *form1 << std::endl << std::endl;
}

int main()
{
    Bureaucrat  camila("Camila", 1);
    Bureaucrat  albert("Albert", 150);
    Form        homework("homework", 150, 150);
    Form        exam("exam", 10, 10);

    std::cout << std::endl << "---Test Assined---" << std::endl << std::endl;

    testGrade(&albert, &homework);
    testGrade(&albert, &exam);
    testGrade(&camila, &homework);
    testGrade(&camila, &exam);
    
    std::cout << std::endl << "---Test Copy---" << std::endl << std::endl;
    
    testCopy(&homework, &exam);
    
    return 0;
}
