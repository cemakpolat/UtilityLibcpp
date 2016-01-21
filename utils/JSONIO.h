/*
 * JSONIO.h
 *
 *  Created on: Sep 27, 2013
 *      Author: cem
 */

#ifndef JSONIO_H_
#define JSONIO_H_
#include <string>
#include <vector>
#include "writer.h"
#include "elements.h"
#include "reader.h"

/*! \class Utilities
 *  \brief Utilities, as its name implies, is composed of utility functions
 *
 */

class JSONIO {
public:
	JSONIO();
	~JSONIO();

	//Read JSON file and return as JSON Object.
	static json::Object readJSONFile(std::string& fileName1) {
		std::string path = "";
		//pathFinder(DataAccess::userModelFolderName,userId);
		const char *fileName = (path + ".txt").c_str();

		std::stringstream buffer;
		json::Object elemRootFile1;

		std::ifstream file(fileName);
		try {
			if (file) {
				std::cout << "JsonDataAccess: User's Profile exists"
						<< std::endl;
				buffer << file.rdbuf();
				file.close();

				try {
					json::Reader::Read(elemRootFile1, buffer);
					return elemRootFile1;
				} catch (json::Reader::ParseException& e) {

				}
			} else {
				std::cout << "File does not exist" << std::endl;
			}
		} catch (std::exception& e) {
			std::cout << "File does not exist" << std::endl;
		}
		return elemRootFile1;
	}

	// Write the given object in a file as a JSON object.
	static void fileJSONWrite(const json::Object& tobeWritten,
			const std::string& fileName) {
		bool succes = false;
		std::ofstream myfile;
		std::stringstream stream1;
		//string path;
		try {

			json::Writer::Write(tobeWritten, stream1);
			//	path = pathFinder(DataAccess::userModelFolderName,fileName);
			//const char *fileName = (path + ".txt").c_str();
			myfile.open(fileName.c_str());
			if (myfile.is_open()) {
				myfile << stream1.str();
				myfile.close();
			}
			succes = true;

		} catch (std::exception& e) {
			e.what();
		}
	}

	//Convert the json format string to JSON Object
	static json::Object convertStringToJSON(std::string& str) {
		try {
			std::istringstream sBadDocument(str);
			json::Object jsonObj;
			json::Reader::Read(jsonObj, sBadDocument);
			return jsonObj;
		} catch (json::Reader::ParseException& e) {
			std::cout << "Utilities:2:Caught json::ParseException: " << e.what()
					<< ", Line/offset: " << e.m_locTokenBegin.m_nLine + 1 << '/'
					<< e.m_locTokenBegin.m_nLineOffset + 1 << std::endl
					<< std::endl;
		} catch (json::Exception& e) {
			e.what();
		}
		json::Object *obj = NULL;
		return *obj;
	}

	//Convert the given the json object to String
	static std::string convertJSONToString(json::Object jo) {

		std::stringstream stream1;
		try {
			json::Writer::Write(jo, stream1);
		} catch (json::Exception &e) {
			std::cerr << "JSON Writing Exception " << e.what() << std::endl;
		}
		return stream1.str();
	}
};

#endif /* JSONIO_H_ */
