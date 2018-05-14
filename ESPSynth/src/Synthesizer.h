/*
 * Synthesizer.h
 *
 *  Created on: 21.01.2018
 *      Author: Jakob
 */

#ifndef SYNTH_H_
#define SYNTH_H_

#include "Arduino.h"
#include "Note.h"
#include "MidiHandler.h"

//extern HardwareSerial Serial;


class Synthesizer {
public:
	Synthesizer();
	virtual ~Synthesizer();
	void start();
	void noteOn(uint8_t note, uint8_t channel, uint8_t velocity);
	void noteOff(uint8_t note, uint8_t channel, uint8_t velocity);
	void midiMessage(midiMessage_t message);
	int16_t run();

private:
	Note* NoteTable [16][128];
	uint8_t channelactive[16];
	int16_t currentsample = 0;

};


#endif /* SYNTH_H_ */

