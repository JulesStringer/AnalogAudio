/* 
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

