/*
 * Amp.cpp
 *
 *  Created on: 11.02.2018
 *      Author: Jakob
 */

#include "Amp.h"

Amp::Amp(uint8_t amplification) {
	this->amplification = amplification;

}

Amp::~Amp() {
	// TODO Auto-generated destructor stub
}

void Amp::setAmplification(uint8_t amplification)
{
	this->amplification = amplification;
	//Serial.print("amplification set: ");
	//Serial.println(this->amplification);
}
int16_t Amp::out()
{
	return this->currentsample;
}
int16_t Amp::amplify(int16_t input)
{
	//Serial.print("amp in: ");
	//Serial.println(input);
	this->currentsample = (input*amplification) / 256;
	//Serial.print("amp out: ");
	//Serial.println(this->currentsample);
	return this->currentsample;
}
