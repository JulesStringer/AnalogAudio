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
 * File:   MCP4341.h
 * Author: jules
 *
 * Created on 05 November 2016, 21:15
 */

#ifndef MCP4341_H
#define	MCP4341_H

#include "../PIC32Device/ControlledDevice.h"
class IODevice;
#include "MCP4341SPI2.h"
//
// Addresses
// 0 Volatile Wiper 0
// 1 Volatile Wiper 1
// 2 NV Wiper 0
// 3 NV Wiper 1
// 4 Volatile TCON
// 5 Status
// 6 Volatile wiper 2
// 7 Volatile wiper 3
// 8 NV Wiper 2
// 9 NV Wiper 3
// 10 Volatile TCON1
// 11-15 EEPROM
//

// Structures

typedef union
{
    unsigned buf : 16;
    struct
    {
        unsigned data : 10;
        unsigned cmd : 2;
        unsigned addr : 4;
    };
}MCP4341Command;

typedef union
{
    unsigned status : 9;
    struct
    {
        unsigned reserved : 2;
        unsigned WL3 : 1;
        unsigned WL2 : 1;
        unsigned EEWA : 1;
        unsigned WL1 : 1;
        unsigned WL0 : 1;
        unsigned reserved2 : 1;
        unsigned WP : 1;
    };
}MCP4341Status;

typedef union
{
    unsigned tcon : 9;
    struct
    {
        unsigned reserved : 1;
        unsigned R1HW : 1;
        unsigned R1A : 1;
        unsigned R1W : 1;
        unsigned R1B : 1;
        unsigned R0HW : 1;
        unsigned R0A : 1;
        unsigned R0W : 1;
        unsigned R0B : 1;
    };
}MCP4341TCON0;

#define TCON0_ADDR 4

typedef union
{
    unsigned tcon : 9;
    struct
    {
        unsigned reserved : 1;
        unsigned R3HW : 1;
        unsigned R3A : 1;
        unsigned R3W : 1;
        unsigned R3B : 1;
        unsigned R2HW : 1;
        unsigned R2A : 1;
        unsigned R2W : 1;
        unsigned R2B : 1;
    };
}MCP4341TCON1;

#define TCON1_ADDR 10

typedef union
{
    unsigned status : 9;
    struct
    {
        unsigned reserved2: 2;
        unsigned WL3 : 1;
        unsigned WL2 : 1;
        unsigned EEWA : 1;
        unsigned WL1 : 1;
        unsigned WL0 : 1;
        unsigned reserved : 1;
        unsigned WP : 1;
    };
}MCP4341STATUS;

#define STATUS_ADDR 5
#define CMDERR_MASK 0x200


class MCP4341 : public ControlledDevice
{
public:
    MCP4341();
    MCP4341(const MCP4341& orig);
    virtual ~MCP4341();
    virtual void Initialise(unsigned char nDevice, MCP4341SPI2* pSPI);
    virtual void SetLevel(unsigned char nLevel);
    virtual void SendReading(IODevice* pDevice, unsigned char byCommand, unsigned char nDevice);
    void SetBalance(unsigned char nBalance);
    bool Write(unsigned char address, unsigned short data);
    unsigned short Read(unsigned char address);
private:
    void Set();
    unsigned char m_LeftWiperAddr;
    unsigned char m_RightWiperAddr;
    unsigned m_TCON0Set : 9;
    unsigned m_TCON0Clr : 9;
    unsigned m_TCON1Set : 9;
    unsigned m_TCON1Clr : 9;
    unsigned short m_nLevel;
    unsigned short m_nBalance;  // Equal is 128, 0 is left 0, right nLevel, 255 is left nLevel, right 0
    MCP4341SPI2* m_pSPI;
};

#endif	/* MCP4341_H */

