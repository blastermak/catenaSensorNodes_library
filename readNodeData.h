/* 
	readNodeData.h - Header file for reading data from Catena nodes
	Created by Jim Mak, September 19th 2017
	For use with Catena nodes
*/
#ifndef readNodeData_h
#define readNodeData_h

#include "Arduino.h"
#include "DallasTemperature.h"

class readNodeData {
  public:
	//Constructor for DS18B20 sensor
	//The idea is to use shared DallasTemperature object created from OneWire object
    readNodeData(String sensorLocation, String sensorSpecifier, String sensorType, uint8_t sensorAddress[8], DallasTemperature dtInstance);
	
	//Variabelen 
    String		_sensorLocation;
	String		_sensorSpecifier;
    String		_sensorType;
	uint8_t*	_sensorAddress;
    float		_sensorValue1;
	float		_sensorValue2;
	
	DallasTemperature _dtInstance;

	//Functies
	void returnAddress();
	float returnTemp();
	const char* prepareMqttChannel();
};

#endif