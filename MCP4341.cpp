/* 
 * File:   MCP4341.cpp
 * Author: Jules Stringer
 * 
 * Created on 05 November 2016, 21:15
 */

#include "MCP4341.h"
#include "../PIC32Device/hardwareprofile.h"
#include "pindefs.h"

MCP4341::MCP4341() 
    : m_LeftWiperAddr(6)
    , m_RightWiperAddr(0)
    , m_TCON0Set(1 << 2)
    , m_TCON1Set(1 << 2)
    , m_TCON0Clr(0x1FF ^ (1 << 2))
    , m_TCON1Clr(0x1FF ^ (1 << 2))
    , m_nLevel(0)
    , m_nBalance(128)
{
}
MCP4341::MCP4341(const MCP4341& orig) 
{
    m_LeftWiperAddr = orig.m_LeftWiperAddr;
    m_RightWiperAddr = orig.m_RightWiperAddr;
    m_TCON0Set = orig.m_TCON0Set;
    m_TCON1Set = orig.m_TCON1Set;
    m_TCON0Clr = orig.m_TCON0Clr;
    m_TCON1Clr = orig.m_TCON1Clr;
    m_nLevel = orig.m_nLevel;
    m_nBalance  = orig.m_nBalance;
}
MCP4341::~MCP4341() 
{
}
void MCP4341::Initialise(unsigned char nDevice)
{
    // TODO The following is strictly duplicated, should this move into hardware initialisation
    // Reset chip and set volume to 0
    m_nDevice = nDevice;
    // wiper A is input signal which should be disconnected when turned off
    switch(nDevice)
    {
    case 1:
        m_LeftWiperAddr = 7;  // wiper 3
        m_RightWiperAddr = 1; // wiper 1
        m_TCON0Set= 1 << 6;
        m_TCON1Set = 1 << 6;
        // Also do general initialisation on this channel
        // POT !WP
        POT_WP_TRIS = 0;
        POT_WP_ANSEL = 0;
        POT_WP_LAT = 0; // Initially write protected
        // POT !RESET - initially reset
        POT_RESET_TRIS = 0;
        POT_RESET_ANSEL = 0;
        POT_RESET_LAT = 0;
        // Power control for amplifier boards
        CH1_PWR_TRIS = 0;
        CH1_PWR_ANSEL = 0;
        CH1_PWR_LAT = 0;
        break;
    case 2:
        m_LeftWiperAddr = 6;  // wiper 2
        m_RightWiperAddr = 0; // wiper 0
        m_TCON0Set = 1 << 2;
        m_TCON1Set = 1 << 2;
        // Power control for amplifier boards
        CH2_PWR_TRIS = 0;
        CH2_PWR_ANSEL = 0;
        CH2_PWR_LAT = 0;
        break;
    }
    m_TCON0Clr = 0x1FF ^ m_TCON0Set;
    m_TCON1Clr = 0x1FF ^ m_TCON1Set;
}
void MCP4341::Start()
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
void MCP4341::SetLevel(unsigned char nLevel)
{
    m_nLevel = nLevel;
    Set();
}
void MCP4341::SetBalance(unsigned char nBalance)
{
    m_nBalance = nBalance;
    Set();
}
bool MCP4341::Write(unsigned char address, unsigned short data)
{
    MCP4341Command Command;
    Command.buf = 0;
    Command.addr = address;
    Command.cmd = 0;
    Command.data = data;
    unsigned long ulResult = WriteSPI2(Command.buf);
    return (ulResult & CMDERR_MASK) == 1 ? true : false;
}
unsigned short MCP4341::Read(unsigned char address)
{
    MCP4341Command Command;
    Command.buf = 0;
    Command.addr = address;
    Command.cmd = 3;
    Command.data = 0x3FF;
    unsigned long ulResult = WriteSPI2(Command.buf);
    return ulResult & 0x3FF;    
}
void MCP4341::Set()
{
    MCP4341TCON0 tcon0;
    MCP4341TCON1 tcon1;
    unsigned long uStatus = Read(STATUS_ADDR);
    MCP4341STATUS status;
    status.status = uStatus & 0x1FF;
    // Get TCON and TCON1
    tcon0.tcon = Read(TCON0_ADDR);
    tcon1.tcon = Read(TCON1_ADDR);
    tcon0.tcon = Read(TCON0_ADDR);
    if ( m_nLevel == 0 )
    {
        // Disconnect wipers A terminal
        tcon0.tcon &= m_TCON0Clr;
        tcon1.tcon &= m_TCON1Clr;
        // Turn off power to amplifier
        switch(m_nDevice)
        {
            case 1:
                CH1_PWR_LAT = 0;
                break;
            case 2:
                CH2_PWR_LAT = 0;
                break;
        }
    }
    else
    {
        // Set left and right wipers to level
        unsigned short usLeft = (m_nLevel * m_nBalance)/128;
        unsigned short usRight = (m_nLevel * (256 - m_nBalance))/128;
        if ( !Write(m_LeftWiperAddr, usLeft ))
        {
            Write(m_LeftWiperAddr, usLeft);
        }
        if ( !Write(m_RightWiperAddr, usRight))
        {
            Write(m_RightWiperAddr, usRight);
        }
        // If Wipers disconnected connect them
        tcon0.tcon |= m_TCON0Set;
        tcon1.tcon |= m_TCON1Set;
    }
    // Set TCON registers
    Write(TCON0_ADDR, tcon0.tcon);
    Write(TCON1_ADDR, tcon1.tcon);
    if ( m_nLevel != 0 )
    {
        switch(m_nDevice)
        {
            case 1:
                CH1_PWR_LAT = 1;
                break;
            case 2:
                CH2_PWR_LAT = 1;
                break;
        }
    }
}
void MCP4341::SendReading(IODevice* pDevice, unsigned char byCommand, unsigned char nDevice)
{
    // get volume for channel

    if ( byCommand == 'S')
    {
        unsigned long uLeft = Read(m_LeftWiperAddr);    
        unsigned long uRight = Read(m_RightWiperAddr);
        uLeft = Read(m_LeftWiperAddr);
        // send reading
        unsigned short usValue = (uLeft & 0xFF) << 8 | (uRight & 0xFF);
        SendResult(pDevice, byCommand, nDevice, usValue);
    }
    else if ( byCommand == 'I')
    {
        unsigned long uLeft = Read(TCON0_ADDR);    
        unsigned long uRight = Read(TCON1_ADDR);
        uLeft = Read(TCON0_ADDR);
        // send reading
        unsigned short usValue = (uLeft & 0xFF) << 8 | (uRight & 0xFF);
        SendResult(pDevice, byCommand, nDevice, usValue);
    }
}
