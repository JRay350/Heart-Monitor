/*
 * adc.c
 *
 *  Created on: Dec 21, 2024
 *      Author: jacob
 */

#include "adc.h"
#include "usart.h"

/*Enable Bits*/
#define SR_EOC (1U<<1)
#define CR2_ADON (1U<<0)
#define CR2_CONT (1U<<1)
#define CR2_SWSTART (1U<<30)
#define SQR1_L (1U<<20)
#define SQR3_SQ1 (1U<<0)
#define RCC_ADC1EN (1U<<8)


void adcInit(void) {
	// Allow clock access to ADC
	RCC_APB2ENR |= RCC_ADC1EN;

	// Set data resolution
	ADC_CR1 |= (1U<<24);
	ADC_CR1 &= ~(1U<<25);

	// Set channel
	ADC_SQR1 &= ~(0xF << 20); // Select a single conversion during conversion
	ADC_SQR3 &= ~(0b11111); // Clear bits controlling the 1st conversion to select channel 0

	// Enable ADC
	ADC_CR2 |= CR2_ADON;
}

void convertADC(void) {
	// Set continuous conversion
	ADC_CR2 |= CR2_CONT;

	// Start ADC
	ADC_CR2 |= CR2_SWSTART;
}

int readADC(void) {
	while (!(ADC_SR & SR_EOC))
		;
	return ADC_DR;
}

void sampleSignal(char* buffer, int* programState) {
	char firstByte;
	int byteUSART;

	if (*programState == ON){
		char* ptr = buffer;

		for (int i = 0; i < 64; i++) {
			byteUSART = readADC();
			firstByte = (byteUSART & 0xFF);

			*buffer++ = firstByte;
		}
		// Sampling Complete
		transmitSignal(ptr);
	}
}

void transmitSignal(char* buffer) {
	for (int i = 0; i < 64; i++) {
		writeUSART2(*buffer++);
	}
}
