/*
 * MidiHandler.cpp
 *
 *  Created on: 21.01.2018
 *      Author: Jakob
 */

#include "MidiHandler.h"

uint8_t receive;
uint8_t count;
uint8_t numbytes;
midiMessage_t message;

extern HardwareSerial MidiSerial;

midiMessage_t pollMidi()
{
	message.command = 0;

			while(MidiSerial.available())
				  {
				    receive = MidiSerial.read();
				    if(receive > 127)
				    {
				    	count = 0;
				    	message.command = receive & 0xF0;
				    	message.channel = receive & 0x0F;
				    	if(message.command == PROGRAM || message.command == CHANNELPRESS)
				    	{
				    		numbytes = 1;
				    	}
				    	else
				    	{
				    		numbytes = 2;
				    	}
				    }

				    else
				    {
				      if(count == numbytes)
				      {
				        return message;
				      }

				      if(count < 1)
				      {
				    	message.data1 = receive;
				    	count++;
				      }
				      else if(count >= 1)
				      {
				    	message.data2 = receive;
				      }
				    }

				  }


	return message;
}

