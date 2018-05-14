/*
 * Mixer.h
 *
 *  Created on: 11.02.2018
 *      Author: Jakob
 */

#ifndef MIXER_H_
#define MIXER_H_

#include "SynthComponent.h"

class Mixer: public SynthComponent {
public:
	Mixer(uint8_t level1 = 0, uint8_t level2 = 0, uint8_t level3 = 0);
	virtual ~Mixer();
	void setLevel1(uint8_t level);
	void setLevel2(uint8_t level);
	void setLevel3(uint8_t level);
	int16_t mix(int16_t val1 = 0, int16_t val2 = 0, int16_t val3 = 0);
	int16_t out();

private:
	int16_t currentsample = 0;
	uint8_t level1 = 0;
	uint8_t level2 = 0;
	uint8_t level3 = 0;
};

#endif /* MIXER_H_ */
