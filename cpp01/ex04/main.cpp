/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:33:31 by nboer             #+#    #+#             */
/*   Updated: 2025/03/15 13:12:43 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int	error_handler(std::string msg)
{
	std::cout << msg << std::endl;
	return (1);
}

void replace_str(char* filename, std::string s1, std::string s2)
{
	std::ifstream infile;
	std::ostringstream ss;
	std::ofstream outfile("outfile.txt");
	std::string result;
	size_t pos = 0;
	size_t last_pos = 0;
	
	infile.open(filename);
	ss << infile.rdbuf();
	std::string content = ss.str();

	while ((pos = content.find(s1, last_pos)) != std::string::npos)
	{
		result.append(content.substr(last_pos, pos - last_pos));
		result.append(s2);
		last_pos = pos + s1.length();
	}
	result.append(content.substr(last_pos, pos - last_pos));
	infile.close();
	outfile << result;
	outfile.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (error_handler("Error: wrong argument count"));
	replace_str(argv[1], argv[2], argv[3]);
	return (0);	
}
