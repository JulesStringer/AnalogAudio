/* 
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
