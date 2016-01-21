/*
 * NetUtil.h
 *
 *  Created on: Sep 27, 2013
 *      Author: cem
 */

#ifndef NETUTIL_H_
#define NETUTIL_H_

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Utilities.h"
/*! \class Utilities
 *  \brief Utilities, as its name implies, is composed of utility functions
 *
 */

class NetUtil {
public:
	NetUtil();
	~NetUtil();

	/**
	 * Return Interface via IWconfig command
	 * \return
	 */
	/*Get Network Interface*/
	static string getNetworkInterface() {

		string result = "";
		string str2("802.11");
		size_t found;
		//wlan0
		result = Utilities::exec("iwconfig wlan0");
		found = result.find(str2);
		if (found != string::npos) {
			//cout<<"device is wlan0"<<endl;
			return "wlan0";
		}
		//eth1
		result = Utilities::exec("iwconfig eth1");
		found = result.find(str2);
		if (found != string::npos) {
			return "eth1";
		}
		//en1
		result = Utilities::exec("iwconfig en1");
		found = result.find(str2);
		if (found != string::npos) {
			return "en1";
		}
		//eth0
		result = Utilities::exec("iwconfig eth0");
		found = result.find(str2);
		if (found != string::npos) {
			return "eth0";
		}

	}
	/*
	 * Scan all Access Point around the current AP return a list
	 * including MAC,ESSID and signal level of them.
	 * TODO:Please check this function!
	 */

	struct APObject{
		std::string address;
		std::string essid;
		std::string quality;
	};

	static vector<APObject> scanAllAP() {
		vector<APObject> list;
		string result = "";
		string s =
				"sudo iwlist " + getNetworkInterface()
						+ " scanning|awk '/Address:/{print $4$5}/ESSID:/{print $1}/Quality/{print $3}'>scanningResult";
		result = Utilities::exec(s);
		std::ifstream infile("/root/scanningResult");
		try {
			std::string line;
			size_t found;
			APObject ap;
			while (std::getline(infile, line)) {
				string str("Address");
				found = line.find(str);
				if (found != string::npos) {
					ap.address=line;
				}
				str = "ESSID";
				found = line.find(str);
				if (found != string::npos) {
					ap.essid=line;
				}
				str = "level";
				found = line.find(str);
				if (found != string::npos) {
					ap.quality=line;
					list.push_back(ap);
				}
			}
			return list;
		} catch (std::exception& e) {
			e.what();

		}
		return list;
	}
};
#endif /* NETUTIL_H_ */
