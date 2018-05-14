/*
 * TimedSynthComponent.h
 *
 *  Created on: 09.02.2018
 *      Author: Jakob
 */

#ifndef TIMEDSYNTHCOMPONENT_H_
#define TIMEDSYNTHCOMPONENT_H_

#include "SynthComponent.h"

class TimedSynthComponent: public SynthComponent {
public:
	TimedSynthComponent();
	virtual ~TimedSynthComponent();
	virtual void run() = 0;
};

#endif /* TIMEDSYNTHCOMPONENT_H_ */
