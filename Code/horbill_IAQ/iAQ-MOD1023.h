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

#ifndef __IAQ-MOD1023_H
#define __IAQ-MOD1023_H

#include "Arduino.h"

#define IAQ_ADDR	0x5A

#define uns8	unsigned char
#define uns16	unsigned int
#define sn32	long int

class iAQClass {
	public:
		/* Read all 9 registers in one shot*/
		void readRegisters();
		
		/* Calculate CO2 prediction*/
		uns16 getPrediction();
		
		/* Calculate sensor resistance in ohms*/
		sn32 getResistance();
		
		/* Calculate TVOC prediction*/
		uns16 getTVOC();
		
		/* Get status of data 
		OK - data is valid
		RUNIN - warm-up phase
		BUSY - data integrity >8 bits not guaranteed
		ERROR - sensor possibly defective 
		UNRECOGNIZED DATA - physical connection error*/
		char* getStatus();
};

extern iAQClass iaq;

#endif