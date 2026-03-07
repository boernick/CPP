/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:17:27 by nboer             #+#    #+#             */
/*   Updated: 2026/01/11 19:17:46 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _data(copy._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src)
        _data = src._data;
    return *this;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;       
    for (size_t i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeap)
        daysInMonth[1] = 29;

    if (month < 1 || month > 12 || day < 1)
        return false;
    if (day > daysInMonth[month - 1])
        return false;

    return true;
}
	
bool BitcoinExchange::isValidValue(const std::string &str, double &outValue) {
    if (str.empty())
        return false;

    int dot = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '-' && i == 0)
            continue;
        if (str[i] == '.') {
            dot++;
            continue;
        }
        if (!(isdigit(str[i])))
            return false;
    }
    if (dot > 1)
        return false;

    std::istringstream ss(str);
    ss >> outValue;
    return !ss.fail();
}
		
double BitcoinExchange::getRate(const std::string &date) {
    std::map<std::string, double>::iterator it = _data.lower_bound(date);
    
    if (it != _data.end() && it->first == date)
        return it->second;
    if (it == _data.begin()) {
        std::cerr << "Error: no exchange rate available for this date" << std::endl;
        return -1;
    }
    --it;
    return it->second;
}

void BitcoinExchange::loadDatabase(const std::string &dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file" << std::endl;
        return; 
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        
        std::string date = line.substr(0, comma);
        std::string value = line.substr(comma + 1);
        double rate;
        if (!isValidDate(date) || !isValidValue(value, rate))
            continue;

        _data[date] = rate;
    }
}

void BitcoinExchange::processInput(const std::string &inputFile){
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file.";
        return;
    }

    std::string line;
    std::getline(file, line);
    while (getline(file, line)) {
        if (line.empty())
            continue;
        
        size_t sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 3);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        double value;
        if (!isValidValue(valueStr, value)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000) {
            std::cerr << "Error: too large number." << std::endl;
            continue;
        }
        
        double rate = getRate(date);
        if (rate < 0)
            continue;

        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
}
