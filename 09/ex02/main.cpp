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

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
		  std::cerr << "Error: could not open file." << std::endl;
		  return (1);
    }

    try {
        PmergeMe pm = PmergeMe(argv[1]);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
