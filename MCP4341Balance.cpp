/* 
 * File:   MCP4341Balance.cpp
 * Author: jules
 * 
 * Created on 16 November 2016, 20:27
 */

#include "MCP4341Balance.h"
#include "MCP4341.h"
#include <GenericTypeDefs.h>


MCP4341Balance::MCP4341Balance() 
    : m_pMCP4341(NULL)
{
}
MCP4341Balance::MCP4341Balance(const MCP4341Balance& orig) 
{
    m_pMCP4341 = orig.m_pMCP4341;
}
MCP4341Balance::~MCP4341Balance() 
{
}
void MCP4341Balance::Initialise(MCP4341* pMCP4341)
{
    m_pMCP4341 = pMCP4341;
}
void MCP4341Balance::SetLevel(unsigned char nLevel)
{
    if ( m_pMCP4341 )
    {
        m_pMCP4341->SetBalance(nLevel);
    }
}
void MCP4341Balance::SendReading(IODevice* pDevice, unsigned char byCommand, unsigned char nDevice)
{
    if ( m_pMCP4341 )
    {
        m_pMCP4341->SendReading(pDevice, byCommand, nDevice);
    }
}
