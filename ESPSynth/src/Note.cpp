/*
 * Note.cpp
 *
 *  Created on: 07.02.2018
 *      Author: Jakob
 */

#include "Note.h"

const static uint32_t freqIncTab[] = {796254, 843601, 893765, 946911, 1003217, 1062871, 1126073, 1193033, 1263974, 1339134, 1418763, 1503127, 1592507, 1687203, 1787529, 1893821, 2006434, 2125742, 2252146, 2386065, 2527948, 2678268, 2837526, 3006254, 3185015, 3374406, 3575058, 3787642, 4012867, 4251485, 4504291, 4772130, 5055896, 5356535, 5675051, 6012507, 6370030, 6748811, 7150117, 7575285, 8025735, 8502970, 9008582, 9544261, 10111792, 10713070, 11350103, 12025015, 12740059, 13497623, 14300233, 15150569, 16051469, 17005939, 18017165, 19088521, 20223584, 21426141, 22700205, 24050030, 25480119, 26995246, 28600467, 30301139, 32102938, 34011878, 36034330, 38177043, 40447168, 42852281, 45400411, 48100060, 50960238, 53990491, 57200933, 60602278, 64205876, 68023757, 72068660, 76354085, 80894335, 85704563, 90800821, 96200119, 101920476, 107980983, 114401866, 121204555, 128411753, 136047513, 144137319, 152708170, 161788671, 171409126, 181601643, 192400238, 203840952, 215961966, 228803732, 242409110, 256823506, 272095026, 288274639, 305416341, 323577341, 342818251, 363203285, 384800477, 407681904, 431923931, 457607465, 484818220, 513647012, 544190053, 576549277, 610832681, 647154683, 685636503, 726406571, 769600953, 815363807, 863847862, 915214929, 969636441, 1027294024, 1088380105, 1153098554, 1221665363};

Note::Note(uint8_t note) {
	this->note = note;
	this->velocity = 0;
	this->currentstate = STOPPED;
	OSC1 = new Oscillator(freqIncTab[note], TRIANGLE);
	VOL = new Amp(midiToCV(this->velocity));
	ENV1 = new Envelope(100, 50, 200, 50);

}

Note::~Note() {

}

void Note::on(uint8_t velocity)
{
	//Serial.println("note.On Called");
	this->velocity = midiToCV(velocity);
	ENV1->on();
	this->currentstate = TRIGGERED;
}
void Note::off()
{
	//Serial.println("note.Off Called");
	this->currentstate = RUNNING;
	ENV1->off();
}
int16_t Note::run()
{
	//Serial.println("note.Run Called");
	OSC1->run();
	VOL->setAmplification((this->velocity * ENV1->out()) / 255);
	currentsample = VOL->amplify(OSC1->out());
	ENV1->run();
	if(ENV1->getState() == OFF)
	{
		this->currentstate = STOPPED;
		//Serial.println("note stopped");
	}
	//Serial.print("currentsample: ");
	//Serial.println(currentsample);
	return currentsample;
}
State Note::state()
{
	return this->currentstate;
}


uint8_t midiToCV(uint8_t command)
{
	if(!command)
	{
		return 0;
	}
	return (command << 1) + 1;
}
