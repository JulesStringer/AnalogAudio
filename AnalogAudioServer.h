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
 * File:   AnalogAudioServer.h
 * Author: jules
 *
 * Created on 13 February 2017, 18:12
 */

#ifndef ANALOGAUDIOSERVER_H
#define	ANALOGAUDIOSERVER_H

#include "../PIC32Device/Server.h"
#include "MCP4341.h"
#include "MC14052B.h"
#include "MCP4341Balance.h"

class AnalogAudioServer : public Server
{
public:
    AnalogAudioServer();
    AnalogAudioServer(const AnalogAudioServer& orig);
    virtual ~AnalogAudioServer();
    virtual void InitialiseDevices();
private:
    MCP4341 m_VolumeControl1;
    MCP4341 m_VolumeControl2;
    MC14052B m_Mux1;
    MC14052B m_Mux2;
    MCP4341Balance m_BalanceControl1;
    MCP4341Balance m_BalanceControl2;
};

#endif	/* ANALOGAUDIOSERVER_H */

