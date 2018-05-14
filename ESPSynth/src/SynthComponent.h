/*
 * SynthComponent.h
 *
 *  Created on: 09.02.2018
 *      Author: Jakob
 */

#ifndef SYNTHCOMPONENT_H_
#define SYNTHCOMPONENT_H_

#include "Arduino.h"

class SynthComponent {
public:
	SynthComponent();
	virtual ~SynthComponent();
	//virtual int16_t out() = 0;
};

#endif /* SYNTHCOMPONENT_H_ */
