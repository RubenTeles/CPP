/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:40:25 by rteles            #+#    #+#             */
/*   Updated: 2023/01/10 22:55:39 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    char word[512];    
    
    std::cout << "Hello World!" << std::endl;

    std::cout << "Input a word: ";
    std::cin >> word;
    std::cout << "Tou entered: [" << word << "]" << std::endl;

    return 0;
}x\