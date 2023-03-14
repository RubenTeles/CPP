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

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{

    if (argc != 2)
    {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
    }

    BitcoinExchange bit = BitcoinExchange(argv[1]);

    std::cout << "show:" << std::endl;
    bit.show();
    return 0;
}
