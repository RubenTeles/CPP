/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinnaryTree.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:57:22 by rteles            #+#    #+#             */
/*   Updated: 2023/03/13 20:10:12 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BinnaryTree.hpp"

BinnaryTree::BinnaryTree(char **string)
{
    int legth = 0;

    while (string[legth])
        legth++;

    std::cout << "argumentos: " << legth << std::endl;
    for (int i = 0; i < legth; i++)
    {
        BTree *newTree = new BTree();
        newTree->data = std::stoi(string[i]);
        newTree->right = nullptr;
        newTree->left = nullptr;

        if (i == 0)
            this->root = newTree;
        else
        {
            BTree *aux = this->root; 
            while (aux)
            {
                if (aux->data < newTree->data)
                {
                    if (aux->right == nullptr)
                    {
                        aux->right = newTree;
                        break ;
                    }
                    else
                        aux = aux->right;
                }
                else if (aux->data > newTree->data)
                {
                    if (aux->left == nullptr)
                    {
                        aux->left = newTree;
                        break ;
                    }
                    else
                        aux = aux->left;
                }
            }
        }
    }
    
}

void    deleteTree(BTree *tree)
{
    if (tree->left)
        deleteTree(tree->left);
    if (tree->right)
        deleteTree(tree->right);
    delete tree;
}

BinnaryTree::~BinnaryTree()
{
    if (this->root)
        deleteTree(this->root);
}

void    showTree(int level, BTree *parent, BTree *tree)
{
    if (tree->left)
        showTree(level + 1, tree, tree->left);
    
    std::cout << "Level: " << level << " Data: " << tree->data;

    if (!tree->right && !tree->left)
         std::cout << " Leaf ";

    std::cout << std::endl;

    if (tree->right)
        showTree(level + 1, tree, tree->right);
}

void    BinnaryTree::show(void) const
{
    if (this->root)
        showTree(1, nullptr, this->root);
}

BTree   * BinnaryTree::searchChild(int number)
{
    BTree *aux = this->root; 
    while (aux)
    {
        if (aux->data > number)
            aux = aux->left;
        else if (aux->data < number)
            aux = aux->right;
        else
            return aux;
    }
    return nullptr;
}

void    BinnaryTree::deleteChild(int number)
{
    BTree *curNumber = nullptr;
    BTree *parent = nullptr;

    BTree *aux = this->root; 
    while (aux)
    {
        if (aux->data > number)
        {
            if (aux->left && aux->left->data == number)
                parent = aux;
            aux = aux->left;
        }
        else if (aux->data < number)
        {
            if (aux->right && aux->right->data == number)
                parent = aux;
            aux = aux->right;
        }
        else
        {
            curNumber = aux;
            break;
        }
    }
    if (!curNumber)
    {
        std::cout << "Erro! Number: " << number << " is not inside the BinnaryTree!" << std::endl;
    }
    if (!curNumber->left && !curNumber->right)
    {
        if (!parent)
            this->root = nullptr;
        else if (parent->left->data == number)
            parent->left = nullptr;
        else if (parent->right->data == number)
            parent->right = nullptr;
    }
    else if ((!curNumber->left && curNumber->right) || (curNumber->left && !curNumber->right))
    {
        if (!parent)
         {
            if (curNumber->left)
                this->root = curNumber->left;
            else if (curNumber->right)
                this->root = curNumber->right;
        }
        else if (parent->left->data == number)
        {
            if (curNumber->left)
                parent->left = curNumber->left;
            else if (curNumber->right)
                parent->left = curNumber->right;
        }
        else if (parent->right->data == number)
        {
            if (curNumber->left)
                parent->right = curNumber->left;
            else if (curNumber->right)
                parent->right = curNumber->right;
        }
    }
    else if (curNumber->left && curNumber->right)
    {
        BTree *aux = curNumber->right;
        BTree *auxparent = nullptr;
        int levels = 0;
        while (aux)
        {
            if (aux->left)
            {
                auxparent = aux;
                aux = aux->left;
                levels++;
            }
            else
            {
                if (levels == 0)
                {
                    aux->left = curNumber->left;
                    if (!parent)
                        this->root = curNumber->right;
                    else if (parent->left->data == number)
                        parent->left = curNumber->right;
                    else if (parent->right->data == number)
                        parent->right = curNumber->right;
                    break ;
                }
                if (aux->right)
                    auxparent->left = aux->right;
                else
                    auxparent->left = nullptr;

                aux->right = curNumber->right;
                aux->left = curNumber->left;

                if (!parent)
                    this->root = aux;
                else if (parent->left->data == number)
                    parent->left = aux;
                else if (parent->right->data == number)
                    parent->right = aux;
                break ;
            }
        }
    }
    delete curNumber;
    std::cout << std::endl << "delete: " << number << std::endl << std::endl;
}