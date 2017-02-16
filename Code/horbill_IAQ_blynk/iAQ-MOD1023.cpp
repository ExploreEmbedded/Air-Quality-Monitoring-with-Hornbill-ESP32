/*

Copyright (c) 2015, Embedded Adventures
All rights reserved.

Contact us at source [at] embeddedadventures.com
www.embeddedadventures.com

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

- Neither the name of Embedded Adventures nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
THE POSSIBILITY OF SUCH DAMAGE.

*/

//	MOD1023 indoor air quality sensor Arduino library
//	Written originally by Embedded Adventures

#include "iAQ-MOD1023.h"
#include "Wire.h"

uns8 data[9]; 

void iAQClass::readRegisters() {
	int i = 0;
	Wire.requestFrom(IAQ_ADDR, 9);
	while(Wire.available()) {
		data[i] = Wire.read();
		i++;
	}
}

uns16 iAQClass::getPrediction() {
	return (uns16)((data[0] << 8) + data[1]);
}

sn32 iAQClass::getResistance() {
	return (sn32)(data[3] << 24) + (sn32)(data[4] << 16) + (sn32)(data[5] << 8) + (sn32)data[6];
}

uns16 iAQClass::getTVOC() {
	return (uns16)(data[7] << 8) + (uns16)(data[8]);
}

char *iAQClass::getStatus() {
	if (data[2] == 0x00)
		return "OK";
	else if (data[2] == 0x10)
		return "RUNIN";
	else if (data[2] == 0x01)
		return "BUSY";
	else if (data[2] == 0x80)
		return "ERROR";
	else
		return "UNRECOGNIZED DATA";
}

iAQClass iaq;
