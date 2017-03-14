/* 
 MIT License

Copyright (c) 2017 Jules Stringer

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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
