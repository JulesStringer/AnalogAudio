/* 
 * File:   AnalogAudioServer.h
 * Author: jules
 *
 * Created on 13 February 2017, 18:12
 */

#ifndef ANALOGAUDIOSERVER_H
#define	ANALOGAUDIOSERVER_H

#include "../PIC32Device/Server.h"

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

