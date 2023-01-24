/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:45:44 by rteles            #+#    #+#             */
/*   Updated: 2023/01/24 12:54:35 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl *harl = new Harl();

    harl->complain("comipao");
    harl->complain("warning");
    harl->complain("debug");
    harl->complain("error");
    harl->complain("info");
    harl->complain("random");

    delete harl;
}