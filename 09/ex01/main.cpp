/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:26:01 by rteles            #+#    #+#             */
/*   Updated: 2023/03/13 23:42:56 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{

    if (argc != 2)
    {
		  std::cerr << "Error: need just one argument." << std::endl;
		  return (1);
    }

    try {
        RPN cal = RPN(argv[1]);
        cal.result();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
/*
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "(1 + 1)"
*/
