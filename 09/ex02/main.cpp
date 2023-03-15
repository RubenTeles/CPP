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
    if (argc < 2)
    {
		  std::cerr << "Error: Need Arguments!" << std::endl;
		  return (1);
    }

    try {
        PmergeMe pm = PmergeMe(argv);

        pm.show(argv);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
/*
3 5 9 7 4
`shuf -i 1-100000 -n 3000 | tr "\n" " "`
*/