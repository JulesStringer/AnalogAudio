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
 * File:   pindefs.h
 * Author: jules
 *
 * Created on 13 February 2017, 18:59
 */

#ifndef PINDEFS_H
#define	PINDEFS_H

#include <GenericTypeDefs.h>
#include <xc.h>

 /* Pin assignments 
 * 
 * Naming has 3 parts or optionally 4 parts
 * CHn   can be CH1 or CH2
 * FFF   application Function (e.g. PWR, MUXA, MUXB, POT)
 * PPP   optional pin function e.g. SDO, SDI, SCK, CS, RX, TX  
 * HHH   hardware function (e.g. LAT, TRIS, PORT)
 */
// Power control for amplifier boards
#define CH1_PWR_LAT      LATBbits.LATB0
#define CH1_PWR_TRIS     TRISBbits.TRISB0
#define CH1_PWR_ANSEL    ANSELBbits.ANSB0
#define CH2_PWR_LAT      LATBbits.LATB1
#define CH2_PWR_TRIS     TRISBbits.TRISB1
#define CH2_PWR_ANSEL    ANSELBbits.ANSB1
// Multiplexer channel control
#define CH1_MUXB_LAT     (LATBbits.LATB2)
#define CH1_MUXB_TRIS    (TRISBbits.TRISB2)
#define CH1_MUXB_ANSEL   (ANSELBbits.ANSB2)
#define CH1_MUXB_PORT    (PORTBbits.RB2)

#define CH1_MUXA_LAT     (LATAbits.LATA2)
#define CH1_MUXA_TRIS    (TRISAbits.TRISA2)
#define CH1_MUXA_ANSEL   (ANSELAbits.ANSA2)
#define CH1_MUXA_PORT    (PORTAbits.RA2)

#define CH2_MUXB_LAT     (LATAbits.LATA3)
#define CH2_MUXB_TRIS    (TRISAbits.TRISA3)
#define CH2_MUXB_ANSEL   (ANSELAbits.ANSA3)
#define CH2_MUXB_PORT    (PORTAbits.RA3)

#define CH2_MUXA_LAT     (LATBbits.LATB4)
#define CH2_MUXA_TRIS    (TRISBbits.TRISB4)
#define CH2_MUXA_ANSEL   (PRODL)
#define CH2_MUXA_PORT    (PORTBbits.RB4)
// POT !WP
#define POT_WP_LAT     (LATAbits.LATA4)
#define POT_WP_TRIS    (TRISAbits.TRISA4)
#define POT_WP_ANSEL   (PRODL)
// POT !RESET
#define POT_RESET_LAT     (LATBbits.LATB7)
#define POT_RESET_TRIS    (TRISBbits.TRISB7)
#define POT_RESET_ANSEL   (PRODL)


#endif	/* PINDEFS_H */

