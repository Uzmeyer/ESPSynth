/*
 * Envelope.h
 *
 *  Created on: 11.02.2018
 *      Author: Jakob
 */

#ifndef ENVELOPE_H_
#define ENVELOPE_H_

#include "TimedSynthComponent.h"

enum Envelopestate{
	ATTACK,
	DECAY,
	SUSTAIN,
	RELEASE,
	OFF
};

class Envelope: public TimedSynthComponent {
public:
	Envelope(uint8_t attack = 0, uint8_t decay = 0, uint8_t sustain = 0, uint8_t release = 0);
	virtual ~Envelope();
	void run();
	uint8_t out();
	void on();
	void off();
	void panic();
	void setAttack(uint8_t attack);
	void setDecay(uint8_t attack);
	void setSustain(uint8_t attack);
	void setRelease(uint8_t attack);
	Envelopestate getState();

private:
	uint8_t attack;
	uint8_t decay;
	uint8_t sustain;
	uint8_t release;
	uint8_t amp = 0;
	uint8_t prevamp = 0;
	Envelopestate currentstate = ATTACK;
	uint32_t phase = 0;
};

#endif /* ENVELOPE_H_ */
