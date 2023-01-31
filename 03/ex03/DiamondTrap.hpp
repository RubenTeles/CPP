/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:18:55 by rteles            #+#    #+#             */
/*   Updated: 2023/01/31 16:48:14 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;
        DiamondTrap(void);

    public:
        DiamondTrap(std::string name);
        DiamondTrap( DiamondTrap const & src);
        ~DiamondTrap(void);

        DiamondTrap & operator=(DiamondTrap const & rhs);
        
        std::string getNameDiamond(void) const;
        
        void whoAmI(void);
        void attack(const std::string& target);
};

#endif