/*
 * Oscillator.h
 *
 *  Created on: 09.02.2018
 *      Author: Jakob
 */

#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#include "TimedSynthComponent.h"

enum Waveform
{
	SINE,
	TRIANGLE,
	SQUARE,
	SAW
};
class Oscillator: public TimedSynthComponent {
public:
	Oscillator(uint32_t frequency = 0, Waveform waveform = SINE);
	virtual ~Oscillator();
	void setFrequency(uint32_t frequency);
	void setOffset(int32_t offset);
	void setWaveform(Waveform waveform);
	void setPulsewidth(uint8_t pulsewidth);
	void run();
	int16_t out();

private:
	uint32_t frequency;
	int32_t frequency_offset = 0;
	uint32_t phase = 0;
	int16_t currentsample = 0;
	Waveform waveform;
	uint8_t pulsewidth = 127;

};

/*
class LFO: public TimedSynthComponent {
public:
	LFO();
	virtual ~LFO(uint32_t frequency = 0, Waveform waveform = SINE);
	void setFrequency(uint32_t frequency);
	void setWaveform(Waveform waveform);
	void setPulsewidth(uint8_t pulsewidth);
	void run();
	int16_t out();

private:
	uint32_t frequency;
	uint32_t phase;
	int16_t currentsample;
	Waveform waveform;
	uint8_t pulsewidth;
};
*/


#endif /* OSCILLATOR_H_ */
