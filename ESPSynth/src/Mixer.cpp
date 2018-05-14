/*
 * Mixer.cpp
 *
 *  Created on: 11.02.2018
 *      Author: Jakob
 */

#include "Mixer.h"

Mixer::Mixer(uint8_t level1, uint8_t level2, uint8_t level3) {
	this->level1 = level1;
	this->level2 = level2;
	this->level3 = level3;

}

Mixer::~Mixer() {
	// TODO Auto-generated destructor stub
}
void Mixer::setLevel1(uint8_t level)
{
	this->level1 = level;
}

void Mixer::setLevel2(uint8_t level)
{
	this->level2 = level;
}

void Mixer::setLevel3(uint8_t level)
{
	this->level3 = level;
}

int16_t Mixer::mix(int16_t val1, int16_t val2, int16_t val3)
{
	this->currentsample = ((val1 * level1) / 255) + ((val2 * level2) / 255) + ((val3 * level3) / 255);
	return currentsample;
}

int16_t Mixer::out()
{
	return this->currentsample;
}

