/***************************************************
Copyright (c) 2018 Luis Llamas
(www.luisllamas.es)
Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/
 
#ifndef _I2CSCANNER_h
#define _I2CSCANNER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Wire.h>

class I2CScanner
{
 protected:
	void inline printHeader();
	void inline printAdressResult(byte error, byte address);
	void inline printResult();
	byte inline scan(byte address);

 public:
	uint8_t Devices_Count;
	uint8_t Low_Address = 1;
	uint8_t High_Address = 127;
	
	void Init();
	bool Scan();
	bool Scan(byte address);
	bool Scan(byte addreses[], uint8_t length);
};

#endif

