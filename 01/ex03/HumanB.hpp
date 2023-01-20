/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:27:42 by rteles            #+#    #+#             */
/*   Updated: 2023/01/20 16:30:04 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon      wp;
    public:
        HumanB(std::string name);
        ~HumanB();
        
        void    attack(void);
        void    setWeapon(Weapon weapon);
};
