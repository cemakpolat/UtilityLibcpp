/*
 *
 *  Version 1.0
 * Copyright Master Thesis project - 2013
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by  the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Utilities.h
 *
 *  Created on: 01.10.2013
 *      Author: Cem Akpolat
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_
#include <string>
#include <vector>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <unistd.h>
using namespace std;

/*! \class Utilities
 *  \brief Utilities, as its name implies, is composed of utility functions
 *
 */
class Utilities {
public:

	/**
	 * A Constructor.
	 */
	Utilities();
	/**
	 *A Destructor.
	 */
	~Utilities();

	/**
	 * Write console a static string
	 \param line
	 */
	static void writeConsole(const std::string& line) {
		std::cout << line << std::endl;
	}
	/**
	 * Write console a string
	 * \param line
	 */
	static void writeConsole(std::string& line) {
		std::cout << line << std::endl;
	}

	static int randomGenerator(int min, int max) {

		//time_t t;
		//time(&t);
		//srand((unsigned int) t);
		int num = rand() % max + min;
		//printf("generated number %d\n ", num);
		return num;
	}
	/**
	 * Sleep during a time randomly selected which should smaller than 5 seconds.

	 */
	static void randomBackOfftime() {

		int randResult = 1 + (rand() % 5);
		//string randStr=" in randombackoff time state: "+Utilities::convertIntToString(randResult);
		try {
			sleep(randResult * 1);
		} catch (std::exception& e) {
			e.what();
		}

	}
	/*random variable is choosen from 1 to a given value. Given value is referred to as maximumvalue,
	 * it means the max random value could be the given value.
	 * @maxValue
	 */
	/**
	 * Sleep during a time randomly selected which should smaller than max seconds.
	 * \param max
	 */
	static void randomBackOfftime(int maxValue) {

		int randResult = 1 + (rand() % maxValue);
		//string randStr=" in randombackoff time state: "+Utilities::convertIntToString(randResult);
		try {
			sleep(randResult * 1);
		} catch (std::exception& e) {
			e.what();
		}

	}

	/**
	 * Execute the given command on the back console then return the output of the executed command
	 * \param  command
	 * \sa
	 * \return string output
	 */
	static string exec(string cmd) {
		FILE* pipe = popen(cmd.c_str(), "r");
		if (!pipe)
			return "ERROR";
		char buffer[128];
		std::string result = "";
		while (!feof(pipe)) {
			if (fgets(buffer, 128, pipe) != NULL)
				result += buffer;
		}
		pclose(pipe);
		return result;
	}

};

#endif /* UTILITIES_H_ */
