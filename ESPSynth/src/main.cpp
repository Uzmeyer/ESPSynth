#include <Arduino.h>
#include "Glock.h"
#include <soc/rtc.h>
#include "driver/i2s.h"
#include "Synthesizer.h"
#include "MidiHandler.h"


static const i2s_port_t i2s_num = (i2s_port_t)I2S_NUM_0; // i2s port number 0

//static i2s_config_t i2s_config;
static const i2s_config_t i2s_config = {
     .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX), //normal external dac
     .sample_rate = 44100,  //44100 sample rate
     .bits_per_sample = (i2s_bits_per_sample_t)I2S_BITS_PER_SAMPLE_16BIT,
     .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
     .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
     .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
     .dma_buf_count = 8, //1 buffer did not work
     .dma_buf_len = 64,  //small buffer for low latency
	 .use_apll = false
};

static const i2s_pin_config_t pin_config = {
    .bck_io_num = 26,
    .ws_io_num = 25,
    .data_out_num = 14,
    .data_in_num = I2S_PIN_NO_CHANGE
};

uint16_t sample_pushed = 1;
int16_t currentsample = 0;
int32_t currentI2S = 0;
HardwareSerial MidiSerial(1);
Synthesizer Synth;
Oscillator Osc;
midiMessage_t midiMessage;

int32_t assembleI2S(int16_t sample);

uint32_t Ringbuffer[256];
uint8_t RingWrite=0;
uint8_t RingRead=0;
uint8_t RingCount=0;

midiMessage_t midiBuffer[256];
uint8_t midiWrite = 0;
uint8_t midiRead = 0;
uint8_t midiCount = 0;

int newmessage = 0;

void setup() {
    // put your setup code here, to run once:
    
}

void loop() {
    // put your main code here, to run repeatedly:
}