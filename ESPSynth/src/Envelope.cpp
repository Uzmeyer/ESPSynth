/*
 * Envelope.cpp
 *
 *  Created on: 11.02.2018
 *      Author: Jakob
 */

#include "Envelope.h"

const uint16_t rcp[] =  {65535, 32767, 21844, 16383, 13106, 10922, 9361, 8191, 7281, 6553, 5957, 5460, 5040, 4680, 4368, 4095, 3854, 3640, 3448, 3276, 3120, 2978, 2848, 2730, 2620, 2520, 2426, 2340, 2259, 2184, 2113, 2047, 1985, 1927, 1871, 1819, 1770, 1724, 1679, 1637, 1597, 1559, 1523, 1488, 1455, 1424, 1393, 1364, 1336, 1310, 1284, 1259, 1236, 1213, 1191, 1169, 1149, 1129, 1110, 1091, 1073, 1056, 1039, 1023, 1007, 992, 977, 963, 949, 935, 922, 909, 897, 885, 873, 861, 850, 839, 829, 818, 808, 798, 789, 779, 770, 761, 752, 744, 735, 727, 719, 711, 704, 696, 689, 682, 675, 668, 661, 654, 648, 642, 635, 629, 623, 617, 611, 606, 600, 595, 589, 584, 579, 574, 569, 564, 559, 554, 550, 545, 541, 536, 532, 528, 523, 519, 515, 511};

Envelope::Envelope(uint8_t attack, uint8_t decay, uint8_t sustain, uint8_t release) {
	this->attack = attack;
	this->decay = decay;
	this->sustain = sustain;
	this->release = release;

}

Envelope::~Envelope() {
	// TODO Auto-generated destructor stub
}

void Envelope::run()
{
	switch(currentstate)
	{
		case ATTACK:
		{
			//Serial.println("ATTACK");
			if(this->phase >= 8388480)
			{
				this->amp = 255;
				this->currentstate = DECAY;
				this->phase = 8388480;
				break;
			}

			this->amp = this->phase >> 15;
			this->phase += rcp[this->attack >> 1];
			break;
		}
		case DECAY:
		{
			//Serial.println("DECAY");
			if((this->phase >> 15) <= this->sustain || this->phase > 8388480)
			{
				this->amp = sustain;
				if(sustain)
				{
					this->currentstate = SUSTAIN;
				}
				else
				{
					this->currentstate = OFF;
					this->phase = 0;
				}
				break;
			}
			this->amp = this->phase >> 15;
			this->phase -= rcp[this->decay >> 1];
			break;
		}
		case SUSTAIN:
		{
			//Serial.println("SUSTAIN");
			break;
		}
		case RELEASE:
		{
			//Serial.println("RELEASE");
			if(this->phase > 8388480)
			{
				this->amp = 0;
				this->currentstate = OFF;
				this->phase = 0;
				break;
			}
			this->amp = this->phase >> 15;
			this->phase -= rcp[this->release >> 1];
			break;
		}
		default:
		{
			this->amp = 0;
			this->currentstate = OFF;
			break;
		}
	}
}
uint8_t Envelope::out()
{
	//Serial.print("envelope amp: ");
	//Serial.println(this->amp);
	return this->amp;
}
void Envelope::on()
{
	this->currentstate = ATTACK;
}
void Envelope::off()
{
	if(sustain)
	{
		this->currentstate = RELEASE;
	}
}
void Envelope::panic()
{
	this->currentstate = OFF;
	this->amp = 0;
	this->phase = 0;
}
void Envelope::setAttack(uint8_t attack)
{
	this->attack = attack;
}
void Envelope::setDecay(uint8_t decay)
{
	this->decay = decay;
}
void Envelope::setSustain(uint8_t sustain)
{
	this->sustain = sustain;
}
void Envelope::setRelease(uint8_t release)
{
	this->release = release;
}
Envelopestate Envelope::getState()
{
	return this->currentstate;
}
