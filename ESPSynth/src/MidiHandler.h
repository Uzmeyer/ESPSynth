/*
 * MidiHandler.h
 *
 *  Created on: 21.01.2018
 *      Author: Jakob
 */

#ifndef MIDIHANDLER_H_
#define MIDIHANDLER_H_

#include "Arduino.h"

#define NOTEOFF 0x80
#define NOTEON  0x90
#define POLYPRESS 0xA0 //poly aftertouch
#define CONTROL 0xB0
#define PROGRAM 0xC0 //program change, only one command byte
#define CHANNELPRESS 0xD0 //channel aftertouch, only one command byte
#define PITCHBEND 0xE0
#define SYSTEM 0xF0
#define ALLSOUNDOFF 0x78
#define ALLNOTEOFF 0x7B

struct midiMessage_t{
	uint8_t command;
	uint8_t channel;
	uint8_t data1;
	uint8_t data2;
};



midiMessage_t pollMidi();

#endif /* MIDIHANDLER_H_ */
