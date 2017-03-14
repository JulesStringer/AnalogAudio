/* 
 * File:   MC14052B.cpp
 * Author: jules
 * 
 * Created on 05 November 2016, 22:20
 */

#include "MC14052B.h"
#include "../PIC32Device/IODevice.h"
#include "pindefs.h"

MC14052B::MC14052B() 
{
}

MC14052B::MC14052B(const MC14052B& orig) 
{
}

MC14052B::~MC14052B() 
{
}
void MC14052B::SetLevel(unsigned char nLevel)
{
    nLevel--;
    if ( nLevel < 4 )
    {
        switch(m_nDevice)
        {
        case 1:
            CH1_MUXA_LAT = nLevel & 1;
            CH1_MUXB_LAT = nLevel >> 1 & 1;
            break;
        case 2:
            CH2_MUXA_LAT = nLevel & 1;
            CH2_MUXB_LAT = nLevel >> 1 & 1;
            break;
        }
    }
}
void MC14052B::Initialise(unsigned char nChannel)
{
    ControlledDevice::Initialise(nChannel);
    switch(m_nDevice)
    {
    case 1:
        CH1_MUXB_TRIS = 0;
        CH1_MUXB_ANSEL = 0;
        CH1_MUXB_LAT = 0;
        CH1_MUXA_TRIS = 0;
        CH1_MUXA_ANSEL = 0;
        CH1_MUXA_LAT = 0;
        break;
    case 2:
        CH2_MUXB_TRIS = 0;
        CH2_MUXB_ANSEL = 0;
        CH2_MUXB_LAT = 0;
        CH2_MUXA_TRIS = 0;
        CH2_MUXA_ANSEL = 0;
        CH2_MUXA_LAT = 0;
        break;
    }
}
void MC14052B::SendReading(IODevice* pDevice, unsigned char byCommand, unsigned char nDevice)
{
    unsigned char value = 0;
    switch(m_nDevice)
    {
    case 1:
        value = CH1_MUXB_PORT << 1 | CH1_MUXA_PORT;
        break;
    case 2:
        value = CH2_MUXB_PORT << 1 | CH2_MUXA_PORT;
        break;
    }
    // Send response 
    SendResult(pDevice, byCommand, nDevice, value);
}
