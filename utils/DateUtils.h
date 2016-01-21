/*
 * DateUtils.h
 *
 *  Created on: Sep 27, 2013
 *      Author: cem
 */

#ifndef DATEUTILS_H_
#define DATEUTILS_H_
#include <string>
#include <vector>
#include "Casting.h"
#include "StringOp.h"
/*! \class Utilities
 *  \brief Utilities, as its name implies, is composed of utility functions
 *
 */

using namespace std;

class DateUtils {
public:
	DateUtils();
	~DateUtils();

	/**
	 * Convert the given second to String
	 * \param second
	 * \sa
	 * \return string long time
	 */
	static std::string convertlongTimeToStringTime(long second) {
		long elapsedTime = second;
		int hours = (int) elapsedTime / (60 * 60);
		int minutes = (int) (elapsedTime / (60)) % 60;
		int seconds = (int) (elapsedTime) % 60;
		//int mili = (int) (milisecond) % (1000);
		// System.out.println("convertMiliSecondTimeToString: "+milisecond);
		// System.out.println("hour: "+hours + ":" + minutes + ":" + seconds +
		// ":" + mili);
		std::string result = Casting::convertIntToString(hours) + ":"
				+ Casting::convertIntToString(minutes) + ":"
				+ Casting::convertIntToString(seconds);
		//std::cout<<"longToString: "<<result<<std::endl;
		return result;
	}
	/**
	 * Time compare with current time
	 * \param value
	 * \param time
	 * \sa
	 * \return true if time is smaller than given values else false
	 */
	static bool timeCompareWithCurrentTime(int value, std::string& time) {
		//std::cout<<"time in dhcp: "<<atoi(time.c_str())<<std::endl;
		//std::cout<<"current time: "<<getCurrentTimeAsSecond()<<std::endl;
		if ((getCurrentTimeAsSecond() - atoi(time.c_str())) < value) {
			return true;
		} else {
			return false;
		}

	}
	/**
	 * \return current Minute in integer format
	 */
	static int getCurrentMinute() {

		std::string time = getCurrentTimeAsString();
		std::vector<std::string> list = StringOp::split(time, ':');
		int hour = Casting::convertStringToInt(list[0]);
		int min = Casting::convertStringToInt(list[1]);
		return hour * 60 + min;
	}

	/**
	 * Get Current Date time in the format %Y/%m/%d-%H:%M:%S
	 * \return current date time in the string
	 */
	static std::string getCurrentDateAndTimeAsString() {
		time_t rawtime;
		struct tm * timeinfo;
		char buffer[80];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, 80, "%Y/%m/%d-%H:%M:%S", timeinfo);
		std::stringstream ss;
		ss << buffer;
		return ss.str();

	}
	/**
	 * Get current time in the format "%H:%M"
	 * \return current time in string format
	 */
	static std::string getCurrentTimeHM() {
		time_t rawtime;
		struct tm * timeinfo;
		char buffer[80];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, 80, "%H:%M", timeinfo);
		std::stringstream ss;
		ss << buffer;
		return ss.str();

	}
	/**
	 * Get current time as string in format  "%H:%M:%S"
	 * \return current time in the string format
	 */
	static std::string getCurrentTimeAsString() {
		time_t rawtime;
		struct tm * timeinfo;
		char buffer[80];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, 80, "%H:%M:%S", timeinfo);
		std::stringstream ss;
		ss << buffer;
		return ss.str();

	}
	/**
	 * Convert the given time to string format  "%H:%M:%S"
	 * \param time
	 * \return string
	 */
	static std::string getTimeFromGivenTime(const time_t& time) { //time should be already assigned to time value.
		struct tm * timeinfo;
		char buffer[80];
		timeinfo = localtime(&time);
		strftime(buffer, 80, "%H:%M:%S", timeinfo);
		std::stringstream ss;
		ss << buffer;
		return ss.str();
	}
	/**
	 * Get current Date as string in the format  "%Y/%m/%d"
	 * \return string
	 */
	static std::string getCurrentDateAsString() {
		time_t rawtime;
		struct tm * timeinfo;
		char buffer[80];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, 80, "%Y/%m/%d", timeinfo);
		std::stringstream ss;
		ss << buffer;
		return ss.str();

	}
	/**
	 * Return given number in the form of the second
	 * \param second
	 * \return second
	 */
	static int second(int second) {
		//int oneSecond=1000000;
		return 1000000 * second;
	}
	/**
	 * Return given number in the form of minutes
	 * \param min
	 * \return min
	 */
	static unsigned int minute(int min) {
		//int oneSecond=1000000*60;
		return 1000000 * 60 * min;
	}

	/**
	 * Convert the String in the date format to Milisecond
	 * \param  time
	 * \return long miliseconds
	 */
	static long convertStringToMilisecond(std::string time) {

		std::vector<std::string> strTime = StringOp::split(time, ':');
		long second = 0;
		second = atoi(strTime[0].c_str()) * 1 * 60 * 60 + second;
		second = atoi(strTime[1].c_str()) * 1 * 60 + second;
		second = atoi(strTime[2].c_str()) * 1 + second;
		//milisecond = atoi(strTime[3].c_str()) + milisecond;
		// System.out.println(" convertStringToMilisecond: "+milisecond);
		return second;
	}
	/**
	 * Get Current Time as second
	 * \return second
	 */
	static time_t getCurrentTimeAsSecond() {
		time_t seconds;
		seconds = time(NULL);
		return seconds;
	}
	/**
	 *Convert milisecond in the time format of  "%Y/%m/%d-%H:%M:%S"
	 *\param  time
	 * \return string
	 */
	static std::string convertMilisecondToString(const time_t& time) {//time should be already assigned to time value.
		struct tm * timeinfo;
		char buffer[80];
		timeinfo = localtime(&time);
		strftime(buffer, 80, "%Y/%m/%d-%H:%M:%S", timeinfo);
		std::stringstream ss;
		ss << buffer;
		return ss.str();
	}
	/**
	 * Convert data time string to Milisecond
	 * \param  time
	 * \return time_t
	 */
	static time_t convertDateTimeStringToMilisecond(const std::string& time1) {
		if (time1 != "0") {
			std::vector<std::string> date;
			std::vector<std::string> d;
			std::vector<std::string> t;
			date = StringOp::split(time1, '-');
			d = StringOp::split(date[0], '/');
			t = StringOp::split(date[1], ':');
			time_t rawtime;
			struct tm * timeinfo;
			time(&rawtime);
			timeinfo = localtime(&rawtime);
			timeinfo->tm_year = atoi(d[0].c_str()) - 1900;
			timeinfo->tm_mon = atoi(d[1].c_str()) - 1;
			timeinfo->tm_mday = atoi(d[2].c_str());
			timeinfo->tm_hour = atoi(t[0].c_str());
			timeinfo->tm_min = atoi(t[1].c_str());
			timeinfo->tm_sec = atoi(t[2].c_str());
			time_t x = mktime(timeinfo);
			return x;
		} else {

			return 0;
		}
	}
	/**
	 * Convert time string to Milisecond
	 * \param time
	 * \return time_t milisecond
	 */
	static time_t convertTimeStringToMilisecond(const std::string& time1) {
		if (time1 != "0") {
			std::vector<std::string> t;
			t = StringOp::split(time1, ':');
			time_t rawtime;
			struct tm * timeinfo;
			time(&rawtime);
			timeinfo = localtime(&rawtime);
			//	timeinfo->tm_year = atoi(d[0].c_str())-1900;
			//	timeinfo->tm_mon = atoi(d[1].c_str())-1;
			//	timeinfo->tm_mday =atoi(d[2].c_str());
			timeinfo->tm_hour = atoi(t[0].c_str());
			timeinfo->tm_min = atoi(t[1].c_str());
			timeinfo->tm_sec = atoi(t[2].c_str());
			time_t x = mktime(timeinfo);
			return x;
		} else {
			return 0;
		}
	}
};

#endif /* DATEUTILS_H_ */
