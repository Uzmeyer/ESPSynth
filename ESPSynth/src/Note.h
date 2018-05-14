/*
 * Note.h
 *
 *  Created on: 07.02.2018
 *      Author: Jakob
 */

#ifndef NOTE_H_
#define NOTE_H_

#include "Arduino.h"
#include "Oscillator.h"
#include "Amp.h"
#include "Envelope.h"

enum State {
	STOPPED,	//note is off
	TRIGGERED,  //note is running and key is still pressed
	RUNNING		//note is still running but key has been released
};

class Note {
public:
	Note(uint8_t note);
	virtual ~Note();
	void on(uint8_t velocity);
	void off();
	int16_t run();
	State state();
	void midiCommand(uint8_t command = 0, uint8_t byte1 = 0, uint8_t byte2 = 0);

private:
	uint8_t note;
	uint8_t velocity;
	int16_t currentsample = 0;
	State currentstate;
	Oscillator* OSC1;
	Amp* VOL;
	Envelope* ENV1;

};

uint8_t midiToCV(uint8_t command);

#endif /* NOTE_H_ */
