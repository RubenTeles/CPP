/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:45:44 by rteles            #+#    #+#             */
/*   Updated: 2023/01/23 17:00:00 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string findTextAndReplace (std::string text, std::string s1, std::string s2)
{
  	std::size_t found;
	
	found = text.find(s1);
  	while (found!=std::string::npos)
  	{
		text = text.substr(0,found) + s2 + text.substr(found+s1.length());
		found = text.find(s1);
  	}
	return (text);
}

int main(int argc, char **argv)
{
	std::ifstream	readFile;
	std::ofstream	writeFile;
	std::string 	text;
	std::string		line;
	
	if (argc != 4)
	{
		std::cerr << "Error!" << std::endl;
		return (1);
	}
	
	readFile.open(argv[1]);
	
	if (readFile.fail())
	{
		std::cerr << "Error Opening File" << std::endl;
		return (1);
	}
	
	if (readFile.is_open())
	{
		while (getline(readFile, line))
		{
			text += line + "\n";
		}
		readFile.close();
	}

	writeFile.open(argv[1]);
	
	if (writeFile.fail())
	{
		std::cerr << "Error Opening File" << std::endl;
		return (1);
	}
	
	if (writeFile.is_open())
	{
		text = findTextAndReplace(text, argv[2], argv[3]);
		writeFile << text;

		writeFile.close();
	}
	
	return (0);
}