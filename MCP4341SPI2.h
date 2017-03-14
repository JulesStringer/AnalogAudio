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
 * File:   CMCP4341SPI2.h
 * Author: jules
 *
 * Created on 14 March 2017, 17:14
 */

#ifndef CMCP4341SPI2_H
#define	CMCP4341SPI2_H

#include "..\PIC32Device\SPI2.h"

class MCP4341SPI2 : public SPI2
{
public:
    MCP4341SPI2();
    MCP4341SPI2(const MCP4341SPI2& orig);
    virtual ~MCP4341SPI2();
    virtual void InitialiseRPR();
    bool Write(unsigned char address, unsigned short data);
    unsigned short Read(unsigned char address);
    void Start();
private:
};

#endif	/* CMCP4341SPI2_H */

