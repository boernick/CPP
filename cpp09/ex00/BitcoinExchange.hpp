/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:17:49 by nboer             #+#    #+#             */
/*   Updated: 2026/01/15 18:08:48 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange {
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void loadDatabase(const std::string &dbFile);
		void processInput(const std::string &inputFile);

	private:
		std::map<std::string, double> _data;

		bool	isValidDate(const std::string &date);
		bool	isValidValue(const std::string &str, double &outValue);
		double	getRate(const std::string &date);
		
};
