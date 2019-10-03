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
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of A1
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A0
	unsigned char tmpC = 0x00; // Temporary variable to hold the value of B0
	unsigned char tmpD = 0x00; // Temporary variable to hold the value of B0
	unsigned char cntavail = 0x00; // Temporary variable to hold the value of B0
	while(1) {
		// 1) Read input
		tmpA = PINA & 0x01;
		tmpB = PINA & 0x02;
		tmpC = PINA & 0x04;
		tmpD = PINA & 0x08;
		// 2) Perform computation
		// if PA0 is 1 and PA1 is 0, then set PB0 to 01 else 00
		if (tmpA == 0x01 && tmpB == 0x00) { // True if  PA0 is 1 and PA1 is 0
			tmpC = (tmpC & 0xFE) | 0x01; // Sets tmpB to bbbbbb01
							 // (clear rightmost 2 bits, then set to 01)
		} else {
			tmpC = (tmpC & 0xFE) | 0x00; // Sets tmpB to bbbbbb00
							 // (clear rightmost 2 bits, then set to 00)
		}	
	// 3) Write output
	PORTB = tmpC;	
	}
	return 0;
}
