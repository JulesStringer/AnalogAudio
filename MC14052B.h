/* 
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

