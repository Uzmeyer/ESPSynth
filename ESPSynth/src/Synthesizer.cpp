/*
 * Synthesizer.cpp
 *
 *  Created on: 21.01.2018
 *      Author: Jakob
 */

#include "Synthesizer.h"

Synthesizer::Synthesizer() {
	/*Serial.println("Initializing NoteTable");
	for(int i = 0; i<16; i++)
	{
		for(int j; j<=127; j++)
		{
			NoteTable[i][j] = NULL;
		}
	}
	for(int i = 0; i<16; i++)
	{
		channelactive[i] = 0;
	}*/

}

Synthesizer::~Synthesizer() {
	for(int i; i<16; i++)
		{
			for(int j; j<=127; j++)
			{
				if(NoteTable[i][j])
				{
					delete NoteTable[i][j];
				}

			}
		}
}

void Synthesizer::start()
{
	Serial.println("Initializing NoteTable");
		for(int i = 0; i<16; i++)
		{
			for(int j; j<=127; j++)
			{
				NoteTable[i][j] = NULL;
			}
		}
		for(int i = 0; i<16; i++)
		{
			channelactive[i] = 0;
		}
}

void Synthesizer::noteOn(uint8_t note, uint8_t channel, uint8_t velocity)
{

	if(!velocity)
	{
		noteOff(note, channel, velocity);
		return;
	}
	if(!NoteTable[channel][note])
	{
		NoteTable[channel][note] = new Note(note);
	}
	NoteTable[channel][note]->on(velocity);
	channelactive[channel] = 1;
}

void Synthesizer::noteOff(uint8_t note, uint8_t channel, uint8_t velocity)
{

	if(NoteTable[channel][note])
	{
		NoteTable[channel][note]->off();
	}
}

void Synthesizer::midiMessage(midiMessage_t message)
{
	Serial.println("MidiMEssage Called");
	switch(message.command)
	{
	case (ALLSOUNDOFF):
	{

	}
	case (ALLNOTEOFF):
	{
		Serial.println("PANIC!");
		for(int i; i<16; i++)
		{
			for(int j; j<=127; j++)
			{
				if(NoteTable[i][j])
				{
					NoteTable[i][j]->off();
				}

			}
		}
		break;
	}
	default:
		break;

	}

}

int16_t Synthesizer::run()
{
	currentsample = 0;
	for(int i = 0; i<16; i++)
	{
		if(!channelactive[i])
		{
			continue;
		}
		int currentchannelactive = 0;
		for(int j = 0; j<128; j++)
		{
			if(NoteTable[i][j])
			{
				if(NoteTable[i][j]->state() == STOPPED)
				{
					delete NoteTable[i][j];
					NoteTable[i][j] = NULL;
					continue;
				}
				this->currentsample += NoteTable[i][j]->run();
				currentchannelactive = 1;

			}
		}
		channelactive[i] = currentchannelactive;
	}
	return currentsample;
}
