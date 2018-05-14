/*
 * Amp.h
 *
 *  Created on: 11.02.2018
 *      Author: Jakob
 */

#ifndef AMP_H_
#define AMP_H_

#include "SynthComponent.h"

class Amp: public SynthComponent {
public:
	Amp(uint8_t amplification = 0);
	virtual ~Amp();
	void setAmplification(uint8_t amplification);
	int16_t out();
	int16_t amplify(int16_t input);

private:
	int16_t currentsample = 0;
	uint8_t amplification = 0;
};

#endif /* AMP_H_ */
