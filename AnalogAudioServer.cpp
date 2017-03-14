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
 * File:   AnalogAudioServer.cpp
 * Author: jules
 * 
 * Created on 13 February 2017, 18:12
 */

#include "AnalogAudioServer.h"
#include "BoardDef.h"

AnalogAudioServer::AnalogAudioServer() 
{
}

AnalogAudioServer::AnalogAudioServer(const AnalogAudioServer& orig) 
{
}

AnalogAudioServer::~AnalogAudioServer() 
{
  
}

void AnalogAudioServer::InitialiseDevices()
{
    m_VolumeControl1.Initialise(1);
    m_VolumeControl2.Initialise(2);
    m_Mux1.Initialise(1);
    m_Mux2.Initialise(2);
    m_BalanceControl1.Initialise(&m_VolumeControl1);
    m_BalanceControl2.Initialise(&m_VolumeControl2);
    AddDevice(1, &m_VolumeControl1);
    AddDevice(2, &m_VolumeControl2);
    AddDevice(1, &m_Mux1);
    AddDevice(2, &m_Mux2);
    AddDevice(1, &m_BalanceControl1);
    AddDevice(2, &m_BalanceControl2);
    MCP4341::Start();
}
extern "C" void RunServer()
{
    AnalogAudioServer svr;
    svr.Run();
}
int GetBoardID()
{
    return SWITCH_ID;
}
