/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinnaryTree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:57:22 by rteles            #+#    #+#             */
/*   Updated: 2023/03/13 22:22:15 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_HPP
# define BTREE_HPP

#include <iostream>


struct BTree
{
    int   data;
    BTree *right;
    BTree *left;
};


class BinnaryTree
{
    private:
        BTree *root;
        
    public:
        BinnaryTree(char **string);
        ~BinnaryTree();

        void    show(void) const;
        void    deleteChild(int number);
        BTree   *searchChild(int number);
};

#endif