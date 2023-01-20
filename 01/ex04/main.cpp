/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:45:44 by rteles            #+#    #+#             */
/*   Updated: 2023/01/20 17:21:19 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	writeFile(std::string text, std::string file, std::string s1, std::string s2)
{
	(void)text;
	(void)file;
	(void)s1;
	(void)s2;
	//TODO
}

int main(int argc, char **argv)
{
	std::ifstream	myfile;
	std::string 	text;
	std::string		line;
	
	if (argc != 4)
	{
		std::cerr << "Error!" << std::endl;
		return (1);
	}
	
	myfile.open(argv[1]);
	
	if (myfile.fail())
	{
		std::cerr << "Error Opening File" << std::endl;
		return (1);
	}
	
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			text += line + "\n";
		}
		myfile.close();
	}
	//writeFile(text, argv[1], argv[2], argv[3]);
	
	std::cout << text << std::endl;
	
	return (0);
}