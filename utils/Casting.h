/*
 * Casting.h
 *
 *  Created on: Sep 27, 2013
 *      Author: cem
 */

#ifndef CASTING_H_
#define CASTING_H_
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/*! \class Utilities
 *  \brief Utilities, as its name implies, is composed of utility functions
 *
 */

class Casting {
public:
	Casting();
	~Casting();
	/**
	 * Convert String to Long Double
	 * \param string
	 * \return long double
	 */
	inline static long double convertStringToLongDouble(std::string input) {
		long double anz;
		std::istringstream inStream(input);
		inStream >> anz;
		return anz;
	}
	/**
	 * Convert long double to string
	 * \param val to be converted
	 * \return value
	 */
	inline static std::string convertLongDoubleToString(long double val) {
		std::stringstream ss;
		ss << val;
		return ss.str();
	}
	/**
	 * Convert float to string
	 * \param  val
	 * \return string
	 */
	inline static std::string convertFloatToString(float val) {
		std::stringstream ss;
		ss << val;
		return ss.str();
	}
	/**
	 * Convert long to string
	 * \param long val
	 * \sa
	 * \return stream
	 */
	inline static std::string convertLongToString(long val) {
		std::ostringstream stream;
		stream << val;
		return stream.str();
	}
	/**
	 *Convert string to long
	 * \param str
	 * \return long
	 */
	static long convertStringToLong(std::string& str) {
		try {
			return atol(str.c_str());
		} catch (std::exception& e) {
			std::cout
					<< "Utilities:Converting could not be successfully performed! "
					<< e.what() << std::endl;
			return 0;
		}
		return 0;
	}
	/**
	 * Convert string to double
	 * \param s
	 * \sa
	 * \return double
	 */
	static double convertStringToDouble(std::string& s) {
		double result = 0;
		try {

			result = atof(s.c_str());
		} catch (std::exception& e) {
			std::cout
					<< "Utilities:Converting could not be successfully performed! "
					<< e.what() << std::endl;
			return result;
		}
		return result;
	}
	/**
	 * Convert Double to string
	 * \param number
	 * \sa
	 * \return string
	 */
	static std::string convertDoubleToString(double& number) {
		std::stringstream ss; //create a stringstream
		ss << number; //add number to the stream
		return ss.str(); //return a string with the contents of the stream
	}

	/**
	 * Cinvert String to integer
	 * \param  s
	 * \return int
	 */
	static int convertStringToInt(std::string& s) {
		try {
			return atoi(s.c_str());
		} catch (std::exception& e) {
			std::cout
					<< "Utilities:Converting could not be successfully performed! "
					<< e.what() << std::endl;
			return 0;
		}
		return 0;
	}

	/**
	 * Convert Integer To String
	 * \param number
	 * \sa
	 * \return string
	 */
	static std::string convertIntToString(int number) {
		std::stringstream ss;	//create a stringstream
		ss << number;	//add number to the stream
		return ss.str();	//return a string with the contents of the stream
	}

	/**
	 * Convert String to Integer with CPP method
	 * \param  s
	 * \return integer
	 */
	static int convertStringToIntCPP(std::string& s) {
		std::stringstream ss(s); // Could of course also have done ss("1234") directly.
		int i = -1;
		if ((ss >> i).fail()) {
			std::cout << "Utilities:Error occured" << std::endl;
		}
		//std::cout << i << std::endl;
		return i;
	}
	/**
	 * Convert String to Integer with C method
	 * \param def
	 * \return integer
	 */
	static int convertStringToIntC(std::string& def) {
		int val = 0;
		try {
			val = atoi(def.c_str());
			return val;
		} catch (std::exception& e) {
			std::cout
					<< "Utilities:Converting could not be succesfully performed! "
					<< e.what() << std::endl;
			return val;
		}
		return val;
	}

};

#endif /* CASTING_H_ */
