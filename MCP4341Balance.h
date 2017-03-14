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
 * File:   MCP4341Balance.h
 * Author: jules
 *
 * Created on 16 November 2016, 20:27
 */


#ifndef MCP4341BALANCE_H
#define	MCP4341BALANCE_H

#include "../PIC32Device/ControlledDevice.h"

class MCP4341;

class MCP4341Balance  : public ControlledDevice
{
public:
    MCP4341Balance();
    MCP4341Balance(const MCP4341Balance& orig);
    void Initialise(MCP4341* pMCP4341);
    virtual void SetLevel(unsigned char nLevel);
    virtual void SendReading(IODevice* pDevice, unsigned char byCommand, unsigned char nDevice);
    virtual ~MCP4341Balance();
private:
    MCP4341* m_pMCP4341;
};

#endif	/* MCP4341BALANCE_H */

