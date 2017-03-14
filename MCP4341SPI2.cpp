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
 * File:   CMCP4341SPI2.cpp
 * Author: jules
 * 
 * Created on 14 March 2017, 17:14
 */

#include "MCP4341SPI2.h"
#include "pindefs.h"
#include "MCP4341.h"

MCP4341SPI2::MCP4341SPI2() 
{
}
MCP4341SPI2::MCP4341SPI2(const MCP4341SPI2& orig) 
{
}
MCP4341SPI2::~MCP4341SPI2() 
{
}
void MCP4341SPI2::InitialiseRPR()
{
    SPI2_SS_LAT=1;     // normally chip is not selected
    // POT SDI
    SPI2_SDI_TRIS = 1;
    SPI2_SDI_ANSEL = 0;
    SPI2_SDI_RPR = SPI2_SDI_RPRVAL;
    // POT SDO
    SPI2_SDO_TRIS = 0;
    SPI2_SDO_ANSEL = 0;
    SPI2_SDO_RPR = SPI2_SDO_RPRVAL;
    // POT SCK
    SPI2_SCK_TRIS = 0;
    SPI2_SCK_ANSEL = 0;
    SPI2_SCK_RPR = SPI2_SCK_RPRVAL;
    // POT SS
    SPI2_SS_TRIS = 0;
    SPI2_SS_ANSEL = 0;

    SPI2_SS_LAT = 1;
    SPI2_SS_RPR = SPI2_SS_RPRVAL;
}
bool MCP4341SPI2::Write(unsigned char address, unsigned short data)
{
    MCP4341Command Command;
    Command.buf = 0;
    Command.addr = address;
    Command.cmd = 0;
    Command.data = data;
    unsigned long ulResult = Put((unsigned long)Command.buf);
    return (ulResult & CMDERR_MASK) == 1 ? true : false;
}
unsigned short MCP4341SPI2::Read(unsigned char address)
{
    MCP4341Command Command;
    Command.buf = 0;
    Command.addr = address;
    Command.cmd = 3;
    Command.data = 0x3FF;
    unsigned long ulResult = Put( (unsigned long)Command.buf);
    return ulResult & 0x3FF;    
}
void MCP4341SPI2::Start()
{
    POT_RESET_LAT = 1;  // Set not reset
    // Send initial status for TCON0 and TCON1
    MCP4341TCON0 tcon0;
    tcon0.tcon = 0x1FF;
    tcon0.R0A = 0;
    tcon0.R1A = 0;
    MCP4341TCON1 tcon1;
    tcon1.tcon = 0x1FF;
    tcon1.R2A = 0;
    tcon1.R3A = 0;
    Write(TCON0_ADDR, tcon0.tcon);
    unsigned long u0 = Read(TCON0_ADDR);
    Write(TCON1_ADDR, tcon1.tcon);
    unsigned long u1 = Read(TCON1_ADDR);
    int n = 0;
}
