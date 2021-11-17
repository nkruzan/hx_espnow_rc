#pragma once

#include <Arduino.h>
#include <stdint.h>

#include "ppm_packet.h"
//include for HXRCLOG usage
#include "HX_ESPNOW_RC_Common.h"

//write packet every ?ms
#define PPM_RATE_MS            15
#define PPM_FRAME_LENGTH 22500  //set the PPM frame length in microseconds (1ms = 1000µs)
#define PPM_PULSE_LENGTH 300  //set the pulse length
#define PPM_SIG_PIN 2 //set PPM signal output pin on the arduino
#define PPM_INVERTED false
#define PPM_CPU_MHZ 80
#define PPM_CHANNEL_NUMBER 18  //set the number of chanels
//=====================================================================
//=====================================================================
class PPMEncoder
{
private:
    PPMPacket lastPacket;
    unsigned long lastPacketTime;
    int ppm[PPM_CHANNEL_NUMBER];
public:
    PPMEncoder();

    void init(uint8_t tx_pin, bool invert );

    void setFailsafe( bool failsafe );
    void setChannelValueDirect( uint8_t index, uint16_t value );
    void setChannelValue( uint8_t index, uint16_t value );
    void loop();
};



