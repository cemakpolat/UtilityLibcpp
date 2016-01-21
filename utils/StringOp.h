/*
 * StringOp.h
 *
 *  Created on: Sep 27, 2013
 *      Author: cem
 */

#ifndef STRINGOP_H_
#define STRINGOP_H_
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>


/*! \class Utilities
 *  \brief Utilities, as its name implies, is composed of utility functions
 *
 */

using namespace std;

class StringOp {
public:
	StringOp();
	~StringOp();

	/**
	 * Check whether the given string is in the given text or not
	 * \param text
	 * \param searchParam
	 * \return true if string is involved in the second string, otherwise false
	 */
	static bool contains(std::string& text, std::string searchParam) {
		if (std::string::npos != text.find(searchParam)) {
			return true;
		} else {
			return false;
		}
	}
	/**
		 * \param string s
		 * \param delim
		 * \param elem
		 * \return elems
		 */
		static std::vector<std::string> &split(const std::string &s, char delim,
				std::vector<std::string> &elems) {
			std::stringstream ss(s);
			std::string item;
			while (std::getline(ss, item, delim)) {
				elems.push_back(item);
			}
			return elems;
		}
		/**
		 * Split the string according to the delimeter
		 * \param string to be splitted
		 * \param delimiter
		 * \return vector in which the splitted strings
		 */
		static std::vector<std::string> split(const std::string &s, char delim) {
			std::vector<std::string> elems;
			return split(s, delim, elems);
		}
		/**
			 *trim from start
			 * \param  s
			 * \sa
			 * \return
			 */
			static inline std::string &ltrim(std::string &s) {
				s.erase(s.begin(),
						std::find_if(s.begin(), s.end(),
								std::not1(std::ptr_fun<int, int>(std::isspace))));
				return s;
			}
			/**
			 * trim from end
			 * \param  s
			 * \sa
			 * \return
			 */
			static inline std::string &rtrim(std::string &s) {
				s.erase(
						std::find_if(s.rbegin(), s.rend(),
								std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
						s.end());
				return s;
			}

			/**
			 * trim from both ends
			 * \param string s
			 * \return
			 */
			static inline std::string &trim(std::string &s) {
				return ltrim(rtrim(s));
			}
};



#endif /* STRINGOP_H_ */
