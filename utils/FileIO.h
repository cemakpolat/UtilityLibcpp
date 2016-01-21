/*
 * FileIO.h
 *
 *  Created on: Sep 27, 2013
 *      Author: cem
 */

#ifndef FILEIO_H_
#define FILEIO_H_

#include <string>
#include <vector>
#include <unistd.h>
#include <sys/stat.h>
#include <sstream>
#include <fstream>
#include <iostream>
/*! \class Utilities
 *  \brief Utilities, as its name implies, is composed of utility functions
 *
 */

using namespace std;

class FileIO {
public:
	FileIO();
	~FileIO();

	/**
	 * Write the text in the file
	 * \param fileName
	 * \param string will be written
	 */
	static void fileWrite(string& fileName, string& outputString) {
		try {
			ofstream file;
			file.open(fileName.c_str());
			if (file.is_open()) {
				file << outputString;
				file << "\n";
				file.close();
			}
		} catch (exception& e) {
			cerr << " " << e.what() << endl;
		}
	}
	/**
	 * Append the text to the provided file
	 * \param fileName
	 * \param text will be appended
	 */
	static void fileAppend(string& fileName, string& outputString) {
		try {
			ofstream file;
			file.open(fileName.c_str(), ios::app);
			if (file.is_open()) {
				file << outputString;
				file << "\n";
				file.close();
			}
		} catch (exception& e) {
			cerr << " " << e.what() << endl;
		}
	}

	/**
	 *Read the given file and return file content in a string
	 * \param string s
	 * \sa
	 * \return
	 */
	static string readFile(string& fileName) {
		ifstream infile;
		infile.open(fileName.c_str());
		string sLine;
		while (!infile.eof()) {
			getline(infile, sLine);
			cout << sLine << endl;
			sLine += sLine;
		}
		infile.close();
		return sLine;
	}

	/**
	 *Read the given file and return file content in a string via append method
	 * \param fileName
	 * \return the content of the file
	 */
	static string readFile2(string& fileName) {
		ifstream infile;
		string text;
		infile.open(fileName.c_str());
		string sLine;
		while (!infile.eof()) {
			getline(infile, sLine);

			text.append(sLine);
		}
		infile.close();
		return text;
	}

	/**
	 *Find the root path of the given file.
	 * \param
	 * \sa
	 * \return
	 */
	static string pathFinder(const string folderName, const string fileName) {
		char resolved_path[200];

		//locate the requested paths
		string x = "./" + folderName;
		realpath(x.c_str(), resolved_path);
		//printf("\n%s\n", resolved_path);

		//check whether path refers to an object or not
		struct stat sb;
		if (!(stat(resolved_path, &sb) == 0 && S_ISDIR(sb.st_mode))) {
			string cmd = "mkdir " + folderName;
			system(cmd.c_str());
		}
		string path = resolved_path;
		path = path + "/" + fileName;
		//cout << path << endl;

		return path;
	}
};

#endif /* FILEIO_H_ */
