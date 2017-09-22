/* 
	readNodeData.cpp - Library for dynamically reading sensor data from Catena nodes
	Created by Jim Mak, September 19th 2017
	For use with Catena nodes
*/
#include "Arduino.h"
#include "readNodeData.h"
#include "OneWire.h"
#include "DallasTemperature.h"


readNodeData::readNodeData(String sensorLocation, String sensorSpecifier, String sensorType, uint8_t sensorAddress[8], DallasTemperature dtInstance){
	this->_sensorLocation	= sensorLocation;
	this->_sensorSpecifier	= sensorSpecifier;
	this->_sensorType		= sensorType;
	this->_sensorAddress	= sensorAddress;
	this->_dtInstance		= dtInstance;
}

void readNodeData::returnAddress(){
	for (uint8_t i = 0; i < 8; i++){
		Serial.print("0x");
		Serial.print(this->_sensorAddress[i], HEX);
		Serial.print(", ");
	}
}

const char* readNodeData::prepareMqttChannel(){
	char _tempString[200];
	snprintf(_tempString, sizeof(_tempString), "catena/sensor/%s/%s/%s", this->_sensorLocation.c_str(), this->_sensorType.c_str(), this->_sensorSpecifier.c_str());
	Serial.println(_tempString);
	return _tempString;
}


float readNodeData::returnTemp(){
	this->_dtInstance.requestTemperaturesByAddress(this->_sensorAddress);
	float temp = this->_dtInstance.getTempC(this->_sensorAddress);
	return temp;
}