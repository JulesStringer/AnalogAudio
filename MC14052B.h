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
 * File:   MC14052B.h
 * Author: jules
 *
 * Created on 05 November 2016, 22:20
 */

#ifndef MC14052B_H
#define	MC14052B_H

#include "../PIC32Device/ControlledDevice.h"

class IODevice;

class MC14052B : public ControlledDevice
{
public:
    MC14052B();
    MC14052B(const MC14052B& orig);
    virtual ~MC14052B();
    virtual void SetLevel(unsigned char nChannel);
    virtual void SendReading(IODevice* pDevice, unsigned char byCommand, unsigned char nDevice);
    virtual void Initialise(unsigned char nChannel);
private:

};

#endif	/* MC14052B_H */

