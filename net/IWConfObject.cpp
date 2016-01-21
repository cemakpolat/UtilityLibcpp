/*
 * IWConfObject.cpp
 *
 *  Created on: Mar 4, 2013
 *      Author: cem
 */

#include "IWConfObject.h"
#include "Casting.h"

/*! \class IWConfObject
 *  \brief
 */

IWConfObject::IWConfObject() {

}

IWConfObject::~IWConfObject() {
}
std::string IWConfObject::getLinkQuality(){
	return this->linkQuality;
}
std::string IWConfObject::getSignalLevel(){
	return this->signalLev;
}
std::string IWConfObject::getMacAddr(){
	return this->macAddr;
}
std::string IWConfObject::getChannel(){
	return this->channel;
}

void IWConfObject::setChannel(std::string& val){
	this->channel=val;
}
std::string IWConfObject::getSNR() {
	int sigLev = Casting::convertStringToIntC(this->signalLev);
	int noiseLev = Casting::convertStringToIntC(this->noiseLevel);
	int res = sigLev - noiseLev;
	return Casting::convertIntToString(res);
}
std::string IWConfObject::getSSID() {
	return this->ssid;
}
std::string IWConfObject::getTXPower() {
	return this->txpower;
}
std::string IWConfObject::getBitRate() {
	return this->bitrate;
}
std::string IWConfObject::getRetryLimit() {
	return this->retryLim;
}

std::string IWConfObject::getNoiseLevel() {
	return this->noiseLevel;
}
