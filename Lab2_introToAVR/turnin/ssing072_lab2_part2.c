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

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of A1
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A0
	unsigned char tmpC = 0x00; // Temporary variable to hold the value of B0
	unsigned char tmpD = 0x00; // Temporary variable to hold the value of B0
	unsigned char cntavail = 4; // Temporary variable to hold the value of B0
	while(1) {
		// 1) Read input
		tmpA = PINA & 0x01;
		tmpB = PINA & 0x02;
		tmpC = PINA & 0x04;
		tmpD = PINA & 0x08;
		cntavail = 4;
		// 2) Perform computation
		// if PA0 is 1 and PA1 is 0, then set PB0 to 01 else 00
		if (tmpA == 0x01) { // True if  PA0 is 1 and PA1 is 0
			cntavail  = cntavail - 1; // Sets tmpB to bbbbbb01
							 // (clear rightmost 2 bits, then set to 01)
		}
		if (tmpB == 0x02) { // True if  PA0 is 1 and PA1 is 0
			cntavail  = cntavail - 1; // Sets tmpB to bbbbbb01
							 // (clear rightmost 2 bits, then set to 01)
		} 
		if (tmpC == 0x04) { // True if  PA0 is 1 and PA1 is 0
			cntavail  = cntavail - 1; // Sets tmpB to bbbbbb01
							 // (clear rightmost 2 bits, then set to 01)
		} 
		if (tmpD == 0x08) { // True if  PA0 is 1 and PA1 is 0
			cntavail  = cntavail - 1; // Sets tmpB to bbbbbb01
							 // (clear rightmost 2 bits, then set to 01)
		} 
		// 3) Write output
		PORTC = cntavail;	
	}
	return 0;
}
