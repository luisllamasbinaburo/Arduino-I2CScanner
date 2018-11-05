/***************************************************
Copyright (c) 2018 Luis Llamas
(www.luisllamas.es)
Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/
 
#include "I2CScanner.h"

void I2CScanner::printHeader()
{
	Serial.println(F("--- Scan started ---"));
}

void I2CScanner::printAdressResult(byte error, byte address)
{
	if (error == 0)
	{
		Serial.print(F("I2C device found at address 0x"));
		if (address < 16) Serial.print("0");
		Serial.print(address, HEX);
		Serial.println(F("  !"));

		Devices_Count++;
	}
	else if (error == 4)
	{
		Serial.print(F("Unknow error at address 0x"));
		if (address < 16) Serial.print("0");
		Serial.println(address, HEX);
	}
}

void I2CScanner::printResult()
{
	if (Devices_Count == 0) Serial.println(F("No I2C devices found"));
	Serial.println(F("--- Scan finished ---\n"));
}


byte I2CScanner::scan(byte address)
{
	Wire.beginTransmission(address);
	byte error = Wire.endTransmission();
	return error;
}

void I2CScanner::Init()
{
	Wire.begin();
}

bool I2CScanner::Scan()
{
	printHeader();
	
	Devices_Count = 0;
	for (byte address = Low_Address; address < High_Address; address++)
	{
		byte error = scan(address);
		printAdressResult(error, address);
	}

	printResult();
	return Devices_Count > 0;
}

bool I2CScanner::Scan(byte address)
{
	printHeader();

	Devices_Count = 0;
	byte error = scan(address);
	printAdressResult(error, address);

	printResult();
	return Devices_Count > 0;
}

bool I2CScanner::Scan(byte addreses[], uint8_t length)
{
	printHeader();

	Devices_Count = 0;
	for (byte index = 0; index < length; index++)
	{
		byte address = addreses[index];
		byte error = scan(address);
		printAdressResult(error, address);
	}

	printResult();
	return Devices_Count > 0;
}
