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

#include "BinnaryTree.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "need elements" << std::endl;
        return 0;
    }

    std::cout << "argc: " << argc << std::endl;
    
    BinnaryTree *bt = new BinnaryTree(++argv);
    bt->show();
    
    bt->deleteChild(50);
    
    bt->show();
    delete bt;
    
    return 0;
}
//./BTR 50 76 21 4 32 64 15 52 14 100 83 2 3 70 87 80