/*	Author: ssing072
 *  Partner(s) Name: Neha Gupta
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
/*
int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	while(1) {
		// 1) Read input
		tmpA = PINA & 0x01;
		// 2) Perform computation
		// if PA0 is 1, set PB1PB0 = 01, else = 10
		if (tmpA == 0x01) { // True if  PA0 is 1
			tmpB = (tmpB & 0xFC) | 0x01; // Sets tmpB to bbbbbb01
							 // (clear rightmost 2 bits, then set to 01)
		} else {
			tmpB = (tmpB & 0xFC) | 0x00; // Sets tmpB to bbbbbb00
							 // (clear rightmost 2 bits, then set to 00)
		}	
	// 3) Write output
	PORTB = tmpB;	
	}
	return 0;
}
*/
int main(void) {
    DDRA = 0x00;
    PORTA = 0xFF;
    DDRB = 0xFF;
    PORTB = 0x00;
    unsigned char tmp1 = 0x00;
    unsigned char tmp2 = 0x00;
    unsigned char tmp3 = 0x00;
    while (1)
    {
    tmp1 = PINA & 0x01;
    tmp2 = PINA & 0x02;
    if( tmp1 == 0x01 && tmp2 == 0x00)
    {
    tmp3 = (tmp3 & 0xFE) | 0x01;
    }
    else
    {
    tmp3 = (tmp3 & 0xFE) | 0x00;
    }
    PORTB = tmp3;
   }
 // }
  return 1;
 }
