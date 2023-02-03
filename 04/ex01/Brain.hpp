/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:27:26 by rteles            #+#    #+#             */
/*   Updated: 2023/02/03 18:38:40 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain
{
    protected:
        std::string ideas[100];
                
    public:
        Brain(void);
        Brain(std::string _type);
        Brain( Brain const & src);
        ~Brain(void);

        Brain & operator=(Brain const & rhs);
        
        std::string getIdeas(void) const;

};

#endif